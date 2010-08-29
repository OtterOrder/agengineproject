#include "AG3DScene.h"

#include "AG3DCamera.h"
#include "AGLight.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AG3DScene::AG3DScene()
{
}

//------------------------------------------------------------------------------------------------------------------------------
AG3DScene::~AG3DScene()
{
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AG3DScene::Update ()
{
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