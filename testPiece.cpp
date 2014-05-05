/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"
#include "Cavalier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;


/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  // instancie un objet p1 de type Piece
  //Piece p1;
  // p1 est une piece blanche de coordonnees (3,3)
  //p1.init( 3, 3,true );

  // On l'affiche
  /*
  cout << "Piece: x=" << p1.x() << " y=" << p1.y() << " "
       << ( p1.isWhite() ? "blanche" : "noire" ) << endl;
  */
  //p1.affiche();

  //Test constructeur avec parametre
  //Piece p2(1,1,false);
  //p2.affiche();
  /*
  cout << "Piece: x=" << p2.x() << " y=" << p2.y() << " "
       << ( p2.isWhite() ? "blanche" : "noire" ) << endl;
  */

  //Piece tab[4];

  //Tester class Joueur
  /*
  cout << "Player 1: " << endl;
  Joueur player1(true);
  player1.affiche();

  cout << "Player 2: " << endl;
  Joueur player2(false);
  player2.affiche();
  */

  //Tester 2 piece meme endroit
  /*
  Piece p3(1,1,true);
  cout << "Tester !!!" << endl;
  cout << ( p3.isExisted(p1)? "Il existe une piece ici" : "Valide") << endl;
  cout << ( p3.isExisted(p2)? "Il existe une piece ici" : "Valide") << endl;
  */

  //Tester passage par reference
  /*
  cout << " Tester !!!" << endl;
  Piece p3;
  p3 = p1.plusforte(p2);
  */

  //Tester Echiquier
  Echiquier e;
  //Joueur player1(true);  //Player white
  //Joueur player2(false); //Player black
  //e.placer(&p1);
  //e.placer(&p2);


  //Placer les piece dans l'echiquier
  /*
  JoueurBlanc player1;
  JoueurNoir player2;

  player1.placerPiece(e);
  player2.placerPiece(e);
  player1.affiche();
  player2.affiche();
  */

  //e.deplacer(&p2, 5,5);
  // /*
  Fou f(2,1,false);
  e.placer(&f);
  Tour t(6,6,true);
  e.placer(&t);
  e.affiche();

  if(t.mouvementValide(e,6,8)) {
       cout << "Tour Yes!!!" << endl;
       e.deplacer(&t,6,8);
    }

  if (f.mouvementValide(e,8,7)) {
      cout << "Fou Yes!!!" << endl;
      e.deplacer(&f,8,7);
    }

  // */
  e.affiche();


  // les objets definis dans cette fonction sont automatiquement d�truits.
  // Ex : p1

}
