#include "AG3DEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AG3DEntity::AG3DEntity()
{
	_mpParent = NULL;

	mPosition		= AGVector3f(0.f, 0.f, 0.f);
	mOrientation	= AGVector3f(0.f, 0.f, 0.f);
	mScale			= AGVector3f(1.f, 1.f, 1.f);
}

//------------------------------------------------------------------------------------------------------------------------------
AG3DEntity::~AG3DEntity()
{
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AG3DEntity::Update ()
{
	AGMatrix M1, M2, M3;
	AGMatrixRotationX(&M1,  AGDegToRad(mOrientation.x) );
	AGMatrixRotationY(&M2,  AGDegToRad(mOrientation.y) );
	AGMatrixRotationZ(&M3,  AGDegToRad(mOrientation.z) );

	M2 = M1 * M2 * M3;

	AGMatrixTranslation(&M1, mPosition.x, mPosition.y, mPosition.z);

	mWorld = M1 * M2;
}