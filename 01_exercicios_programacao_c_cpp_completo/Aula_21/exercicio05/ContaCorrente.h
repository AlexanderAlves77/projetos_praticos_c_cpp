/*
 * ContaCorrente.h
 *
 * Representa uma conta-corrente.
 *
 * Parte do exercício 4.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef CONTACORRENTE_H_
#define CONTACORRENTE_H_

namespace exercicio05 {
	class ContaCorrente {
		double saldo;

	protected:
		double virtual getTaxaOperacao();

	public:
		ContaCorrente() { saldo = 0; }
		void depositar(double quantia);
		void sacar(double quantia);
		double getSaldo();
	};
}
#endif
