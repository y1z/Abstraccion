#include "CApp.h"

CApp::CApp()
{
}


CApp::~CApp()
{
	if (mptr_Window != nullptr) { delete mptr_Window; }
}

int CApp::Run()
{
	if (!Init())
	{
		return -1;
	}

	while (isRunnig)
	{

		mptr_Window->HandleMessage();
		Upadate();
		Render();

	}

	return 0;
}

bool CApp::Init()
{
	m_GraphManager = new CGraphicsManager();
	mptr_Window = new CWindow();

	// Window need to be first 
	if (!mptr_Window->InitWindow())
	{
		return false;
	}

	if (!m_GraphManager->InitGraphics(mptr_Window))
	{
		return false;
	}

	mptr_RenderTargetView = m_GraphManager->CreateRenderTragetFromBackBuffer();

	return true;
}

void CApp::Upadate()
{
}

void CApp::Render()
{
	float color[4] = { 1.0f,0.f,0.f,1.0f };

	m_GraphManager->SetRenderTargetView(*mptr_RenderTargetView);

	m_GraphManager->ClearRenderTargetView(*mptr_RenderTargetView, color);

	m_GraphManager->Present();

}
