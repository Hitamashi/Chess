/** 
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

#include "Echiquier.h"
#include <QtWidgets>
#include <string>
#include <QObject>

class Echiquier;
/**
 * Declaration d'une classe modélisant une piece de jeu d'echec.
 */
class Piece : public QWidget
{
    Q_OBJECT
protected:
  int m_x;
  int m_y;
  bool m_white;
  bool m_clicked;
  bool m_selected;
  QPoint m_mousePos;

public:
  Piece();
  Piece(int x, int y, bool white, Echiquier* parent);
  Piece(const Piece &autre);
  ~Piece();

  void movePiece( int x, int y );
  int x();
  int y();
  bool isWhite();
  void setSelected(bool select);

  bool mouvementLegal(Echiquier &e, int x, int y);
  virtual bool mouvementValide( Echiquier & e, int x, int y );

protected:
  virtual void paintEvent(QPaintEvent *);
  void paintPiece(QString name);

signals:
  void clickPiece();
  void releasePiece();

public:
    void mouseReleaseEvent ( QMouseEvent * e );
    void mousePressEvent ( QMouseEvent * e );
}; 

#endif // !defined Piece_h
