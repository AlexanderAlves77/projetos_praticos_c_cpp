/*=================================================================================
*  Arquivo     : Vertex (Arquivo de Sombreamento)
*  Cria��o     : 16 Set 2023
*  Author      : Alexander Alves
*  Compilador  : D3DCompiler
*  Atualiza��o : 15 Set 2023
*
*  Descri��o   : Um vertex shader simples que apenas passa a posi��o e cor
*                do v�rtice para frente sem realizar nenhuma transforma��o.
===================================================================================*/

struct VertexIn
{
    float3 PosL  : POSITION;
    float4 Color : COLOR;
};

struct VertexOut
{
    float4 PosH  : SV_POSITION;
    float4 Color : COLOR;
};

VertexOut main(VertexIn vin)
{
    VertexOut vout;

    // apenas adiciona a componente w = 1 em cada v�rtice
    vout.PosH = float4(vin.PosL, 1.0f);

    // apenas passa a cor do v�rtice para o pixel shader
    vout.Color = vin.Color;

    return vout;
}