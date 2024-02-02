#pragma once
#ifndef _LISTA_H_
#define _LISTA_H_
using namespace std;

template<class T>
class No
{
private:
	T v;
	No* prox;
public:
	No(T v)
	{
		this->v = v;
		this->prox = NULL;
	}

	T obterValor()
	{
		return v;
	}

	No* obterProx()
	{
		return prox;
	}

	void setProx(No* p)
	{
		prox = p;
	}
};

template<class T>
class Lista
{
private:
	No<T> *cabeca;
	No<T> *cauda;
public:
	Lista()
	{
		cabeca = NULL;
		cauda = NULL;
	}

	Lista(T v)
	{
		cabeca = new No<T>(v);
		cauda = cabeca;
	}

	virtual ~Lista()
	{
		delete cabeca;
	}

	void mostrar()
	{
		cout << "Imprimindo todos os elementos...\n";
		No<T>* c = cabeca;

		if (vazia())
			cout << "A lista NAO possui elementos!!\n";
		else
		{
			while (c)
			{
				cout << c->obterValor() << endl;
				c = c->obterProx();
			}
			cout << endl;
		}
	}

	bool vazia()
	{
		return (cabeca == NULL);
	}

	void inserir_inicio(T v)
	{
		No<T>* novo_no = new No(v);
		novo_no->setProx(cabeca);
		cabeca = novo_no;
	}

	void inserir_final(T v)
	{
		No<T>* novo_no = new No<T>(v);

		if (vazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			cauda->setProx(novo_no);
			cauda = novo_no;
		}
	}

	T tamanho()
	{
		if (vazia())
			return 0;

		No<T>* c = cabeca;
		int tam = 0;
		do
		{
			c = c->obterProx();
			tam++;
		} while (c);
		return tam;
	}

	bool existe(T v)
	{
		No<T>* c = cabeca;
		while (c)
		{
			if (c->obterValor() == v)
				return true;
			c = c->obterProx();
		}
		return false;
	}

	void remover()
	{
		if (!vazia())
		{
			if (cabeca->obterProx() == NULL)
				cabeca = NULL;
			else if (cabeca->obterProx()->obterProx() == NULL)
				cabeca->setProx(NULL);
			else
			{
				No<T>* ant_ant = cabeca;
				No<T>* ant = cabeca->obterProx();
				No<T>* corrente = cabeca->obterProx()->obterProx();

				while (corrente)
				{
					No<T>* aux = ant;
					ant = corrente;
					ant_ant = aux;
					corrente = corrente->obterProx();
				}
				delete ant_ant->obterProx();
				ant_ant->setProx(NULL);
				cauda = ant_ant;
			}
		}
	}
};


#endif 