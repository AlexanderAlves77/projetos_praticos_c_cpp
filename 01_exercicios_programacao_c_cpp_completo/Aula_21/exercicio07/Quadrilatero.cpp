/*
 * Quadrilatero.cpp
 *
 * Implementação de Quadrilatero.
 *
 * Parte do exercício 7.
 *
 *  Created on: Aug 14, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include "Quadrilatero.h"

namespace exercicio07 {
	Quadrilatero::Quadrilatero(double l1, double l2, double l3, double l4) {
		lados = new double[4];
		lados[0] = l1;
		lados[1] = l2;
		lados[2] = l3;
		lados[3] = l4;
	}

	double Quadrilatero::calcularPerimetro() const {
		return lados[0] + lados[1] + lados[2] + lados[3];
	}

	Quadrilatero::~Quadrilatero() {
		delete lados;
	}
}
