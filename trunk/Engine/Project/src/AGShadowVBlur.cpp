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
	AGTextureFilter Filter;
	_mMaterial.GetPixelShader()->SetTexture("ShadowSampler", mpTexture, &Filter);
	_mMaterial.GetPixelShader()->SetTexture("BlurSampler", mpBlurCoef, &Filter);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGShadowVBlur::End ()
{
	AGTextureFilter Filter (AGTextureFilter::Point, AGTextureFilter::Point);
	_mMaterial.GetPixelShader()->SetTexture("ShadowSampler", NULL, &Filter);
	_mMaterial.GetPixelShader()->SetTexture("BlurSampler", NULL, &Filter);
}