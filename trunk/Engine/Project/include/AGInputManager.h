#pragma once

#include "AGSingleton.h"

#include "AGUtilities.h"
#include "AGInputs.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGInputManager : public AGSingleton<AGInputManager>
{
friend class AGSingleton<AGInputManager>;

private:
	std::vector<AGInputs*>	_mpInputsList;

protected:
	AGInputManager	();
	~AGInputManager	();

public:
	void	Update	();

	u32		AddInputs	(AGInputs* _pInputs);		// Return Inputs Id
	void	ClearInputs ();
	
	inline AGInputs* GetInputs (u32 _Id)	{ return _mpInputsList[_Id]; };
};

#define AGGetInputs(_Id) AGInputManager::GetSingleton()->GetInputs(_Id)