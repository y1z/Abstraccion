#include "CApp.h"
#include <Includes/Camara.h>
#include <Includes/CBuffer.h>

CApp::CApp()
{
	m_WorldMatrice = XMMatrixIdentity();
}


CApp::~CApp()
{
	if (mptr_Window != nullptr) { delete mptr_Window; }
	if (m_GraphManager != nullptr) { delete m_GraphManager; }
	if (mptr_Camara != nullptr) { delete mptr_Camara; }
	if (mptr_RenderTargetView != nullptr) { delete mptr_RenderTargetView; }
	if (mptr_Window != nullptr)
	{
		delete mptr_Window;
	}
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
	mptr_Camara = new Camara();
	mptr_WorldBuffer = new CBuffer();

	// Window need to be first 
	if (!mptr_Window->InitWindow())
	{
		return false;
	}
	// should be second 
	if (!m_GraphManager->InitGraphics(mptr_Window))
	{
		return false;
	}

	if (!mptr_Camara->InitCam(m_GraphManager))
	{
		return false;
	}
	mptr_WorldBuffer->InitConstanteBuffer(sizeof(m_WorldMatrice), &m_WorldMatrice);
	m_GraphManager->CreateBuffer(*mptr_WorldBuffer);


	m_GraphManager->SetConstantBuffer(mptr_Camara->GetBufferView());
	m_GraphManager->SetConstantBuffer(mptr_Camara->GetBufferProyection());
	m_GraphManager->SetConstantBuffer(*mptr_WorldBuffer);
	/*! this should be replace with a method that has argument for 
	window Width and Window Hight*/
	m_GraphManager->InitDefaultViewPort();
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
