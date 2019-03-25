#pragma once
#include "HeaderForDriecxAndWindows.h"
#include "CSwapChain.h"
#include "Device.h"
#include "DeviceContext.h"
#include "CWindow.h"
#include "CTexture.h"
class CGraphicsManager
{
public:// constructor 
	CGraphicsManager();
	~CGraphicsManager();
public:
	bool InitGraphics();
	bool CreateRenderTragetFromBackBuffer();
private:
	Device *mptr_Device = nullptr;
	DeviceContext* mptr_DeviceContext = nullptr;
	CSwapChain* mptr_SwapChain = nullptr;
	CWindow * mptr_Window = nullptr;

};

