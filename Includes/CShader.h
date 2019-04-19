#pragma once
#include "DirectX_Stuff.h"
#include <string>
class CShader
{
public:// constructor 
	CShader();
	virtual ~CShader();
protected:// functions 
	bool ComplieShader(const std::wstring &FileName,
										 const std::string &EntryPoint,
										 const std::string &ShaderModel);
public:
	ID3DBlob* GetBlob() const;
	void Init(const std::wstring &FileName,
						const std::string &EntryPoint,
						const std::string &ShaderModel);

protected:// variables
	ID3DBlob* mptr_OutBlob = nullptr;
};

