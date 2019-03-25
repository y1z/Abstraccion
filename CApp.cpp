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

	if (!m_GraphManager->InitGraphics())
	{
		return false;
	}



	return true;
}

void CApp::Upadate()
{
}

void CApp::Render()
{
}
