/*
 * Empresa.cpp
 *
 * Implementação de Empresa.
 *
 * Parte do exercício 2.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <iostream>
#include "Empresa.h"

namespace exercicio02 {
	Empresa::Empresa(const char* nome, const char* cnpj) {
		this->nome = nome;
		this->cnpj = cnpj;
		numDeps = 0;
		cout << "Criada a empresa \"" << nome << "\" (CNPJ " << cnpj << ")\n";
	}

	void Empresa::adicionar(Departamento* departamento) {
		departamentos[numDeps++] = departamento;
		cout << "Departamento \"" << *departamento << "\" adicionado à empresa \"" << nome << "\"\n";
	}

	void Empresa::darAumento(double percentual) {
		cout << "Dando aumento de " << percentual << "% para todo funcionário da empresa \"" << nome << "\"\n";
		for (int i = 0; i < numDeps; i++)
			departamentos[i]->darAumento(percentual);
	}

	ostream& operator<< (ostream &out, const Empresa &empresa) {
		return out << empresa.nome;
	}
}
