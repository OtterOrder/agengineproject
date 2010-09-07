#include "AGResourceManager.h"
#include <assert.h>

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGResourceManager::AGResourceManager()
{
}

//------------------------------------------------------------------------------------------------------------------------------
AGResourceManager::~AGResourceManager()
{
}

//------------------------------------------------------------------------------------------------------------------------------
void AGResourceManager::Destroy()
{
	Clear();
	assert( _mResourcesList.empty() );
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGResourceManager::Add(cStr _FileName, u32 _Crc, AGResource* _pResource)
{
	assert(_pResource != NULL);

	_mResourcesList.insert(pair<u32, AGResource*>(_Crc, _pResource));
	_pResource->SetName(_FileName);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGResourceManager::Clear()
{
	if( !_mResourcesList.empty() )
	{
		for( Iterator It = _mResourcesList.begin(); It != _mResourcesList.end(); It++ )
		{
			SAFE_DELETE(It->second);
		}
		_mResourcesList.clear();
	}
}