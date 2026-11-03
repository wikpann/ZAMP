#include <iostream>
#include "Interp4Set.hh"


using std::cout;
using std::endl;


extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
}




/*!
 * \brief Tworzy obiekt klasy Interp4Set.
 *
 * Tworzy obiekt klasy Interp4Set.
 * \return Zwraca wskaźnik na obiekt klasy bazowej utworzonego
 *         obiektu klas Inter4Set.
 */
AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Set();
}


/*!
 *
 */
Interp4Set::Interp4Set()
{}



/*!
 * Wyświetla składnię polecenia.
 */
void Interp4Set::PrintSyntax() const
{
  cout << "   Set  NazwaObiektu  WspX  WspY  WspZ  KatOX[stopnie]  KatOY[stopnie]  KatOZ[stopnie]" << endl;
}
