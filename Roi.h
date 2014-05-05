/** 
 * Header de Roi.cxx
 *
 * @file Roi.h
 * 
 * Heritage de class Piece
 * 
 */

#ifndef Roi_h
#define Roi_h
#include "Piece.h"
#include <QObject>
class Echiquier;

class Roi : public Piece {
    Q_OBJECT
  public:
    Roi();
    Roi(bool white, Echiquier* parent);
	bool mouvementValide( Echiquier & e, int x, int y );
    void paintEvent(QPaintEvent *);
};

#endif
