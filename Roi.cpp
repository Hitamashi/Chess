/** 
 * Mise en oeuvre de Roi.h
 *
 * @file Roi.cxx
 */

#include "Roi.h" 
#include "Echiquier.h"

#include <iostream>
using namespace std;

Roi::Roi(){
    this->setFixedSize(Echiquier::SIZE,Echiquier::SIZE);
}

Roi::Roi(bool white, Echiquier *parent) {
    this->setParent(parent);
    this->setFixedSize(Echiquier::SIZE,Echiquier::SIZE);
	m_white = white;
	m_x = 4;
	if (white) 
		m_y = 1;
	else 
		m_y = 8;
    movePiece(m_x,m_y);
}

bool Roi::mouvementValide( Echiquier & e, int x, int y ) {	
	int X = m_x;
	int Y = m_y;
	
	if( x<1 || x>8 || y<1 || y>8 ) {
		return false;
	}
	
	//Valide mouvement
	if ( x>X+1 || x<X-1 || y>Y+1 || y<Y-1  || (x==X && y==Y) ) {
		return false;
	}
	return true;	
}

void Roi::paintEvent(QPaintEvent *) {
    QString name = "";
    if(m_white){
        name = "WKing.png";
    }
    else {
        name = "BKing.png";
    }
    this->paintPiece(name);
}
