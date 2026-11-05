#ifndef GEOMOBJECT_HH
#define GEOMOBJECT_HH
#include <string>

class GeomObject {
private:
    std::string &Name;

public:
    const std::string &GetName() const;
    void SetName(const std::string &Name);
};

#endif