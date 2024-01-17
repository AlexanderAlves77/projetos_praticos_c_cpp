#include <iostream>
#include "Triangulo.h"
using namespace std;

namespace exercicio01 {
	void main() {
		double x1, y1, x2, y2, x3, y3;

		// Lê as coordenadas.
		cout << "Informe as coordenadas (x1, y1), (x2, y2) e (x3, y3) dos vértices do triângulo\n";
		cout << "x1 = "; cin >> x1;
		cout << "y1 = "; cin >> y1;
		cout << "x2 = "; cin >> x2;
		cout << "y2 = "; cin >> y2;
		cout << "x3 = "; cin >> x3;
		cout << "y3 = "; cin >> y3;

		// Cria o triangulo, calcula e exibe seu perímetro.
		Triangulo tri(x1, y1, x2, y2, x3, y3);
		cout << "O perímetro do triângulo é " << tri.perimetro();
	}
}
