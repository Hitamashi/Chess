/** 
 * Mise en oeuvre de Tour.h
 *
 * @file Tour.cxx
 */

#include "Tour.h" 
#include "Echiquier.h"

#include <iostream>
using namespace std;

Tour::Tour() 
{	
    this->setFixedSize(Echiquier::SIZE,Echiquier::SIZE);
}

Tour::Tour(int x, int y, bool white,Echiquier* parent) : Piece(x,y,white,parent)
{
}

bool Tour::mouvementValide( Echiquier & e, int x, int y ) 
{
	int X = m_x;
	int Y = m_y;
	
	//Dans l'echiquier
	if( x<1 || x>8 || y<1 || y>8 ) {
		return false;
	}
	
	//Valide mouvement
	if ( (x!=X && Y!=y) || (x==X && y==Y) ) {
		return false;
	}
	
	//Pas blocker
	//y change
	if (x==X) { 
		int movY = (y>Y? 1:-1);
        for (int i=Y+movY; i != y; i += movY) {
			if (e.getPiece(x,i) != NULL) {
				return false;
			}
		}
	}
	//x change
	else {
		int movX = (x>X? 1:-1);
        for (int i=X+movX; i!= x; i+=movX) {
			if (e.getPiece(i,y) != NULL) {
				return false;
			}
		}
	}
	return true;
}

void
Tour::paintEvent(QPaintEvent *) {
    QString name = "";
    if(m_white){
        name = "WRook.png";
    }
    else {
        name = "BRook.png";
    }

    paintPiece(name);
}
