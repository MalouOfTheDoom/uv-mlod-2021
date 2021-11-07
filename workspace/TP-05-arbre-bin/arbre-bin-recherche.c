#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a == NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a;
	a = malloc(sizeof(Noeud));
	a->val = e;
	a->filsDroit = NULL;
	a->filsGauche = NULL;
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
    if (estVide(a))
        return creer(e);

    ArbreBinaire b = a;

    while ( !estVide(b) ){
        if (e==b->val)
        	return (a);
        if (e < b->val) {
			if (!estVide(b->filsGauche)) 
				b = b->filsGauche;
            else {
                b->filsGauche = creer(e);
            }
        }
        if (e > b->val) {
			if (!estVide(b->filsDroit)) 
                b = b->filsDroit;
            else {
                b->filsDroit = creer(e);
            }
        }
    }
    return a; 
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	ArbreBinaire b = a;
	if ( !estVide(b) ) {
		if ( e < b->val ) {
			b->filsGauche = insere_r( b->filsGauche, e);
			return b;
		}
		if ( e > b->val ) {
			b->filsDroit = insere_r( b->filsDroit, e);
			return b;
		}
		// si doublon
		return b;
	}
	return creer(e);
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	int res = 0;
	if ( estVide(a) ) {
		return 0;
	}
	else {
		res += 1;
		res += nombreDeNoeud(a->filsGauche) + nombreDeNoeud(a->filsDroit);
		return res;
	}
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	ArbreBinaire b = a;
	int profondeur = 1;
	
	while ( !estVide(b) ) {
		if ( e == b->val ) return profondeur;
		if ( e < b->val) {
			if ( !estVide(b->filsGauche) ) {
				b = b->filsGauche;
				profondeur++ ;
			}
			else return -1;
		}
		if (e > b->val ) {
			if ( !estVide(b->filsDroit) ) {
				b = b->filsDroit;
				profondeur++ ;
			}
			else return -1;
			
		}
	}
	return -1;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	ArbreBinaire b = a;
	if ( !estVide(b) ) {
		int hGauche = hauteur(b->filsGauche);
		int hDroite = hauteur(b->filsDroit);
		return 1 + (hGauche > hDroite ? hGauche : hDroite);
	}
	return 0;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){
	if (estVide(a) || a->val == elem)
        return NULL;

    ArbreBinaire b = a;

    while ( !estVide(b) ){
        if (elem < b->val) {
			if (!estVide(b->filsGauche)) {
				if ( b->filsGauche->val == elem) return b;
			}
			b = b->filsGauche;

        }
        else {
			if (!estVide(b->filsDroit)) {
				if ( b->filsDroit->val == elem) return b;
			}
			b = b->filsDroit;
        }
    }
    return NULL; 
}


void afficheRGD_r(ArbreBinaire a){
	if (!estVide(a)) {
		printf("%i ", a->val);
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
	}
}

void afficheGRD_r(ArbreBinaire a){
	if (!estVide(a)) {
		afficheGRD_r(a->filsGauche);
		printf("%i ", a->val);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a){
	if (!estVide(a)) {
		afficheGDR_r(a->filsGauche);
		afficheGDR_r(a->filsDroit);
		printf("%i ", a->val);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	ArbreBinaire b = a;

	if (estVide(b)) return NULL;
	while ( !estVide(b->filsGauche) ) {
		b = b->filsGauche;
	}
	return b;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	ArbreBinaire b = a;

	if (estVide(b)) return NULL;
	while ( !estVide(b->filsDroit) ) {
		b = b->filsDroit;
	}
	return b;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe pas dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem) {
	if ( estVide(a) || a->val == elem)
		return a;
	if ( elem < a->val )
		return recherche_r( a->filsGauche, elem );
	else
		return recherche_r( a->filsDroit, elem );
	return NULL;
}


// supprime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{
	ArbreBinaire b = a;
	if ( !estVide(b) ) {
		if ( x < b->val ) {
			b->filsGauche = supprimer_r( b->filsGauche, x);
			return a;
		}
		if ( x > b->val ) {
			b->filsDroit = supprimer_r( b->filsDroit, x);
			return a;
		}
		
		//si b->val == x
		//cas feuille
		if ( estVide(b->filsGauche) && estVide(b->filsDroit) ) {
			free(b);
			return NULL;
		}
		//cas un seul descendant gauche
		if ( estVide(b->filsDroit)) {
			ArbreBinaire temp = b->filsGauche;
			free(b);
			return temp;
		}
		//cas un seul descendant droit
		if ( estVide(b->filsGauche)) {
			ArbreBinaire temp = b->filsDroit;
			free(b);
			return temp;
		}
		//cas deux descendants. on remplace par le plus à droite du SAG.
		ArbreBinaire toMove = b->filsGauche;
		ArbreBinaire sauvFilsGauche = b->filsGauche;
		ArbreBinaire sauvFilsDroit = b->filsDroit;
		free(b);
		while( !estVide(toMove->filsDroit) ) {
			toMove = toMove->filsDroit;
		}
		ArbreBinaire arbreRes = creer( toMove->val );
		arbreRes->filsDroit = sauvFilsDroit;
		arbreRes->filsGauche = supprimer_r(sauvFilsGauche, toMove->val);
		return arbreRes;
	}
	return a;
}

void detruire_r(ArbreBinaire a){
	if ( !estVide(a) ) {
		detruire_r(a->filsGauche);
		detruire_r(a->filsDroit);
		free(a);
	}
}

