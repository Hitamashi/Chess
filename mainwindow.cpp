#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Echiquier.h"
#include "Joueur.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(700,520);
    this->setWindowTitle("Chess Game");
    QPixmap icon(128,128);
    icon.load(":/Images/ChessIcon.png");
    this->setWindowIcon(QIcon(icon));

    QWidget* central = centralWidget();
    chessBoard = new Echiquier(central);

    QPushButton* pNew = central->findChild<QPushButton*>("pBNew");
    QPushButton* pExit = central->findChild<QPushButton*>("pBExit");
    QStatusBar* status = statusBar();
    status->showMessage("Press New Game to Start");

    connect(pNew,SIGNAL(clicked()),SLOT(buttonNew()));
    connect(pExit,SIGNAL(clicked()),SLOT(close()));

    this->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::buttonNew() {
    QPushButton *p = (QPushButton*) sender();

    QWidget* central = this->centralWidget();
    delete chessBoard;
    chessBoard = new Echiquier(central);
    chessBoard->setVisible(true);
    playerWhite = new JoueurBlanc(chessBoard);
    playerBlack = new JoueurNoir(chessBoard);
}
