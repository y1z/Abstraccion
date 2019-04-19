#pragma once
#include <vector>
// utility Headers
#include "Usable_Window.h"
#include "DirectX_Stuff.h"
// using for debugging
#include <comdef.h>
// MY Classes 
#include "CSwapChain.h"
#include "CDevice.h"
#include "CDeviceContext.h"
#include "CWindow.h"
#include "CTexture.h"
#include "CBuffer.h"
#include "CVertexShader.h"

class CShader;
class CVertexShader;

/*!
\class CGraphicsManager 
\brief this is where all Graphics related operations 
happen
*/

class CGraphicsManager
{
public:// constructor 
	CGraphicsManager();
	~CGraphicsManager();
public:// functions 
	bool InitGraphics(CWindow *);
	CTexture* CreateRenderTragetFromBackBuffer();

	void SetRenderTargetView(CTexture &Rendertarget,  CTexture *DepthStencil = NULL);
	void SetConstantBuffer(CBuffer &Constbuffer);
	void ClearRenderTargetView(CTexture &RenderTarget, float *ptr);
	void Present(int A = 0 , int B = 0);



	CVertexShader * CreateVertexShader(const std::wstring &FileName,
																		 const std::string &EntryPoint,
																		 const std::string &ShaderModel);



	ID3D11InputLayout *CreateInputLayout(std::vector<D3D11_INPUT_ELEMENT_DESC> &Layout,
																			 CVertexShader &VertexShader);

	bool CreateBuffer(CBuffer &buffer);



	void InitDefaultViewPort();

	//! For using multiple constant Buffers 
	uint16_t m_ConstantBufferSlotCount = 0;

private:// variables 
	CDevice *mptr_Device = nullptr;
	CDeviceContext *mptr_DeviceContext = nullptr;
	CSwapChain *mptr_SwapChain = nullptr;
	CWindow *mptr_Window = nullptr;
	CBuffer *mptr_Buffer = nullptr;
};

