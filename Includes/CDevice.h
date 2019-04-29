#pragma once

#include "Usable_Window.h"
#include "DirectX_Stuff.h"
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

	bool CreateBuffer(CBuffer &buffer);

	bool InitDevice(CSwapChain *, CDeviceContext *, CWindow *);

	ID3D11Device* GetDevice() const;
	ID3D11Device** GetDeviceRef();

	bool CreateDepthSencil(CTexture &Texture);

private://variables

	ID3D11Device	*mptr_Device = nullptr;

	D3D11_BUFFER_DESC m_BufferDesc{ 0 };
	D3D11_SUBRESOURCE_DATA m_InitData{ 0 };
};

