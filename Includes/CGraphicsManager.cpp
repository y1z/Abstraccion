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

void CGraphicsManager::Draw(CBuffer &Buffer)
{
	mptr_DeviceContext->
		GetDeviceContext()->Draw(Buffer.GetElementCount(),
														 0);
}


bool CGraphicsManager::InitGraphics(CWindow *Window)
{
	bool Result = false;

	mptr_Device = new CDevice();
	mptr_SwapChain = new CSwapChain();
	mptr_DeviceContext = new CDeviceContext();

	Result = mptr_Device->InitDevice(
		mptr_SwapChain,
		mptr_DeviceContext,
		Window);

	return Result;
}

CTexture* CGraphicsManager::ReciveRenderTragetFromBackBuffer()
{
	CTexture *Texture = nullptr;

	Texture = mptr_SwapChain->GetFromBuffer(0);

	// Initializes a RenderTarget 
	mptr_Device->GetDevice()->
		CreateRenderTargetView(Texture->GetTexture2D(),
													 nullptr,
													 Texture->GetRenderTragetRef());

	return Texture;
}

void CGraphicsManager::SetRenderTargetView(CTexture & Rendertarget,
																					 CTexture *DepthStencil)
{

	if (DepthStencil != NULL)
	{
		mptr_DeviceContext->GetDeviceContext()->
			OMSetRenderTargets(1,
												 Rendertarget.GetRenderTragetRef(),
												 DepthStencil->GetDepthSetncilView());
	}
	else
	{
		mptr_DeviceContext->GetDeviceContext()->
			OMSetRenderTargets(1,
												 Rendertarget.GetRenderTragetRef(),
												 nullptr);
	}

}

void CGraphicsManager::SetConstantBuffer(CBuffer &Constbuffer)
{
	mptr_DeviceContext->
		GetDeviceContext()->PSSetConstantBuffers(m_SlotCount,
																						 1,
																						 Constbuffer.GetBufferRef());

	m_SlotCount++;
}


void CGraphicsManager::ClearRenderTargetView(CTexture &RenderTarget,
																						 float *ptr_color)
{
	if (ptr_color != nullptr)
	{
		mptr_DeviceContext->GetDeviceContext()->
			ClearRenderTargetView(RenderTarget.GetRenderTraget(), ptr_color);
	}
	else
	{
		// should be purple
		float DefualtColor[4] = { 0.3f,0.08f,0.7f,.0f };

		mptr_DeviceContext->GetDeviceContext()->
			ClearRenderTargetView(RenderTarget.GetRenderTraget(), DefualtColor);
	}

}

void CGraphicsManager::Present(int A, int Flags)
{
	mptr_SwapChain->GetSwapChian()->Present(A, Flags);
}

CVertexShader* CGraphicsManager::ReceiveVertexShader(
	const std::wstring & FileName,
	const std::string & EntryPoint,
	const std::string & ShaderModel)
{
	CVertexShader *ptr_VertexShader = new CVertexShader();

	ptr_VertexShader->Init(FileName, EntryPoint, ShaderModel);

	HRESULT hr = mptr_Device->GetDevice()->
		CreateVertexShader(ptr_VertexShader->GetBlob()->GetBufferPointer(),
											 ptr_VertexShader->GetBlob()->GetBufferSize(),
											 nullptr,
											 ptr_VertexShader->GetVertexShaderRef());

	if (FAILED(hr))
	{
		assert(SUCCEEDED(hr), "failed Vertex Shader Creation");
	}

	return ptr_VertexShader;
}


CPixelShader * CGraphicsManager::ReceivePixelShader(
	const std::wstring &FileName,
	const std::string & EntryPoint,
	const std::string & ShaderModel)
{
	CPixelShader *ptr_PixelShader = new CPixelShader();

	ptr_PixelShader->Init(FileName, EntryPoint, ShaderModel);

	HRESULT hr = mptr_Device->GetDevice()->
		CreatePixelShader(ptr_PixelShader->GetBlob()->GetBufferPointer(),
											ptr_PixelShader->GetBlob()->GetBufferSize(),
											nullptr,
											ptr_PixelShader->GetPixelShaderRef());

	if (FAILED(hr))
	{
		assert(SUCCEEDED(hr), "failed Pixel Shader Creation");
	}

	return ptr_PixelShader;
}

CSampler * CGraphicsManager::ReciveDefaultSampler()
{
	CSampler * ptr_Sampler = new CSampler();
	ptr_Sampler->InitDefaultSampler();

	HRESULT hr = S_OK;

	hr = mptr_Device->GetDevice()->CreateSamplerState(&ptr_Sampler->GetDescriptorRef(),
																										ptr_Sampler->GetSamplerRef());

	if (FAILED(hr))
	{
		assert(SUCCEEDED(hr), "Sampler creation failed");
	}


	return ptr_Sampler;
}

CSampler * CGraphicsManager::ReciveAnisotropicSampler()
{
	CSampler * ptr_Sampler = new CSampler();
	ptr_Sampler->InitAnisotropicSampler();

	HRESULT hr = S_OK;

	hr = mptr_Device->GetDevice()->CreateSamplerState(&ptr_Sampler->GetDescriptorRef(),
																										ptr_Sampler->GetSamplerRef());

	if (FAILED(hr))
	{
		assert(SUCCEEDED(hr), "Sampler creation failed");
	}


	return ptr_Sampler;
}

void CGraphicsManager::SetVertexShader(CVertexShader * ptr_Vertex)
{
	mptr_DeviceContext->GetDeviceContext()->
		VSSetShader(ptr_Vertex->GetVertexShader(),
								nullptr,
								0);
}

void CGraphicsManager::SetPixelShader(CPixelShader * ptr_Pixel)
{
	mptr_DeviceContext->GetDeviceContext()->
		PSSetShader(ptr_Pixel->GetPixelShader(),
								nullptr,
								0);
}

void CGraphicsManager::SetSampler(CSampler * ptr_Sampler)
{
	mptr_DeviceContext->GetDeviceContext()->
		PSSetSamplers(0,
									1,
									ptr_Sampler->GetSamplerRef());
}

void CGraphicsManager::SetVertexBuffer(CBuffer & buffer)
{
	mptr_DeviceContext->SetVertexBuffer(buffer);
}

void CGraphicsManager::SetIndiceBuffer(CBuffer & buffer, int Format = 10)
{
	mptr_DeviceContext->SetIndiceBuffer(buffer, Format);
}

void CGraphicsManager::SetInputLayout(ID3D11InputLayout *InputLayout)
{
	mptr_DeviceContext->GetDeviceContext()->IASetInputLayout(InputLayout);
}

void CGraphicsManager::SetTopology(int Format = 4)
{
	mptr_DeviceContext->SetTopology(Format);
}


ID3D11InputLayout* CGraphicsManager::ReceiveInputLayout(
	std::vector<D3D11_INPUT_ELEMENT_DESC> &Layout,
	CVertexShader &VertexShader)
{
	ID3D11InputLayout *ptr_Input = nullptr;

	mptr_Device->GetDevice()->
		CreateInputLayout(&Layout[0],
											Layout.size(),
											VertexShader.GetBlob()->GetBufferPointer(),
											VertexShader.GetBlob()->GetBufferSize(),
											&ptr_Input);

	return ptr_Input;
}


bool CGraphicsManager::CreateBuffer(CBuffer & buffer)
{
	HRESULT Hr = S_OK;
	Hr = mptr_Device->GetDevice()->CreateBuffer(
		buffer.GetDescRef(), buffer.GetDataRef(), buffer.GetBufferRef());

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
