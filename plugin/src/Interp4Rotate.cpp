#include <iostream>
#include "Interp4Rotate.hh"


using std::cout;
using std::endl;


extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
}




/*!
 * \brief Tworzy obiekt klasy Interp4Rotate.
 *
 * Tworzy obiekt klasy Interp4Rotate.
 * \return Zwraca wskaźnik na obiekt klasy bazowej utworzonego
 *         obiektu klas Inter4Rotate.
 */
AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Rotate();
}


/*!
 *
 */
Interp4Rotate::Interp4Rotate()
{}



/*!
 * Wyświetla składnię polecenia.
 */
void Interp4Rotate::PrintSyntax() const
{
  cout << "   Rotate  NazwaObiektu  NazwaOsi[x|y|z]  SzybkoscKatowa[stopnie/s]  KatObrotu[stopnie]" << endl;
}
