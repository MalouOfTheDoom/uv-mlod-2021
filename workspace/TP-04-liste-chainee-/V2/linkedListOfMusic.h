#pragma once

#include <stdbool.h>
#include <string.h>

// ============
// Types
// ============

struct music_s {
    char *name;
    char *artist;
    char *album;
    char *genre;
    int diskNumber;
    int trackNumber;
    int year;
};
typedef struct music_s Music;

struct cellule_s {
	Music *music;
	struct cellule_s* suiv;
};

typedef struct cellule_s Cellule;
typedef Cellule* Liste;

// ============
// Functions
// ============

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l);

// créer une liste d'un seul élément contenant la musique passée en paramètre.
Liste creer(Music *music);

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Music *music, Liste l);

//afficher une musique.
void afficheMusic(Music *music);

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_Music
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l);

// version recursive
void afficheListe_r(Liste l);

//détruire une musique.
void detruireMusic(Music *music);

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l);

// version récursive
void detruire_r(Liste l);

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Music *music, Liste l);

// version recursive
Liste ajoutFin_r(Music *music, Liste l);

//compare deux musiques.
bool equalsMusic(Music *music1, Music *music2);

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Music *music,Liste l);

// version récursive
Liste cherche_r(Music *music,Liste l);

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Music *music, Liste l);

// version recursive
Liste retirePremier_r(Music *music, Liste l);

void afficheEnvers_r(Liste l);

Liste trierParAnnee(Liste l);