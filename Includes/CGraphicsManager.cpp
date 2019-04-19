#include "CGraphicsManager.h"


CGraphicsManager::CGraphicsManager()
{
}

CGraphicsManager::~CGraphicsManager()
{
	if (mptr_Device != nullptr) { delete mptr_Device; }

	if (mptr_SwapChain != nullptr) { delete mptr_SwapChain; }
	if (mptr_DeviceContext != nullptr) { delete mptr_DeviceContext; }
	if (mptr_Window != nullptr) { delete mptr_Window; }
}


bool CGraphicsManager::InitGraphics(CWindow *Window)
{
	bool Result = false;

	mptr_Device = new CDevice();
	mptr_SwapChain = new CSwapChain();
	mptr_DeviceContext = new CDeviceContext();

	Result = mptr_Device->InitDevice(mptr_SwapChain, mptr_DeviceContext, Window);

	return Result;
}

CTexture* CGraphicsManager::ReciveRenderTragetFromBackBuffer()
{
	CTexture *Texture = nullptr;

	Texture = mptr_SwapChain->GetFromBuffer(0);

	// Initializes a RenderTarget 
	mptr_Device->GetDevice()->CreateRenderTargetView(Texture->GetTexture2D(),
																									 nullptr,
																									 Texture->GetRenderTragetRef());

	return Texture;
}

void CGraphicsManager::SetRenderTargetView(CTexture & Rendertarget, 
																					 CTexture *DepthStencil)
{

	if (DepthStencil != NULL)
	{
		mptr_DeviceContext->GetDirecXContext()->OMSetRenderTargets(1, Rendertarget.GetRenderTragetRef(), DepthStencil->GetDepthSetncilView());
	}
	else
	{
		mptr_DeviceContext->GetDirecXContext()->OMSetRenderTargets(1, Rendertarget.GetRenderTragetRef(), nullptr);
	}

}

void CGraphicsManager::SetConstantBuffer(CBuffer &Constbuffer)
{
	mptr_DeviceContext->GetDirecXContext()->
		PSSetConstantBuffers(m_SlotCount++,
												 1,
												 Constbuffer.GetBufferRef());
}


void CGraphicsManager::ClearRenderTargetView(CTexture &RenderTarget, float *ptr_color)
{
	if (ptr_color != nullptr)
	{
		mptr_DeviceContext->GetDirecXContext()->ClearRenderTargetView(RenderTarget.GetRenderTraget(), ptr_color);
	}
	else
	{
		// should be purple
		float DefualtColor[3] = { 0.3f,0.08f,0.7f };

		mptr_DeviceContext->GetDirecXContext()->ClearRenderTargetView(RenderTarget.GetRenderTraget(), ptr_color);
	}

}

void CGraphicsManager::Present(int A, int Flags)
{
	mptr_SwapChain->GetSwapChian()->Present(A, Flags);
}

CVertexShader* CGraphicsManager::ReceiveVertexShader(const std::wstring & FileName,
																										 const std::string & EntryPoint,
																										 const std::string & ShaderModel)
{
	CVertexShader *ptr_VertexShaderTemp = new CVertexShader();

	ptr_VertexShaderTemp->Init(FileName, EntryPoint, ShaderModel);

	HRESULT hr = mptr_Device->GetDevice()->CreateVertexShader(ptr_VertexShaderTemp->GetBlob()->GetBufferPointer(),
																														ptr_VertexShaderTemp->GetBlob()->GetBufferSize(),
																														nullptr,
																														ptr_VertexShaderTemp->GetVertexShaderRef());

	if (FAILED(hr))
	{
		assert(SUCCEEDED(hr), "failed VertexShader Creation");
	}

	return ptr_VertexShaderTemp;
}


ID3D11InputLayout* CGraphicsManager::ReceiveInputLayout(std::vector<D3D11_INPUT_ELEMENT_DESC> &Layout,
																												CVertexShader &VertexShader)
{
	ID3D11InputLayout *ptr_Input = nullptr;

	mptr_Device->GetDevice()->CreateInputLayout(&Layout[0], Layout.size(), VertexShader.GetBlob()->GetBufferPointer(),
																							VertexShader.GetBlob()->GetBufferSize(), &ptr_Input);

	return ptr_Input;
}


bool CGraphicsManager::CreateBuffer(CBuffer & buffer)
{
	HRESULT Hr = S_OK;
	Hr = mptr_Device->GetDevice()->CreateBuffer(buffer.GetDescRef(), buffer.GetDataRef(), buffer.GetBufferRef());
	if (FAILED(Hr))
	{
		return false;
	}
	return true;
}

void CGraphicsManager::InitDefaultViewPort()
{
	mptr_DeviceContext->SetDefaultViewPort();
}
