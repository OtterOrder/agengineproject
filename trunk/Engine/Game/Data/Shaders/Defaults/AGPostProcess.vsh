
struct VS_OUTPUT
{
	float4 Position	: POSITION;
	float2 UV		: TEXCOORD0;
};

VS_OUTPUT VSMain (float3 vPos : POSITION)
{
    VS_OUTPUT Output;

	Output.Position = float4(vPos, 1.f);
	Output.UV = (vPos + (1.f).xx) / 2.f;
	Output.UV.y = 1.f - Output.UV.y;

	return Output;
}