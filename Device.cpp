#include "Device.h"



Device::Device()
{
}


Device::~Device()
{
}
/*!
	\brief Create a vertex buffer 
	\param [in] SizeVertex tells the size of a SINGLE vertex in bytes. 
	\param [in] CountVertex How many vertex there are. 
	\param [out] VertexBuffer The Resulting VertexBuffer 
*/

bool Device::CreateVertexBuffer(uint32_t SizeVertex, uint32_t CountVertex, 
																 ID3D11Buffer* VertexBuffer)
{

	D3D11_BUFFER_DESC Desc;
	Desc.Usage = D3D11_USAGE_DEFAULT;
	SecureZeroMemory(static_cast<PVOID>(&Desc), sizeof(Desc));
	Desc.ByteWidth = SizeVertex * CountVertex;
	Desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	Desc.CPUAccessFlags = 0;


	return false;
}


