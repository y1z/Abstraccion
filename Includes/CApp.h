#pragma once
#include <vector>
#include "CGraphicsManager.h"
#include "CVertexShader.h"

class Camara;

class CBuffer;

class CVertexShader;

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
	CGraphicsManager * m_GraphManager = nullptr;
	CWindow* mptr_Window = nullptr;
	CTexture* mptr_RenderTargetView = nullptr;
	Camara *mptr_Camara = nullptr;
	CBuffer *mptr_WorldBuffer = nullptr;
	CVertexShader *mptr_VertexShader = nullptr;

	DirectX::XMMATRIX m_WorldMatrice;

	std::vector<D3D11_INPUT_ELEMENT_DESC> m_Layout;
	
	ID3D11InputLayout *mptr_InputLayout = nullptr;

	bool isRunnig = true;
};

