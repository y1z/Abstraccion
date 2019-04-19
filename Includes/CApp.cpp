#include "CApp.h"
#include "Camara.h"
#include "CBuffer.h"

CApp::CApp()
{
	m_WorldMatrice =DirectX::XMMatrixIdentity();
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
	mptr_RenderTargetView = m_GraphManager->ReciveRenderTragetFromBackBuffer();
	mptr_VertexShader = m_GraphManager->ReceiveVertexShader(L"Shaders\\Abstraccion.fx", "VS", "vs_4_0");



	// using implicit constructors 
	m_Layout.push_back({ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 });
	m_Layout.push_back({ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 });

	mptr_InputLayout = m_GraphManager->ReceiveInputLayout(m_Layout, *mptr_VertexShader);

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
