// gcc -W -Wall -std=c99 linkedList.c linkedListOfString.c -o linkedListOfString

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
    //printf("%s", line); 

    return line;
}

/* create an empty Music object */
Music* createMusicObject(){
    Music *music = malloc(4*sizeof(char*) + 3*sizeof(int));
    return music;
}

/* create a Music pointer from a string with all data separated by commas */
Music* fillMusicData(char *line){
    Music *music = createMusicObject(); //todo créer
    char *separator = ",";
    char *extracted;
    int compteur = 0;
    extracted = strsep(&line, separator); //attention, utilise un malloc -> il faut free().
    while (extracted != NULL) {
        // printf("extracted: '%s'\n", extracted);
        // printf("left: '%s'\n", line);
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
        extracted = strsep(&line, separator);
        compteur += 1;
    }
    return music;
    
}

int main(void){
	char fileName[] = "music.csv"; 
    FILE *f;

    f = fopen(fileName,"r"); 

    //we get rid of the first line. The order of the data in the .csv is hard-coded in the createMusic() function.
    scanLine(f);

    //for each line, we create a new Music object
    Music *music;
    char* line = scanLine(f);
    music = fillMusicData(line);
    printf("%s \n", music->artist);

    fclose(f);
	return EXIT_SUCCESS;
}