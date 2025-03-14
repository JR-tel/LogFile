# LogFile
Rad Studio 12 Community Edition.
Crea fichero log simple para registrar acciones ......

 Al crear el logger debemos especificar el path y el nombre de fichero.
 El PATH lo crea si no existe.
 El nombre de fichero se completa con '(dd-mm-yyyy)-' + el nombre y la extensión.
 Es un fichero diario.
 Si el fichero existe añade al final de fichero, no lo borra.
 La cadena de NIVEL (INFO,WARNING,ERROR...) será como máx de 8 caracteres.

  Crear logger:
   Logger *Logger1 = new Logger(".\\Logs","Logger1.log");

  Añadir mensajes:
   Logger1->Add(nivel, mensaje);
