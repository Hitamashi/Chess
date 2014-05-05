/**
 * Header de Echiquier.cxx
 *
 * @file Echiquier.h
 */

#if !defined Echiquier_h
#define Echiquier_h

#include "TabVar.h"
#include <vector>
#include <QWidget>

class Piece;

/**
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */
class Echiquier : public QWidget
{
    Q_OBJECT
private:
  /**
   * Les cases de l'echiquier
   */
    vector <Piece*> m_cases;
    bool m_joueurCourant;
    bool endGame;

   /**
    * Les annoncer
    */
    /** Annoncer si mouvement est invalide
     * @brief anonMoveInvalid
     * @param checked
     */
    void anonSelectInvalid();
    void anonMoveInvalid(bool checked);
    void anonCheck();
    void anonPawnPromote(Piece *p);

public:
    const static int SIZE = 60;
    const static int POS_X = 10;
    const static int POS_Y = 10;
  /**
   * Constructeur par d�faut.
   * Initialise � vide l'echiquier.
   */
  Echiquier(QWidget *parent);

  /**
   * Recupere la piece situee sur une case.
   *
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 0 si aucune piece n'est sur cette case et un pointeur
   * vers une piece sinon.
   */
  Piece* getPiece( int x, int y );

  /**
   * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
   *
   * @param p un pointeur vers une piece
   *
   * @return 'true' si le placement s'est bien passe, 'false' sinon
   * (case occupee, coordonnees invalides, piece vide )
   */
  bool placer( Piece* p );

  /**
   * Deplace une piece sur l'echiquier, des coordonnees specifiees
   * dans la piece aux coordonnees x,y.
   *
   * @param p un pointeur vers une piece
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 'true' si le placement s'est bien passe, 'false' sinon
   * (case occupee, coordonnees invalides, piece vide, piece pas
   * presente au bon endroit sur l'echiquier)
   */
  bool deplacer( Piece* p, int x, int y );

  /**
   * Enleve la piece situee sur une case (qui devient vide).
   *
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 0 si aucune piece n'est sur cette case et le pointeur
   * vers la piece enlevee sinon.
   */
  Piece* enleverPiece( int x, int y );

  /**
   * Affiche l'echiquier avec des # pour les cases noires et . pour
   * les blanches si elles sont vides, et avec B pour les pieces
   * blanches et N pour les pieces noires.
   */
  void affiche();

  /**
   * Methode pour dessiner Echiquier
   * @brief paintEvent
   * @param e
   */
  void paintEvent(QPaintEvent *);

  /**
   * Verifier si le Roi est en danger
   * @brief IsChecked
   * @param white
   * @return true si le Roi en danger, false sinon
   */
  bool IsChecked(bool white);

  /**
   * Verifier qu'un player peut continue jouer
   * @brief CanMove
   * @param player
   * @return true si le joueur peut deplacer au moins une piece,
   * false sinon.
   */
  bool CanMove(bool player);

  /**
   * Changer le m_joueurCourant
   * @brief changerJoueur
   */
  void changerJoueur();

  /**
   * Verifier si le jeu peut continuer
   * @brief IsGameOver
   * @return true if "stalemate" ou "checkmate", false sinon
   */
  bool IsGameOver();

  bool getEndGame();

  /**
   * Les methodes et les attributs pour gerer mouse_event
   *
   */
protected:
    bool pieceSelected;
    Piece* piece_slt;
    QPoint mousePos;
    QPoint m_mouseClickPos;

protected slots:
    void mouseMoveEvent(QMouseEvent *e);

public slots:
    void pieceClicked();
    void pieceReleased();
};

#endif // !defined Echiquier_h

