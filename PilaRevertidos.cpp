//---------------------------------------------------------------------------

	#pragma hdrstop

//---------------------------------Librerias---------------------------------

	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <cstdlib>
	#include <fstream>
	#include <windows.h>
	#include "PilaRevertidos.h"
	using namespace std;

//---------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------M�todos-----------------------------------

	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void InsertarPR(PilaPR &Pila, string PalabraBuscar, string PalabraReemplazar, bool Estado, string Palabra, int Posicion)
	{
		PilaPR aux = new(struct CambiosPR);

		aux -> PalabraBuscar = PalabraBuscar;
		aux -> PalabraReemplazar = PalabraReemplazar;
		aux -> Estado = Estado;
		aux -> Palabra = Palabra;
		aux -> Posicion = Posicion;


		aux -> sgte = Pila;

		Pila = aux;
	}

	void MostrarPR(PilaPR &Pila)
	{
		PilaPR aux = Pila;

		while(aux != NULL)
		{
            cout<< aux -> PalabraBuscar << endl;
			cout<< aux -> PalabraReemplazar << endl;
			cout<< aux -> Estado << endl;
			cout<< aux -> Palabra << endl;
			cout<< aux -> Posicion << endl;

			aux = aux -> sgte;
		}
    }

	string EliminarPR(PilaPR &Pila, string PalabraBuscar, string PalabraReemplazar, bool Estado, string Palabra, int Posicion)
	{
		PilaPR aux = Pila;
		string Res = "";

		if(aux != NULL)
		{
			PalabraBuscar = aux -> PalabraBuscar;
			PalabraReemplazar = aux -> PalabraReemplazar;
			Estado = aux -> Estado;
			Palabra = aux -> Palabra;
			Posicion = aux -> Posicion;

            Res = PalabraBuscar + ";" + PalabraReemplazar;

			Pila = aux -> sgte;

			delete(aux);
		}
		return Res;
	}

	void ReporteBuscadosPR(PilaPR &Pila)
	{
		ofstream Reporte21("Reporte2-1.dot");
		PilaPR aux = Pila;
		Reporte21<< "digraph G" << endl;
		Reporte21<< "{" << endl;
		Reporte21<< "Revertidos [shape = cds, fontname = Arial, fontcolor = black, style=filled, fillcolor = red]" <<endl;
		Reporte21<< "node [shape = box, fontname = Arial, fontcolor = black, color = red];" <<endl;
		int contador = 0;
		string temp[10000];
		string Same;
		string Estado;
		string Posicion;
		string Asc = "";

		if(aux != NULL)
		{
			do
			{
				if(aux -> Estado == false)
				{
					Estado = "No Revertido";
				}
				else
				{
					Estado = "Revertido";
				}

				if(aux -> Posicion == -1)
				{
					Posicion = "Null";
				}
				else
				{
					Posicion = aux -> Posicion;
				}

				Reporte21<< "A" << contador << " [label = " <<"\"" << "Palabra Buscar: " << aux -> PalabraBuscar << "\\l" << "Palabra Reemplazar: " << aux -> PalabraReemplazar << "\\l" << "Estado: " << Estado << "\\l"  << "Palabra: " << aux -> Palabra << "\\l"  << "Posicion: " << Posicion << "\\l" <<"\"]" <<endl;
				temp[contador] = "A" + to_string(contador);
				contador++;
				aux = aux -> sgte;
			}
			while(aux != NULL);


			for(int i = 0; i < contador; i++)
			{
				Same = Same + temp[i] + " ";
				if(i < contador - 1)
				{
					Asc = Asc + temp[i] + "->";
				}
				else
			   {
				   Asc = Asc + temp[i];
			   }
			}
			Reporte21<< "{ rank = same " << Same << "}" << endl;
			Reporte21<< Asc <<endl;
		}
		Reporte21<< " " <<endl;
		Reporte21<< "}";
		Reporte21.close();

		//Generar Imagen
		system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng Reporte2-1.dot -o Reporte2-1.png");
		//Abrir Imagen
		system("C:\\Usac\\\"Estructuras De Datos\"\\EDD_1S2020_P1_201801628\\Win32\\Debug\\Reporte2-1.png &" );
	}
