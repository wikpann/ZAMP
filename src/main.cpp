#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "AbstractInterp4Command.hh"
#include "LibInterface.hh"
#include "Set4LibInterface.hh"

using namespace std;

#define PLUGIN_NAME__move "libInterp4Move.so"
#define PLUGIN_NAME__pause "libInterp4Pause.so"
#define PLUGIN_NAME__rotate "libInterp4Rotate.so"
#define PLUGIN_NAME__set "libInterp4Set.so"



int main()
{
  // void *pLibHnd_Move;
  // AbstractInterp4Command *(*pCreateCmdInterp_Move)(void);
  // std::string cmdName = "Pause";
  // LibInterface interface(pLibHnd_Move, cmdName, pCreateCmdInterp_Move);
  // interface.loadPlugin();
  // interface.printSyntax();

  Set4LibInterface map;
  map.AddPlugin("Move");
  map.AddPlugin("Pause");
  map.AddPlugin("Set");
  map.AddPlugin("Rotate");

  map.FindPlugin("Set")->printSyntax();
}
