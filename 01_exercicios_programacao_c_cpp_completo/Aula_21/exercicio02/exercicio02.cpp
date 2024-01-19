#include <iostream>
#include "Empresa.h"
#include "Departamento.h"
#include "Funcionario.h"
using namespace std;

namespace exercicio02 {
	void main() {
		Empresa* empresa = new Empresa("Prog3 S.A.", "00.000.000/0001-00");

		Departamento* rh = new Departamento("RH");
		empresa->adicionar(rh);

		Departamento* ti = new Departamento("TI");
		empresa->adicionar(ti);

		Funcionario* ana = new Funcionario("Ana", 2500, "01/06/2013");
		rh->adicionar(ana);
		Funcionario* bruno = new Funcionario("Bruno", 2500, "02/06/2013");
		rh->adicionar(bruno);
		Funcionario* carla = new Funcionario("Carla", 4000, "01/05/2013");
		rh->adicionar(carla);

		Funcionario* daniel = new Funcionario("Daniel", 4000, "01/05/2013");
		ti->adicionar(daniel);
		Funcionario* elisa = new Funcionario("Elisa", 3000, "15/05/2013");
		ti->adicionar(elisa);

		empresa->darAumento(10);

		ana->transferir(ti);
	}
}
