
float4x4 g_mWorldViewProjection;    // World * View * Projection matrix

struct VS_INPUT
{
	float3 Position		: POSITION;
};

struct VS_OUTPUT
{
	float4 Position	: POSITION;
	float2 Depth	: TEXCOORD0;
};

VS_OUTPUT VSMain (VS_INPUT _Input)
{
    VS_OUTPUT Output;

	Output.Position 	= mul(float4(_Input.Position, 1.0f), g_mWorldViewProjection);
	Output.Depth		= Output.Position.zw;

	return Output;
}