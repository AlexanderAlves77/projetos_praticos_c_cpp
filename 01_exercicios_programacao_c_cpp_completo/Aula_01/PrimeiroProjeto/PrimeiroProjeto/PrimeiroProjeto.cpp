#include <iostream>
// A diretiva de pr�-processador #include
// indica para incluir o arquivo de cabe�alho
// iostream

int main()
// fun��o principal. Todo o programa C++ come�a
// com est� fun��o principal main()
{ // indica in�cio de um bloco
	// cout comando de sa�da de dados
	// endl indica para inserir um caracter de quebra de linha na frase
	// string tem que est� em entre aspas duplas
	std::cout << "Primeiro Codigo" << std::endl;
	system("PAUSE");
	// system pause chama o shell do windows (DOS) 
	// e coloca este comando PAUSE
	return 0;
	// retorna para o sistema operacional zero
	// zero � o padr�o para informar que tudo deu certo
	// assim se a fun��o main der certo ela retornar� 0
} // indica o final de um bloco

// CTRL + SHIFT + B - Compilar o c�digo fonte
// CTRL + F5 - Executar o programa
// ALT + SHIFT + <ENTER> Maximizar/Minimizar Janela
// CTRL + K + C - Comentar o c�digo que selecionou
// CTRL + C no final da linha - C�pia ela toda sem precisar selecionar