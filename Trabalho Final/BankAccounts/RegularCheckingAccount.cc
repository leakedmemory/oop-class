#include "RegularCheckingAccount.hpp"

RegularCheckingAccount::RegularCheckingAccount(
    unsigned accountNumber, Person* owner, double balance
) : Account(accountNumber, owner, balance) {}

RegularCheckingAccount::~RegularCheckingAccount() {}
