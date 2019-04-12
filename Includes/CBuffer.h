#pragma once
#include<Includes/Usable_Window.h>
#include<Includes/DirectX_Stuff.h>

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

	UINT GetStride();
	UINT *GetStridePtr();

	UINT GetOffSet();
	UINT *GetOffSetPtr();

public:// variables 
	ID3D11Buffer* mptr_Buffer = nullptr;
private:
	uint32_t m_CountElements = 0;
	uint32_t m_ElementSize = 0;
	UINT m_Stride = 0;
	UINT m_OffSet = 0;

	D3D11_BIND_FLAG m_BufferType;
	D3D11_BUFFER_DESC m_Discriptor;
	D3D11_SUBRESOURCE_DATA m_data;
};

template<typename T>
inline bool CBuffer::InitBufferData(T * DataStruct, uint32_t CountElements,
																		uint32_t OffSet, D3D11_BIND_FLAG bufferType)
{
	// size of single element 
	m_ElementSize = sizeof(*DataStruct);
	// get the stride 
	m_Stride = sizeof(*DataStruct) - OffSet;

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

inline D3D11_SUBRESOURCE_DATA * CBuffer::GetDataRef()
{
	return &m_data;
}

inline ID3D11Buffer * CBuffer::GetBuffer() 
{
	return mptr_Buffer;
}

inline ID3D11Buffer ** CBuffer::GetBufferRef()
{
	return &mptr_Buffer;
}

inline UINT CBuffer::GetStride()
{
	return m_Stride;
}

inline UINT * CBuffer::GetStridePtr()
{
	return &m_Stride;
}

inline UINT CBuffer::GetOffSet()
{
	return m_OffSet;
}

inline UINT * CBuffer::GetOffSetPtr()
{
	return &m_OffSet;
}
