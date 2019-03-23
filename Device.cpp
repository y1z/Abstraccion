#include "Device.h"
Device::Device(){

	
}

//! \todo Finish InitDevice

Device::~Device()
{

	if (mptr_Device != nullptr) { mptr_Device->Release(); }
}

/*!
	\brief Create a vertex buffer
	\param [in] SizeVertex tells the size of a SINGLE vertex in bytes.
	\param [in] CountVertex How many vertex there are.
	\param [in] DataVertex it's a pointer to INITIALIZED memory
	\param [out] VertexBuffer The Resulting VertexBuffer
*/
bool Device::CreateVertexBuffer(uint32_t SizeVertex, uint32_t CountVertex,
																void *DataVertex, ID3D11Buffer* VertexBuffer)
{

	D3D11_BUFFER_DESC Desc;
	Desc.Usage = D3D11_USAGE_DEFAULT;

	// initializes the memory 
	SecureZeroMemory(static_cast<PVOID>(&Desc), sizeof(Desc));
	// how much memory does the vertex takes up 
	Desc.ByteWidth = SizeVertex * CountVertex;
	Desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	Desc.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	SecureZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = DataVertex;
	HRESULT	hr = mptr_Device->CreateBuffer(&Desc, &InitData, &VertexBuffer);
	if (FAILED(hr))
		return false;

	return	true;
}

/*!
\brief inti a Device in combination with a SwapChain 
\param [in] DescSwapChain a Descriptor Struct that contain information of the Swap chain 
\param [out] SwapChain in other word what controls whats drawn to the screen 
\param [out] DeviceContext This variable will set all values created by the Device 
*/

bool Device::InitDeviceAndSwapChain(DXGI_SWAP_CHAIN_DESC *DescSwapChain, IDXGISwapChain *&SwapChain,
																		ID3D11DeviceContext *&DeviceContext)
{
	D3D_DRIVER_TYPE DrivesOpctions[] = {
 D3D_DRIVER_TYPE_HARDWARE,
 D3D_DRIVER_TYPE_REFERENCE,
 D3D_DRIVER_TYPE_UNKNOWN,
 D3D_DRIVER_TYPE_WARP,
 D3D_DRIVER_TYPE_SOFTWARE,
 D3D_DRIVER_TYPE_NULL
	};


	UINT Flags = 0;
	Flags |= D3D11_CREATE_DEVICE_DEBUG;

	HRESULT	 Result;

	for (char i = 0; i < ARRAYSIZE(DrivesOpctions); ++i)
	{
		Result = D3D11CreateDeviceAndSwapChain(NULL, DrivesOpctions[i], NULL,
																					 Flags, NULL, NULL, 
																					 D3D11_SDK_VERSION, DescSwapChain, &SwapChain
																					 , &mptr_Device, NULL, &DeviceContext);
		if (SUCCEEDED(Result))
		{
			return true;
		}

	}

	return false;
}

bool Device::InitDevice()
{
	/*
	HRESULT hr = S_OK;

		IDXGIDevice * pDXGIDevice = nullptr;
	hr = mptr_Device->QueryInterface(__uuidof(IDXGIDevice), (void **)&pDXGIDevice);


	IDXGIAdapter * pDXGIAdapter = nullptr;
	hr = pDXGIDevice->GetAdapter(&pDXGIAdapter);

	IDXGIFactory * pIDXGIFactory = nullptr;
	pDXGIAdapter->GetParent(__uuidof(IDXGIFactory), (void **)&pIDXGIFactory);

	D3D11CreateDevice()*/
	return false;
}

ID3D11Device * Device::GetDevice()
{
	return mptr_Device;
}


