#include "AG3DScene.h"

#include "AG3DCamera.h"
#include "AGLight.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AG3DScene::AG3DScene()
{
	_mpCamera = new AG3DCamera();
}

//------------------------------------------------------------------------------------------------------------------------------
AG3DScene::~AG3DScene()
{
	SAFE_DELETE(_mpCamera);

	//AG3DGraphicEntity::Iterator GEntityIt;	// erreur de compilation. ?
	std::vector<AG3DGraphicEntity*>::iterator GEntityIt;	////.
	for (GEntityIt = _mpGraphicEntites.begin(); GEntityIt != _mpGraphicEntites.end(); GEntityIt++)
	{
		SAFE_DELETE(*GEntityIt);
	}
	_mpGraphicEntites.clear();

	AGLight::Iterator LightIt;
	for (LightIt = _mpLights.begin(); LightIt != _mpLights.end(); LightIt++)
	{
		SAFE_DELETE(*LightIt);
	}
	_mpLights.clear();
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AG3DScene::Update ()
{
	_mpCamera->Update();

	//AG3DGraphicEntity::Iterator GEntityIt;	// erreur de compilation. ?
	std::vector<AG3DGraphicEntity*>::iterator GEntityIt;	////.

	for (GEntityIt = _mpGraphicEntites.begin(); GEntityIt != _mpGraphicEntites.end(); GEntityIt++)
	{
		(*GEntityIt)->Update();
	}

	AGLight::Iterator LightIt;
	for (LightIt = _mpLights.begin(); LightIt != _mpLights.end(); LightIt++)
	{
		(*LightIt)->Update();
	}
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AG3DGraphicEntity* AG3DScene::GetNewGraphicEntity ()
{
	AG3DGraphicEntity* pGraphicEntity = new AG3DGraphicEntity();
	_mpGraphicEntites.push_back(pGraphicEntity);
	return pGraphicEntity;
}

//------------------------------------------------------------------------------------------------------------------------------
void AG3DScene::RemoveGraphicEntity (AG3DGraphicEntity* _pGraphicEntity)
{
	//AG3DGraphicEntity::Iterator GEntityIt;	// erreur de compilation. ?
	std::vector<AG3DGraphicEntity*>::iterator GEntityIt;	////.

	for (GEntityIt = _mpGraphicEntites.begin(); GEntityIt != _mpGraphicEntites.end(); GEntityIt++)
	{
		if (_pGraphicEntity == *GEntityIt)
		{
			_mpGraphicEntites.erase(GEntityIt);
			return;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGSpotLight* AG3DScene::GetNewSpotLight ()
{
	AGSpotLight* pSpotLight = new AGSpotLight();
	_mpLights.push_back(pSpotLight);
	return pSpotLight;
}

//------------------------------------------------------------------------------------------------------------------------------
void AG3DScene::RemoveLight (AGLight* _pLight)
{
	AGLight::Iterator LightIt;

	for (LightIt = _mpLights.begin(); LightIt != _mpLights.end(); LightIt++)
	{
		if (_pLight == *LightIt)
		{
			_mpLights.erase(LightIt);
			return;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGSkybox* AG3DScene::GetNewSkybox ()
{
	AGSkybox* pSkybox = new AGSkybox();
	AG3DGraphicEntity * Ptr=dynamic_cast<AG3DGraphicEntity*>(pSkybox);
	_mpGraphicEntites.push_back(Ptr);
	return pSkybox;
}

//------------------------------------------------------------------------------------------------------------------------------
AGPRTLightProbe* AG3DScene::GetNewPRTSkybox ()
{
	AGPRTLightProbe* pSkybox = new AGPRTLightProbe();
	AG3DGraphicEntity * Ptr=dynamic_cast<AG3DGraphicEntity*>(pSkybox);
	_mpGraphicEntites.push_back(Ptr);
	return pSkybox;
}