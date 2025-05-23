/*=================================================================================
*  Arquivo     : Triangle (Arquivo de Cabe�alho)
*  Cria��o     : 15 Set 2023
*  Author      : Alexander Alves
*  Compilador  : Visual C++ 2019
*  Atualiza��o : 15 Set 2023
*
*  Descri��o   : Constr�i curvas usando corner-cutting no Direct3D 12
===================================================================================*/

#ifndef CURVES_H
#define CURVES_H

#include "DXUT.h"
#include <D3DCompiler.h>
#include <DirectXMath.h>
#include <DirectXColors.h>
using namespace DirectX;

// ------------------------------------------------------------------------------

struct Vertex
{
    XMFLOAT3 Pos;
    XMFLOAT4 Color;
};

// ------------------------------------------------------------------------------

class Curves : public App
{
private:
    ID3D12RootSignature* rootSignature;
    ID3D12PipelineState* pipelineState;
    Mesh* geometry;

    static const uint MaxVertex = 10;
    Vertex vertices[MaxVertex];
    uint count;
    uint index;

public:
    void Init();
    void Update();
    void Display();
    void Finalize();

    void BuildGeometry();
    void BuildRootSignature();
    void BuildPipelineState();
};

// ------------------------------------------------------------------------------

#endif