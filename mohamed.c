#include <stdio.h>
#include <stdlib.h>
#include <miAPI.h>
#include "file.h"

// Liste des constantes à redéfinir si besoin
#define EV1 "DVIS"
#define EV2 "DTOU"
#define FORMAT MAT_FORMAT
#define PATH "C:\\Users\\Gilles\\Desktop" 
#define TITLE "Sélectionner les fichiers"
#define FILTER "Fichier C3D|*.c3d"

int main()
{
 int count = 0; // nombre de fichiers dans la liste
 // sélection d'une liste de fichiers
 char** files = miGetFileList(FILTER, TITLE, PATH, &count);
 if (files != NULL) // si la liste est non NULL
 {
 int i;
 for(i = 0; i < count; i++) // boucle sur la liste des fichiers
 {
 if (miOpenDataFile(files[i])) // ouvre le fichier
 {
 fi_export(files[i], EV1, EV2, FORMAT); // exportation entre EV1 et EV2
 miCloseData(); // ferme le fichier de données
 }
 }
 for(i = 0; i < count; i++) // libération de la mémoire (liste)
 free(files[i]);
 free(files);
 }
 return 0;
}
