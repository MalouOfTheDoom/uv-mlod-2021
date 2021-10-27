
#include <stdio.h>
#include <stdlib.h>
#include "linkedListOfMusic.h"
#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la un pointeur vers une musique
Liste creer(Music *music){
	Liste res;
	res = malloc(sizeof(Cellule));
	res->music = music;
	res->suiv = NULL;
	return res;
}

// ajoute l'élément music en tete de la liste l
Liste ajoutTete(Music *music, Liste l) {
	Liste res = creer(music);
	res->suiv = l;
	return res;
}

//affiche une musique.
void afficheMusic(Music *music) {
    printf("%s,%s,%s,%s,%i,%u,%u\n",
    music->name,
    music->artist,
    music->album,
    music->genre,
    music->diskNumber,
    music->trackNumber,
    music->year);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_Music
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste p = l;

	while(!estVide(p)) {
		afficheMusic(p->music);
		p=p->suiv;
	}
	//printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if( !estVide(l) ) {
		afficheMusic(l->music);
		afficheListe_r(l->suiv);
	}
	else
		printf("\n");
}

// Détruire une musique.
void detruireMusic(Music *music) {
	free(music);
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste suivant, courant = l;

	while(!estVide(courant)) {
		suivant=courant->suiv;
		detruireMusic(courant->music);
		free(courant);
		courant = suivant;
	}
}

// version récursive
void detruire_r(Liste l) {
	if( !estVide(l) ){
		detruire_r(l->suiv);
		detruireMusic(l->music);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément music a été ajouté en fin
// version itérative
Liste ajoutFin_i(Music *music, Liste l) {
	Liste elem = creer(music);
	Liste p = l;

	if(estVide(p))
		return elem;

	while(!estVide(p->suiv))
		p = p->suiv;
	p->suiv=elem;

	return l;
}

// version recursive
Liste ajoutFin_r(Music *music, Liste l) {
	if(estVide(l))
		return creer(music);
	else
		l->suiv=ajoutFin_r(music,l->suiv);
	return l;
}
 
// compare deux Musics
bool equalsMusic(Music *music1, Music *music2){
	if( strcmp(music1->name, music2->name) != 0) return false;
	if( strcmp(music1->artist, music2->artist) != 0) return false;
	if( strcmp(music1->album, music2->album) != 0) return false;
	if( strcmp(music1->genre, music1->genre) != 0) return false;
	if (music1->diskNumber != music2->diskNumber) return false;
	if (music1->trackNumber != music2->trackNumber) return false;
	if (music1->year != music2->year) return false;
	return true;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur music ou NULL
// version itérative
Liste cherche_i(Music *music,Liste l) {
	Liste p = l;

	while(!estVide(p) && !equalsMusic(p->music, music))
		p=p->suiv;

	return p;
}

// version récursive
Liste cherche_r(Music *music, Liste l) {
	if(estVide(l) || equalsMusic(l->music,music))
		return l;
	else
		return cherche_r(music,l->suiv);
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur music a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Music *music, Liste l) {
	Liste precedent, p;

	if(estVide(l))
		return l;

	if(equalsMusic(l->music,music)) {
		p = l->suiv;
		l->suiv = NULL;
		detruire_r(l);
		return p;
	}

	precedent = l;
	p = l->suiv;
	while(!estVide(p) && !equalsMusic(p->music,music)) {
		precedent = p;
		p = p->suiv;
	}

	if(!estVide(p)) {
		// on a trouvé music
		precedent->suiv = p->suiv;
		p->suiv = NULL;
		detruire_r(p);
	}

	return l;
}


// version recursive
Liste retirePremier_r(Music *music, Liste l) {
	if(estVide(l))
		return l;

	if(equalsMusic(l->music,music)) {
		Liste p = l->suiv;
		l->suiv = NULL;
		detruire_r(l);
		return p;
	}

	l->suiv = retirePremier_r(music,l->suiv);
	return l;
}


// Affiche la liste l à l'envers i.e. du dernier élément jusqu'au premier
void afficheEnvers_r(Liste l) {
	if(!estVide(l)) {
		if(!estVide(l->suiv))
			afficheEnvers_r(l->suiv);
		afficheMusic(l->music);
		printf(" ");
	}
}

Liste trierParAnnee(Liste l){
	Music *currentMusic = l->music;
	Liste listeTriee = creer(currentMusic);
	Liste sauvegarde = listeTriee;
	l = l->suiv;
	
	while(!estVide(l)){
		currentMusic = l->music;
		while( !estVide(listeTriee)){
			if (currentMusic->year >= listeTriee->music->year) {
				if(!listeTriee->suiv || currentMusic->year <= (listeTriee->suiv)->music->year) {
					ajoutFin_i(currentMusic, listeTriee);
					break;
				}
				else {
					listeTriee = listeTriee->suiv;
				}
			}
			else {
				ajoutTete(currentMusic, listeTriee);
				break;
			}
		}
		l = l->suiv;
	}
	return sauvegarde;
}

