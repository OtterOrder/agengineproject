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
	AGTextureFilter Filter;
	_mMaterial.GetPixelShader()->SetTexture("ShadowSampler", mpTexture, &Filter);
	_mMaterial.GetPixelShader()->SetTexture("BlurSampler", mpBlurCoef, &Filter);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGShadowHBlur::End ()
{
	AGTextureFilter Filter;
	_mMaterial.GetPixelShader()->SetTexture("ShadowSampler", NULL, &Filter);
	_mMaterial.GetPixelShader()->SetTexture("BlurSampler", NULL, &Filter);
}