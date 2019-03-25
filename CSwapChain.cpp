#include "CSwapChain.h"



CSwapChain::CSwapChain()
{
}


CSwapChain::~CSwapChain()
{
	mptr_SwapChain->Release();
}

IDXGISwapChain *CSwapChain::GetSwapChian() const
{
	return mptr_SwapChain;
}

IDXGISwapChain ** CSwapChain::GetSwapChianPointerRef()
{
	return &mptr_SwapChain;
}
