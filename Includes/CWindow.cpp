#include "CWindow.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


/*!
\todo make InitWindow take a pointer to WndProc */

CWindow::CWindow()
{
	m_Width = 800;
	m_Height = 600;
}


CWindow::~CWindow()
{
}


bool CWindow::InitWindow()
{
	m_Instance = GetModuleHandle(nullptr);
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.lpfnWndProc = WndProc;// poniter to functino
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_Instance;
	wcex.hIcon = LoadIcon(m_Instance, IDI_WINLOGO);// sirve para hacer logos 
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = m_WindowName.c_str();
	wcex.hIconSm = wcex.hIcon;

	if (!RegisterClassEx(&wcex))
		return false;

	int Syle = WS_OVERLAPPEDWINDOW;

	m_Wnd = CreateWindowEx(WS_EX_APPWINDOW, m_WindowName.c_str(), m_WindowName.c_str(), Syle,
												 0,// DICTAN DONDE ESTA LA VENTANA 
												 0,// DICTAN DONDE ESTA LA VENTANA 
												 m_Width, m_Height,// Dictan las dimenciones de la ventana 
												 NULL, // si tuviera otra venta le pasaria el puntero a esta 
												 NULL,
												 m_Instance,
												 NULL);

	if (m_Wnd == nullptr)
	{
		return false;
	}

	ShowWindow(m_Wnd, SW_SHOW);

	return true;
}

void CWindow::HandleMessage()
{
	MSG	msg = { 0 };

	while (PeekMessage(&msg, NULL,
				 0u, 0u, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

int CWindow::GetWidth()
{
	return m_Width;
}

int CWindow::GetHeight()
{
	return m_Height;
}

HWND CWindow::GetHandle()
{
	return m_Wnd;
}

HWND & CWindow::GetHandleRef()
{
	// TODO: insert return statement here
	return m_Wnd;
}





LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}