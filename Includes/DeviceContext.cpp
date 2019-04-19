#include "CDeviceContext.h"
#include "GlobalValues.h"

CDeviceContext::CDeviceContext()
{
}


CDeviceContext::~CDeviceContext()
{
	mptr_ImmediateContext->Release();
}

ID3D11DeviceContext * CDeviceContext::GetDirecXContext()
{
	return mptr_ImmediateContext;
}

ID3D11DeviceContext ** CDeviceContext::GetContextPointerRef()
{
	return &mptr_ImmediateContext;
}

/*just for testing */
void CDeviceContext::SetDefaultViewPort()
{
	D3D11_VIEWPORT ViewPort;
	ViewPort.Width = (FLOAT)DEFAULT_WIDTH;
	ViewPort.Height = (FLOAT)DEFAULT_HEIGHT;
	ViewPort.MinDepth = 0.0f;
	ViewPort.MaxDepth = 1.0f;
	ViewPort.TopLeftX = 0;
	ViewPort.TopLeftY = 0;

	mptr_ImmediateContext->RSSetViewports(1, &ViewPort);
}
