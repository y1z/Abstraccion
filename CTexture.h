#pragma once
#include "HeaderForDriecxAndWindows.h"
class CTexture
{
public:
	CTexture();
	~CTexture();
public:

public:
	ID3D11Texture2D*                    mptr_DepthStencil = nullptr;
	ID3D11DepthStencilView*             mptr_DepthStencilView = nullptr;
	ID3D11RenderTargetView*             mptr_RenderTargetView = nullptr;
};

