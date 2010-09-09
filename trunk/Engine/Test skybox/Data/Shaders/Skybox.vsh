
float4x4 g_mWorldViewProjection;    // World * View * Projection matrix
float4x4 g_mInvWorldViewProjection;
float4x4 gWorld;

struct VS_OUTPUT
{
    float4 Position : POSITION;
    float3 CoordTex : TEXCOORD2;
};

VS_OUTPUT VSMain (float4 vPos : POSITION)
{
    VS_OUTPUT Output;

	Output.Position = mul(vPos, g_mWorldViewProjection);
    float3 ObjectPosition = mul(vPos, gWorld);
    
    Output.CoordTex = ObjectPosition;	

	return Output;
}