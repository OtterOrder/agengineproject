#pragma once

#include "AGVertexShader.h"
#include "AGPixelShader.h"
#include "AGScene.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGMaterial
{
protected:
	AGVertexShader*	_mpVertexShader;
	AGPixelShader*	_mpPixelShader;

public:
							AGMaterial	();
	virtual					~AGMaterial	();

			void			SetShader		(cStr _VertexShaderFileName, cStr _VertexEntryPoint, cStr _PixelShaderFileName, cStr _PixelEntryPoint);
			void			SetVertexShader	(cStr _FileName, cStr _EntryPoint);
			void			SetPixelShader	(cStr _FileName, cStr _EntryPoint);

	inline	AGVertexShader*	GetVertexShader	()		{ return _mpVertexShader; };
	inline	AGPixelShader*	GetPixelShader	()		{ return _mpPixelShader; };

			void			Activate ();
};