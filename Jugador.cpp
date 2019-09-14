#include "Persona.cpp"

#ifndef JUGADOR_CPP
#define JUGADOR_CPP

using namespace std;


class Jugador: public Persona
{
	private:
		string numero;
		string posicion;
	
	public:
		Jugador(){}
		Jugador(string i, string nom, string ali, string ed, string num, string pos) : Persona(i,nom,ali,ed)
		{
			numero=num;
			posicion=pos;
		}
		Jugador(string num, string nom, string pos) : Persona(nom)
		{
			numero=num;
			posicion=pos;
		}
		void imprimir()
		{
			Persona::imprimir();
			cout<<"\tNumero: "<<numero<<"\tPosicion: "<<posicion;
		}
		string getNumero()
		{
			return numero;
		}
		string getPosicion()
		{
			return posicion;
		}
		
};


#endif
