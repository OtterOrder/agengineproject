#pragma once

#include "AGTypesDX9.h"
#include "AGSingleton.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGDeviceManager : public AGSingleton <AGDeviceManager>
{
private:
	AGPD3D		_mpD3d;
	AGPDevice	_mpDevice;

public:
	AGDeviceManager		();
	~AGDeviceManager	();

	bool	Initialize	();
	void	Destroy		();

	inline const AGPDevice&	GetDevice	()	const	{ return _mpDevice; };

	inline bool		BeginScene	()								{ if( SUCCEEDED(_mpDevice->BeginScene()) ) return true; return false; };
	inline void		EndScene	()								{ _mpDevice->EndScene(); };

	inline void		Present		()								{ _mpDevice->Present(NULL, NULL, NULL, NULL); };

	inline void		Clear (u32 _Flags, u32 _Color, float _Z)	{ _mpDevice->Clear( 0, NULL, _Flags, _Color, _Z, 0 ); };

	void	DrawMesh (AGPVertexDeclaration& _VertDelc, AGPVertexBuffer& _VB, u32& _VertexSize, AGPIndexBuffer& _IB, u32& _NbVertices, u32& _NbFaces);

	inline void		SetVertexShader	(AGPVertexShader _VertexShader)		{ _mpDevice->SetVertexShader(_VertexShader); };
	inline void		SetPixelShader	(AGPPixelShader _PixelShader)		{ _mpDevice->SetPixelShader(_PixelShader); };

	void	SetInt		(AGPConstantTable& _ConstTable, cStr _VarName, s32& _Int);
	void	SetFloat	(AGPConstantTable& _ConstTable, cStr _VarName, float& _Float);
	void	SetVector2f	(AGPConstantTable& _ConstTable, cStr _VarName, AGVector2f& _Vector);
	void	SetVector3f	(AGPConstantTable& _ConstTable, cStr _VarName, AGVector3f& _Vector);
	void	SetVector4f	(AGPConstantTable& _ConstTable, cStr _VarName, AGVector4f& _Vector);
	void	SetMatrix	(AGPConstantTable& _ConstTable, cStr _VarName, AGMatrix& _Matrix);
	void	SetTexture	(AGPConstantTable& _ConstTable, cStr _VarName, AGPTexture& _Texture);
	void	SetTexture	(AGPConstantTable& _ConstTable, cStr _VarName, AGPTextureCube& _Texture);
};