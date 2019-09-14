#include <vector>

#include "Director.cpp"
#include "Preparador.cpp"
#include "Medico.cpp"
#include "Jugador.cpp"

#ifndef EQUIPO_CPP
#define EQUIPO_CPP

using namespace std;


class Equipo
{
	private:
		string nombrePais;
		string slogan;
		Director *directorTecnico;
		Preparador *preparadorFisico;
		Medico *medico;
		vector<Jugador*> jugadores;
		
	
	public:
		Equipo(){}
		Equipo(string nomPa, string sl, Director *dir, Preparador *prep, Medico *med)
		{
			nombrePais=nomPa;
			slogan=sl;
			directorTecnico=dir;
			preparadorFisico=prep;
			medico=med;
		}
		Equipo(string nomPa, Director *dir, Preparador *prep, Medico *med)
		{
			nombrePais=nomPa;
			directorTecnico=dir;
			preparadorFisico=prep;
			medico=med;
		}
		void addJugadores(vector<Jugador*> nuevos)
		{
			for(int x=0;x<nuevos.size();x++)
				jugadores.push_back(nuevos.at(x));
			
		}
		string getPais()
		{
			return nombrePais;
		}
		Director* getDirector()
		{
			return directorTecnico;
		}
		Preparador* getPreparador()
		{
			return preparadorFisico;
		}
		Medico* getMedico()
		{
			return medico;
		}
		vector<Jugador*> getJugadores()
		{
			return jugadores;
		}
		
};


#endif
