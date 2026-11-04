#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include <string>
#include "AbstractInterp4Command.hh"

/*!
 * \file 
 * \brief Zawiera definicję klasy LibInterface
 *
 *  Zawiera definicję klasy LibInterface.
 *  Zapewnia ona dostęp do danej wtyczki oraz funkcji interfejsu wtyczki obsługującej dane polecenie.
 */

 /*!
  * \brief Zapewnia dostęp do wtyczki oraz funkcji jej interfejsu.
  *
  * Znajduje i wczytuje wtyczkę oraz wyświetla komunikat o ewentualnym niepowodzeniu.
  * Pozwala na dostęp do funkcji interfejsu danej wtyczki
  */
class LibInterface {
private:
    void *_LibHandler;
    std::string _CmdName;
    AbstractInterp4Command* (*_pCreateInterp)(void);

public:
    LibInterface(void *LibHandler, std::string &CmdName, AbstractInterp4Command* (*pCreateInterp)(void));
    ~LibInterface();
    void loadPlugin();
    void printSyntax();
};

#endif