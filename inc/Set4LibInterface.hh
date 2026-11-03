#ifndef SET4LIBINTERFACE_HH
#define SET4LIBINTERFACE_HH

#include <map>
#include <memory>
#include <LibInterface.hh>
/*!
 * \file 
 * \brief Zawiera definicję klasy LibInterface
 *
 *  Zawiera definicję klasy Set4LibInterface.
 *  Umożliwia ona obsługę kolekcji wtyczek.
 */


class Set4LibInterface : public std::map<std::string, std::shared_ptr<LibInterface>> {
public:
    bool AddPlugin(const std::string &LibName);
    std::shared_ptr<LibInterface> FindPlugin(const std::string &CmdName);
};
#endif 