#include "IntegerSet.h"

using namespace std;

IntegerSet unionOfSets(const IntegerSet &is1, const IntegerSet &is2)
{
  IntegerSet unionSet;

  for (int i = 0 ; i < 100 ; i++)
    unionSet.nums[i] = is1.nums[i] || is2.nums[i];
  
  return unionSet;
}

IntegerSet intersectionOfSets(const IntegerSet &is1, const IntegerSet &is2)
{
  IntegerSet intersectionSet;

  for (int i = 0 ; i < 100 ; i++)
    intersectionSet.nums[i] = is1.nums[i] && is2.nums[i];
  
  return intersectionSet;
}

ostream &operator<<(ostream &out, const IntegerSet &is) {
  out << "[ ";
  for (int i = 0 ; i < 100 ; i++)
    if (is.nums[i])
      out << i << " ";
  out << "]" << endl;

  return out;
}

IntegerSet::IntegerSet()
{
  setZeros();
}

IntegerSet::IntegerSet(int *inteiros, int tam)
{
  setZeros();
  for (int i = 0 ; i < tam ; i++)
    nums[inteiros[i]] = 1;
}

void IntegerSet::insertElement(int k)
{
  if (k >= 0 && k < 100)
    nums[k] = 1;
}

void IntegerSet::deleteElement(int k)
{
  if (k >= 0 && k < 100)
    nums[k] = 0;
}

void IntegerSet::print() const
{
  cout << "[ ";
  for (int i = 0 ; i < 100 ; i++)
    if (nums[i])
      cout << i << " ";
  cout << "]" << endl;
}

void IntegerSet::setZeros()
{
  for (int i = 0 ; i < 100 ; i++)
    nums[i] = 0;
}

void IntegerSet::operator<<(int k)
{
  if (k >= 0 && k < 100)
    nums[k] = 1;
}

void IntegerSet::operator>>(int k)
{
  if (k >= 0 && k < 100)
    nums[k] = 0;
}

IntegerSet IntegerSet::operator|(const IntegerSet &is) const {
  IntegerSet unionSet;

  for (int i = 0 ; i < 100 ; i++)
    unionSet.nums[i] = this->nums[i] || is.nums[i];
  
  return unionSet;
}

IntegerSet IntegerSet::operator&(const IntegerSet &is) const {
  IntegerSet intersectionSet;

  for (int i = 0 ; i < 100 ; i++)
    intersectionSet.nums[i] = this->nums[i] && is.nums[i];
  
  return intersectionSet;
}
