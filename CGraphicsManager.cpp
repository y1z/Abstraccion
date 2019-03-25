#include "CGraphicsManager.h"



CGraphicsManager::CGraphicsManager()
{
}


CGraphicsManager::~CGraphicsManager()
{
	delete mptr_Device;
	delete mptr_SwapChain;
	delete mptr_DeviceContext;
	delete mptr_Window;
}


bool CGraphicsManager::InitGraphics()
{
	bool Result = false;

	mptr_Device = new Device();
	mptr_SwapChain = new CSwapChain();
	mptr_DeviceContext = new DeviceContext();
	mptr_Window = new CWindow();

	mptr_Window->InitWindow();



	Result = mptr_Device->InitDevice(mptr_SwapChain, mptr_DeviceContext,mptr_Window);

	return Result;
}
