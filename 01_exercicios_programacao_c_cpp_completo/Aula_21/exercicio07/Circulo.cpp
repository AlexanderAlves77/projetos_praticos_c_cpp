/*
 * Circulo.cpp
 *
 * Implementação de Circulo.
 *
 * Parte do exercício 7.
 *
 *  Created on: Aug 14, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <iostream>
#include "Circulo.h"
using namespace std;

namespace exercicio07 {
	const double PI = 3.141592;

	Circulo::Circulo(double raio) {
		this->raio = raio;
	}

	double Circulo::calcularPerimetro() const {
		return 2 * PI * raio;
	}

	double Circulo::calcularArea() const {
		return PI * raio * raio;
	}

	void Circulo::print(ostream &out) const {
		out << "Círculo de raio " << raio;
	}
}
