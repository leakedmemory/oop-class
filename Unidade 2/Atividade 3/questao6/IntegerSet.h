#ifndef INTEGER_SET_H
#define INTEGER_SET_H 

#include <iostream>

using namespace std;

class IntegerSet 
{
  friend IntegerSet unionOfSets(const IntegerSet &, const IntegerSet &);
  friend IntegerSet intersectionOfSets(const IntegerSet &, const IntegerSet &);
  
  friend ostream &operator<<(ostream &, const IntegerSet &);
  
public:
  IntegerSet();
  IntegerSet(int *, int);

  void insertElement(int);
  void deleteElement(int);

  void print() const;

  void operator<<(int);
  void operator>>(int);
  IntegerSet operator|(const IntegerSet &) const;
  IntegerSet operator&(const IntegerSet &) const;

private:
  int nums[100];
  void setZeros();
};

#endif
