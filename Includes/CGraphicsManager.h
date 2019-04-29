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
#include "CShader.h"
#include "CVertexShader.h"
#include "CPixelShader.h"
#include "CSampler.h"

class CShader;
class CVertexShader;

/*!
\class CGraphicsManager "CGraphicsManager.h"
\brief this is where all Graphics related operations 
happen, Creation , setting ,initialization etc..

*/

class CGraphicsManager
{
public:// constructor 
	CGraphicsManager();
	~CGraphicsManager();
public:// functions 
	/** Is used to draw or geometry on screen*/
	void Draw(CBuffer &IndiceBuffer);

	/*! Initialize's all Graphics related operations */
	bool InitGraphics(CWindow *);
	/*! Return's a pointer For a renderTraget*/
	CTexture *ReciveRenderTargetFromBackBuffer();

	void SetRenderTargetView(CTexture &Rendertarget,  CTexture *DepthStencil = NULL);
	void SetConstantBuffer(CBuffer &Constbuffer);
	void ClearRenderTargetView(CTexture &RenderTarget, float *ptr);
	void Present(int A = 0 , int B = 0);


	/*! Returns's a pointer for a vertex shader */
	CVertexShader * ReceiveVertexShader(const std::wstring &FileName,
																		 const std::string &EntryPoint,
																		 const std::string &ShaderModel);

	CPixelShader * ReceivePixelShader(const std::wstring &FileName,
																			const std::string &EntryPoint,
																			const std::string &ShaderModel);
	/*! Return a pointer to a CSampler class with Default values*/
	CSampler *ReciveDefaultSampler();
	/*! Return a pointer to CSampler class with Anisotropic enabled*/
	CSampler *ReciveAnisotropicSampler();

	CTexture *ReciveDepthSencil();

	void SetVertexShader(CVertexShader *ptr_Vertex);

	void SetPixelShader(CPixelShader *ptr_Pixel);

	void SetSampler(CSampler *ptr_Sampler);

	void SetVertexBuffer(CBuffer &buffer);

	void SetIndiceBuffer(CBuffer &buffer, int Format);

	void SetInputLayout(ID3D11InputLayout *InputLayou);

	void SetTopology(int Format);

	bool initTexture2D(CTexture &Texture,int Format);

	/*! Return's a pointer for a input layout*/
	ID3D11InputLayout *ReceiveInputLayout(std::vector<D3D11_INPUT_ELEMENT_DESC> &Layout,
																			 CVertexShader &VertexShader);

	/*!Initialize's a CBuffer, the buffer MUST already have data inside it self*/
	bool CreateBuffer(CBuffer &buffer);

	void InitDefaultViewPort();

	//! For using multiple constant Buffers 
	uint16_t m_SlotCount = 0;

	CDevice *mptr_Device = nullptr;
	CDeviceContext *mptr_DeviceContext = nullptr;
private:// variables 

	CSwapChain *mptr_SwapChain = nullptr;
	CWindow *mptr_Window = nullptr;
};

