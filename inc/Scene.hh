#ifndef SCENE_HH
#define SCENE_HH
#include <string>
#include <memory>
#include "GeomObject.hh"

class Scene {
public:
    bool AddGeomObj(const std::string &ObjName);
    std::shared_ptr<GeomObject> FindGeomObject(const std::string &ObjName);
};

#endif