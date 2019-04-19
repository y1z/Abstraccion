#pragma once
#include "Usable_Window.h"
#include "DirectX_Stuff.h"

struct SimpleVertex
{
	DirectX::XMFLOAT3 Pos;
	DirectX::XMFLOAT2 Tex;
};

struct CBNeverChanges
{
	DirectX::XMMATRIX mView;
};

struct CBChangeOnResize
{
	DirectX::XMMATRIX mProjection;
};

struct CBChangesEveryFrame
{
	DirectX::XMMATRIX mWorld;
	DirectX::XMFLOAT4 vMeshColor;
};