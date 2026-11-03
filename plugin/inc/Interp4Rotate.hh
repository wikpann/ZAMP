#ifndef  COMMAND4Rotate_HH
#define  COMMAND4Rotate_HH

#include "AbstractInterp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Rotate
 *
 * Plik zawiera definicję klasy Interp4Rotate ...
 */

/*!
 * \brief Modeluje interpreter polecenia Rotate
 *
 *  Klasa modeluje interpreter polecenie dla modelu obiektu fizycznego,
 *  które wymusza jego obrót.
 */
class Interp4Rotate: public AbstractInterp4Command {

 public:
  /*!
   * \brief
   */
  Interp4Rotate();  
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
   */
  virtual void PrintSyntax() const override;

 };

#endif
