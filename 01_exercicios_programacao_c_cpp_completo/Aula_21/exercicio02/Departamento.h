/*
 * Departamento.h
 *
 * Representa um departamento de uma empresa.
 *
 * Parte do exercício 2.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef DEPARTAMENTO_H_
#define DEPARTAMENTO_H_

#include <string>
#include "Funcionario.h"
using namespace std;

namespace exercicio02 {
	class Departamento {
		string nome;
		Funcionario* funcionarios[100];
		int numFuncs;

	public:
		Departamento(const char* nome);
		void adicionar(Funcionario* funcionario);
		void darAumento(double percentual);
		void remover(Funcionario* funcionario);
		friend ostream& operator<< (ostream &out, const Departamento &departamento);
	};
}

#endif
