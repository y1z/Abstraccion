#include "DeviceContext.h"



DeviceContext::DeviceContext()
{
}


DeviceContext::~DeviceContext()
{
	mptr_ImmediateContext->Release();
}

ID3D11DeviceContext * DeviceContext::GetDirecXContext()
{
	return mptr_ImmediateContext;
}

ID3D11DeviceContext ** DeviceContext::GetContextPointerRef()
{
	return &mptr_ImmediateContext;
}
