#include <iostream>
#include <dlfcn.h>
#include "LibInterface.hh"

LibInterface::LibInterface(void *LibHandler, std::string &CmdName, AbstractInterp4Command* (*pCreateInterp)(void)) {
    _LibHandler = LibHandler;
    _CmdName = CmdName;    
    _pCreateInterp = pCreateInterp;

}

LibInterface::~LibInterface() {
    dlclose(_LibHandler);
}

int LibInterface::loadPlugin() {
    const std::string plugin_name = "libInterp4" + _CmdName + ".so";
    
    _LibHandler = dlopen(plugin_name.c_str(), RTLD_LAZY);
    void *pFun = dlsym(_LibHandler,"CreateCmdInterp");
    if (pFun) {
        std::cout  << ":)  Funkcja \"CreateCmdInterp\" zostala znaleziona we wtyczce "
	    << "\"" << plugin_name << "\"." << std::endl;
    } else {
        std::cerr << "!!! Nie znaleziono funkcji CreateCmdInterp" << std::endl;
        return 0;
    }
    _pCreateInterp = reinterpret_cast<AbstractInterp4Command* (*)(void)>(pFun);

    return 1;
}

void LibInterface::printSyntax() {
    AbstractInterp4Command *pInterp = _pCreateInterp();

    std::cout << std::endl;
    pInterp->PrintSyntax();
    std::cout << std::endl;
  
    delete pInterp;
}