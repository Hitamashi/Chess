/** 
 * Mise en oeuvre de Pion.h
 *
 * @file Pion.cxx
 */

#include "Pion.h" 
#include "Echiquier.h"

#include <iostream>
using namespace std;

Pion::Pion() 
{	
    this->setFixedSize(Echiquier::SIZE,Echiquier::SIZE);
}

Pion::Pion(int x, int y, bool white,Echiquier* parent) : Piece(x,y,white,parent)
{ }

bool
Pion::mouvementValide( Echiquier & e, int x, int y )
{
    int X = m_x;
    int Y = m_y;

    //Dans l'echiquier
    if( x<1 || x>8 || y<1 || y>8 ) {
        return false;
    }

    if(e.getPiece(x,y)==NULL) {
        //Cases pas occuppe
        //Mouver aligné
        if(x == X) {
            if(this->isWhite()) {
                if(this->y() == 2)
                    return y == Y+2 || y == Y+1;
                else
                    return y == Y+1;
            }
            else {
                if(this->y() == 7)
                    return y == Y-2 || y == Y-1;
                else
                    return y == Y-1;
            }
        }
    }
    else {
        //Cases occuppe par opposite couleur
        if ( x==X+1 || x == X-1 ){
            if(this->isWhite()) {
                return y == Y+1;
            }
            else {
                return y == Y-1;
            }
        }
    }
    return false;
}

void
Pion::paintEvent(QPaintEvent *) {
    QString name = "";
    if(m_white){
        name = "WPawn.png";
    }
    else {
        name = "BPawn.png";
    }
    paintPiece(name);
}

bool
Pion::canPromote(){
    if(m_white) return m_y == 8;
    else return m_y == 1;
}
