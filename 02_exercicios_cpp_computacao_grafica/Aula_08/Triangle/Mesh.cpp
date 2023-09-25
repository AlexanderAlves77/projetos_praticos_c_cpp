/*=================================================================================
*  Arquivo     : Mesh (Código Fonte)
*  Criação     : 15 Set 2023
*  Author      : Alexander Alves
*  Compilador  : Visual C++ 2019
*  Atualização : 15 Set 2023
*
*  Descrição   : Representa uma malha 3D em Direct3D 12
===================================================================================*/

#include "Mesh.h"

// -------------------------------------------------------------------------------

Mesh::Mesh(string name)
{
    id = name;

    vertexBufferCPU = nullptr;
    vertexBufferGPU = nullptr;
    vertexBufferUpload = nullptr;

    vertexByteStride = 0;
    vertexBufferSize = 0;
}

// -------------------------------------------------------------------------------

Mesh::~Mesh()
{
    if (vertexBufferUpload) vertexBufferUpload->Release();
    if (vertexBufferGPU) vertexBufferGPU->Release();
    if (vertexBufferCPU) vertexBufferCPU->Release();
}

// -------------------------------------------------------------------------------

D3D12_VERTEX_BUFFER_VIEW * Mesh::VertexBufferView()
{
    vertexBufferView.BufferLocation = vertexBufferGPU->GetGPUVirtualAddress();
    vertexBufferView.StrideInBytes = vertexByteStride;
    vertexBufferView.SizeInBytes = vertexBufferSize;

    return &vertexBufferView;
}

// -------------------------------------------------------------------------------

