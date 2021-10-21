#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Cellule *cell =  (Cellule*) malloc( sizeof(Cellule) ); //Liste liste = (Liste) malloc(sizeof(Cellule))
	Liste liste = cell;
	cell->val = v;  
	cell->suiv = NULL;
	return liste;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste n = creer(v);
	n->suiv = l;
	return n;
}

void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste p = l;

	while(!estVide(p)) {
		afficheElement(p->val);
		p = p->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if (estVide(l)) {
		printf("\n");
		return;
	}

	afficheElement(l->val);
	if (l->suiv) {
		afficheListe_r(l->suiv);
	}
	else printf("\n");
}

void detruireElement(Element v) { 
	TODO;
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	if (estVide(l)) return;

	Liste p = l;
	while(p->suiv){
		detruireElement(&(p->val));
		p = p->suiv;
	}
	detruireElement(&(p->val));
}

// version récursive
void detruire_r(Liste l) {
	if (estVide(l)) return;
	if(l->suiv){
		detruire_r(l->suiv);
	}
	detruireElement(&(l->val));
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	if (estVide(l)) return creer(v);

	Liste p = l;
	while(p->suiv) {
		p = p->suiv;
	}
	Liste listeAjout = creer(v);
	p->suiv = listeAjout;
	p = l;
	return p;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if (estVide(l)) return creer(v);

	if (l->suiv) {
		return( ajoutFin_r(v, l->suiv) );
	}
	else {
		Liste listeAjout = creer(v);
		l->suiv = listeAjout;
		return l;
	}
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	if (estVide(l)) return NULL;

	Liste p = l;
	while (!equalsElement(p->val, v)) {
		if(p->suiv) {
			p = p->suiv;
		}
		else return NULL;
	}
	return p;

}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if (estVide(l)) return NULL;
	
	if (equalsElement(l->val, v)) {
		return l;
	}
	else { 
		if(l->suiv) {
			return (cherche_r(v, l->suiv));
		}
		else {
			return NULL;
		}
		
	}
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste p = cherche_i(v, l);
	if(p) {
		return TODO;
		// reparcourir la boucle pour trouver la cellule d'avant => augmentation de la compléxité.
		// il faudrait une méthode cherche_i qui retourne la cellule AVANT celle possédant l'élément...
	}
	else return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if (estVide(l)) return l;

	return TODO;
	
}


void afficheEnvers_r(Liste l) {
	TODO;
}



