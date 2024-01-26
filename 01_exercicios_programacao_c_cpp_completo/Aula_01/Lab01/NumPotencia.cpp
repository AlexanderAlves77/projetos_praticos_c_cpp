#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int nPower(int n, int x)
{
    int count = 1;
    if (x <= 0)
        return count;
    for (int i = 0; i < x; i++) 
        count = count * n;
    return count;
}

int main () 
{
  cout << "Exponiacao de 3 elevado a 8 e: " << nPower(3, 8);  
  return 0;
}