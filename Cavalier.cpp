/** 
 * Mise en oeuvre de Cavalier.h
 *
 * @file Cavalier.cxx
 */

#include "Cavalier.h" 
#include "Echiquier.h"

#include <iostream>
using namespace std;

Cavalier::Cavalier(){
    this->setFixedSize(Echiquier::SIZE,Echiquier::SIZE);
}

Cavalier::Cavalier(int x, int y, bool white,Echiquier* parent) : Piece(x,y,white,parent)
{ 
}

bool Cavalier::mouvementValide( Echiquier & e, int x, int y ) {
	int X = m_x;
	int Y = m_y;
	
	if( x<1 || x>8 || y<1 || y>8 ) {
		return false;
	}
	
	bool position= ( (x==X+2 && y==Y+1) || (x==X+1 && y==Y+2) ||
					(x==X-2 && y==Y+1) || (x==X+1 && y==Y-2) ||
					(x==X+2 && y==Y-1) || (x==X-1 && y==Y+2) ||
					(x==X-2 && y==Y-1) || (x==X-1 && y==Y-2) ) ;
	
	if (!( position || (x==X && y==Y))) {
		return false;
	}
	return true;
	
}

void
Cavalier::paintEvent(QPaintEvent *) {
    QString name = "";
    if(m_white){
        name = "WKnight.png";
    }
    else {
        name = "BKnight.png";
    }

    paintPiece(name);
}
