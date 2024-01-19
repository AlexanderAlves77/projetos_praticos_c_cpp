/*
 * Empresa.h
 *
 * Representa uma empresa.
 *
 * Parte do exercício 2.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef EMPRESA_H_
#define EMPRESA_H_

#include <string>
#include "Departamento.h"
using namespace std;

namespace exercicio02 {
	class Empresa {
		string nome;
		string cnpj;
		Departamento* departamentos[10];
		int numDeps;

	public:
		Empresa(const char* nome, const char* cnpj);
		void adicionar(Departamento* departamento);
		void darAumento(double percentual);
		friend ostream& operator<< (ostream &out, const Empresa &empresa);
	};
}

#endif
