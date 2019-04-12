#pragma once
#include "HeaderForDriecxAndWindows.h"

class DeviceContext
{
public:
	DeviceContext();
	~DeviceContext();
public:// functions 
	ID3D11DeviceContext* GetDirecXContext();
	ID3D11DeviceContext** GetContextPointerRef();


private:// variables 
	ID3D11DeviceContext*        mptr_ImmediateContext = nullptr;
	ID3D11Buffer*               mptr_VertexBuffer = nullptr;
};

