#include "AG2DGroup.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AG2DGroup::AG2DGroup()
{
}

//------------------------------------------------------------------------------------------------------------------------------
AG2DGroup::~AG2DGroup()
{
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AG2DGroup::DeleteEntity(AG2DEntity* _pEntity)
{
	AG2DEntity::Iterator EntityIt;

	for (EntityIt = _mpEntities.begin(); EntityIt != _mpEntities.end(); EntityIt++)
	{
		if (_pEntity == *EntityIt)
		{
			SAFE_DELETE(_pEntity);
			_mpEntities.erase(EntityIt);
			return;
		}
	}
}