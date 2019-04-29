#include "CDevice.h"
#include "GlobalValues.h"

CDevice::CDevice(){


}



CDevice::~CDevice()
{

	if (mptr_Device != nullptr) { mptr_Device->Release(); }
}

/*! The Buffer should Have the data within it self */
bool CDevice::CreateBuffer(CBuffer & buffer)
{
	HRESULT Result = S_OK;
	Result = mptr_Device->CreateBuffer(buffer.GetDescRef(), buffer.GetDataRef(), buffer.GetBufferRef());

	if (FAILED(Result))
		return false;

	return true;
}

/*! Creates the Device along with SwapChain and DeviceContext*/
bool CDevice::InitDevice(CSwapChain *SwapChain, CDeviceContext *Context, CWindow *Window)
{

	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = Window->GetWidth();
	sd.BufferDesc.Height = Window->GetHeight();
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = Window->GetHandleRef();
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;

	D3D_DRIVER_TYPE DrivesOpctions[] = {
 D3D_DRIVER_TYPE_HARDWARE,
 D3D_DRIVER_TYPE_REFERENCE,
 D3D_DRIVER_TYPE_UNKNOWN,
 D3D_DRIVER_TYPE_WARP,
 D3D_DRIVER_TYPE_NULL,
 D3D_DRIVER_TYPE_SOFTWARE
	};


	UINT Flags = 0;
#ifdef _DEBUG
	Flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	HRESULT	 IsDiveceCreated S_OK;

	for (char i = 0; i < ARRAYSIZE(DrivesOpctions); ++i)
	{
		IsDiveceCreated = D3D11CreateDeviceAndSwapChain(NULL, DrivesOpctions[i], NULL,
																										Flags, NULL, NULL,
																										D3D11_SDK_VERSION, &sd, SwapChain->GetSwapChianPointerRef()
																										, &mptr_Device, NULL, Context->GetContextPointerRef());
		if (SUCCEEDED(IsDiveceCreated))
		{
			return true;
		}

	}

	return false;
}

ID3D11Device* CDevice::GetDevice() const
{
	return mptr_Device;
}

ID3D11Device ** CDevice::GetDeviceRef()
{
	return  &mptr_Device;
}

bool CDevice::CreateDepthSencil(CTexture & Texture)
{
	//checks for errors
	HRESULT hr = S_OK;


	D3D11_TEXTURE2D_DESC descDepth;
	ZeroMemory(&descDepth, sizeof(descDepth));
	descDepth.Width = DEFAULT_WIDTH;
	descDepth.Height = DEFAULT_HEIGHT;

	descDepth.MipLevels = 1;
	descDepth.ArraySize = 1;
	descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;

	descDepth.SampleDesc.Count = 1;
	descDepth.SampleDesc.Quality = 0;
	descDepth.Usage = D3D11_USAGE_DEFAULT;
	descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	descDepth.CPUAccessFlags = 0;
	descDepth.MiscFlags = 0;

	D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
	ZeroMemory(&descDSV, sizeof(descDSV));
	descDSV.Format = descDepth.Format;
	descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	descDSV.Texture2D.MipSlice = 0; 

	hr = mptr_Device->CreateTexture2D(&descDepth,
																		nullptr,
																		Texture.GetTexture2DRef());
	if (FAILED(hr))
	{
		assert(SUCCEEDED(hr), "Error with TEXTURE creation");
	}

	hr = mptr_Device->CreateDepthStencilView(Texture.GetTexture2D(),
																			&descDSV,
																			Texture.GetDepthSetncilViewRef());

	if (FAILED(hr))
	{
		assert(SUCCEEDED(hr), "Error with depth stencil creation");
	}


	return true;
}
