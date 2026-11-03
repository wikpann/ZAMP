#include <iostream>
#include "Interp4Pause.hh"


using std::cout;
using std::endl;


extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
}




/*!
 * \brief Tworzy obiekt klasy Interp4Pause.
 *
 * Tworzy obiekt klasy Interp4Pause.
 * \return Zwraca wskaźnik na obiekt klasy bazowej utworzonego
 *         obiektu klas Inter4Pause.
 */
AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Pause();
}


/*!
 *
 */
Interp4Pause::Interp4Pause()
{}



/*!
 * Wyświetla składnię polecenia.
 */
void Interp4Pause::PrintSyntax() const
{
  cout << "   Pause  NazwaObiektu  CzasPausyMs[ms]" << endl;
}
