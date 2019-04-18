#include "CSwapChain.h"



CSwapChain::CSwapChain()
{
}


CSwapChain::~CSwapChain()
{
	mptr_SwapChain->Release();

	if (mptr_Texture != nullptr) { delete mptr_Texture; }
}

CTexture* CSwapChain::GetFromBuffer(uint32_t indice)
{
	CTexture * ptr_Texture = new CTexture();

	mptr_SwapChain->GetBuffer(indice, __uuidof(ID3D11Texture2D), (LPVOID*)ptr_Texture->GetTexture2DRef());

	return ptr_Texture;
}

IDXGISwapChain *CSwapChain::GetSwapChian() const
{
	return mptr_SwapChain;
}

IDXGISwapChain ** CSwapChain::GetSwapChianPointerRef()
{
	return &mptr_SwapChain;
}
