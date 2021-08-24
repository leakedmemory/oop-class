#include <iostream>
#include "HugeInteger.h"

using namespace std;

int main() {
  HugeInteger hi1("7974659841356841539846513");
  HugeInteger hi2("9784651239846519784651679465134651");

  // string s2 = "9784651239846519784651679465134651";

  cout << "hi1 = " << hi1;
  cout << "hi2 = " << hi2;

  // hi1.add(hi2);
  // cout << "hi1 += hi2" << endl << "hi1 = ";
  // hi1.output();
  // cout << endl;

  // cout << endl << endl;

  HugeInteger hi7 = "batata";
  cout << hi7;
  
  HugeInteger hi3 = "123456789";
  HugeInteger hi4 = "123456789";
  HugeInteger hi8 = "987654321";

  if (hi3 == hi4)
    cout << "hi3 e hi4 são iguais" << endl;
  if (hi3 != hi8)
    cout << "hi3 e hi8 não são iguais" << endl;
  if (hi3 >= hi4)
    cout << "hi3 é maior ou igual hi4" << endl;
  if (hi3 <= hi4)
    cout << "hi3 é menor ou igual hi4" << endl;

  HugeInteger hi5 = "87654321";
  HugeInteger hi6 = "76543210";

  if (hi5 > hi6)
    cout << "hi5 é maior que hi6" << endl;
  if (hi3 < hi8)
    cout << "hi3 é menor que hi8" << endl;

  return 0;
}
