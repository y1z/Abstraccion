#pragma once
// utility Headers
#include <Includes/Usable_Window.h>
#include <Includes/DirectX_Stuff.h>
// using for debugging
#include <comdef.h>
// MY Classes 
#include "CSwapChain.h"
#include "CDevice.h"
#include "DeviceContext.h"
#include "CWindow.h"
#include "CTexture.h"
#include "CBuffer.h"

class CGraphicsManager
{
public:// constructor 
	CGraphicsManager();
	~CGraphicsManager();
public:// functions 
	bool InitGraphics(CWindow *);
	CTexture* CreateRenderTragetFromBackBuffer();

	void SetRenderTargetView(CTexture &Rendertarget,  CTexture *DepthStencil = NULL);
	void SetConstanteBuffer(CBuffer &Constbuffer);
	void ClearRenderTargetView(CTexture &RenderTarget, float *ptr);
	void Present(int A = 0 , int B = 0);

	bool CreateBuffer(CBuffer &buffer);

	void DebugTestBuffer(CBuffer &d);

	void InitViewPort();

	int SlotCount = 0;

private:// variables 
	CDevice *mptr_Device = nullptr;
	DeviceContext *mptr_DeviceContext = nullptr;
	CSwapChain *mptr_SwapChain = nullptr;
	CWindow *mptr_Window = nullptr;
	CTexture *mptr_Texture = nullptr;
	CBuffer *mptr_Buffer = nullptr;


};

