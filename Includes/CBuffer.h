#pragma once
#include "Usable_Window.h"
#include "DirectX_Stuff.h"

/*!
\file 
\class CBuffer "CBuffer.h" 
\brief this is a general buffer class it has the ability to be a 
Index buffer ,Vertex buffer and Constant buffer, just call the respective 
init Method.

*/

class CBuffer
{
public:// constructor
	CBuffer();
	~CBuffer();
public:// functions 
	template <typename T>
	bool InitBufferData(T* DataStruct, uint32_t m_CountElements,
											uint32_t Stride, D3D11_BIND_FLAG bufferType);
	
	template<typename T>
	bool InitConstanteBuffer(uint32_t Size, T *DataStruct);

	D3D11_BUFFER_DESC GetDesc();
	D3D11_BUFFER_DESC* GetDescRef();

	D3D11_SUBRESOURCE_DATA GetData();
	D3D11_SUBRESOURCE_DATA* GetDataRef();

	ID3D11Buffer* GetBuffer();
	ID3D11Buffer** GetBufferRef();

	uint32_t GetStride();
	uint32_t GetStrideRef();

	uint32_t GetOffSet();
	uint32_t GetOffSetRef();

	uint32_t GetElementCount();

public:// variables 
	ID3D11Buffer* mptr_Buffer = nullptr;
private:
	uint32_t m_CountElements = 0;
	uint32_t m_ElementSize = 0;
	uint32_t m_Stride = 0;
	uint32_t m_OffSet = 0;

	D3D11_BIND_FLAG m_BufferType;
	D3D11_BUFFER_DESC m_Discriptor;
	D3D11_SUBRESOURCE_DATA m_data;
};

inline CBuffer::CBuffer(){
	SecureZeroMemory(&m_Discriptor, sizeof(m_Discriptor));
	m_Discriptor.Usage = D3D11_USAGE_DEFAULT;
	m_Discriptor.CPUAccessFlags = 0;
	SecureZeroMemory(&m_data, sizeof(m_data));
}

inline CBuffer::~CBuffer()
{
	if (mptr_Buffer) { mptr_Buffer->Release(); }
}

// can be Index buffer or Vertex buffer 
template<typename T>
inline bool CBuffer::InitBufferData(T *DataStruct, uint32_t CountElements,
																		uint32_t OffSet, D3D11_BIND_FLAG bufferType)
{
	// size of single element 
	m_ElementSize = sizeof(*DataStruct);
	// get the stride 
	m_Stride = sizeof(*DataStruct);

	m_OffSet = OffSet;

	if (CountElements < 3)
		return false;

	this->m_CountElements = CountElements;

	this->m_BufferType = bufferType;

	// for descriptor
	m_Discriptor.ByteWidth = sizeof(T) * CountElements;
	m_Discriptor.BindFlags = bufferType;
	// for data
	m_data.pSysMem = DataStruct;

	if (m_ElementSize == 0)
		return false;

	if (m_Stride <= 0)
		return false;

	return true;
}

template<typename T>
inline bool CBuffer::InitConstanteBuffer(uint32_t Size, T * DataStruct)
{
	// this is so the descriptor doesn't have garbage or irreverent data  
	memset(&m_Discriptor, 0, sizeof(m_Discriptor));
	m_Discriptor.Usage = D3D11_USAGE_DEFAULT;
	m_Discriptor.ByteWidth = Size;
	m_Discriptor.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

	m_BufferType = D3D11_BIND_CONSTANT_BUFFER;

	m_Discriptor.CPUAccessFlags = 0;
	// this is so the SUB-RESOURCE doesn't have garbage or irreverent data 
	memset(&m_data, 0, sizeof(m_data));

	m_data.pSysMem = DataStruct;

	return true;
}

inline D3D11_BUFFER_DESC CBuffer::GetDesc()
{
	return m_Discriptor;
}

inline D3D11_BUFFER_DESC* CBuffer::GetDescRef()
{
	return &m_Discriptor;
}

inline D3D11_SUBRESOURCE_DATA CBuffer::GetData()
{
	return m_data;
}

inline D3D11_SUBRESOURCE_DATA* CBuffer::GetDataRef()
{
	return &m_data;
}

inline ID3D11Buffer* CBuffer::GetBuffer() 
{
	return mptr_Buffer;
}

inline ID3D11Buffer** CBuffer::GetBufferRef()
{
	return &mptr_Buffer;
}

inline uint32_t CBuffer::GetStride()
{
	return m_Stride;
}

inline uint32_t CBuffer::GetStrideRef()
{
	return m_Stride;
}

inline uint32_t CBuffer::GetOffSet()
{
	return m_OffSet;
}

inline uint32_t CBuffer::GetOffSetRef()
{
	return m_OffSet;
}

inline uint32_t CBuffer::GetElementCount()
{
	return m_CountElements;
}
