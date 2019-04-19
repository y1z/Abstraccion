#pragma once
#include "Usable_Window.h"
#include "DirectX_Stuff.h"

class CDeviceContext
{
public:
	CDeviceContext();
	~CDeviceContext();
public:// functions 

	ID3D11DeviceContext* GetDirecXContext();
	//! 
	ID3D11DeviceContext** GetContextPointerRef();

	/*! This function exist to help create a window with 
	no argument*/
	void SetDefaultViewPort();


private:// variables 
	ID3D11DeviceContext*        mptr_ImmediateContext = nullptr;
	ID3D11Buffer*               mptr_VertexBuffer = nullptr;
};

