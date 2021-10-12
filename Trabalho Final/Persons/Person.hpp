#ifndef Person_hpp
#define Person_hpp

#include <string>

class Person
{
public:
    virtual ~Person();

    std::string getName() const { return this->name; }

protected:
    std::string name;
};

#endif
