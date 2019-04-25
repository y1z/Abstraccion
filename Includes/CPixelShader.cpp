#include "CPixelShader.h"

CPixelShader::CPixelShader()
{
}


CPixelShader::~CPixelShader()
{
	if (mptr_PixelShader != nullptr) { mptr_PixelShader->Release(); }
}

ID3D11PixelShader * CPixelShader::GetPixelShader()
{
	return mptr_PixelShader;
}

ID3D11PixelShader ** CPixelShader::GetPixelShaderRef()
{
	return &mptr_PixelShader;
}
