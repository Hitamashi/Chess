/** 
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include "Piece.h"
#include<iostream>

using namespace std;

Piece::Piece()
{
    this->setFixedSize(Echiquier::SIZE,Echiquier::SIZE);
	cout << "Une piece creee: par defaut" << endl;
  // ne fait rien => objet instancie mais non valide.
   m_selected = false;
   setCursor(Qt::OpenHandCursor);
}

//Constructeur avec parametre
Piece::Piece(int x, int y, bool white, Echiquier *parent):
    QWidget(parent)
{
    this->setFixedSize(Echiquier::SIZE,Echiquier::SIZE);
	cout << "Une piece creee: avec parametre" << endl;
	m_x = x;
	m_y = y;
	m_white = white;
    m_selected = false;
    movePiece(x,y);
    setCursor(Qt::OpenHandCursor);
}

//Constructeur par copie
Piece::Piece(const Piece &autre)
{
    this->setFixedSize(Echiquier::SIZE, Echiquier::SIZE);
    this->setGeometry(autre.geometry());
	m_x = autre.m_x;
	m_y = autre.m_y;
	m_white = autre.m_white;
    m_selected = autre.m_selected;
    setCursor(Qt::OpenHandCursor);
}

Piece::~Piece()
{
	//cout << "Une piece detruite" << endl;
}

void
Piece::movePiece( int x, int y )
{
    int size = Echiquier::SIZE;
    this->move((x-1)*size,(y-1)*size);

    m_x = x;
    m_y = y;
}

int
Piece::x()
{
  return m_x;
}

int
Piece::y()
{
  return m_y;
}

bool
Piece::isWhite()
{
  return m_white;
}

void
Piece::setSelected(bool select){
    m_selected = select;
}

bool
Piece::mouvementLegal( Echiquier & e, int x, int y ) {
    if (e.getPiece(x,y) == NULL) {
        if(mouvementValide(e,x,y)){
            return true;
        }
    }
    else if ( e.getPiece(x,y)->isWhite() != this-> isWhite() ) {
        if(mouvementValide(e,x,y)) {
            return true;
        }
    }
	return false;
}

bool 
Piece::mouvementValide( Echiquier & e, int x, int y )
{
}

void
Piece::paintEvent(QPaintEvent *)
{
}

void
Piece::paintPiece(QString name)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int size = Echiquier::SIZE;

    if(m_selected){
        QColor color(162,107,205);
        painter.fillRect(1,1,size-1,size-1,color);
    }

    QImage img;
    //img.load(name);
    img.load(":/Images/" + name);
    if(img.isNull()) {
        painter.drawText(120,20,"Image");
    }
    else {
        QPixmap pix;
        pix = QPixmap::fromImage(img);
        if(pix.isNull()) {
            painter.drawText(70,20,"Pixmap");
        }
        else {
            painter.drawPixmap(0,0,size,size,pix);
        }

    }
    painter.end();
}

void
Piece::mousePressEvent ( QMouseEvent *e )
{
    // Store the click point
    m_clicked = true;
    m_mousePos = e->pos();
    setCursor(Qt::ClosedHandCursor);
    emit clickPiece();
}

void
Piece::mouseReleaseEvent ( QMouseEvent *e )
{
    // check if cursor not moved since click beginning
    int size = Echiquier::SIZE;
    QRect rect = QRect(0,0,size,size);
    if ((m_clicked) && (rect.contains(e->pos())))
    {
        // emit release signal
        emit releasePiece();
    }
    m_clicked = false;
    setCursor(Qt::OpenHandCursor);
}
