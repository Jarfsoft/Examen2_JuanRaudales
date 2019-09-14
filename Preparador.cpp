#include "Persona.cpp"

#ifndef PREPARADOR_CPP
#define PREPARADOR_CPP

using namespace std;


class Preparador: public Persona
{
	private:
		string carrera;
	
	public:
		Preparador(){}
		Preparador(string i, string nom, string ali, string ed, string carr) : Persona(i,nom,ali,ed)
		{
			carrera=carr;
		}
		Preparador(string nom, string carr) : Persona(nom)
		{
			carrera=carr;
		}
		void imprimir()
		{
			cout<<"Preparador\t";
			Persona::imprimir();
			cout<<"\tCarrera: "<<carrera;
		}
		string getCarrera()
		{
			return carrera;
		}
	
		
};


#endif
