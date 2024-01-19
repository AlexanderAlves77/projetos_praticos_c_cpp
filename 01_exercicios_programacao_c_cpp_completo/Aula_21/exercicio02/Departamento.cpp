/*
 * Departamento.cpp
 *
 * Implementação de Departamento.
 *
 * Parte do exercício 2.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <iostream>
#include "Departamento.h"

namespace exercicio02 {
	Departamento::Departamento(const char* nome) {
		this->nome = nome;
		numFuncs = 0;
		cout << "Criado o departamento \"" << nome << "\"\n";
	}

	void Departamento::adicionar(Funcionario* funcionario) {
		funcionarios[numFuncs++] = funcionario;
		funcionario->departamento = this;
		cout << "Funcionário \"" << *funcionario << "\" adicionado ao departamento \"" << nome << "\"\n";
	}

	void Departamento::darAumento(double percentual) {
		cout << "Dando aumento de " << percentual << "% para todo funcionário do departamento \"" << nome << "\"\n";
		for (int i = 0; i < numFuncs; i++)
			funcionarios[i]->darAumento(percentual);
	}

	void Departamento::remover(Funcionario* funcionario) {
		int i, idx = -1;
		for (i = 0; i < numFuncs && idx == -1; i++)
			if (funcionarios[i] == funcionario)
				idx = i;

		if (idx != -1) {
			for (i = idx; i < numFuncs - 1; i++)
				funcionarios[i] = funcionarios[i + 1];
			funcionarios[i] = NULL;
			cout << "Funcionário \"" << *funcionario << "\" removido do departamento \"" << nome << "\"\n";
		}
	}

	ostream& operator<< (ostream &out, const Departamento &departamento) {
		return out << departamento.nome;
	}
}
