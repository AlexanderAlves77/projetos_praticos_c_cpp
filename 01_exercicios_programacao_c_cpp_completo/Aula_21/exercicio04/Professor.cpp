/*
 * Professor.cpp
 *
 * Implementação de professor.
 *
 * Parte do exercício 4.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include "Professor.h"

namespace exercicio04 {
	Professor::Professor(const string& disciplina) {
		this->disciplina = disciplina;
	}

	Professor::Professor(const string& nome, int idade, double altura): Pessoa(nome, idade, altura) { }

	const string& Professor::getDisciplina() const {
		return disciplina;
	}
}
