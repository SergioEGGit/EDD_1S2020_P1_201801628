//------------------------------------------------------------------------------

	#ifndef PilaLogH
	#define PilaLogH
	#include <iostream>
	#include <string>
	#include <cstdlib>
	using namespace std;

//-------------------------------Estructura-------------------------------------

	struct CambiosPL
	{
		string PalabraBuscar;
		string PalabraReemplazar;
		bool Estado;
		string Palabra;
		int Posicion;
		struct CambiosPL *sgte;
	};

	typedef struct CambiosPL *PilaPL;

	void InsertarPL(PilaPL &Pila, string PalabraBuscar, string PalabraReemplazar, bool Estado, string Palabra, int Posicion);

	void MostrarPL(PilaPL &Pila);

	string EliminarPL(PilaPL &Pila, string PalabraBuscar, string PalabraReemplazar, bool Estado, string Palabra, int Posicion);

	void ReporteBuscadosPL(PilaPL &Pila);

//------------------------------------------------------------------------------

	#endif
