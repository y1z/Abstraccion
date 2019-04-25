#pragma once
#include "Usable_Window.h"
#include "DirectX_Stuff.h"

class CBuffer;

class CDeviceContext
{
public:
	CDeviceContext();
	~CDeviceContext();
public:// functions 

	ID3D11DeviceContext* GetDeviceContext();
	//! for creating the device and swap-chain together
	ID3D11DeviceContext** GetContextPointerRef();

	/*! This function exist to help create a window with 
	no argument*/
	void SetDefaultViewPort();
	/** will be used to set the Indice buffer 
	*@param Format [in] will be cast to a DXGI_FORMAT valid value range from
	*0 to 132*/
	void SetIndiceBuffer(CBuffer &Buffer,int Format);

	void SetVertexBuffer(CBuffer &Buffer);

	/** Set's Topology  
	*@param [in] Format choses which format is used valid values 
	*range from 0 to 64 */
	void SetTopology(int Format = 4);

private:// variables 
	ID3D11DeviceContext*        mptr_DeviaceContext = nullptr;
	ID3D11Buffer*               mptr_VertexBuffer = nullptr;
};

