#pragma once
#include "HeaderForDriecxAndWindows.h"
#include "Structs.h"

class Device
{
public:
	Device();
	~Device();
public: // functions 

	bool CreateVertexBuffer(uint32_t SizeElements, uint32_t CountElements, ID3D11Buffer* VertexBuffer);

public://variables
	HINSTANCE                   m_Inst = NULL;
	HWND                        m_Wnd = NULL;
	D3D_DRIVER_TYPE             m_riverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL           m_FeatureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device*               mptr_Device = nullptr;

	IDXGISwapChain*             mptr_SwapChain = nullptr;
	ID3D11RenderTargetView*     mptr_RenderTargetView = nullptr;
	ID3D11Texture2D*            mptr_DepthStencil = nullptr;
	ID3D11DepthStencilView*     mptr_DepthStencilView = nullptr;
	ID3D11VertexShader*         mptr_VertexShader = nullptr;
	ID3D11PixelShader*          mptr_PixelShader = nullptr;
	ID3D11InputLayout*          mptr_VertexLayout = nullptr;
	ID3D11Buffer*               mptr_IndexBuffer = nullptr;
	ID3D11Buffer*               mptr_CBNeverChanges = nullptr;
	ID3D11Buffer*               mptr_CBChangeOnResize = nullptr;
	ID3D11Buffer*               mptr_CBChangesEveryFrame = nullptr;
	ID3D11ShaderResourceView*   mptr_TextureRV = nullptr;
	ID3D11SamplerState*         mptr_SamplerLinear = nullptr;
	XMMATRIX*                    mptr_World;
	XMMATRIX *                   mptr_View;
	XMMATRIX *                   mptr_Projection;
	XMFLOAT4 *                   mptr_MeshColor;
};

