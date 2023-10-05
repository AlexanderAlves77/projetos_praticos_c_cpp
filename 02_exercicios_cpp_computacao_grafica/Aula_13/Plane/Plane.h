/*=================================================================================
*  Arquivo     : Plane (Arquivo de Cabe�alho)
*  Cria��o     : 16 Set 2023
*  Author      : Alexander Alves
*  Compilador  : Visual C++ 2019
*  Atualiza��o : 16 Set 2023
*
*  Descri��o   : Constr�i um cubo usando o Direct3D 12
===================================================================================*/

#ifndef PLANE_H
#define PLANE_H

#include "DXUT.h"
#include <D3DCompiler.h>
#include <DirectXMath.h>
#include <DirectXColors.h>
using namespace DirectX;

// ------------------------------------------------------------------------------

struct Vertex
{
    XMFLOAT4 Pos;
    XMFLOAT4 Color;
};

// ------------------------------------------------------------------------------

class Plane : public App
{
private:
    ID3D12RootSignature* rootSignature = nullptr;
    ID3D12PipelineState* pipelineState = nullptr;
    Mesh* geometry = nullptr;

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