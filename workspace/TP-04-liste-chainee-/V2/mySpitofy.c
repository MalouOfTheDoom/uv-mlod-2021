// gcc -W -Wall linkedListOfMusic.c mySpitofy.c -o mySpitofy

// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./linkedListOfString

#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine(FILE *f)
{
    int maxLineSize = 255;
	char *line = calloc(maxLineSize+1,sizeof(char));

    fgets(line, maxLineSize+1, f);

    return line;
}

/* create an empty Music object */
Music* createMusicObject(){
    Music *music = malloc(4*sizeof(char*) + 3*sizeof(int));
    return music;
}

/* create a Music pointer from a string with all data separated by commas */
Music* CreateMusicFromData(char *line){
    
    char *lineCopy = strdup(line);
    Music *music = createMusicObject();
    char *separator = ",";
    char *extracted;
    int compteur = 0;
    extracted = strsep(&lineCopy, separator); //attention, utilise un malloc -> il faut free().

    while (extracted != NULL) {
        switch(compteur) {
            case 0: music->name = extracted; break;
            case 1: music->artist = extracted; break;
            case 2: music->album = extracted; break;
            case 3: music->genre = extracted; break;
            case 4: music->diskNumber = atoi(extracted); break; //we use atoi to convert char* to int.
            case 5: music->trackNumber = atoi(extracted) ; break;
            case 6: music->year = atoi(extracted); break;
            default: break;
        }
        extracted = strsep(&lineCopy, separator);
        compteur += 1;
    }

    free(lineCopy);
    return music;
}

int main(void){
	char fileName[] = "music.csv"; 
    FILE *f;

    f = fopen(fileName,"r"); 

    //we get rid of the first line. The order of the data in the .csv is hard-coded in the createMusic() function.
    char *line = scanLine(f);

    Liste musicList = NULL;
    //for each line, we create a new Music object and put it in the list.
    while( !feof(f) ) {
        line = scanLine(f);
        if(line[0] != '\0'){ //on vérifie que notre ligne n'est pas vide.
            Music *music = CreateMusicFromData(line);
            musicList = ajoutFin_r(music, musicList);
        }
    }

    afficheListe_i(musicList);

    detruire_r(musicList);
    fclose(f);
	return EXIT_SUCCESS;
}