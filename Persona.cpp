#include <iostream>

#ifndef PERSONA_CPP
#define PERSONA_CPP

using namespace std;


class Persona
{
	private:
		string id;
		string nombre;
		string alias;
		string edad;
	
	public:
		Persona(){}
		Persona(string i, string nom, string ali, string ed)
		{
			id=i;
			nombre=nom;
			alias=ali;
			edad=ed;
		}
		Persona(string nom)
		{
			nombre=nom;
		}
		virtual void imprimir()
		{
			cout<<"Nombre: "<<nombre;
		}
		string getNombre()
		{
			return nombre;
		}
		
};


#endif
