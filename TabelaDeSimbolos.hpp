#include <iostream>
#include <list>
#include <string>
#include <utility>

#include "Simbolo.hpp"
#include "Token.hpp"

using namespace std;

class TabelaDeSimbolos {
	private:
		list< pair<Simbolo, string> > elementos;
	public:
		void add(Simbolo simbolo);
		void imprimir(void);
};

void TabelaDeSimbolos::add(Simbolo simbolo) {
	pair<Simbolo, string> par(simbolo, Token::getToken(simbolo.getLexema()));
	elementos.push_back(par);
}

void TabelaDeSimbolos::imprimir(void) {
	cout << "LINHA\tLEXEMA\t\tTOKEN";
	
	for (list< pair<Simbolo, string> >::iterator i = elementos.begin();
			i != elementos.end(); ++i) {
				
		cout << endl << (*i).first.getNumeroLinha() << "\t";
		cout << (*i).first.getLexema() << "\t";
		cout << (*i).second;
	}
}
