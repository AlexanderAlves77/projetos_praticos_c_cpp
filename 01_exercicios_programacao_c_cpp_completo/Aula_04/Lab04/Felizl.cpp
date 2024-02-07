#include <iostream> 
using namespace std; 

// ---------------------------------------
// protótipos

void feliz(void); 
void feriado(void); 

// ---------------------------------------
// função principal

int main() 
{ 
	cout << "Eu desejo a todos um ";    
	feliz();    
	feriado();    
	cout << "e um ";    
	cout << endl;

	return 0; 
}

// ---------------------------------------
// definição das funções auxiliares

void feliz(void) 
{ 
	cout << "Feliz "; 
}

void feriado(void) 
{ 
	cout << "Feriado "; 
}


// ---------------------------------------