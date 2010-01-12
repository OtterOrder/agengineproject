#pragma once

#include "AGVertexShader.h"
#include "AGPixelShader.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGMaterial
{
private:
	AGVertexShader*	_mpVertexShader;
	AGPixelShader*	_mpPixelShader;

public:
	AGMaterial	();
	~AGMaterial	();

	void	SetShader		(cStr _VertexShaderFileName = NULL, cStr _VertexEntryPoint = NULL, cStr _PixelShaderFileName = NULL, cStr _PixelEntryPoint = NULL);
	void	SetVertexShader	(cStr _FileName, cStr _EntryPoint);
	void	SetPixelShader	(cStr _FileName, cStr _EntryPoint);

	inline AGVertexShader*		GetVertexShader	()		{ return _mpVertexShader; };
	inline AGPixelShader*		GetPixelShader	()		{ return _mpPixelShader; };

	void	Apply ();
};