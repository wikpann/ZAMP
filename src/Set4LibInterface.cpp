#include "Set4LibInterface.hh"

bool Set4LibInterface::AddPlugin(const std::string &LibName) {
    std::string name = LibName;
    
    void *LibHandler = nullptr;
    AbstractInterp4Command *(*pCreateCmdInterp)(void) = nullptr;
    std::shared_ptr<LibInterface> interface(new LibInterface(LibHandler, name, pCreateCmdInterp));
    interface->loadPlugin();
    
    this->insert_or_assign(LibName, interface);
    return true;
}

std::shared_ptr<LibInterface> Set4LibInterface::FindPlugin(const std::string &CmdName) {
    if(this->find(CmdName) == this->end()) {
        return nullptr;
    }
    
    return (*this)[CmdName];
}