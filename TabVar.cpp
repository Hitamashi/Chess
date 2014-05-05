// fichier TabVar.cc
#include "TabVar.h"
#include "Piece.h"
// constructeur par défaut :
// initialise les données membres
template <class T>
TabVar<T>::TabVar(){
  m_tailleMax=m_nbElems=0;
  m_tab=NULL;
}
// constructeur avec paramètre
// crée un tableau "vide" de taille 'taille'
template <class T>
TabVar<T>::TabVar(int taille){
  m_nbElems=0;
  m_tailleMax=taille;
  m_tab=new T[m_tailleMax];
}
// destructeur. Désalloue si besoin
template <class T>
TabVar<T>::~TabVar(){
  if(m_tab!=NULL)
    delete[] m_tab;
}
// constructeur par copie
// alloue et recopie
template <class T>
TabVar<T>::TabVar(const TabVar<T>& t){
  m_nbElems=t.m_nbElems;
  m_tailleMax=t.m_tailleMax;
  m_tab=new T[m_tailleMax];
  for(int i=0;i<m_nbElems;i++)
    m_tab[i]=t.m_tab[i];
}
// affectation ; désalloue si besoin
// puis alloue et recopie
template <class T>
TabVar<T>& TabVar<T>:: operator=(const TabVar<T>& t){
  if(this!=&t){
    if(m_tab!=NULL)
      delete[] m_tab;
    m_nbElems=t.m_nbElems;
    m_tailleMax=t.m_tailleMax;
    m_tab=new T[m_tailleMax];
    for(int i=0;i<m_nbElems;i++)
      m_tab[i]=t.m_tab[i];
  }
  return *this;
}
// permet d'accéder en lecture/écriture à un élément du tableau
// on écrit t[i] et on accède à t.m_tab[i]
template <class T>
T& TabVar<T>::operator[](int i) const {
  return m_tab[i];
}
// taille effectivement utilisée
template <class T>
int TabVar<T>::size() const{
  return m_nbElems;
}
// insertion d'un élément en position i
template <class T>
void TabVar<T>::insert(int place, const T& elem){
  // si on a la place, on décale, puis on insère :
  if(m_nbElems<m_tailleMax){
    for(int i = m_nbElems; i > place ; i--)
      m_tab[i]=m_tab[i-1];
    m_tab[place]=elem;
    m_nbElems++;
  }
  // sinon : le tableau est plein : on réalloue plus grand
  else{
    T* tmp = new T[++m_tailleMax];
    m_nbElems++;
    // on recopie en insérant où il faut
    int i;
    for(i=0;i<place;i++)
      tmp[i]=m_tab[i];
    tmp[place]=elem;
    for(i=place+1;i<m_nbElems;i++)
      tmp[i]=m_tab[i-1];
    // on désalloue si le tableau n'était pas vide avant ;
    if(m_tailleMax>1)
      delete[] m_tab;
    m_tab=tmp;
  }
}

template class TabVar<int>;
template class TabVar<float>;
template class TabVar<string>;
template class TabVar<char>;
template class TabVar<double>;
template class TabVar<Piece *>;
