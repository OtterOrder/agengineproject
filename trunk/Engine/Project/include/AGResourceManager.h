#pragma once

#include "AGSingleton.h"
#include "AGResource.h"

#include <map>
using namespace std;

//------------------------------------------------------------------------------------------------------------------------------
class AGResourceManager : public AGSingleton<AGResourceManager>
{
friend class AGSingleton<AGResourceManager>;

private:
	DefineMapIterator(u32, AGResource, Iterator);
	map<u32, AGResource*> _mResourcesList;

protected:
	AGResourceManager		();
	~AGResourceManager		();

private:
	void Add(cStr _ResName, u32 _Crc, AGResource* _pResource);
	void Clear();


public:

	template< class T >
	T* Load(cStr _FileName, cStr _ResourceName, void* _Parameters = NULL )
	{
		u32 Crc = CRC::GetCRC(_ResourceName);

		Iterator It = _mResourcesList.find(Crc);

		if( It != _mResourcesList.end() )
		{
			It->second->IncRefCount();
			return static_cast<T*>(It->second);
		}
		else
		{
			T* pResource	= new T();
			Add( _ResourceName, Crc, dynamic_cast<AGResource*>(pResource) );

			if( pResource->Load(_FileName, _Parameters) != AGResource::RES_SUCCEED )
			{
				AGWarning(false, "Resource load failed");
				SAFE_DELETE(pResource);
				return NULL;
			}

			pResource->IncRefCount();
			return pResource;
		}
	}
};