//---------------------------------------------------------------------------
/*
  Al crear el logger debemos especificar el path y el nombre de fichero
  El PATH lo crea si no existe.
  El nombre de fichero se completa con '(dd-mm-yyyy)-' + el nombre y la extensi�n.
  Es un fichero diario.
  Si el fichero existe a�ade al final de fichero, no lo borra.
  La cadena de NIVEL (INFO,WARNING,ERROR...) ser� como m�x de 8 caracteres.

  Crear logger:
   Logger *Logger1 = new Logger(".\\Logs","Logger1.log");

  A�adir mensajes:
   Logger1->Add(nivel, mensaje);

*/
//---------------------------------------------------------------------------
#ifndef LogFileH
#define LogFileH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.StrUtils.hpp>
#include <System.IOUtils.hpp>   //TDirectory, TPath, TFile
#include <System.hpp>

#include <iostream>
#include <fstream>

class Logger
 {
   public:
	 //Constructores y destructor
	 Logger(AnsiString FicheroPath, AnsiString Nombre);
	 ~Logger();
	 //Variables
	 TFileStream *FicheroLogger;  //fichero de log

	 //M�todos
	 void Add(AnsiString Nivel,AnsiString Mensaje);

   private:
	 //Variables
	 AnsiString FicheroNombre;
	 AnsiString FicheroPath;

	 //M�todos
	 void CrearPath();
	 void CrearFichero();
	 AnsiString GetFechaHora();
	 AnsiString GetFecha();
 };
 #endif
