#pragma once
#include "HeaderForDriecxAndWindows.h"
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

private:
	ID3D11Texture2D*        mptr_Texture2D = nullptr;
	ID3D11DepthStencilView* mptr_DepthStencilView = nullptr;
	ID3D11RenderTargetView* mptr_RenderTargetView = nullptr;
};

