
float4x4 g_mWorldViewProjection;    // World * View * Projection matrix

struct VS_INPUT
{
	float4 Position	: POSITION;
	float2 UV		: TEXCOORD0;
};

struct VS_OUTPUT
{
	float4 Position	: POSITION;
	float2 UV		: TEXCOORD0;
};

VS_OUTPUT VSMain (VS_INPUT _Input)
{
    VS_OUTPUT Output;

	Output.Position = mul(_Input.Position, g_mWorldViewProjection);
	Output.UV		= _Input.UV;

	return Output;
}