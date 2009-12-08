#pragma once

#include "AG3DEntity.h"

#include <vector>
using namespace std;

//------------------------------------------------------------------------------------------------------------------------------
class AG3DGroup : public AG3DEntity
{
public:
	DefineVectorIterator(AG3DGroup, Iterator);

private:
	vector<AG3DEntity*>	_mpEntities;

public:
	AG3DGroup	();
	~AG3DGroup	();

	inline	void AddEntity		(AG3DEntity* _pEntity)	{ _mpEntities.push_back(_pEntity); };
			void DeleteEntity	(AG3DEntity* _pEntity);
};