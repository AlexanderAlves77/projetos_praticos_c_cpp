#include <iostream>
#include <string>
#include "Forma.h"
#include "Quadrado.h"
#include "Retangulo.h"
#include "Circulo.h"
using namespace std;

namespace exercicio07 {
	void main() {
		cout << "Quantas formas deseja criar?\n";
		int qtd;
		cin >> qtd;
		Forma** formas = new Forma*[qtd];

		int i = 0;
		while (i < qtd) {
			cout << "Que forma deseja criar: [Q]uadrado; [R]etângulo; [C]írculo?\n";
			char escolha;
			cin >> escolha;

			switch(escolha) {
			case 'q': case 'Q':
				cout << "Digite o tamanho do lado: ";
				double lado;
				cin >> lado;
				formas[i++] = new Quadrado(lado);
				break;

			case 'r': case 'R':
				cout << "Digite o tamanho da base e da altura: ";
				double base, altura;
				cin >> base >> altura;
				formas[i++] = new Retangulo(base, altura);
				break;

			case 'c': case 'C':
				cout << "Digite o tamanho do raio: ";
				double raio;
				cin >> raio;
				formas[i++] = new Circulo(raio);
				break;

			default:
				cout << "Opção inválida.\n";
			}
		}

		cout << "\nFormas criadas:\n";
		for (i = 0; i < qtd; i++) cout << i << " - " << (formas[i]) << ";\n";

		cout << "\nPerímetros das formas:\n";
		for (i = 0; i < qtd; i++) cout << i << " - " << formas[i]->calcularPerimetro() << ";\n";

		cout << "\nÁreas das formas:\n";
		for (i = 0; i < qtd; i++) cout << i << " - " << formas[i]->calcularArea() << ";\n";
	}
}
