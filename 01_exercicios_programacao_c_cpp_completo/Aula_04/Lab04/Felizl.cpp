#include <iostream> 
using namespace std; 

// ---------------------------------------
// prot�tipos

void feliz(void); 
void feriado(void); 

// ---------------------------------------
// fun��o principal

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
// defini��o das fun��es auxiliares

void feliz(void) 
{ 
	cout << "Feliz "; 
}

void feriado(void) 
{ 
	cout << "Feriado "; 
}


// ---------------------------------------