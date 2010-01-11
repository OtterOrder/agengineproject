#pragma once

#include "AGGraphicEntity.h"
#include "AG3DEntity.h"

#include "AGResourceManager.h"

#include "AGMesh.h"
#include "AGMaterial.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG3DGraphicEntity : public AG3DEntity, public AGGraphicEntity
{
private:
	AGMesh*		_mpMesh;
	AGMaterial*	_mpMaterial;

public:
	AG3DGraphicEntity	();
	~AG3DGraphicEntity	();

	void			SetMesh	(cStr _FileName)	{ SAFE_DECREF(_mpMesh);	_mpMesh = AGResourceManager::GetSingleton()->Load<AGMesh>(_FileName); };
	inline AGMesh*	GetMesh	()					{ return _mpMesh; };

	inline void			SetMaterial (AGMaterial* _pMaterial)	{ SAFE_DELETE(_mpMaterial); _mpMaterial = _pMaterial; };
	inline AGMaterial*	GetMaterial	()							{ return _mpMaterial; };
};