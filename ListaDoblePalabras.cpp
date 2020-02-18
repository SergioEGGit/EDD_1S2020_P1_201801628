//---------------------------------------------------------------------------

	#pragma hdrstop

//---------------------------------Librerias---------------------------------

	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <cstdlib>
	#include <windows.h>
	#include "ListaDoblePalabras.h"
	using namespace std;

//---------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------M�todos-----------------------------------

	void InsertarFinalLDP(ListaLDP &Cabeza, ListaLDP &Cola, string Palabra)
	{
		ListaLDP aux = new(struct PalabrasLD);

		aux -> Palabra = Palabra;
		aux -> sgte = NULL;
		aux -> ante = NULL;

		if(Cabeza == NULL)
		{
			Cabeza = aux;
			Cola = aux;
		}
		else
		{
			Cola -> sgte = aux;
			aux -> ante = Cola;
			Cola = aux;
		}

	}

	void BorrarUltimoLDP(ListaLDP &Cola)
	{
		ListaLDP aux = new(struct PalabrasLD);

		aux = Cola;
		Cola = Cola -> ante;
		aux -> ante = NULL;
		Cola -> sgte = NULL;
	}

	void MostrarLDP(ListaLDP &Cabeza)
	{
		ListaLDP aux = Cabeza;
		while(aux != NULL)
		{
			cout<< aux -> Palabra <<endl;
			aux = aux -> sgte;
		}
	}




