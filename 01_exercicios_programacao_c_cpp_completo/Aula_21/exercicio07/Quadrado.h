/*
 * Quadrado.h
 *
 * Representa um quadrado no plano cartesiano.
 *
 * Parte do exercício 7.
 *
 *  Created on: Aug 14, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef QUADRADO_H_
#define QUADRADO_H_

#include <iostream>
#include "Quadrilatero.h"
using namespace std;

namespace exercicio07 {
	class Quadrado: public exercicio07::Quadrilatero {
	public:
		Quadrado(double lado);
		double calcularArea() const;

		void print(ostream &out) const;
	};
}
#endif
