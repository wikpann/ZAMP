#include <iostream>
#include <dlfcn.h>
#include "LibInterface.hh"

LibInterface::LibInterface(void *LibHandler, std::string &CmdName, AbstractInterp4Command* (*pCreateInterp)(void)) {
    _LibHandler = LibHandler;
    _CmdName = CmdName;    
    _pCreateInterp = pCreateInterp;

}

LibInterface::~LibInterface() {
    if(dlclose(_LibHandler) == -1) {
        std::cerr << "!!! Nie udało się zwolnić biblioteki " << std::endl;
        std::exit(1);
    }
}

void LibInterface::loadPlugin() {
    const std::string plugin_name = "libInterp4" + _CmdName + ".so";
    
    _LibHandler = dlopen(plugin_name.c_str(), RTLD_LAZY);
    if(_LibHandler == nullptr) {
        std::cerr << "!!! Nie znaleziono wtyczki " << plugin_name << std::endl;
        std::exit(1);
    }

    void *pFun = dlsym(_LibHandler,"CreateCmdInterp");
    if (pFun) {
        std::cout  << ":)  Funkcja \"CreateCmdInterp\" zostala znaleziona we wtyczce "
	    << "\"" << plugin_name << "\"." << std::endl;
    } else {
        std::cerr << "!!! Nie znaleziono funkcji CreateCmdInterp" << std::endl;
        std::exit(1);
    }

    _pCreateInterp = reinterpret_cast<AbstractInterp4Command* (*)(void)>(pFun); 
}

void LibInterface::printSyntax() {
    if(_pCreateInterp == nullptr) {
        std::cerr << "!!! Wtyczka " << _CmdName << "nie została załadowana" << std::endl;
        return;
    }

    AbstractInterp4Command *pInterp = _pCreateInterp();

    std::cout << std::endl;
    pInterp->PrintSyntax();
    std::cout << std::endl;
  
    delete pInterp;
}