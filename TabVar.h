// fichier TabVar.h
#ifndef _TABVAR_H
#define _TABVAR_H
#include <iostream>
#include <string>
using namespace std;
/////////////////////////////////////////////
// une mini-classe template tableau dynamique
/////////////////////////////////////////////
template <class T>  // T est un paramètre de la classe définie juste après
class TabVar{
 public:
  ///////////////////////////////////////
  // méthodes indispensables classiques :
  ///////////////////////////////////////
  TabVar();
  TabVar(int taille);
  ~TabVar();
  TabVar(const TabVar& autre);
  TabVar& operator=(const TabVar& autre);
  ////////////////////////////////////////////////
  // retourne une référence à un objet de type T :
  ////////////////////////////////////////////////
  T& operator[](int i) const;
  //////////////////////
  // quelques services :
  //////////////////////
  // fournit la taille :
  int size() const;
  // ajoute un élément de type T en position i du tableau :
  void insert(int place, const T& elem);
  
 private:

  T* m_tab;
  int m_tailleMax;
  int m_nbElems;
};
// force l'instanciation pour les principaux
// types utilisés ; à compléter si besoin
/*
template class TabVar<int>;
template class TabVar<float>;
template class TabVar<string>;
template class TabVar<char>;
template class TabVar<double>;
*/
#endif
