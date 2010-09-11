
float4x4 g_mWorldViewProjection;    // World * View * Projection matrix
float4x4 gWorld;
float4x4 gWorldIT;

struct VS_INPUT
{
	float3 Position		: POSITION;
	float3 Normal 		: NORMAL;
	float3 Tangent		: TANGENT;
	float3 Binormal  	: BINORMAL;
	float2 UV			: TEXCOORD0;
};

struct VS_OUTPUT
{
	float4 Position			: POSITION;
	float2 UV				: TEXCOORD0;
	float3 WorldPosition	: TEXCOORD1;
	float3 WorldNormal		: NORMAL;
	float3 Tangent			: TEXCOORD2;
	float3 Binormal			: TEXCOORD3;
	float3 ScreenUV			: TEXCOORD4;
};

VS_OUTPUT VSMain (VS_INPUT _Input)
{
    VS_OUTPUT Output;

	Output.Position 		= mul(float4(_Input.Position, 1.0f), g_mWorldViewProjection);
	Output.WorldPosition	= mul(float4(_Input.Position, 1.0f), gWorld);
	Output.WorldNormal		= mul(float4(_Input.Normal,   0.0f), gWorldIT);
	Output.UV				= _Input.UV;
	Output.Tangent			= _Input.Tangent;
	Output.Binormal			= cross( Output.WorldNormal , Output.Tangent);
	Output.ScreenUV			= Output.Position.xyw;

	return Output;
}