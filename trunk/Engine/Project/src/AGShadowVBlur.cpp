#include "AGShadowVBlur.h"

#include "AGShadowManager.h"

#define	AGShadowBlurPShader	".\\Data\\Shaders\\Defaults\\AGShadowVBlur.psh"
#define AGShadowBlurPEntryP	"PSMain"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGShadowVBlur::AGShadowVBlur ()
{
	_mMaterial.SetPixelShader(AGShadowBlurPShader, AGShadowBlurPEntryP);
}

//------------------------------------------------------------------------------------------------------------------------------
AGShadowVBlur::~AGShadowVBlur ()
{
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGShadowVBlur::Setup ()
{
	AGSamplerState SampState (AGSamplerState::Linear, AGSamplerState::Linear, AGSamplerState::Clamp, AGSamplerState::Clamp);
	_mMaterial.GetPixelShader()->SetTexture("ShadowSampler", mpTexture, &SampState);
	SampState = AGSamplerState ();
	_mMaterial.GetPixelShader()->SetTexture("BlurSampler", mpBlurCoef, &SampState);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGShadowVBlur::End ()
{
	AGSamplerState SampState;
	_mMaterial.GetPixelShader()->SetTexture("ShadowSampler", NULL, &SampState);
	_mMaterial.GetPixelShader()->SetTexture("BlurSampler", NULL, &SampState);
}