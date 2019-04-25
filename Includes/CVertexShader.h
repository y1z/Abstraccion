#pragma once
#include "CShader.h"

class CVertexShader : public CShader
{
public:
	CVertexShader();
	~CVertexShader();
public:
	ID3D11VertexShader *GetVertexShader();
	ID3D11VertexShader **GetVertexShaderRef();

private:
	ID3D11VertexShader *mptr_VertexShader = nullptr;
};

