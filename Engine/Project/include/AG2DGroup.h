#pragma once

#include "AG2DEntity.h"

#include <vector>
using namespace std;

//------------------------------------------------------------------------------------------------------------------------------
class AG2DGroup : public AG2DEntity
{
public:
	DefineVectorIterator(AG2DGroup, Iterator);

private:
	vector<AG2DEntity*>	_mpEntities;

public:
	AG2DGroup	();
	~AG2DGroup	();

	inline	void AddEntity		(AG2DEntity* _pEntity)	{ _mpEntities.push_back(_pEntity); };
			void DeleteEntity	(AG2DEntity* _pEntity);
};