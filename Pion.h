/** 
 * Header de Pion.cxx
 *
 * @file Pion.h
 * 
 * Heritage de class Piece
 * 
 */

#ifndef Pion_h
#define Pion_h
#include "Piece.h"
class Echiquier;

class Pion : public Piece {
    Q_OBJECT
  public:
	Pion();
    Pion(int x, int y, bool white, Echiquier *parent);
	bool mouvementValide( Echiquier & e, int x, int y );
    void paintEvent(QPaintEvent *);
    bool canPromote();
};

#endif


