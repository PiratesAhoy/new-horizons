texture g_FontBitmap;
texture g_GradientTexture;

sampler FontTextureSampler =
sampler_state
{
    Texture = g_FontBitmap;
    MipFilter = LINEAR;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

sampler GradientTextureSampler =
sampler_state
{
    Texture = g_GradientTexture;
    MipFilter = LINEAR;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

void ps_font(float3 vPosition: POSITION, float4 vColor: COLOR, float3 vTexCoord: TEXCOORD, out float4 fColor: COLOR0)
{
    float4 texColor = tex2D(FontTextureSampler, vTexCoord);
    fColor = vColor * texColor;
}

void ps_font_gradient(float3 vPosition: POSITION, float4 vColor: COLOR, float3 vTexCoord: TEXCOORD, out float4 fColor: COLOR0)
{
    float4 texColor = tex2D(FontTextureSampler, vTexCoord);
    float4 gradientColor = tex2D(GradientTextureSampler, float2(0, vTexCoord.z));
    fColor = gradientColor * vColor * texColor;
}

technique BmFont
{
    pass p0
    {
        CullMode = none;
        FogEnable = false;
        AlphaTestEnable = false;
        ZEnable = false;
        AlphaBlendEnable = true;
        SrcBlend = srcalpha;
        DestBlend = invsrcalpha;

        PixelShader = compile ps_2_0 ps_font();
    }
}

technique BmFontGradient
{
    pass p0
    {
        CullMode = none;
        FogEnable = false;
        AlphaTestEnable = false;
        ZEnable = false;
        AlphaBlendEnable = true;
        SrcBlend = srcalpha;
        DestBlend = invsrcalpha;

        PixelShader = compile ps_2_0 ps_font_gradient();
    }
}
