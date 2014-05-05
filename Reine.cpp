/** 
 * Mise en oeuvre de Reine.h
 *
 * @file Reine.cxx
 */

#include "Reine.h" 
#include "Echiquier.h"

#include <iostream>
using namespace std;

Reine::Reine() {
    this->setFixedSize(Echiquier::SIZE,Echiquier::SIZE);
}

Reine::Reine(bool white, Echiquier *parent) {
    this->setParent(parent);
    this->setFixedSize(Echiquier::SIZE, Echiquier::SIZE);
	m_white = white;
	m_x = 5;
	if (white) 
		m_y = 1;
	else 
		m_y = 8;

    movePiece(m_x,m_y);
}

Reine::Reine(int x, int y, bool white, Echiquier* parent) :
    Piece(x, y, white, parent) {}

bool Reine::mouvementValide( Echiquier & e, int x, int y ) 
{
    int X = m_x;
    int Y = m_y;

    //Dans l'echiquier
    if( x<1 || x>8 || y<1 || y>8 ) {
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
        return true;
    }
    //x change
    else if(y==Y) {
        int movX = (x>X? 1:-1);
        for (int i=X+movX; i!= x; i+=movX) {
            if (e.getPiece(i,y) != NULL) {
                return false;
            }
        }
        return true;
    }
    else if( abs(x-X) == abs(y-Y) ) {
        int i,j;
        int movX = (x>X? 1:-1);
        int movY = (y>Y? 1:-1);
        for (i = X + movX, j = Y +movY ; i!=x && j!=y; i+=movX, j+=movY) {
            if (e.getPiece(i,j) != NULL) {
                return false;
            }
        }
        return true;
    }

    return false;
}

void
Reine::paintEvent(QPaintEvent *){
    QString name = "";
    if(m_white){
        name = "WQueen.png";
    }
    else {
        name = "BQueen.png";
    }
    paintPiece(name);
}
