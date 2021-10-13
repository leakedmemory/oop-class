#ifndef Person_hpp
#define Person_hpp

#include <string>

class Person
{
public:
    Person(std::string);
    virtual ~Person();

    std::string getName() const;

protected:
    std::string name;
};

#endif
