#pragma once
#include <iostream>
using namespace std;

namespace Listas
{
	template<class TL>
	class Lista
	{
	private:

		template<class TE>
		class Elemento
		{
		private:
			Elemento<TE>* pProx;
			TE* pInfo;

		public:
			Elemento()
			{
				pProx = nullptr; pInfo = nullptr;
			}

			~Elemento()
			{
				pProx = nullptr; pInfo = nullptr;
			}

			void setProximo(Elemento<TE>* pEl)
			{
					pProx = pEl;
			}

			void setInfo(TE* inf)
			{
				pInfo = inf;
			}

			Elemento<TE>* getProx() const
			{
				return pProx;
			}

			TE* getInfo() const
			{
				return pInfo;
			}
		};

		Elemento<TL>* pPrim;
		Elemento<TL>* pUlt;

		public:

			class Iterador
			{
			private:
				Elemento<TL>* pEl;

			public:
				Iterador(Elemento<TL>* pEl = nullptr)
				{
					this->pEl = pEl;
				}

				~Iterador()
				{
					pEl = nullptr;
				}

				Iterador& operator++()
				{
					if (pEl != nullptr)
					{
						pEl = pEl->getProx();
					}
					return *this;
				}

				TL* operator*()
				{
					if (pEl != nullptr)
					{
						return pEl->getInfo();
					}
					else
					{
						return nullptr;
					}
				}

				bool isNulo() const
				{
					return (pEl == nullptr);
				}
			};

			Lista();
			~Lista();
			void incluir(TL* pTp);
			void limpaLista();
			Iterador getInicio() const
			{
				return Iterador(pPrim);
			}
	};
	template <class TL>
	Lista<TL>::Lista()
	{
		pPrim = nullptr; pUlt = nullptr;
	}

	template <class TL>
	Lista<TL>::~Lista()
	{
		limpaLista();
	}


	template<class TL>
	void Lista<TL>::incluir(TL* pTp)
	{
		if (pTp != nullptr)
		{
			Elemento<TL>* pEl = new Elemento<TL>;
			if (pEl != nullptr)
			{
				pEl->setInfo(pTp);
				if (pPrim == nullptr)
				{
					pPrim = pEl;
					pUlt = pEl;
				}
				else
				{
					pUlt->setProximo(pEl);
					pUlt = pEl;
				}
			}
			else
				cout << "Erro ao incluir elemento na lista (ponteiro para elemento nulo)" << endl;
		}
		else
			cout << "Erro ao incluir elemento na lista (objeto nulo)" << endl;
		}

	template<class Tl>
	void Lista<Tl>::limpaLista()
	{
		Elemento<Tl>* pEl = pPrim;
		Elemento<Tl>* pElAux;
		while (pEl != nullptr)
		{
			pElAux = pEl->getProx();
			delete pEl;
			pEl = pElAux;
		}
		pPrim = nullptr;
		pUlt = nullptr;
	}
}
