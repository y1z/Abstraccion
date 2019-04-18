#pragma once
#include <Windows.h>
#include <string>


class CWindow
{
public:
	CWindow();
	~CWindow();
public:// functions 
	bool InitWindow();
	void HandleMessage();

	int GetWidth();
	int GetHeight();

	HWND GetHandle();
	HWND& GetHandleRef();


private:// variables 
	HINSTANCE m_Instance;
	HRESULT m_Result;
	std::wstring m_WindowName = L"Vetana_Meca";
	HWND m_Wnd;

	int m_Width;
	int m_Height;

	using Funcptr_WindProc = LRESULT(CALLBACK *)(HWND, UINT, WPARAM, LPARAM);

};

