#pragma once
#include "CShader.h"


class CPixelShader : public CShader
{
public:// constructor 
	CPixelShader();
	~CPixelShader();
public:// functions 

	ID3D11PixelShader *GetPixelShader();
	ID3D11PixelShader **GetPixelShaderRef();
private:// variables
	ID3D11PixelShader *mptr_PixelShader = nullptr;
};

