/*
 * Ponto.h
 *
 * Representa um ponto no plano cartesiano.
 *
 * Parte do exercício 1.
 *
 *  Created on: Aug 9, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef PONTO_H_
#define PONTO_H_

namespace exercicio01 {
	class Ponto {
		/* Coordenadas (x, y) do ponto no plano cartesiano. */
		double x, y;

	public:
		/* Construtor que recebe as coordenadas. */
		Ponto(double _x = 0, double _y = 0);

		/* Calcula a distância entre dois pontos. */
		double distancia(const Ponto& ponto) const;
	};
}

#endif
