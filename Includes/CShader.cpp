#include "CShader.h"
#include "DirectX_Stuff.h"
#include "Usable_Window.h"


CShader::CShader()
{
}


CShader::~CShader()
{
	if (mptr_OutBlob != nullptr) { mptr_OutBlob->Release(); }
}

bool CShader::ComplieShader(const std::wstring & FileName, const std::string & EntryPoint, const std::string & ShaderModel)
{
	HRESULT hr = S_OK;

	DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
	// Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
	// Setting this flag improves the shader debugging experience, but still allows 
	// the shaders to be optimized and to run exactly the way they will run in 
	// the release configuration of this program.
	dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

	ID3DBlob* ptr_ErrorBlob;
	hr = D3DCompileFromFile(FileName.c_str(), nullptr,
													D3D_COMPILE_STANDARD_FILE_INCLUDE, EntryPoint.c_str(),
													ShaderModel.c_str(), dwShaderFlags, 0, &mptr_OutBlob, &ptr_ErrorBlob);

		if (FAILED(hr))
		{
			if (ptr_ErrorBlob != NULL)
				OutputDebugStringA((char*)ptr_ErrorBlob->GetBufferPointer());
			if (ptr_ErrorBlob) ptr_ErrorBlob->Release();
			return hr;
		}
	if (ptr_ErrorBlob) ptr_ErrorBlob->Release();

	return true;
}

ID3DBlob * CShader::GetBlob() const
{
	return mptr_OutBlob;
}

void CShader::Init(const std::wstring & FileName, const std::string & EntryPoint, const std::string & ShaderModel)
{
	ComplieShader(FileName, EntryPoint, ShaderModel);
}
