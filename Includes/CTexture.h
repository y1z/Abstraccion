#pragma once
#include "Usable_Window.h"
#include "DirectX_Stuff.h" 
#include <string>
#include "CGraphicsManager.h"
/**



*/

class CTexture
{
public:
	CTexture();
	~CTexture();
public:
	ID3D11RenderTargetView* GetRenderTraget() const;
	ID3D11RenderTargetView** GetRenderTragetRef();

	ID3D11Texture2D* GetTexture2D();
	ID3D11Texture2D** GetTexture2DRef();

	ID3D11DepthStencilView*GetDepthSetncilView();
	ID3D11DepthStencilView**GetDepthSetncilViewRef();

	ID3D11ShaderResourceView ** GetShaderView();

	int GetWidth();
	int GetHeight();
	int GetChannel();


	unsigned char *GetColor();

	bool LoadFromFile(std::string FilePath, CGraphicsManager &Graph);

private:

	std::vector<unsigned char> m_ColorBuffer;

	int m_Width = 0;
	int m_Height = 0;
	int m_Channel = 0;

	ID3D11Texture2D*        mptr_Texture2D = nullptr;
	ID3D11DepthStencilView* mptr_DepthStencilView = nullptr;
	ID3D11RenderTargetView* mptr_RenderTargetView = nullptr;
	ID3D11ShaderResourceView * mptr_ShaderView = nullptr;
};

