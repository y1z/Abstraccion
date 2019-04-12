#pragma once
#include "CGraphicsManager.h"

class Camara;

class CBuffer;

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
	XMMATRIX m_WorldMatrice;

	bool isRunnig = true;
};

