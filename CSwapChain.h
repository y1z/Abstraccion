#pragma once
#include "HeaderForDriecxAndWindows.h"

class CSwapChain
{
public:// constructors y destructor 
	CSwapChain();
	~CSwapChain();
public:// functions 

	IDXGISwapChain* GetSwapChian() const;
	IDXGISwapChain** GetSwapChianPointerRef() ;

private:// variables 
	IDXGISwapChain* mptr_SwapChain = nullptr;
};

