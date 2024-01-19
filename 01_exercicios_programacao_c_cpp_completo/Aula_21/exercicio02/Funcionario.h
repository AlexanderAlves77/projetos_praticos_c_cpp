/*
 * Representa um funcionário de uma empresa.
 *
 * Parte do exercício 2.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include <string>
using namespace std;

namespace exercicio02 {
	/* Declaração antecipada da classe Departamento para evitar dependência circular. */
	class Departamento;

	class Funcionario {
		string nome;
		double salario;
		string dataAdmissao;
		Departamento* departamento;

		friend class Departamento;

	public:
		Funcionario(const char* nome, double salario, const char* dataAdmissao);
		void transferir(Departamento *departamento);
		void darAumento(double percentual);
		friend ostream& operator<< (ostream &out, const Funcionario &funcionario);
	};
}

#endif
