#include <string>
#include <iostream>
#include "Professor.h"
using namespace std;

namespace exercicio04 {
	void main() {
		Professor p1("Prog3");
		Professor p2("Vítor Souza", 32, 1.78);

		cout << "p1 = " << p1.getNome() << " (idade: " << p1.getIdade() << "; altura: " << p1.getAltura() << "; disciplina: " << p1.getDisciplina() << ")\n";
		cout << "p2 = " << p2.getNome() << " (idade: " << p2.getIdade() << "; altura: " << p2.getAltura() << "; disciplina: " << p2.getDisciplina() << ")\n";
	}
}
