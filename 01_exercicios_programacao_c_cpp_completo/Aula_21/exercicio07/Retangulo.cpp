/*
 * Retangulo.cpp
 *
 * Implementação de Retangulo.
 *
 * Parte do exercício 7.
 *
 *  Created on: Aug 14, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <iostream>
#include "Retangulo.h"
using namespace std;

namespace exercicio07 {
	Retangulo::Retangulo(double base, double altura): Quadrilatero(base, altura, base, altura) {}

	double Retangulo::calcularArea() const {
		return lados[0] * lados[1];
	}

	void Retangulo::print(ostream &out) const {
		out << "Retângulo de base " << lados[0] << " e altura " << lados[1];
	}
}
