#pragma once

#include "AGGraphicEntity.h"
#include "AG3DEntity.h"

#include "AGResourceManager.h"

#include "AGMesh.h"
#include "AGMaterial.h"
#include "AG3DMaterial.h"
#include "AGDebugCamera.h"	////.

//------------------------------------------------------------------------------------------------------------------------------
class AG3DGraphicEntity : public AG3DEntity, public AGGraphicEntity
{
public:
	DefineVectorIterator(AG3DEntity,  Iterator);

private:
	AGMesh*			_mpMesh;
	AG3DMaterial*	_mpMaterial;

public:
	AGVector3f	mOrientation;
	AGVector3f	mScale;

public:
							AG3DGraphicEntity	();
							~AG3DGraphicEntity	();

	void					SetMesh	(cStr _FileName)	{ SAFE_DECREF(_mpMesh);	_mpMesh = AGResourceManager::GetSingleton()->Load<AGMesh>(_FileName); };
	inline	AGMesh*			GetMesh	()					{ return _mpMesh; };

	inline	void			SetMaterial (AG3DMaterial* _pMaterial)	{ SAFE_DELETE(_mpMaterial); _mpMaterial = _pMaterial; };
	inline	AG3DMaterial*	GetMaterial	()							{ return _mpMaterial; };

	virtual	void			Update ();

			void			Draw	(CFirstPersonCamera* _pCamera, AG3DScene* _pScene);		////.
};