#include "CGraphicsManager.h"



CGraphicsManager::CGraphicsManager()
{
}


CGraphicsManager::~CGraphicsManager()
{
	delete mptr_Device;
	delete mptr_SwapChain;
	delete mptr_DeviceContext;
	delete mptr_Window;
	delete mptr_Buffer;
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

CTexture* CGraphicsManager::CreateRenderTragetFromBackBuffer()
{
	CTexture *Texture = nullptr;

	Texture = mptr_SwapChain->GetFromBuffer(0);

	// Initializes a RenderTarget 
	mptr_Device->GetDevice()->CreateRenderTargetView(Texture->GetTexture2D(), nullptr, Texture->GetRenderTragetRef());

	return Texture;
}

void CGraphicsManager::SetRenderTargetView(CTexture & Rendertarget, CTexture * DepthStencil)
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
	mptr_DeviceContext->GetDirecXContext()->PSSetConstantBuffers(m_ConstantBufferSlotCount++, 1, Constbuffer.GetBufferRef());
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
