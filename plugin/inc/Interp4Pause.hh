#ifndef  COMMAND4Pause_HH
#define  COMMAND4Pause_HH

#include "AbstractInterp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Pause
 *
 * Plik zawiera definicję klasy Interp4Pause ...
 */

/*!
 * \brief Modeluje interpreter polecenia Pause
 *
 *  Klasa modeluje interpreter polecenie dla modelu obiektu fizycznego,
 *  które wymusza jego zatrzymanie się.
 */
class Interp4Pause: public AbstractInterp4Command {

 public:
  /*!
   * \brief
   */
  Interp4Pause();  
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
   */
  virtual void PrintSyntax() const override;

 };

#endif
