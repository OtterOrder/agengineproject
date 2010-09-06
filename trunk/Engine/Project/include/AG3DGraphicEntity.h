#pragma once

#include "AGGraphicEntity.h"
#include "AG3DEntity.h"

#include "AGResourceManager.h"

#include "AGMesh.h"
#include "AGMaterial.h"
#include "AG3DMaterial.h"

#include "AGDebugCamera.h"	////.
#include "AGTexture.h"		////.

//------------------------------------------------------------------------------------------------------------------------------
class AG3DGraphicEntity : public AG3DEntity, public AGGraphicEntity
{
public:
	DefineVectorIterator(AG3DEntity,  Iterator);

protected:
	AGMesh*			_mpMesh;
	AG3DMaterial*	_mpMaterial;
	AG3DMaterial*	_mpZMaterial;
	AG3DMaterial*	_mpShadowMaterial;

public:
	AGVector3f		mOrientation;
	AGVector3f		mScale;
	bool			mShadowed;		////.

public:
							AG3DGraphicEntity	();
							~AG3DGraphicEntity	();

	void					SetMesh			(cStr _FileName)			{ SAFE_DECREF(_mpMesh);	_mpMesh = AGResourceManager::GetSingleton()->Load<AGMesh>(_FileName); };
	inline	AGMesh*			GetMesh			()							{ return _mpMesh; };

	inline	void			SetMaterial		(AG3DMaterial* _pMaterial)	{ SAFE_DELETE(_mpMaterial); _mpMaterial = _pMaterial; };
	inline	AG3DMaterial*	GetMaterial		()							{ return _mpMaterial; };

	////.
	inline	void			SetZMaterial		(AG3DMaterial* _pZMaterial)	{ SAFE_DELETE(_mpZMaterial); _mpZMaterial = _pZMaterial; };
	inline	AG3DMaterial*	GetZMaterial		()							{ return _mpZMaterial; };
	inline	void			SetShadowMaterial	(AG3DMaterial* _pMaterial)	{ SAFE_DELETE(_mpShadowMaterial); _mpShadowMaterial = _pMaterial; };
	inline	AG3DMaterial*	GetShadowMaterial	()							{ return _mpShadowMaterial; };
	////.

	virtual	void			Update			();

	virtual	void			Draw			(CFirstPersonCamera* _pCamera, AG3DScene* _pScene);		////.
			////.
			void			DrawZ			(AGMatrix& _ViewMatrix, AGMatrix& _ProjMatrix, AGMatrix& _ViewProjMatrix);
			void			DrawShadow		(CFirstPersonCamera* _pCamera, AGMatrix& _LightViewProjMatrix, AGPTexture& _ShadowMap);
			////.
};