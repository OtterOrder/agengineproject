
float4x4 g_mWorldViewProjection;    // World * View * Projection matrix
float4x4 gWorld;
float4x4 gLightViewProj;

struct VS_INPUT
{
	float3 Position		: POSITION;
};

struct VS_OUTPUT
{
	float4 Position	: POSITION;
	float4 PosProj	: TEXCOORD0;
	float2 ZW		: TEXCOORD1;
};

VS_OUTPUT VSMain (VS_INPUT _Input)
{
    VS_OUTPUT Output;

	Output.Position 	= mul(float4(_Input.Position, 1.0f), g_mWorldViewProjection);
	
	Output.PosProj		= mul(mul(float4(_Input.Position, 1.0f), gWorld), gLightViewProj);
	Output.ZW			= Output.Position.zw;

	return Output;
}