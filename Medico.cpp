#include "Persona.cpp"

#ifndef MEDICO_CPP
#define MEDICO_CPP

using namespace std;


class Medico: public Persona
{
	private:
		string especialidad;
	
	public:
		Medico(){}
		Medico(string i, string nom, string ali, string ed, string esp) : Persona(i,nom,ali,ed)
		{
			especialidad=esp;
		}
		Medico(string nom, string esp) : Persona(nom)
		{
			especialidad=esp;
		}
		void imprimir()
		{
			cout<<"Medico\t";
			Persona::imprimir();
			cout<<"\tEspecialidad: "<<especialidad;
		}
		string getEspecialidad()
		{
			return especialidad;
		}
		
	
		
};


#endif
