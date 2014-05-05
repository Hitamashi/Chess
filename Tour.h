/** 
 * Header de Tour.cxx
 *
 * @file Tour.h
 * 
 * Heritage de class Piece
 * 
 */

#ifndef Tour_h
#define Tour_h
#include "Piece.h"
#include <QObject>

class Echiquier;

class Tour : public Piece {
    Q_OBJECT
  public:
	Tour();
    Tour(int x, int y, bool white, Echiquier *parent);
	bool mouvementValide( Echiquier & e, int x, int y );
    void paintEvent(QPaintEvent*);
};

#endif


