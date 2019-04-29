#include "CSampler.h"

CSampler::CSampler()
{
	memset(&m_SamplerDescriptor, 0, sizeof(m_SamplerDescriptor));
}

CSampler::~CSampler(){
	if (mptr_Sampler != nullptr) { mptr_Sampler->Release(); }
}

void CSampler::InitDefaultSampler()
{
	isAnisotropic = false;

	SecureZeroMemory(&m_SamplerDescriptor, sizeof(m_SamplerDescriptor));
	m_SamplerDescriptor.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	m_SamplerDescriptor.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
	m_SamplerDescriptor.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
	m_SamplerDescriptor.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
	m_SamplerDescriptor.ComparisonFunc = D3D11_COMPARISON_NEVER;
	m_SamplerDescriptor.MinLOD = 0;
	m_SamplerDescriptor.MaxLOD = D3D11_FLOAT32_MAX;
}

void CSampler::InitAnisotropicSampler()
{
	isAnisotropic = true;

	SecureZeroMemory(&m_SamplerDescriptor, sizeof(m_SamplerDescriptor));
	m_SamplerDescriptor.Filter = D3D11_FILTER_ANISOTROPIC;
	m_SamplerDescriptor.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	m_SamplerDescriptor.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	m_SamplerDescriptor.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	m_SamplerDescriptor.ComparisonFunc = D3D11_COMPARISON_NEVER;

	m_SamplerDescriptor.MaxAnisotropy = m_AnisotropicLevel;

	m_SamplerDescriptor.MinLOD = 0;
	m_SamplerDescriptor.MaxLOD = D3D11_FLOAT32_MAX;
}

bool CSampler::IncreseAnisotropicLevel()
{
	if (isAnisotropic && m_AnisotropicLevel < 16)
	{
		m_AnisotropicLevel++;
		return true;
	}

	return false;
}

bool CSampler::DecreaseAnisotropicLevel()
{
	if (isAnisotropic && m_AnisotropicLevel > 1)
	{
		m_AnisotropicLevel--;
		return true;
	}
	return false;
}

ID3D11SamplerState * CSampler::GetSampler()
{
	return mptr_Sampler;
}

ID3D11SamplerState ** CSampler::GetSamplerRef()
{
	return &mptr_Sampler;
}

D3D11_SAMPLER_DESC CSampler::GetDescriptor()
{
	return m_SamplerDescriptor;
}

D3D11_SAMPLER_DESC & CSampler::GetDescriptorRef()
{
	return m_SamplerDescriptor;
}
