#include "Grupo.cpp"

#include <fstream>
#include <string.h>
#include <windows.h>
#include <conio.h>

using namespace std;

string token(string cadena, string divisor, int pos);
vector<string> getGrupos(string);
vector<string> getCiudades(string, vector<string>);
vector<string> getEstadios(string, vector<string>);
vector<string> getNombresJugadores(string);
vector<string> getNumeroJugadores(string);
vector<string> getPosicionesJugadores(string);
int numeroChars(string, char);

int main(int argc, char** argv)
{
	int opcion=0;
	
	vector<Grupo*> grupos;
	
	while(opcion!=7)
	{
		cout<<"****************Mundial RUSIA 2018****************\n\n1. Importar datos del archivo\n2. Listar grupos y sus equipos\n3. Ver detalle de equipo\n4. Agregar equipo a grupo\n5. Eliminar equipo\n6. Guardar los datos del programa\n7. Salir\n\nSeleccion: ";
		cin>>opcion;
		if(opcion==1)
		{
			vector<string> nombresGrupos;
			nombresGrupos = getGrupos("./Examen II.txt");
			vector<string> nombresCiudades;
			nombresCiudades = getCiudades("./Examen II.txt",nombresGrupos);
			vector<string> nombresEstadios;
			nombresEstadios = getEstadios("./Examen II.txt",nombresGrupos);
			Grupo* nuevoGrupo;
			
			for(int x=0;x<nombresGrupos.size();x++)
			{
				nuevoGrupo= new Grupo(nombresGrupos.at(x), nombresCiudades.at(x), nombresEstadios.at(x));
				grupos.push_back(nuevoGrupo);
			}
			
			fstream Leer;
			string linea;
			
			vector<string> nombres;
			vector<string> numeros;
			vector<string> posiciones;
			
			vector<Jugador*> jugadores;
			Jugador *nuevoJugador;
			
			vector<Equipo*> equipos;
			Equipo *nuevoEquipo;
			
			string pais;
			
			Director *nuevoDirector;
			
			Preparador *nuevoPreparador;
			
			Medico *nuevoMedico;
			
			
			Leer.open("./Examen II.txt");
			while(!Leer.eof())
			{
				getline(Leer,linea);
				nombres = getNombresJugadores(token(linea,"|",3));
				numeros = getNumeroJugadores(token(linea,"|",3));
				posiciones = getPosicionesJugadores(token(linea,"|",3));
				
				pais=token(token(linea,"|",2),";",2);
				
				for(int y=0;y<nombres.size();y++)
				{
					nuevoJugador=new Jugador(numeros.at(y),nombres.at(y),posiciones.at(y));
					jugadores.push_back(nuevoJugador);
				}
				
				nuevoDirector = new Director(token(token(token(linea,"|",4),":",1),",",2),  token(token(token(token(linea,"|",4),":",1),",",3),"#",2));
				nuevoPreparador = new Preparador(token(token(token(linea,"|",4),":",2),",",2), token(token(token(token(linea,"|",4),":",2),",",3),"#",2));
				nuevoMedico = new Medico(token(token(token(linea,"|",4),":",3),",",2), token(token(token(token(linea,"|",4),":",3),",",3),"#",2));
				
				nuevoEquipo = new Equipo(pais,nuevoDirector,nuevoPreparador,nuevoMedico);
				
				nuevoEquipo->addJugadores(jugadores);
				
				for(int y=0;y<grupos.size();y++)
					if(grupos.at(y)->getNombre()==token(token(linea,"|",2),";",1))
					{
						grupos.at(y)->addEquipo(nuevoEquipo);
						break;
					}
				
				nombres.clear();
				numeros.clear();
				posiciones.clear();
				jugadores.clear();
			}
			
			Leer.close();
			
		}
		if(opcion==2)
		{
			cout<<"\n\n\n";
			for(int x=0;x<grupos.size();x++)
			{
				Sleep(500);
				cout<<grupos.at(x)->getNombre();
				cout<<"\n\n";
				Sleep(1000);
				for(int y=0;y<grupos.at(x)->getEquipos().size();y++)
				{
					cout<<"\tPais: "<<grupos.at(x)->getEquipos().at(y)->getPais()<<endl;
					Sleep(500);
					cout<<"\t"; grupos.at(x)->getEquipos().at(y)->getDirector()->imprimir();
					Sleep(500);
					cout<<endl<<"\t"; grupos.at(x)->getEquipos().at(y)->getPreparador()->imprimir();
					Sleep(500);
					cout<<endl<<"\t"; grupos.at(x)->getEquipos().at(y)->getMedico()->imprimir();
					Sleep(500);
					cout<<endl<<"\tJugadores: ";
					cout<<"\n\n";
					Sleep(500);
					for(int z=0;z<grupos.at(x)->getEquipos().at(y)->getJugadores().size();z++)
					{
						cout<<"\t\t"; grupos.at(x)->getEquipos().at(y)->getJugadores().at(z)->imprimir();
						cout<<endl;
						Sleep(250);
					}
					cout<<"\n\n";
				}
				cout<<"\n\n\n";
			}
		}
		if(opcion==3)
		{
			cout<<"\n\n";
			if(grupos.size()==0)
			{
				cout<<"Importe los datos primero.";
			}else
			{
				for(int x=0;x<grupos.size();x++)
				{
					cout<<x+1<<". "<<grupos.at(x)->getNombre()<<endl;
				}
				cout<<"\nSeleccione el numero del grupo: ";
				cin>>opcion;
				opcion--;
				int opcion2;
				
				cout<<"\n\n";
				for(int x=0;x<grupos.at(opcion)->getEquipos().size();x++)
				{
					cout<<x+1<<". "<<grupos.at(opcion)->getEquipos().at(x)->getPais()<<endl;
				}
				cout<<"\nSeleccione el numero de pais: ";
				cin>>opcion2;
				opcion2--;
				
				cout<<"\n\nNombre: "<<grupos.at(opcion)->getNombre()<<"\nEstadio: "<<grupos.at(opcion)->getEstadio()<<"\nEquipo: "<<endl;
				cout<<"\t"; grupos.at(opcion)->getEquipos().at(opcion2)->getDirector()->imprimir();
				Sleep(500);
				cout<<endl<<"\t"; grupos.at(opcion)->getEquipos().at(opcion2)->getPreparador()->imprimir();
				Sleep(500);
				cout<<endl<<"\t"; grupos.at(opcion)->getEquipos().at(opcion2)->getMedico()->imprimir();
				Sleep(500);
				cout<<endl<<"\tJugadores: ";
				cout<<"\n\n";
				Sleep(500);
				for(int z=0;z<grupos.at(opcion)->getEquipos().at(opcion2)->getJugadores().size();z++)
				{
					cout<<"\t\t"; grupos.at(opcion)->getEquipos().at(opcion2)->getJugadores().at(z)->imprimir();
					cout<<endl;
					Sleep(250);
				}
				
			}
			
			opcion=0;
		}
		if(opcion==4)
		{
			string pa, nomDir, numTit, nomPrep, carr, nomMed, esp, nomJug, num, pos;
			cout<<"\n\nNombre del pais: ";
			cin>>pa;
			cout<<"Nombre del director tecnico: ";
			cin>>nomDir;
			cout<<"Numero de titulos: ";
			cin>>numTit;
			cout<<"Nombre del preparador fisico: ";
			cin>>nomPrep;
			cout<<"Carrera: ";
			cin>>carr;
			cout<<"Nombre del medico: ";
			cin>>nomMed;
			cout<<"Especialidad: ";
			cin>>esp;
			cout<<"Cantidad de jugadores que va a agregar: ";
			cin>>opcion;
			vector<Jugador*> nuevosJugadores;
			Jugador* nuevoJugador;
			for(int x=0;x<opcion;x++)
			{
				cout<<"Nombre del jugador: ";
				cin>>nomJug;
				cout<<"Numero: ";
				cin>>num;
				cout<<"Posicion: ";
				cin>>pos;
				nuevoJugador= new Jugador(num,nomJug,pos);
				nuevosJugadores.push_back(nuevoJugador);
			}
			
			Director* nueDir = new Director(nomDir,numTit);
			Preparador* nuePre = new Preparador(nomPrep,carr);
			Medico* nueMed = new Medico(nomMed, esp);
			Equipo* nuevo = new Equipo(pa,nueDir,nuePre,nueMed);
			nuevo->addJugadores(nuevosJugadores);
			cout<<"\n\n";
			for(int x=0;x<grupos.size();x++)
			{
				cout<<x+1<<". "<<grupos.at(x)->getNombre()<<endl;
			}
			cout<<"\nSeleccione el numero del grupo a agregar: ";
			cin>>opcion;
			opcion--;
			grupos.at(opcion)->addEquipo(nuevo);
			
			cout<<"\n\nEquipo agregado existosamente.\n\n";
			
			opcion=0;
		}
		if(opcion==5)
		{
			for(int x=0;x<grupos.size();x++)
			{
				cout<<x+1<<". "<<grupos.at(x)->getNombre()<<endl;
			}
			cout<<"\nSeleccione el numero del grupo a eliminar: ";
			cin>>opcion;
			opcion--;
			
			grupos.erase(grupos.begin()+opcion);
		}
		if(opcion==6)
		{
			ofstream Escribir;
			Escribir.open("./Examen II.txt");
			for(int x=0;x<grupos.size();x++)
			{
				for(int y=0;y<grupos.at(x)->getEquipos().size();y++)
				{
					Escribir<<grupos.at(x)->getCiudad()+","<<grupos.at(x)->getEstadio()+"|"+grupos.at(x)->getNombre()+";"+grupos.at(x)->getEquipos().at(y)->getPais()+"|";
					for(int z=0;z<grupos.at(x)->getEquipos().at(y)->getJugadores().size();z++)
					{
						if(z!=grupos.at(x)->getEquipos().at(y)->getJugadores().size()-1)
							Escribir<<grupos.at(x)->getEquipos().at(y)->getJugadores().at(z)->getNumero()+","+grupos.at(x)->getEquipos().at(y)->getJugadores().at(z)->getNombre()+","+grupos.at(x)->getEquipos().at(y)->getJugadores().at(z)->getPosicion()+":";
						else
							Escribir<<grupos.at(x)->getEquipos().at(y)->getJugadores().at(z)->getNumero()+","+grupos.at(x)->getEquipos().at(y)->getJugadores().at(z)->getNombre()+","+grupos.at(x)->getEquipos().at(y)->getJugadores().at(z)->getPosicion()+"|";
					}
					Escribir<<"Director Tecnico,"+grupos.at(x)->getEquipos().at(y)->getDirector()->getNombre()+",titulos_ganados#"+grupos.at(x)->getEquipos().at(y)->getDirector()->getNumeroTitulos()+":";
					Escribir<<"Preparador Fisico,"+grupos.at(x)->getEquipos().at(y)->getPreparador()->getNombre()+",carrera#"+grupos.at(x)->getEquipos().at(y)->getPreparador()->getCarrera()+":";
					Escribir<<"Medico,"+grupos.at(x)->getEquipos().at(y)->getMedico()->getNombre()+",especialidad#"+grupos.at(x)->getEquipos().at(y)->getMedico()->getEspecialidad()<<endl;
				}
					
			}
			Escribir.close();
		}
	
	
		cout<<"\n\n";
	}
	
	return 0;
}


