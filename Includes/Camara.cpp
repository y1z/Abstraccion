#include "Camara.h"
#include "CGraphicsManager.h"
#include "GlobalValues.h"

Camara::Camara()
{
}


Camara::~Camara()
{
}

bool Camara::InitCam(CGraphicsManager *GraphManager)
{
	// Position
	DirectX::XMVECTOR Eye = DirectX::XMVectorSet(0.f, 0.f, -50.0f, 1.f);
	// Direction 
	DirectX::XMVECTOR Up = DirectX::XMVectorSet(0.f, 1.f, 0.f, 1.f);
	// Direction 
	DirectX::XMVECTOR At = DirectX::XMVectorSet(0.f, 0.f, 0.f, 1.f);

	m_View = DirectX::XMMatrixLookAtLH(Eye, At, Up);
	m_View = DirectX::XMMatrixTranspose(m_View);

	m_Projection = DirectX::XMMatrixPerspectiveFovLH(DirectX::XM_PIDIV4, DEFAULT_HEIGHT / (FLOAT)DEFAULT_WIDTH, 0.01f, 100.0f);
	m_Projection = DirectX::XMMatrixTranspose(m_View);

	ConstanteBufferView.InitConstanteBuffer(sizeof(m_View), &m_View);

	ConstanteBufferProyection.InitConstanteBuffer(sizeof(m_Projection), &m_Projection);

	GraphManager->CreateBuffer(ConstanteBufferView);
	GraphManager->CreateBuffer(ConstanteBufferProyection);

	return true;
}

CBuffer& Camara::GetBufferView()
{
	return ConstanteBufferView;
}

CBuffer& Camara::GetBufferProyection()
{
	return ConstanteBufferProyection;
}
