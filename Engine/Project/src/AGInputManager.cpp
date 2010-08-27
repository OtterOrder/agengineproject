#include "AGInputManager.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGInputManager::AGInputManager()
{
}

//------------------------------------------------------------------------------------------------------------------------------
AGInputManager::~AGInputManager()
{
	ClearInputs();
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGInputManager::Update ()
{
	AGInputs::Iterator lInputsIt;

	for (lInputsIt = _mpInputsList.begin(); lInputsIt != _mpInputsList.end(); lInputsIt++)
	{
		(*lInputsIt)->Update();
	}
}

//------------------------------------------------------------------------------------------------------------------------------
u32 AGInputManager::AddInputs(AGInputs* _pInputs)
{
	_mpInputsList.push_back(_pInputs);
	return _mpInputsList.size() -1;
}

//------------------------------------------------------------------------------------------------------------------------------
void AGInputManager::ClearInputs()
{
	AGInputs::Iterator lInputsIt;

	for (lInputsIt = _mpInputsList.begin(); lInputsIt != _mpInputsList.end(); lInputsIt++)
		SAFE_DELETE((*lInputsIt));

	_mpInputsList.clear();
}