string token(string cadena, string divisor, int pos)
{
       if(cadena.size()>0){
         char oracion[cadena.size()]; 
         for (int i=0;i<=cadena.size();i++)
         {
               oracion[i]=cadena[i];
         }                    
         char *ptrtoken; 
         int num=1;
         const char* d=divisor.c_str();
         ptrtoken = strtok(oracion , d);             
         while(ptrtoken){
             if(num==pos){ 
                return ptrtoken;                    
             }                 
             ptrtoken = strtok(NULL, d);
             num++;
         }
         return "";
       }else{
             return "";
       }
}


vector<string> getGrupos(string archivo)
{
	string linea,gruPa,grup;
	fstream Leer;
	Leer.open(archivo.c_str());
	vector<string> grupos;
	bool esta;
	while(!Leer.eof())
	{
		esta=false;
		getline(Leer,linea);
		gruPa=token(linea,"|",2);
		grup=token(gruPa,";",1);
		
		for(int x=0;x<grupos.size();x++)
			if(grupos.at(x)==grup)
				esta=true;
				
		if(!esta)
			grupos.push_back(grup);
	}
	Leer.close();
	return grupos;
}


vector<string> getCiudades(string archivo, vector<string> grupos)
{
	string linea,ciuEst,ciu,gruPa,grup;
	fstream Leer;
	Leer.open(archivo.c_str());
	vector<string> ciudades;
	for(int x=0;x<grupos.size();x++)
	{
		ciudades.push_back(grupos.at(x));
	}
	while(!Leer.eof())
	{
		getline(Leer,linea);
		
		gruPa=token(linea,"|",2);
		grup=token(gruPa,";",1);
		
		ciuEst=token(linea,"|",1);
		ciu=token(ciuEst,",",1);
		
		for(int x=0;x<ciudades.size();x++)
			if(ciudades.at(x)==grup)
				ciudades.at(x)=ciu;
				
	}
	Leer.close();
	return ciudades;
}


