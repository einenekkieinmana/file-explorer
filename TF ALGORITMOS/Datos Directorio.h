#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <msclr/marshal_cppstd.h>
#include "dirent.h"
#include <sys/stat.h>
#include <locale.h>
#include <math.h>

using namespace std;
using namespace System;
using namespace System::IO;

struct Fecha {
	int dia, mes, anio;
};

struct DatosDirectorio {
	string name;
	Fecha fecha;
	string extension;
	long long size_kb;

	DatosDirectorio(DirectoryInfo ^dato)
	{
		size_kb = 0;
		name = msclr::interop::marshal_as<string>(dato->Name);
		fecha.dia = int(dato->CreationTime.Day);
		fecha.mes = int(dato->CreationTime.Month);
		fecha.anio = int(dato->CreationTime.Year);
		try {
			for each (auto variable in dato->GetFiles())
			{
				size_kb += variable->Length / 1024;
			}
		}
		catch (Exception ^Ex)
		{

		}
	}

	DatosDirectorio(FileInfo ^dato)
	{
		size_kb = 0;
		name = msclr::interop::marshal_as<string>(dato->Name);
		fecha.dia = int(dato->CreationTime.Day);
		fecha.mes = int(dato->CreationTime.Month);
		fecha.anio = int(dato->CreationTime.Year);
		extension = msclr::interop::marshal_as<string>(dato->Extension);
		size_kb = dato->Length;
	}

	DatosDirectorio()
	{

	}

	void MostrarDatosArchivo()
	{
		cout << "Nombre: " << name << endl;
		cout << "Fecha de creaci�n: " << endl;
		cout << "\t Extensi�n: " << extension << endl;
		cout << "\t Dia: " << fecha.dia << endl;
		cout << "\t Mes: " << fecha.mes << endl;
		cout << "\t A�o: " << fecha.anio << endl;
		cout << "Size (kb): " << size_kb << endl << endl;
	}

	void MostrarDatos()
	{
		cout << "Nombre: " << name << endl;
		cout << "Fecha de creaci�n: " << endl;
		cout << "\t Dia: " << fecha.dia << endl;
		cout << "\t Mes: " << fecha.mes << endl;
		cout << "\t A�o: " << fecha.anio << endl;
		cout << "Size (kb): " << size_kb << endl << endl;
	}

};
