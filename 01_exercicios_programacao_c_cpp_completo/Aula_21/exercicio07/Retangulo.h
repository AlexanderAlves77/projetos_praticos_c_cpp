/*
 * Retangulo.h
 *
 * Representa um retângulo no plano cartesiano.
 *
 * Parte do exercício 7.
 *
 *  Created on: Aug 14, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef RETANGULO_H_
#define RETANGULO_H_

#include <iostream>
#include "Quadrilatero.h"
using namespace std;

namespace exercicio07 {
	class Retangulo: public exercicio07::Quadrilatero {
	public:
		Retangulo(double base, double altura);
		double calcularArea() const;

		void print(ostream &out) const;
	};
}
#endif
