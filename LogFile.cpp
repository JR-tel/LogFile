//---------------------------------------------------------------------------

#pragma hdrstop

#include "LogFile.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Logger::Logger(AnsiString Path, AnsiString Nombre)
 {
   FicheroPath = Path;
   FicheroNombre = Nombre;
   CrearPath();    //Si no existe lo crea
   CrearFichero(); //Si no existe lo crea
 }

//--------------------------------------------------------------------------
void Logger::CrearPath()
{
  //Crea el directorio si no existe
   try
	{ if (!TDirectory::Exists(FicheroPath)) { TDirectory::CreateDirectory(FicheroPath); } }
   catch ( ... )
	{ ShowMessage("Problemas al crear el directorio "+FicheroPath); }
}
//-------------------------------------------------------------------------
void Logger::CrearFichero()
{
  //Crea el fichero si no existe (dd-mm-yyyy)-Nombre.
  //Si existe se abre en lectura escritura y
  //Nos posicionamos al final del fichero para añadir texto
  AnsiString F;
  F = FicheroPath + "\\" + GetFecha() + "-" + FicheroNombre;
  if( !FileExists(F) )
   {
	 try
	  { FicheroLogger = new TFileStream (F, fmCreate); }
	 catch ( ... )
	  { ShowMessage("Problemas al crear el fichero "+ F); }
   }
  else
   {
	 try
	  {
		FicheroLogger = new TFileStream (F, fmOpenReadWrite);
		FicheroLogger->Seek(0,soFromEnd);
	  }
	 catch ( ... )
	  { ShowMessage("Problemas al abrir el fichero " + F); }
   }
}
 //------------------------------------------------------------------
 AnsiString Logger::GetFechaHora()
 {
   TDateTime hora = Now();
   return  AnsiString(hora.FormatString("[dd/mm/yy hh:mm:ss]"));
 }
 //------------------------------------------------------------------
 AnsiString Logger::GetFecha()
 {
   TDateTime hora = Now();
   return  AnsiString(hora.FormatString("(dd-mm-yy)"));
 }
 //-------------------------------------------------------------------
void Logger::Add(AnsiString Nivel,AnsiString Mensaje)
 {
   //Añade mensaje con nivel
   short B;
   B = Nivel.Length();
   //Formateamos El NIVEL para que tenga siempre 8 caracteres
   if(B > 8) { Nivel.SetLength(8); }
   if(B < 8) { Nivel = Nivel + DupeString(' ',8-B); }
   //A mayusculas
   Nivel.UpperCase();

   //Formato 1
   Mensaje = GetFechaHora() + "-" + Nivel + "->"+ Mensaje + "\r\n";
   FicheroLogger->Write(Mensaje.c_str(), Mensaje.Length() );
 }
//--------------------------------------------------------------------




