/*
 * Professor.h
 *
 * Representa um professor.
 *
 * Parte do exercício 4.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include <string>
#include "../exercicio03/Pessoa.h"
using namespace std;

namespace exercicio04 {
	class Professor: public exercicio03::Pessoa {
		string disciplina;

	public:
		Professor(const string& disciplina);
		Professor(const string& nome, int idade, double altura);
		const string& getDisciplina() const;
	};
}
#endif
