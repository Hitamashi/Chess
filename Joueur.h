/** 
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#ifndef Joueur_h
#define Joueur_h

#include "Piece.h"
#include "Echiquier.h"
#include "Roi.h"
#include "Reine.h"
#include "Pion.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"
#include <vector>

using namespace std;
/**
 * Declaration la classe joueur
 */

class Joueur 
{
protected:
	bool _white;
	vector <Piece*> _pieces;
	
public:
    Joueur(bool _white, Echiquier *parent);
	Joueur();
	~Joueur();
	bool placerPiece(Echiquier &e);
	
};

class JoueurBlanc : public Joueur 
{
  public:
    JoueurBlanc(Echiquier* parent);
};

class JoueurNoir : public Joueur {
  public:
    JoueurNoir(Echiquier* parent);
};

#endif
