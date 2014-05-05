/** 
 * Header de Fou.cxx
 *
 * @file Fou.h
 * 
 * Heritage de class Piece
 * 
 */

#ifndef Fou_h
#define Fou_h
#include "Piece.h"
#include <QObject>
class Echiquier;

class Fou : public Piece {
    Q_OBJECT
  public:
    Fou();
    Fou(int x, int y, bool white,Echiquier* parent);
	bool mouvementValide( Echiquier & e, int x, int y );
    void paintEvent(QPaintEvent *);
};

#endif


