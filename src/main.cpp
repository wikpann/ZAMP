#include <iostream>
#include <fstream>
#include "AbstractInterp4Command.hh"
#include "LibInterface.hh"
#include "Set4LibInterface.hh"

using namespace std;

#define PLUGIN_NAME__move "libInterp4Move.so"
#define PLUGIN_NAME__pause "libInterp4Pause.so"
#define PLUGIN_NAME__rotate "libInterp4Rotate.so"
#define PLUGIN_NAME__set "libInterp4Set.so"



int main(int argc, char* argv[])
{
  std::string line;

  if(argc < 2) {
    std::cout << "Za mała liczba argumentów" << std::endl;
    return 1;
  }
  std::fstream file(argv[1]);

  if(!file.is_open()) {
    std::cerr << "Nie udało się otworzyć pliku" << std::endl;
    return 1;
  }

  Set4LibInterface plugins;
  
  while(std::getline(file, line)) {
    std::shared_ptr<LibInterface> cmd = plugins.FindPlugin(line);
    if(cmd == nullptr) {
      plugins.AddPlugin(line);
      cmd = plugins.FindPlugin(line);
    }
    cmd->printSyntax();
  }

  file.close();

  // void *pLibHnd_Move;
  // AbstractInterp4Command *(*pCreateCmdInterp_Move)(void);
  // std::string cmdName = "Pause";
  // LibInterface interface(pLibHnd_Move, cmdName, pCreateCmdInterp_Move);
  // interface.loadPlugin();
  // interface.printSyntax();




  return 0;
}
