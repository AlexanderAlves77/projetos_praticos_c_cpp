/**********************************************************************************
* Arquivo    : Vertex (Arquivo de Sombreamento)
* Author     : Alexander Alves
* Cria��o    : 11 Jul 2007
* Atualiza��o: 19 Dez 2023
* Compilador : D3DCompiler
*
* Descri��o  : Define um vertex shader que apenas multiplica os v�rtices
*              por uma matriz de transforma��o e proje��o
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