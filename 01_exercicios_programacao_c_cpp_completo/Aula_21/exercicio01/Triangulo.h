/*
 * Triangulo.h
 *
 * Representa um triângulo no plano cartesiano.
 *
 * Parte do exercício 1.
 *
 *  Created on: Aug 9, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef TRIANGULO_H_
#define TRIANGULO_H_

#include "Ponto.h"

namespace exercicio01 {
	class Triangulo {
		Ponto a, b, c;

	public:
		/* Construtor que recebe as coordenadas dos pontos. */
		Triangulo(double xa, double ya, double xb, double yb, double xc, double yc);

		/* Calcula o perímetro do triângulo. */
		double perimetro() const;
	};
}

#endif
