#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Echiquier.h"
#include "Joueur.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Echiquier* chessBoard;
    JoueurBlanc* playerWhite;
    JoueurNoir* playerBlack;

private slots:
    void buttonNew();

};

#endif // MAINWINDOW_H
