#pragma once
#include "DirectX_Stuff.h"
#include "CBuffer.h"
#include "Structs.h"

class CGraphicsManager;

class Camara
{
public:// constructor
	Camara();
	~Camara();
public:// functions
	bool InitCam(CGraphicsManager *GraphManager);

	CBuffer& GetBufferView();
	CBuffer& GetBufferProyection();
public:// variables 
	DirectX::XMMATRIX  m_LookAt;
	DirectX::XMMATRIX  m_View;
	DirectX::XMMATRIX  m_Projection;
private:
	CBuffer m_ConstantBufferView;
	CBuffer m_ConstanteBufferProyection;
};

