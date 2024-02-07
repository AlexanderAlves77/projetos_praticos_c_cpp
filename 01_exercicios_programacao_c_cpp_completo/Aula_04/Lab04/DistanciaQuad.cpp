#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

struct P { int x = 5, y = 8; } p;
struct Q { int x = 20, y = 4; } q;

/*
	Fôrmula 
	Distância = √(𝑄𝑥−𝑃𝑥)2+(𝑄𝑦−𝑃𝑦)2
*/ 
int main()
{
    //struct P p;
    //struct Q q;
    int Xquad = (q.x - p.x) * (q.x - p.x);
    int Yquad = (q.y - p.y) * (q.y - p.y);
	double distancia = sqrt(Xquad + Yquad);
	
	cout << "A distancia e: " << distancia << endl;
	
	return 0;
}