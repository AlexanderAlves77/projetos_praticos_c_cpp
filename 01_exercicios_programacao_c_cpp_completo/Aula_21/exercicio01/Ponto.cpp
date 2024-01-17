/*
 * Ponto.cpp
 *
 * Implementação da classe Ponto.
 *
 * Parte do exercício 1.
 *
 *  Created on: Aug 9, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <cmath>
#include "Ponto.h"
using namespace std;

namespace exercicio01 {
	Ponto::Ponto(double _x, double _y) {
		x = _x; y = _y;
	}

	double Ponto::distancia(const Ponto& ponto) const {
		double difX = ponto.x - x;
		double difY = ponto.y - y;
		return sqrt(difX * difX + difY * difY);
	}
}