vector<string> getEstadios(string archivo, vector<string> grupos)
{
	string linea,ciuEst,est,gruPa,grup;
	fstream Leer;
	Leer.open(archivo.c_str());
	vector<string> estadios;
	for(int x=0;x<grupos.size();x++)
	{
		estadios.push_back(grupos.at(x));
	}
	while(!Leer.eof())
	{
		getline(Leer,linea);
		
		gruPa=token(linea,"|",2);
		grup=token(gruPa,";",1);
		
		ciuEst=token(linea,"|",1);
		est=token(ciuEst,",",2);
		
		for(int x=0;x<estadios.size();x++)
			if(estadios.at(x)==grup)
				estadios.at(x)=est;
				
	}
	Leer.close();
	return estadios;
}



int numeroChars(string cadena, char caracter)
{
	int n=0;
	for(int x=0;x<cadena.size();x++)
	{
		if(cadena[x]==caracter)
			n++;
	}
	return n;
}



vector<string> getNombresJugadores(string equipo)
{
	vector<string> jugadores;
	vector<string> nombres;
	int cant=numeroChars(equipo,':');
	cant++;
	for(int x=1;x<=cant;x++)
	{
		jugadores.push_back(token(equipo,":",x));
	}
	for(int x=0;x<cant;x++)
	{
		nombres.push_back(token(jugadores.at(x),",",2));
	}
	return nombres;
}


vector<string> getNumeroJugadores(string equipo)
{
	vector<string> jugadores;
	vector<string> numeros;
	int cant=numeroChars(equipo,':')+1;
	for(int x=1;x<=cant;x++)
	{
		jugadores.push_back(token(equipo,":",x));
	}
	for(int x=0;x<cant;x++)
	{
		numeros.push_back(token(jugadores.at(x),",",1));
	}
	return numeros;
}


vector<string> getPosicionesJugadores(string equipo)
{
	vector<string> jugadores;
	vector<string> posiciones;
	int cant=numeroChars(equipo,':')+1;
	for(int x=1;x<=cant;x++)
	{
		jugadores.push_back(token(equipo,":",x));
	}
	for(int x=0;x<cant;x++)
	{
		posiciones.push_back(token(jugadores.at(x),",",3));
	}
	return posiciones;
}






