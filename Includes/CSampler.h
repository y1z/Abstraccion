#pragma once
#include "DirectX_Stuff.h"
/**
*@file 'CSampler.h'
*@class CSampler "CSampler.h"
*@brief it controls the sampler and has the ability to 
* use a default setting or Anisotropic.
*
*/

class CSampler
{
public:// constructors
	CSampler();
	~CSampler();
public:// functions 
	/*! just uses the parameters from the tutorial*/
	void InitDefaultSampler();
	/*! The Same as the tutorial EXCEPT it has the 
	Anisotropic filter enabled */
	void InitAnisotropicSampler(); 
	/*! Increases Anisotropic filter AND 
	makes sure it does not go Over 16*/
	bool IncreseAnisotropicLevel();
	/*! Decreases Anisotropic filter AND 
	makes sure it does not go below 1*/
	bool DecreaseAnisotropicLevel();

	ID3D11SamplerState *GetSampler();
	/*! used when a reference is needed*/
	ID3D11SamplerState **GetSamplerRef();

	D3D11_SAMPLER_DESC GetDescriptor();
	/*! used when a reference is needed*/
	D3D11_SAMPLER_DESC &GetDescriptorRef();
private:// variables 

	//! to know if anisotropic filter is used 
	bool isAnisotropic = false;
	/*! For controlling anisotropic*/
	uint8_t m_AnisotropicLevel = 1;

	ID3D11SamplerState* mptr_Sampler = nullptr;

	D3D11_SAMPLER_DESC m_SamplerDescriptor;
};

