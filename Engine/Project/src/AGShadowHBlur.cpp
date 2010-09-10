#include "AGShadowHBlur.h"

#include "AGShadowManager.h"

#define	AGShadowBlurPShader	".\\Data\\Shaders\\Defaults\\AGShadowHBlur.psh"
#define AGShadowBlurPEntryP	"PSMain"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGShadowHBlur::AGShadowHBlur ()
{
	_mMaterial.SetPixelShader(AGShadowBlurPShader, AGShadowBlurPEntryP);
}

//------------------------------------------------------------------------------------------------------------------------------
AGShadowHBlur::~AGShadowHBlur ()
{
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGShadowHBlur::Setup ()
{
	AGSamplerState SampState (AGSamplerState::Linear, AGSamplerState::Linear, AGSamplerState::Clamp, AGSamplerState::Clamp);
	_mMaterial.GetPixelShader()->SetTexture("ShadowSampler", mpTexture, &SampState);
	SampState = AGSamplerState ();
	_mMaterial.GetPixelShader()->SetTexture("BlurSampler", mpBlurCoef, &SampState);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGShadowHBlur::End ()
{
	AGSamplerState SampState;
	_mMaterial.GetPixelShader()->SetTexture("ShadowSampler", NULL, &SampState);
	_mMaterial.GetPixelShader()->SetTexture("BlurSampler", NULL, &SampState);
}