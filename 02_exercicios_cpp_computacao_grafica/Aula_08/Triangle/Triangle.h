/*=================================================================================
*  Arquivo     : Triangle (Arquivo de Cabeçalho)
*  Criação     : 15 Set 2023
*  Author      : Alexander Alves
*  Compilador  : Visual C++ 2019
*  Atualização : 15 Set 2023
*
*  Descrição   : Constrói um Triângulo usando o Direct3D 12
===================================================================================*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

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

class Triangle : public App
{
private:
    ID3D12RootSignature* rootSignature;
    ID3D12PipelineState* pipelineState;
    Mesh* geometry;

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