/** 
 * Header de Cavalier.cxx
 *
 * @file Cavalier.h
 * 
 * Heritage de class Piece
 * 
 */

#ifndef Cavalier_h
#define Cavalier_h
#include "Piece.h"
#include <QObject>
class Echiquier;

class Cavalier : public Piece {
    Q_OBJECT
  public:
	Cavalier();
    Cavalier(int x, int y, bool white, Echiquier *parent);
	bool mouvementValide( Echiquier & e, int x, int y );
    void paintEvent(QPaintEvent *);
};

#endif

