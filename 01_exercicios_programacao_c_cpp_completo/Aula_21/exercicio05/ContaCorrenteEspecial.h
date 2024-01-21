/*
 * ContaCorrenteEspecial.h
 *
  * Representa uma conta-corrente especial.
 *
 * Parte do exercício 4.
 *
 *  Created on: Aug 12, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef CONTACORRENTEESPECIAL_H_
#define CONTACORRENTEESPECIAL_H_

#include "ContaCorrente.h"

namespace exercicio05 {
	class ContaCorrenteEspecial: public exercicio05::ContaCorrente {
		protected:
			double virtual getTaxaOperacao();
	};
}
#endif
