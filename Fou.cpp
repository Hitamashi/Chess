/** 
 * Mise en oeuvre de Fou.h
 *
 * @file Fou.cxx
 */

#include "Fou.h" 
#include "Echiquier.h"
#include <iostream>
using namespace std;

Fou::Fou(){
    this->setFixedSize(Echiquier::SIZE,Echiquier::SIZE);
}

Fou::Fou(int x, int y, bool white, Echiquier *parent) : Piece(x,y,white,parent)
{ 
}
	
bool Fou::mouvementValide( Echiquier & e, int x, int y ) 
{
	int X = m_x;
	int Y = m_y;
	
	//Dans l'echiquier
	if( x<1 || x>8 || y<1 || y>8 ) {
		return false;
	}
	
	//Valide movement
	if ( (abs(x-X) != abs(y-Y) ) || (x==X && y==Y) ) {
		return false;
	}
	
	//Pas Blocker
	int movX = (x>X? 1:-1);
	int movY = (y>Y? 1:-1);
	
	int i,j;
	for(i = X + movX, j = Y +movY ; i!=x && j!=y; i+=movX, j+=movY) {
		if (e.getPiece(i,j) != NULL) {
            //cout <<"(" <<  i << "," << j << ")" << endl;
			return false;
		}
	}
	
	return true;
}

void
Fou::paintEvent(QPaintEvent *) {
    QString name = "";
    if(m_white){
        name = "WBishop.png";
    }
    else {
        name = "BBishop.png";
    }

    paintPiece(name);
}
