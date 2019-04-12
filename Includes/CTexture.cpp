#include "CTexture.h"

CTexture::CTexture()
{
}


CTexture::~CTexture()
{
	mptr_Texture2D->Release();
	mptr_DepthStencilView->Release();
	mptr_RenderTargetView->Release();
}

ID3D11RenderTargetView * CTexture::GetRenderTraget() const
{
	return mptr_RenderTargetView;
}

ID3D11RenderTargetView ** CTexture::GetRenderTragetRef()
{
	return &mptr_RenderTargetView;
}

ID3D11Texture2D * CTexture::GetTexture2D()
{
	return mptr_Texture2D;
}

ID3D11Texture2D ** CTexture::GetTexture2DRef()
{
	return &mptr_Texture2D;
}

ID3D11DepthStencilView * CTexture::GetDepthSetncilView()
{
	return mptr_DepthStencilView;
}

ID3D11DepthStencilView ** CTexture::GetDepthSetncilViewRef()
{
	return &mptr_DepthStencilView;
}
