#include <iostream>
#include "ContaCorrente.h"
#include "ContaCorrenteEspecial.h"
using namespace std;

namespace exercicio05 {
	void main() {
		ContaCorrente conta;
		conta.depositar(1000);
		conta.sacar(100);
		cout << "Conta normal, após depositar R$ 1.000 e sacar R$ 100 o saldo é de R$ " << conta.getSaldo() << '\n';

		ContaCorrenteEspecial especial;
		especial.depositar(1000);
		especial.sacar(100);
		cout << "Conta especial, após depositar R$ 1.000 e sacar R$ 100 o saldo é de R$ " << especial.getSaldo() << '\n';
	}
}
