/*
 * Funcionario.cpp
 *
 * Implementação de Funcionario.
 *
 * Parte do exercício 2.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <iostream>
#include "Departamento.h"

namespace exercicio02 {
	Funcionario::Funcionario(const char* nome, double salario, const char* dataAdmissao) {
		this->nome = nome;
		this->salario = salario;
		this->dataAdmissao = dataAdmissao;
		cout << "Criado o funcionário \"" << nome << "\" ( salário: " << salario << "; admissão: " << dataAdmissao << ")\n";
	}

	void Funcionario::transferir(Departamento *departamento) {
		cout << "Transferindo " << nome << " para o departamento \"" << *departamento << "\"\n";
		this->departamento->remover(this);
		departamento->adicionar(this);
	}

	void Funcionario::darAumento(double percentual) {
		cout << "Dando aumento de " << percentual << "% para o funcionário \"" << nome << "\"\n";
		salario += salario * percentual / 100;
	}

	ostream& operator<< (ostream &out, const Funcionario &funcionario) {
		return out << funcionario.nome;
	}
}
