
/**
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cxx
 */

#include <iostream>
// A besoin de la declaration de la classe
#include "Echiquier.h"
#include "Joueur.h"
#include <QPainter>

using namespace std;

/**
 * Constructeur par d�faut.
 * Initialise � vide l'echiquier.
 */
Echiquier::Echiquier(QWidget *parent):
    QWidget(parent)
{
    this->setFixedSize(SIZE*8+1,SIZE*8+1);
    QRect rect = this->geometry();
    rect.setTop(rect.top() + POS_Y);
    rect.setBottom(rect.bottom() + POS_Y);
    rect.setLeft(rect.left() + POS_X);
    rect.setRight(rect.right() + POS_X);
    this->setGeometry(rect);

    cout << "Echiquier creee " << endl;
    for(int i = 0; i< 64; i++) {
        //m_cases.insert(i,NULL);
        m_cases.push_back(NULL);
    }

    piece_slt = NULL;
    pieceSelected = false;
    this->setMouseTracking(true);
    m_joueurCourant = false;
    changerJoueur();
    endGame = false;
}


/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
Piece*
Echiquier::getPiece( int x, int y )
{
    if ( x>8 || x<1 || y>8 || y<1 ) {
        return NULL;
    }

    int indice = (x-1) + (y-1)*8;
    if (m_cases[indice] != NULL){
        Piece* p = m_cases[indice];
        return p;
    }
    else
        return NULL;
}


/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool
Echiquier::placer( Piece* p )
{
    int x = p->x();
    int y = p->y();
    //Coordonnes invalides
    if ( x>8 || x<1 || y>8 || y<1 )
        return false;

    //Piece vide
    if (p == NULL)
        return false;

    //Case occupee
    int indice = (x-1) + (y-1)*8;
    if (m_cases[indice] != NULL )
        return false;

    connect(p,SIGNAL(clickPiece()),SLOT(pieceClicked()));
    connect(p,SIGNAL(releasePiece()),SLOT(pieceReleased()));
    m_cases[indice] = p;

    return true;
}


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
bool
Echiquier::deplacer( Piece* p, int x, int y )
{
    int pos_x = p->x();
    int pos_y = p->y();
    //Coordonnes invalides
    if ( x>8 || x<1 || y>8 || y<1 )
        return false;

    //Piece vide
    if (p == NULL)
        return false;

    //Piece pas present au bon endroit
    int indice1 = (pos_x-1) + (pos_y-1)*8;
    if (m_cases[indice1]!=p)
        return false;

    if(!p->mouvementLegal(*this,x,y)) {
        return false;
    }

    m_cases[indice1] =NULL;
    p->movePiece(x,y);
    int indice2 = (x-1) + (y-1)*8;

    Piece* p_opp = enleverPiece(x,y);
    if(p_opp!=NULL){
        p_opp->movePiece(9,9);
    }

    m_cases[indice2] = p;
    return true;
}


/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
Piece*
Echiquier::enleverPiece( int x, int y )
{
    if ( x>8 || x<1 || y>8 || y<1 ) {
        return NULL;
    }

    int indice = (x-1) + (y-1)*8;
    if (m_cases[indice] != NULL) {
        return m_cases[indice];
    }
    else
        return NULL;
}


/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */

void
Echiquier::affiche()
{
  cout << endl << "  1 2 3 4 5 6 7 8" << endl;
  for ( int y = 1; y <= 8; ++y )
    {
      cout << y << " ";
      for ( int x = 1; x <= 8; ++x )
    {
      char c;
      Piece* p = getPiece( x, y );
      if ( p == 0 )
        c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
      else
        c = p->isWhite() ? 'B' : 'N';
      cout << c << " ";
    }
      cout << " " << y << endl;
    }
  cout << "  1 2 3 4 5 6 7 8" << endl;
}

/**
 * Verifier si le Roi est en danger
 * @brief IsChecked
 * @param white
 * @return true si le Roi en danger, false sinon
 */
