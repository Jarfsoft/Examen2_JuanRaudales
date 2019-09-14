#include "Equipo.cpp"

#ifndef GRUPO_CPP
#define GRUPO_CPP

using namespace std;


class Grupo
{
	private:
		string nombre;
		string ciudad;
		string estadio;
		vector<Equipo*> equipos;
	
	public:
		Grupo(){}
		Grupo(string nom, string ciu, string est)
		{
			nombre=nom;
			ciudad=ciu;
			estadio=est;
		}
		void addEquipo(Equipo* nuevo)
		{
			equipos.push_back(nuevo);
		}
		string getNombre()
		{
			return nombre;
		}
		vector<Equipo*> getEquipos()
		{
			return equipos;
		}
		string getEstadio()
		{
			return estadio;
		}
		string getCiudad()
		{
			return ciudad;
		}
		
};


#endif
