/** 
 * Header de Reine.cxx
 *
 * @file Reine.h
 * 
 * Heritage de class Piece
 * 
 */

#ifndef Reine_h
#define Reine_h
#include "Piece.h"
#include<QObject>

class Echiquier;

class Reine : public Piece {
    Q_OBJECT
  public:
	Reine();
    Reine(bool white, Echiquier *parent);
    Reine(int x, int y, bool white, Echiquier* parent);
	bool mouvementValide( Echiquier & e, int x, int y );
    void paintEvent(QPaintEvent *);
};

#endif