bool
Echiquier::IsChecked(bool white) {
    int roiX, roiY;
    //Trouver le Roi
    for (int i=1; i<9; i++) {
        for (int j=1; j<9; j++){
            int indice = (i-1) + (j-1)*8;
            Piece* temp = m_cases[indice];
            Roi* roi_tmp = dynamic_cast<Roi*>(temp);
            if (roi_tmp != NULL){
                if (roi_tmp->isWhite() == white) {
                    roiX = roi_tmp->x();
                    roiY = roi_tmp->y();
                }
            }
        }
    }

    //verifier qui les piece qui peuvent atk le Roi
    for (int i=1; i<9; i++) {
        for (int j=1; j<9; j++){
            int indice = (i-1) + (j-1)*8;
            Piece* temp = m_cases[indice];
            if (temp != NULL){
                if (temp->isWhite() != white) {
                    if(temp->mouvementLegal(*this,roiX,roiY)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/**
 * Verifier qu'un player peut continue jouer
 * @brief CanMove
 * @param player
 * @return true si le joueur peut deplacer au moins une piece,
 * false sinon.
 */
bool
Echiquier::CanMove(bool player) {
    for(int row=1; row<9; row++){
        for (int col=1; col<9; col++){
            int indice1 = (row-1) + (col-1)*8;
            if(m_cases[indice1] != NULL) {
                if(m_cases[indice1]->isWhite() == player) {
                    for(int rowM=1; rowM<9; rowM++){
                        for(int colM=1; colM<9; colM++){
                            int indice2 = (rowM-1) + (colM-1)*8;
                            Piece* temp1 = m_cases[indice1];
                            Piece* temp2 = m_cases[indice2];
                            bool move;
                            if(deplacer(temp1,rowM,colM)){
                                move = !IsChecked(player);
                                temp1->movePiece(row,col);
                                m_cases[indice1] = temp1;
                                m_cases[indice2] = NULL;
                                if(temp2!=NULL){
                                    temp2->movePiece(rowM,colM);
                                    m_cases[indice2] = temp2;
                                }
                                if(move) return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;

}

/**
 * Changer le m_joueurCourant
 * @brief changerJoueur
 */
void Echiquier::changerJoueur(){
    m_joueurCourant = !m_joueurCourant;
    QString player = "White";
    if(!m_joueurCourant) player = "Black";

    QWidget* p = dynamic_cast<QWidget*>(this->parent());
    QMainWindow* window = dynamic_cast<QMainWindow*>(p->parent());
    QStatusBar* bar = window->findChild<QStatusBar*>("statusBar");
    bar->showMessage("Turn: " + player);
}

bool
Echiquier::IsGameOver(){
    bool move = this->CanMove(m_joueurCourant);
    if (!move) {
        QMessageBox mess(this);
        mess.setFont(QFont("MV Boli",12) );
        QString result = "";
        if (this->IsChecked(m_joueurCourant)) {
            changerJoueur();
            QString winner = "Player Black wins!";
            if(m_joueurCourant) winner = "Player White wins!";
            mess.setText("Checkmate!\t\n" + winner);
            result = winner;
        }
        else {
            mess.setText("Stalemate!\t");
            result = "Stalemate!";
        }
        mess.exec();

        //Status bar change
        QWidget* p = dynamic_cast<QWidget*>(this->parent());
        QMainWindow* window = dynamic_cast<QMainWindow*>(p->parent());
        QStatusBar* bar = window->findChild<QStatusBar*>("statusBar");
        bar->showMessage(result + " New Game to restart.");
    }
    return !move;
}

bool
Echiquier::getEndGame() {
    return endGame;
}

/**
 * Affiche l'echiquier sur GUI
 */
void
Echiquier::paintEvent(QPaintEvent *) {
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawRect(0,0,this->width()-1,this->height()-1);


    for(int i = 1; i<9; i++) {
        painter.drawLine(0, i*SIZE, this->width(), i*SIZE);
        painter.drawLine(i*SIZE, 0, i*SIZE, POS_Y+this->height());
    }


    for(int i=0; i<8; i++) {
        for(int j=0; j<8;j++) {
            int rectX = i*SIZE+1;
            int rectY = j*SIZE+1;

            if( (i+j)%2 == 0 ){
                painter.fillRect(rectX,rectY,SIZE-1,SIZE-1,QColor(239,222,192));
            }
            else {
                painter.fillRect(rectX,rectY,SIZE-1,SIZE-1,QColor(183,146,130));
            }

            if(piece_slt !=NULL)
                if(piece_slt->mouvementLegal(*this,i+1,j+1)){
                    painter.fillRect(rectX,rectY,SIZE-1,SIZE-1,QColor(175,211,101));
                }
        }
    }
    painter.end();
}

void
Echiquier::mouseMoveEvent(QMouseEvent *e) {
    mousePos = e->pos();
    if(piece_slt != NULL){
        piece_slt->move(e->x()-SIZE/2, e->y()-SIZE/2);
    }
}

void
Echiquier::pieceClicked(){
    Piece* b = (Piece*)sender();

    if(b->isWhite() == m_joueurCourant && !endGame){
        m_mouseClickPos = mousePos;
        piece_slt = b;
        pieceSelected = true;
        b->setSelected(true);
        b->repaint();
        this->repaint();
    }
    else
    {
        anonSelectInvalid();
    }

}

void
Echiquier::pieceReleased(){
    Piece* b = (Piece*)sender();

    int posX = mousePos.x()/SIZE + 1;
    int posY = mousePos.y()/SIZE + 1;
    int x0 = b->x();
    int y0 = b->y();
    bool mouveValide = false;
    bool kingChecked = false;

    if(m_mouseClickPos != mousePos){
        if(pieceSelected){
            int ind1 = (x0-1) + (y0-1)*8;
            int ind2 = (posX-1) + (posY-1)*8;
            Piece* temp = getPiece(posX,posY);

            //Deplacer piece
            if(deplacer(b, posX, posY)){
                //Verifier si le Roi en danger
                if(!IsChecked(m_joueurCourant)){
                    mouveValide = true;
                }
                //Undo le mouvement
                else{
                    kingChecked = true;
                    b->movePiece(x0,y0);
                    m_cases[ind1] = b;
                    m_cases[ind2] = NULL;
                    if(temp!=NULL){
                        temp->movePiece(posX,posY);
                        m_cases[ind2] = temp;
                    }
                }
            }
        }
    }    

    pieceSelected = false;
    piece_slt = NULL;

    b->movePiece(b->x(),b->y());
    b->setSelected(false);
    b->repaint();
    this->repaint();

    if(!mouveValide){
        if (m_mouseClickPos != mousePos)
            anonMoveInvalid(kingChecked);
    }
    else {
        Pion* pion = dynamic_cast<Pion*>(b);
        if(pion!=NULL){
            if(pion->canPromote())
                anonPawnPromote(b);
        }
        changerJoueur();
        endGame = IsGameOver();
        if(!endGame && IsChecked(m_joueurCourant))
            anonCheck();
    }
}


void
Echiquier::anonSelectInvalid(){
    QString text = "It's White's turn";
    if(!m_joueurCourant) text = "It's Black's turn";
    if(endGame) text = "Game Over";

    QMessageBox mess(this);
    mess.setWindowTitle("Selection invalid!");
    mess.setText(text);
    mess.setFont(QFont("MV Boli", 12));
    mess.exec();
}

void
Echiquier::anonMoveInvalid(bool checked){
    QString king = "";
    if(checked) king = "\nYou're checked!\t";
    QMessageBox mess(this);
    mess.setWindowTitle("Move invalid!");
    mess.setIcon(QMessageBox::Warning);
    mess.setText("Move again" + king);
    mess.setFont(QFont("MV Boli", 12));
    mess.exec();
}


void
Echiquier::anonCheck(){
    QString player = "White ";
    if(!m_joueurCourant) player = "Black ";
    QMessageBox mess(this);
    mess.setWindowTitle("Check!");
    mess.setText(player+ "is checked\t");
    mess.setFont(QFont("MV Boli", 12));
    mess.exec();
}

void
Echiquier::anonPawnPromote(Piece* p){
    QString choix = "";
    QStringList pion;
    pion << "Queen" << "Knight" << "Rook" << "Bishop";

    QInputDialog dialog(this);
    dialog.setFont(QFont("MV Boli", 12));

    while(choix == ""){
        choix = dialog.getItem
            (this, "Promotion",
             "Which piece do you want to promote to?", pion,0,false);
    }

    int X = p->x();
    int Y = p->y();
    bool white = p->isWhite();
    p->movePiece(9,9);
    int indice = (X-1) + (Y-1)*8;
    m_cases[indice] = NULL;

    if(choix == "Queen") {
        //...
        Reine* reine = new Reine(X,Y,white, this);
        this->placer(reine);
        reine->setVisible(true);
        reine->movePiece(X,Y);
    }
    else if(choix == "Knight") {
        //...
        Cavalier* cav = new Cavalier(X,Y,white, this);
        this->placer(cav);
        cav->setVisible(true);
        cav->movePiece(X,Y);
    }
    else if(choix == "Rook") {
        //...
        Tour* tour = new Tour(X,Y,white, this);
        this->placer(tour);
        tour->setVisible(true);
        tour->movePiece(X,Y);
    }
    else if(choix == "Bishop") {
        //...
        Fou* fou = new Fou(X,Y,white, this);
        this->placer(fou);
        fou->setVisible(true);
        fou->movePiece(X,Y);
    }
}
