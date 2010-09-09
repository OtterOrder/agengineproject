#include "AGPostProcess.h"

AGPVertexBuffer AGPostProcess::_mpVertexBuffer = NULL;

struct POSTPROCESS_VERTEX
{
	float x,y,z;
	float u,v;
};
#define POSTPROCESS_FVF (AGFVF_XYZ)



#define	AGPostProcessVShader	".\\Data\\Shaders\\Defaults\\AGPostProcess.vsh"
#define AGPostProcessVEntryP	"VSMain"


//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGPostProcess::AGPostProcess ()
{
	_mMaterial.SetVertexShader(AGPostProcessVShader, AGPostProcessVEntryP);
}

//------------------------------------------------------------------------------------------------------------------------------
AGPostProcess::~AGPostProcess ()
{
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGPostProcess::Initialize ()
{
	POSTPROCESS_VERTEX Vertices[4]=
	{
		{-1.f, -1.f,  0.f},
		{ 1.f, -1.f,  0.f},
		{-1.f,  1.f,  0.f},
		{ 1.f,  1.f,  0.f},
	};

	AGCreateVertexBuffer(sizeof(Vertices), POSTPROCESS_FVF, _mpVertexBuffer);

	void * pVertices;
	size_t Size = sizeof(Vertices);

	AGLockVertexBuffer(0, _mpVertexBuffer, Size, (void **)&pVertices);

	memcpy(pVertices, Vertices, Size);

	AGUnlockVertexBuffer(_mpVertexBuffer);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGPostProcess::Destroy ()
{
	SAFE_RELEASE(_mpVertexBuffer);
}


//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGPostProcess::Apply ()
{
	AGDeviceManager* pDeviceManager = AGDeviceManager::GetSingleton();

	pDeviceManager->SetZTest(false);

	if (pDeviceManager->BeginScene())
	{
		_mMaterial.Activate();
		_mMaterial.Apply(NULL, NULL);

		Setup ();

		AGDrawVertexBuffer(sizeof(POSTPROCESS_VERTEX), POSTPROCESS_FVF, _mpVertexBuffer, 0, 2);

		pDeviceManager->EndScene();

		End();
	}

	pDeviceManager->SetZTest(true);
}