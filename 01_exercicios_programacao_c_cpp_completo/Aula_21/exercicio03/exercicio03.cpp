#include <string>
#include <iostream>
#include "Pessoa.h"
using namespace std;

namespace exercicio03 {
	typedef struct TNo {
		Pessoa *pessoa;
		struct TNo* prox;
	} No;

	No *pri = NULL;
	No *ult = NULL;

	void cadastrarPessoa() {
		string nome;
		int idade;
		double altura;

		cout << "Nome: ";
		getline(cin, nome);
		cout << "Idade: ";
		cin >> idade;
		cout << "Altura: ";
		cin >> altura;

		Pessoa *pessoa = new Pessoa(nome, idade, altura);
		No *no = new No;
		no->pessoa = pessoa;
		no->prox = NULL;

		if (pri == NULL) pri = ult = no;
		else {
			ult->prox = no;
			ult = no;
		}
	}

	void listarPessoas() {
		No *no = pri;
		int i = 1;
		while (no != NULL) {
			Pessoa *p = no->pessoa;
			cout << (i++) << ": " << p->getNome() << ", " << p->getIdade() << " ano(s), " << p->getAltura() << "m de altura\n";
			no = no->prox;
		}
	}

	void main() {
		char comando = ' ';
		string enter;
		cout << "Cadastro de pessoas:\n\nDigite 'C' para cadastrar, 'L' para limpar, 'S' para sair.\n";

		while (comando != 'S') {
			cout << "\n> ";
			cin >> comando;
			getline(cin, enter);

			switch (comando) {
			case 'C':
				cadastrarPessoa();
				break;

			case 'L':
				listarPessoas();
				break;
			}
		}
	}
}
