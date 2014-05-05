/** 
 * Mise en oeuvre de Joueur.h
 *
 * @file Joueur.cxx
 */

#include "Joueur.h"
#include <iostream>

using namespace std;
// Constructeur

Joueur::Joueur(bool white,Echiquier* parent)
{
	_white = white;
	
	//1ere ligne
	int y = (white? 2 : 7); 
	 
	//Les Pions
	for (int i = 1; i<9; i++) {
        Pion *pi = new Pion(i,y,white,parent);
        _pieces.push_back(pi);
    }
	
	//2eme ligne
    y = (white? 1: 8);
	//Les Tours
    Tour* t = new Tour(1,y,white,parent);
	_pieces.push_back(t);
    t = new Tour(8,y,white,parent);
	_pieces.push_back(t);
	
	//Les Cavaliers
    Cavalier* c = new Cavalier(2,y,white,parent);
	_pieces.push_back(c);
    c = new Cavalier(7,y,white,parent);
	_pieces.push_back(c);
	
	//Les Fous
    Fou* f = new Fou(3,y,white,parent);
	_pieces.push_back(f);
    f = new Fou(6,y,white,parent);
	_pieces.push_back(f);

	//Le Roi
    Roi* roi = new Roi(white,parent);
    roi->setObjectName("ROI");
	_pieces.push_back(roi);
	
	//La Reine
    Reine* reine = new Reine(white,parent);
	_pieces.push_back(reine);
}

Joueur::Joueur() {
	cout << " Joueur creee " << endl;
}

Joueur::~Joueur() {
	cout << "Joueur destruit " << endl;
	for (int i=0; i<16; i++) {
		delete _pieces[i];
	}
}

bool
Joueur::placerPiece(Echiquier &e) {
	for(int i =0; i<16; i++) {
        if (!e.placer(_pieces[i])) {
			return false;
        }
        _pieces[i]->setVisible(true);
	}
	return true;
}

JoueurBlanc:: JoueurBlanc(Echiquier* parent) : Joueur(true,parent)
{
    placerPiece(*parent);
}

JoueurNoir:: JoueurNoir(Echiquier *parent) : Joueur(false,parent)
{
    placerPiece(*parent);
}
