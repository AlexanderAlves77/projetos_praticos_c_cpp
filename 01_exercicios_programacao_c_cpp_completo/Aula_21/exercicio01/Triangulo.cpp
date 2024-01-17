/*
 * Triangulo.cpp
 *
 * Implementação da classe Triangulo.
 *
 * Parte do exercício 1.
 *
 *  Created on: Aug 9, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include "Triangulo.h"

namespace exercicio01 {
	Triangulo::Triangulo(double xa, double ya, double xb, double yb, double xc, double yc):
			a(xa, ya), b(xb, yb), c(xc, yc) { };

	double Triangulo::perimetro() const {
		return a.distancia(b) + b.distancia(c) + c.distancia(a);
	}
}
