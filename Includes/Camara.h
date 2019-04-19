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
	XMMATRIX  m_LookAt;
	XMMATRIX  m_View;
	XMMATRIX  m_Projection;
private:
	CBuffer ConstanteBufferView;
	CBuffer ConstanteBufferProyection;
};

