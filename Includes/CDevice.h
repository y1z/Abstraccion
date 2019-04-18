#pragma once
#include <Includes/Usable_Window.h>
#include <Includes/DirectX_Stuff.h>
#include "CSwapChain.h"
#include "CDeviceContext.h"
#include "Structs.h"
#include "CWindow.h"
#include "CBuffer.h"

class CDevice
{
public:
	CDevice();
	~CDevice();
public: // functions 

	bool CreateVertexBuffer(uint32_t SizeVertex, uint32_t CountVertex,
													void* Data, ID3D11Buffer *&VertexBuffer);

	bool CreateIndexBuffer(uint32_t SizeVertex, uint32_t CountVertex,
												 void* Data, ID3D11Buffer *&);

	bool CreateBuffer(CBuffer &buffer);

	bool InitDevice(CSwapChain *, CDeviceContext *, CWindow *);

	ID3D11Device* GetDevice() const;
	ID3D11Device** GetDeviceRef();


private://variables

	ID3D11Device	*mptr_Device = nullptr;

	D3D11_BUFFER_DESC m_BufferDesc{ 0 };
	D3D11_SUBRESOURCE_DATA m_InitData{ 0 };
};

