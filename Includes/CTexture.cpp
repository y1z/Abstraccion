#include "CTexture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_Image.h"
CTexture::CTexture()
{
}


CTexture::~CTexture()
{
	mptr_Texture2D->Release();
	mptr_DepthStencilView->Release();
	mptr_RenderTargetView->Release();
}

ID3D11RenderTargetView * CTexture::GetRenderTraget() const
{
	return mptr_RenderTargetView;
}

ID3D11RenderTargetView ** CTexture::GetRenderTragetRef()
{
	return &mptr_RenderTargetView;
}

ID3D11Texture2D * CTexture::GetTexture2D()
{
	return mptr_Texture2D;
}

ID3D11Texture2D ** CTexture::GetTexture2DRef()
{
	return &mptr_Texture2D;
}

ID3D11DepthStencilView * CTexture::GetDepthSetncilView()
{
	return mptr_DepthStencilView;
}

ID3D11DepthStencilView ** CTexture::GetDepthSetncilViewRef()
{
	return &mptr_DepthStencilView;
}

ID3D11ShaderResourceView ** CTexture::GetShaderView()
{
	return &mptr_ShaderView;
}

int CTexture::GetWidth()
{
	return m_Width;
}

int CTexture::GetHeight()
{
	return m_Height;
}

int CTexture::GetChannel()
{
	return m_Channel;
}


unsigned char* CTexture::GetColor()
{
	return &m_ColorBuffer[0];
}

bool CTexture::LoadFromFile(std::string FilePath, CGraphicsManager & Graph)
{
	unsigned char *ptr_Colors = nullptr;

	ptr_Colors = stbi_load(FilePath.c_str(), &m_Width, &m_Height, &m_Channel, 4);

	if (ptr_Colors == nullptr)
	{
		return false;
	}

	memcpy(&m_ColorBuffer[0], &ptr_Colors[0],m_Width * m_Height *4);

	Graph.initTexture2D(*this, 28);

	// TODO : Create Shader Resource view 


	return true;
}
