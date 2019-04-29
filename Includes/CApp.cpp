#include "CApp.h"
#include "Camara.h"
#include "CBuffer.h"
#include "DirectX_Stuff.h"

CApp::CApp()
{
	m_WorldAndColor.mWorld = DirectX::XMMatrixIdentity();
//	DirectX::XMMatrixTranspose(m_WorldAndColor.mWorld);
	m_WorldAndColor.vMeshColor = DirectX::XMFLOAT4(1.f, 0.08f, 0.7f, .0f);
}

CApp::~CApp()
{
	/*C++ classes*/
	if (m_GraphManager != nullptr) { delete m_GraphManager; }
	if (mptr_Window != nullptr) { delete mptr_Window; }
	if (mptr_RenderTargetView != nullptr) { delete mptr_RenderTargetView; }
	if (mptr_DepthSencil != nullptr) { delete mptr_DepthSencil; }
	if (mptr_Camara != nullptr) { delete mptr_Camara; }
	//! shaders 
	if (mptr_WorldBuffer != nullptr) { delete mptr_WorldBuffer; }
	if (mptr_VertexShader != nullptr) { delete mptr_VertexShader; }
	if (mptr_PixelShader != nullptr) { delete mptr_PixelShader; }
	//! buffers 
	if (mptr_VertexBuffer != nullptr) { delete mptr_VertexBuffer; }
	if (mptr_IndexBuffer != nullptr) { delete mptr_IndexBuffer; }
	/*DirectX interfaces*/
	if (mptr_InputLayout != nullptr) { mptr_InputLayout->Release(); }

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
	mptr_VertexBuffer = new CBuffer();
	mptr_IndexBuffer = new CBuffer();
	//! Window need to be first 
	//! Window need to be first 
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
	mptr_WorldBuffer->InitConstanteBuffer(sizeof(m_WorldAndColor), &m_WorldAndColor);
	m_GraphManager->CreateBuffer(*mptr_WorldBuffer);

	m_GraphManager->SetConstantBuffer(mptr_Camara->GetBufferView());
	m_GraphManager->SetConstantBuffer(mptr_Camara->GetBufferProyection());
	m_GraphManager->SetConstantBuffer(*mptr_WorldBuffer);
	/*! this should be replace with a method that has argument for
	window Width and Window Hight*/
	m_GraphManager->InitDefaultViewPort();
	mptr_RenderTargetView = m_GraphManager->ReciveRenderTargetFromBackBuffer();
	mptr_DepthSencil = m_GraphManager->ReciveDepthSencil();
//	m_GraphManager->mptr_Device->CreateDepthSencil(*mptr_RenderTargetView);


	mptr_VertexShader = m_GraphManager->ReceiveVertexShader(L"Shaders\\Abstraccion.fx", "VS", "vs_4_0");
	mptr_PixelShader = m_GraphManager->ReceivePixelShader(L"Shaders\\Abstraccion.fx", "PS", "ps_4_0");

	// This is just for debugging
	std::vector <SimpleVertex> vertices =
	{
			{ DirectX::XMFLOAT3(-1.0f, 1.0f, -1.0f),  DirectX::XMFLOAT2(0.0f, 0.0f) },
			{ DirectX::XMFLOAT3(1.0f, 1.0f, -1.0f),  DirectX::XMFLOAT2(1.0f, 0.0f) },
			{ DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f),   DirectX::XMFLOAT2(1.0f, 1.0f) },
			{ DirectX::XMFLOAT3(-1.0f, 1.0f, 1.0f),  DirectX::XMFLOAT2(0.0f, 1.0f) },
			{ DirectX::XMFLOAT3(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2(0.0f, 0.0f) },
			{ DirectX::XMFLOAT3(1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT2(1.0f, 0.0f) },
			{ DirectX::XMFLOAT3(1.0f, -1.0f, 1.0f), DirectX::XMFLOAT2(1.0f, 1.0f) },
			{ DirectX::XMFLOAT3(-1.0f, -1.0f, 1.0f),  DirectX::XMFLOAT2(0.0f, 1.0f) },
			{ DirectX::XMFLOAT3(-1.0f, -1.0f, 1.0f),  DirectX::XMFLOAT2(0.0f, 0.0f) },
			{ DirectX::XMFLOAT3(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2(1.0f, 0.0f) },
			{ DirectX::XMFLOAT3(-1.0f, 1.0f, -1.0f), DirectX::XMFLOAT2(1.0f, 1.0f) },
			{ DirectX::XMFLOAT3(-1.0f, 1.0f, 1.0f), DirectX::XMFLOAT2(0.0f, 1.0f) },
			{ DirectX::XMFLOAT3(1.0f, -1.0f, 1.0f),  DirectX::XMFLOAT2(0.0f, 0.0f) },
			{ DirectX::XMFLOAT3(1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT2(1.0f, 0.0f) },
			{ DirectX::XMFLOAT3(1.0f, 1.0f, -1.0f), DirectX::XMFLOAT2(1.0f, 1.0f) },
			{ DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f),  DirectX::XMFLOAT2(0.0f, 1.0f) },
			{ DirectX::XMFLOAT3(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2(0.0f, 0.0f) },
			{ DirectX::XMFLOAT3(1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2(1.0f, 0.0f) },
			{ DirectX::XMFLOAT3(1.0f, 1.0f, -1.0f),  DirectX::XMFLOAT2(1.0f, 1.0f) },
			{ DirectX::XMFLOAT3(-1.0f, 1.0f, -1.0f), DirectX::XMFLOAT2(0.0f, 1.0f) },
			{ DirectX::XMFLOAT3(-1.0f, -1.0f, 1.0f), DirectX::XMFLOAT2(0.0f, 0.0f) },
			{ DirectX::XMFLOAT3(1.0f, -1.0f, 1.0f), DirectX::XMFLOAT2(1.0f, 0.0f) },
			{ DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f),  DirectX::XMFLOAT2(1.0f, 1.0f) },
			{ DirectX::XMFLOAT3(-1.0f, 1.0f, 1.0f),  DirectX::XMFLOAT2(0.0f, 1.0f) },
	};


	//std::vector< SimpleVertex> SmVer;
	//for (auto Vertic : vertices)
	//{
	//	SmVer.push_back(Vertic);
	//}

	uint32_t VertexCount = vertices.size();

	//int VertexSize = sizeof(*vertices);

	/*Get the data for the buffers */
	mptr_VertexBuffer->InitBufferData(&vertices[0], VertexCount, 0, D3D11_BIND_VERTEX_BUFFER);
	// This is just for debugging
	
	 std::vector<unsigned short> indices =
	{
			3,1,0,
			2,1,3,

			6,4,5,
			7,4,6,

			11,9,8,
			10,9,11,

			14,12,13,
			15,12,14,

			19,17,16,
			18,17,19,

			22,20,21,
			23,20,22
	};

	//uint32_t IndiceCount = ARRAYSIZE(indices);
	/*Get the data for the buffers */
	mptr_IndexBuffer->InitBufferData(&indices[0], indices.size(), 0, D3D11_BIND_INDEX_BUFFER);
	/*Creating the buffers */
	m_GraphManager->CreateBuffer(*mptr_IndexBuffer);
	m_GraphManager->CreateBuffer(*mptr_VertexBuffer);
	/*Setting the buffers */
	m_GraphManager->SetIndiceBuffer(*mptr_IndexBuffer, (int)DXGI_FORMAT_R16_UINT);
	m_GraphManager->SetVertexBuffer(*mptr_VertexBuffer);

	mptr_Sampler = m_GraphManager->ReciveDefaultSampler();
	/*Setting shaders */
	m_GraphManager->SetVertexShader(mptr_VertexShader);/*
	*/m_GraphManager->SetPixelShader(mptr_PixelShader);

	/*Setting Topology */
//	m_GraphManager->
//		SetTopology(static_cast<int>(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST));


	// using implicit constructors 
	m_Layout.push_back({ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 });
	m_Layout.push_back({ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 });
	/* Creating input-layout*/
	mptr_InputLayout = m_GraphManager->ReceiveInputLayout(m_Layout, *mptr_VertexShader);

	m_GraphManager->SetInputLayout(mptr_InputLayout);

	return true;
}

void CApp::Upadate()
{
}

void CApp::Render()
{
	float color[4] = { 1.0f,0.f,0.f,1.0f };

	CBChangesEveryFrame cb;
	cb.mWorld = DirectX::XMMatrixTranspose(this->m_WorldAndColor.mWorld);
	cb.vMeshColor = this->m_WorldAndColor.vMeshColor;
	m_GraphManager->
		SetTopology(static_cast<int>(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST));

	//m_GraphManager->mptr_DeviceContext->GetDeviceContext()->UpdateSubresource
//	(mptr_WorldBuffer->GetBuffer(), 0, NULL, &cb, 0, 0);
	//m_GraphManager->SetSampler(mptr_Sampler);
	m_GraphManager->SetSampler(mptr_Sampler);

	m_GraphManager->SetRenderTargetView(*mptr_RenderTargetView,mptr_DepthSencil);
	m_GraphManager->ClearRenderTargetView(*mptr_RenderTargetView, nullptr);


	m_GraphManager->SetVertexShader(mptr_VertexShader);
	m_GraphManager->SetPixelShader(mptr_PixelShader);


	m_GraphManager->Draw(*mptr_IndexBuffer);


	m_GraphManager->Present();

}
