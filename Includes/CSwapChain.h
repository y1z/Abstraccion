#pragma once
#include "Usable_Window.h"
#include "DirectX_Stuff.h"
#include "CTexture.h"

class CSwapChain
{
public:// constructors y destructor 
	CSwapChain();
	~CSwapChain();
public:// functions 
	CTexture* GetFromBuffer(uint32_t indice);

	IDXGISwapChain* GetSwapChian() const;
	IDXGISwapChain** GetSwapChianPointerRef();

private:// variables 
	IDXGISwapChain* mptr_SwapChain = nullptr;
	CTexture * mptr_Texture = nullptr;
};

