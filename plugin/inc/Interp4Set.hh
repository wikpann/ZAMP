#ifndef  COMMAND4Set_HH
#define  COMMAND4Set_HH

#include "AbstractInterp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Set
 *
 * Plik zawiera definicję klasy Interp4Set ...
 */

/*!
 * \brief Modeluje interpreter polecenia Set
 *
 *  Klasa modeluje interpreter polecenie dla modelu obiektu fizycznego,
 *  które wymusza jego pozycję.
 */
class Interp4Set: public AbstractInterp4Command {

 public:
  /*!
   * \brief
   */
  Interp4Set();  
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
   */
  virtual void PrintSyntax() const override;

 };

#endif
