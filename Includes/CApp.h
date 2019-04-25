#pragma once
#include <vector>
#include "CGraphicsManager.h"
#include "CVertexShader.h"
#include "Structs.h"

/**
@file "CApp.h"
@class CApp "CApp.h"
@brief This class is responsible for initializing the program

*/

class Camara;

class CBuffer;

class CVertexShader;

class CPixelShader;

class CApp
{
public:// constructor
	CApp();
	~CApp();
public:// function
	int Run();
	bool Init();

	void Upadate();
	void Render();

private:// variables 
	CGraphicsManager *m_GraphManager = nullptr;
	CWindow *mptr_Window = nullptr;
	CTexture *mptr_RenderTargetView = nullptr;
	Camara *mptr_Camara = nullptr;

	CBuffer *mptr_WorldBuffer = nullptr;
	CBuffer *mptr_VertexBuffer = nullptr;
	CBuffer *mptr_IndexBuffer = nullptr;

	CVertexShader *mptr_VertexShader = nullptr;
	CPixelShader *mptr_PixelShader = nullptr;

	CSampler *mptr_Sampler = nullptr;

	DirectX::XMMATRIX m_WorldMatrice;

	CBChangesEveryFrame m_WorldAndColor;

	std::vector<D3D11_INPUT_ELEMENT_DESC> m_Layout;
	
	ID3D11InputLayout *mptr_InputLayout = nullptr;

	bool isRunnig = true;
};

