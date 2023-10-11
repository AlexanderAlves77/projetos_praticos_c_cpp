/*=================================================================================
*  Arquivo     : Pixel (Arquivo de Sombreamento)
*  Cria��o     : 16 Set 2023
*  Author      : Alexander Alves
*  Compilador  : D3DCompiler
*  Atualiza��o : 15 Set 2023
*
*  Descri��o   : Um pixel shader simples que apenas passa a cor do pixel
*                para frente sem realizar nenhuma modifica��o.
===================================================================================*/

struct pixelIn
{
    float4 PosH  : SV_POSITION;
    float4 Color : COLOR;
};

float4 main(pixelIn pIn) : SV_TARGET
{
    return pIn.Color;
}