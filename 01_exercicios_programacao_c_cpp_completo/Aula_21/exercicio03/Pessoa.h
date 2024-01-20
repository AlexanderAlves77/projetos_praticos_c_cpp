/*
 * Pessoa.h
 *
 * Representa uma pessoa.
 *
 * Parte do exercício 3.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef PESSOA_H_
#define PESSOA_H_

#include <string>
using namespace std;

namespace exercicio03 {
	class Pessoa {
		string nome;
		int idade;
		double altura;

	public:
		Pessoa();
		Pessoa(const string& nome, int idade, double altura);

		const string& getNome() const;
		void setNome(const string& nome);
		int getIdade() const;
		void setIdade(int idade);
		double getAltura() const;
		void setAltura(double altura);

		~Pessoa() { }
	};
}
#endif
