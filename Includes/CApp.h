#pragma once
#include "CGraphicsManager.h"
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

	bool isRunnig = true;
};

