#include "CVertexShader.h"



CVertexShader::CVertexShader()
{
}


CVertexShader::~CVertexShader()
{
	if (mptr_VertexShader != nullptr) { mptr_VertexShader->Release(); }
}

ID3D11VertexShader * CVertexShader::GetVertexShader()
{
	return mptr_VertexShader;
}

ID3D11VertexShader ** CVertexShader::GetVertexShaderRef()
{
	return &mptr_VertexShader;
}
