/*=================================================================================
*  Arquivo     : Types (Arquivo de Cabe�alho)
*  Cria��o     : 17 Set 2023
*  Author      : Alexander Alves
*  Compilador  : Visual C++ 2019
*  Atualiza��o : 17 Set 2023
*
*  Descri��o   : Isola os tipos espec�ficos da plataforma fornecendo 
*                tipos consistentes para todo o Motor Gr�fico.
===================================================================================*/

#ifndef DXUT_TYPES_H
#define DXUT_TYPES_H

// atalhos para tipos da linguagem C++
using byte   = unsigned char;
using ushort = unsigned short;
using ulong  = unsigned long;
using llong  = long long;
using ullong = unsigned long long;
using uint   = unsigned int;

// formatos geom�tricos
enum GeometryTypes
{
    UNKNOWN_T,
    BOX_T,
    CYLINDER_T,
    SPHERE_T,
    GEOSPHERE_T,
    GRID_T,
    QUAD_T
};

#endif