class Tempo
{
private:
	int horas;									// quantidade de horas
	int minutos;								// quantidade de minutos

public:
	Tempo();									// construtor padr�o
	Tempo(int h, int m = 0);					// construtor com horas e minutos
	void Exibir() const;						// exibe tempo na tela

	Tempo operator+(const Tempo& t) const;		// retorna soma dos tempos
	const Tempo& operator+=(const Tempo& t);   // soma de tempo - b = (t += a);
	const Tempo & operator-=(const Tempo& t);  // subtra��o de tempo - b = (t += a);
};
