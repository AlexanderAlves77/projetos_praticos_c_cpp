/*
 * Quadrado.cpp
 *
 * Implementação de Quadrado.
 *
 * Parte do exercício 7.
 *
 *  Created on: Aug 14, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <iostream>
#include "Quadrado.h"
using namespace std;

namespace exercicio07 {
	Quadrado::Quadrado(double lado): Quadrilatero(lado, lado, lado, lado) {}

	double Quadrado::calcularArea() const {
		return lados[0] * lados[0];
	}

	void Quadrado::print(ostream &out) const {
		out << "Quadrado de lado " << lados[0];
	}
}
