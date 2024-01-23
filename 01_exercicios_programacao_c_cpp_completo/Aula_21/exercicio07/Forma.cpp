/*
 * Forma.cpp
 *
 * Implementação de Forma.
 *
 * Parte do exercício 7.
 *
 *  Created on: Aug 14, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <iostream>
#include "Forma.h"
using namespace std;

namespace exercicio07 {
	ostream& operator<< (ostream &out, const Forma *forma) {
		forma->print(out);
		return out;
	}
}
