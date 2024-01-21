/*
 * ContaCorrente.cpp
 *
 * Implementação de ContaCorrente.
 *
 * Parte do exercício 4.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include "ContaCorrente.h"

namespace exercicio05 {
	double ContaCorrente::getTaxaOperacao() {
		return 0.05;
	}

	void ContaCorrente::depositar(double quantia) {
		saldo += quantia;
	}

	void ContaCorrente::sacar(double quantia) {
		saldo -= quantia + getTaxaOperacao() * quantia;
	}

	double ContaCorrente::getSaldo() {
		return saldo;
	}
}
