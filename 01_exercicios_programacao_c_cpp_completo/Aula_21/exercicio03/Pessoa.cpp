/*
 * Pessoa.cpp
 *
 * Implementação de Pessoa.
 *
 * Parte do exercício 3.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include "Pessoa.h"

namespace exercicio03 {
	Pessoa::Pessoa() {
		nome = "Indefinido";
		idade = 0;
		altura = 0;
	}

	Pessoa::Pessoa(const string &nome, int idade, double altura) {
		this->nome = nome;
		this->idade = idade;
		this->altura = altura;
	}

	double Pessoa::getAltura() const {
		return altura;
	}

	void Pessoa::setAltura(double altura) {
		this->altura = altura;
	}

	int Pessoa::getIdade() const {
		return idade;
	}

	void Pessoa::setIdade(int idade) {
		this->idade = idade;
	}

	const string& Pessoa::getNome() const {
		return nome;
	}

	void Pessoa::setNome(const string& nome) {
		this->nome = nome;
	}
}
