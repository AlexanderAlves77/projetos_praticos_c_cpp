#include <iostream>
// A diretiva de pré-processador #include
// indica para incluir o arquivo de cabeçalho
// iostream

int main()
// função principal. Todo o programa C++ começa
// com está função principal main()
{ // indica início de um bloco
	// cout comando de saída de dados
	// endl indica para inserir um caracter de quebra de linha na frase
	// string tem que está em entre aspas duplas
	std::cout << "Primeiro Codigo" << std::endl;
	system("PAUSE");
	// system pause chama o shell do windows (DOS) 
	// e coloca este comando PAUSE
	return 0;
	// retorna para o sistema operacional zero
	// zero é o padrão para informar que tudo deu certo
	// assim se a função main der certo ela retornará 0
} // indica o final de um bloco

// CTRL + SHIFT + B - Compilar o código fonte
// CTRL + F5 - Executar o programa
// ALT + SHIFT + <ENTER> Maximizar/Minimizar Janela
// CTRL + K + C - Comentar o código que selecionou
// CTRL + C no final da linha - Cópia ela toda sem precisar selecionar