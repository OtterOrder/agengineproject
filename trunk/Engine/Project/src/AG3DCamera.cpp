#include "AG3DCamera.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AG3DCamera::AG3DCamera()
{
}

//------------------------------------------------------------------------------------------------------------------------------
AG3DCamera::~AG3DCamera()
{
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AG3DCamera::Update ()
{
	AGMatrix M1, M2, M3;
	AGMatrixRotationX(&M1,  AGDegToRad(mOrientation.x) );
	AGMatrixRotationY(&M2,  AGDegToRad(mOrientation.y) );
	AGMatrixRotationZ(&M3,  AGDegToRad(mOrientation.z) );

	M2 = M1 * M2 * M3;

	AGMatrixTranslation(&M1, mPosition.x, mPosition.y, mPosition.z);

	mWorld = M1 * M2;


	AGMatrixInverse (&mView, NULL, &mWorld);

	AGMatrixPerspectiveFovLH (&mProj, mFOV, mRatio, mZNear, mZFar);
}