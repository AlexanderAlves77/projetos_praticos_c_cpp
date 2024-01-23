/*
 * Circulo.h
 *
 * Representa um círculo no plano cartesiano.
 *
 * Parte do exercício 7.
 *
 *  Created on: Aug 14, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef CIRCULO_H_
#define CIRCULO_H_

#include <iostream>
#include "Forma.h"
using namespace std;

namespace exercicio07 {
	class Circulo: public exercicio07::Forma {
		double raio;
	public:
		Circulo(double raio);
		double calcularPerimetro() const;
		double calcularArea() const;

		void print(ostream &out) const;
	};
}
#endif
