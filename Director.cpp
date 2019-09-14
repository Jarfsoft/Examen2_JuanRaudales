#include "Persona.cpp"

#ifndef DIRECTOR_CPP
#define DIRECTOR_CPP

using namespace std;


class Director: public Persona
{
	private:
		string aniosExperiencia;
		string numeroTitulos;
	
	public:
		Director(){}
		Director(string i, string nom, string ali, string ed, string an, string num) : Persona(i,nom,ali,ed)
		{
			aniosExperiencia=an;
			numeroTitulos=num;
		}
		Director(string nom,string num) : Persona(nom)
		{
			numeroTitulos=num;
		}
		void imprimir()
		{
			cout<<"Director\t";
			Persona::imprimir();
			cout<<"\tNumero de titulos: "<<numeroTitulos;
		}
		string getNumeroTitulos()
		{
			return numeroTitulos;
		}
		
};


#endif
