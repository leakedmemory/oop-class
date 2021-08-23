#include "IntegerSet.h"

int main() {
  IntegerSet set1;

  int arr[] = {10, 20, 30, 50};
  IntegerSet set2(arr, 4);

  set1 << 10;
  set2 >> 50;

  cout << set1;
  cout << set2;

  IntegerSet set3 = set1 | set2;
  IntegerSet set4 = set1 & set2;

  cout << set3;
  cout << set4;

  return 0;
}
