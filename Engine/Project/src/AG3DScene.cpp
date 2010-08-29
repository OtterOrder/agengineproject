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

	//AGLight::Iterator LightIt;	// erreur de compilation. ?
	std::vector<AGLight*>::iterator LightIt;	////.
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
void AG3DScene::RemoveGraphicObject(AG3DGraphicEntity* _pGraphicEntity)
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