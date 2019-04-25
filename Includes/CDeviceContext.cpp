#include "CDeviceContext.h"
#include "GlobalValues.h"
#include "CBuffer.h"
CDeviceContext::CDeviceContext()
{
}

CDeviceContext::~CDeviceContext()
{
	mptr_DeviaceContext->Release();
}

ID3D11DeviceContext * CDeviceContext::GetDeviceContext()
{
	return mptr_DeviaceContext;
}

ID3D11DeviceContext ** CDeviceContext::GetContextPointerRef()
{
	return &mptr_DeviaceContext;
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

	mptr_DeviaceContext->RSSetViewports(1, &ViewPort);
}

void CDeviceContext::SetIndiceBuffer(CBuffer &buffer, int Format = 10)
{
	mptr_DeviaceContext->IASetIndexBuffer(buffer.GetBuffer(),
																				static_cast<DXGI_FORMAT>(Format),
																				0);
}

void CDeviceContext::SetVertexBuffer(CBuffer & Buffer)
{
	UINT Stride = Buffer.GetStride();
	UINT OffSet = Buffer.GetOffSet();

	const	UINT *ptr_Stride = &Stride;
	const	UINT *ptr_OffSet = &OffSet;

	mptr_DeviaceContext->IASetVertexBuffers(0,
																					1,
																					Buffer.GetBufferRef(),
																					&Stride,
																					ptr_OffSet);
}
// default value is 4
void CDeviceContext::SetTopology(int Format)
{
	mptr_DeviaceContext->IASetPrimitiveTopology(
		static_cast<D3D_PRIMITIVE_TOPOLOGY>(Format));
}

