/*
 * Forma.h
 *
 * Representa uma forma qualquer no plano cartesiano.
 *
 * Parte do exercício 7.
 *
 *  Created on: Aug 14, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef FORMA_H_
#define FORMA_H_

#include <iostream>
using namespace std;

namespace exercicio07 {
	class Forma {
	public:
		virtual double calcularPerimetro() const = 0;
		virtual double calcularArea() const = 0;
		virtual void print(ostream &out) const = 0;

		friend ostream& operator<< (ostream &out, const Forma *forma);
	};
}
#endif
