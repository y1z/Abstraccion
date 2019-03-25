#include "Device.h"


//! \todo Finish InitDevice


Device::Device(){

	
}



Device::~Device()
{

	if (mptr_Device != nullptr) { mptr_Device->Release(); }
}

/*!
	\brief Create a vertex buffer
	\param [in] SizeVertex tells the size of a SINGLE vertex in bytes.
	\param [in] CountVertex How many vertex there are.
	\param [in] DataVertex it's a pointer to INITIALIZED memory
	\param [out] VertexBuffer The Resulting vertexBuffer
*/
bool Device::CreateVertexBuffer(uint32_t SizeVertex, uint32_t CountVertex,
																void *DataVertex, ID3D11Buffer  *&VertexBuffer)
{
	m_BufferDesc.Usage = D3D11_USAGE_DEFAULT;

	// initializes the memory 
	SecureZeroMemory(static_cast<PVOID>(&m_BufferDesc), sizeof(m_BufferDesc));
	// how much memory does the vertex takes up in bytes 
	m_BufferDesc.ByteWidth = SizeVertex * CountVertex;
	m_BufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	m_BufferDesc.CPUAccessFlags = 0;

	SecureZeroMemory(&m_InitData, sizeof(m_InitData));
	m_InitData.pSysMem = DataVertex;

	HRESULT	hr = mptr_Device->CreateBuffer(&m_BufferDesc, &m_InitData, &VertexBuffer);
	if (FAILED(hr))
		return false;


	return	true;
}


/*!
	\brief Create a Indice buffer
	\param [in] SizeIndice tells the size of a SINGLE Indice in bytes.
	\param [in] CountIndice How many Indices there are.
	\param [in] DataIndice it's a pointer to INITIALIZED memory
	\param [out] IndiceBuffer The Resulting Buffer for Indices 
*/

bool Device::CreateIndexBuffer(uint32_t SizeIndice, uint32_t CountIndice,
															 void* DataIndice, ID3D11Buffer *&IndiceBuffer)
{
	m_BufferDesc.Usage = D3D11_USAGE_DEFAULT;
	m_BufferDesc.ByteWidth = SizeIndice * CountIndice;
	m_BufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	m_BufferDesc.CPUAccessFlags = 0;

	m_InitData.pSysMem = DataIndice;

	HRESULT	hr = mptr_Device->CreateBuffer(&m_BufferDesc, &m_InitData, &IndiceBuffer);
	if (FAILED(hr))
		return false;

	return true;
}

/*!
\brief inti a Device in combination with a SwapChain 
\param [in] DescSwapChain a Descriptor Struct that contain information of the Swap chain 
\param [out] SwapChain in other word what controls whats drawn to the screen 
\param [out] DeviceContext This variable will set all values created by the Device 
*/


//
//bool Device::InitDeviceAndSwapChain(DXGI_SWAP_CHAIN_DESC *DescSwapChain, IDXGISwapChain *&SwapChain,
//																		ID3D11DeviceContext *&DeviceContext)
//{
//	/*! \todo make the InitDeviceAndSwapChain have the ability
// to use D3D_DRIVER_TYPE_SOFTWARE in the case all the other ones fails*/
//	D3D_DRIVER_TYPE DrivesOpctions[] = {
// D3D_DRIVER_TYPE_HARDWARE,
// D3D_DRIVER_TYPE_REFERENCE,
// D3D_DRIVER_TYPE_UNKNOWN,
// D3D_DRIVER_TYPE_WARP,
// D3D_DRIVER_TYPE_NULL,
// D3D_DRIVER_TYPE_SOFTWARE
//	};
//
//
//	UINT Flags = 0;
//#ifdef _DEBUG
//	Flags |= D3D11_CREATE_DEVICE_DEBUG;
//#endif
//
//	HRESULT	 IsDiveceCreated S_OK;
//
//	for (char i = 0; i < ARRAYSIZE(DrivesOpctions); ++i)
//	{
//		IsDiveceCreated = D3D11CreateDeviceAndSwapChain(NULL, DrivesOpctions[i], NULL,
//																					 Flags, NULL, NULL, 
//																					 D3D11_SDK_VERSION, DescSwapChain, &SwapChain
//																					 , &mptr_Device, NULL, &DeviceContext);
//		if (SUCCEEDED(IsDiveceCreated))
//		{
//			return true;
//		}
//
//	}
//
//	return false;
//}

//bool Device::InitDevice()
//{
//	/*
//	HRESULT hr = S_OK;
//
//		IDXGIDevice * pDXGIDevice = nullptr;
//	hr = mptr_Device->QueryInterface(__uuidof(IDXGIDevice), (void **)&pDXGIDevice);
//
//
//	IDXGIAdapter * pDXGIAdapter = nullptr;
//	hr = pDXGIDevice->GetAdapter(&pDXGIAdapter);
//
//	IDXGIFactory * pIDXGIFactory = nullptr;
//	pDXGIAdapter->GetParent(__uuidof(IDXGIFactory), (void **)&pIDXGIFactory);
//
//	D3D11CreateDevice()*/
//
//	return false;
//}

bool Device::InitDevice(CSwapChain *SwapChain, DeviceContext *Context, CWindow *Window)
{
//	CWindow

	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = Window->GetWidth();
	sd.BufferDesc.Height = Window->GetHeight();
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = Window->GetHandle();
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
//	/*! \todo make the InitDeviceAndSwapChain have the ability
 //to use D3D_DRIVER_TYPE_SOFTWARE in the case all the other ones fails*/

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

ID3D11Device* Device::GetDevice()
{
	return mptr_Device;
}


