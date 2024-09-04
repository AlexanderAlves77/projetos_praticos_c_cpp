/**********************************************************************************
* Arquivo    : Vertex (Arquivo de Sombreamento)
* Author     : Alexander Alves
* Criação    : 11 Jul 2007
* Atualização: 19 Dez 2023
* Compilador : D3DCompiler
*
* Descrição  : Define um vertex shader que apenas multiplica os vértices
*              por uma matriz de transformação e projeção
*
**********************************************************************************/


Texture2D resource;

SamplerState linearfilter
{
    Filter = MIN_MAG_MIP_LINEAR;
};

SamplerState anisotropic
{
    Filter = ANISOTROPIC;
    MaxAnisotropy = 4;
};

struct pixelIn
{
    float4 Pos   : SV_POSITION;
    float4 Color : COLOR;
    float2 Tex   : TEXCOORD;    
};

float4 main(pixelIn pIn) : SV_TARGET
{
    return resource.Sample(linearfilter, pIn.Tex) * pIn.Color;    
}