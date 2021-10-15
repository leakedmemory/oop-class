#ifndef Person_hpp
#define Person_hpp

#include <string>

class Person
{
public:
    Person(std::string);
    virtual ~Person() = 0;

    void setName(std::string);
    std::string getName() const;

protected:
    std::string name;
};

#endif
