#include <iostream>
#include <vector>

#include "Menu.hpp"

using std::cout;
using std::cin;
using std::endl;

Menu::Menu(Bank* bank) {
    this->bank = bank;
}

void Menu::open() {
    while (true) {
        short int choice = chooseFirstOperation();
        if (choice == 0) {
            managerLoop();
        } else if (choice == 1) {
            holderMenu();
        } else if (choice == -1) {
            cout << "Operação finalizada." << endl;
            break;
        } else {
            errorMessage();
        }
    }
}

void Menu::errorMessage() const {
    cout << "ERRO: por favor, insina um comando válido." << endl;
}

short int Menu::chooseFirstOperation() const {
    short int choice;
    cout << "O que deseja fazer?" << endl;
    cout << "[0] entrar como gerente" << endl;
    cout << "[1] entrar como correntista" << endl;
    cout << "[-1] finalizar" << endl;
    cin >> choice;

    return choice;
}

short int Menu::chooseManagerOperation() const {
    short int choice;
    cout << "O que deseja fazer?" << endl;
    cout << "[0] abrir conta" << endl;
    cout << "[1] consultar conta" << endl;
    cout << "[2] atualizar conta" << endl;
    cout << "[3] fechar conta" << endl;
    cout << "[-1] retornar para menu principal" << endl;
    cin >> choice;

    return choice;
}

void Menu::managerLoop() {
    while (true) {
        short int manager_operation = chooseManagerOperation();
        if (manager_operation == 0) {
            createAccount();
        } else if (manager_operation == 1) {
            unsigned number = askAccountNumber();
            queryAccount(number);
        } else if (manager_operation == 2) {
            unsigned number = askAccountNumber();
            updateAccount(number);
        } else if (manager_operation == 3) {
            unsigned number = askAccountNumber();
            deleteAccount(number);
        } else if (manager_operation == -1) {
            break;
        } else {
            errorMessage();
        }
    }
}

void Menu::createAccount() {
    short int type = askAccountType();
    Account* account = accountFactory(type);
    this->bank->addAccount(account);
    cout << "Conta criada com sucesso" << endl;
}

short int Menu::askAccountType() {
    short int type;
    cout << "Qual tipo de conta deseja criar?" << endl;
    cout << "[0] poupança" << endl;
    cout << "[1] conta corrente normal" << endl;
    cout << "[2] conta corrente com limite" << endl;
    cout << "[-1] cancelar operação" << endl;
    cin >> type;

    return type;
}

Account* Menu::accountFactory(short int account_type) {
    short int person_type = askPersonType();
    unsigned account_number = askAccountNumber();
    Person* person = personFactory(person_type);

    if (account_type == 0) {
        return savingsAccountFactory(account_number, person);
    } else if (account_type == 1) {
        return regularCheckingAccountFactory(account_number, person);
    } else if (account_type == 2) {
        double limit = askLimit();
        return checkingAccountWithLimitFactory(account_number, person, limit);
    } else if (account_type != -1) {
        errorMessage();
    }

    return nullptr;
}

short int Menu::askPersonType() {
    short int type;
    cout << "Qual tipo de pessoa?" << endl;
    cout << "[0] física" << endl;
    cout << "[1] jurídica" << endl;
    cout << "[-1] cancelar operação" << endl;
    cin >> type;

    return type;
}

Person* Menu::personFactory(short int type) {
    std::string name = askHolderName();

    if (type == 0) {
        unsigned long cpf = askCPF();
        return physicalPersonFactory(name, cpf);
    } else if (type == 1) {
        unsigned long cnpj = askCNPJ();
        return legalPersonFactory(name, cnpj);
    } else if (type != -1) {
        errorMessage();
    }

    return nullptr;
}

std::string Menu::askHolderName() {
    std::string name;
    cout << "Insira o nome do proprietário nome: ";
    cin >> name;

    return name;
}

unsigned long Menu::askCPF() {
    unsigned long cpf;
    cout << "Insira o CPF: ";
    cin >> cpf;

    return cpf;
}

unsigned long Menu::askCNPJ() {
    unsigned long cnpj;
    cout << "Insira o CNPJ: ";
    cin >> cnpj;

    return cnpj;
}

PhysicalPerson* Menu::physicalPersonFactory(std::string name, unsigned long cpf) {
    PhysicalPerson* p = new PhysicalPerson(name, cpf);
    return p;
}

LegalPerson* Menu::legalPersonFactory(std::string name, unsigned long cnpj) {
    LegalPerson* p = new LegalPerson(name, cnpj);
    return p;
}

unsigned Menu::askAccountNumber() {
    unsigned number;
    cout << "Digite o número da conta: ";
    cin >> number;

    return number;
}

SavingsAccount* Menu::savingsAccountFactory(unsigned number, Person* person) {
    SavingsAccount* s = new SavingsAccount(number, person);
    return s;
}

RegularCheckingAccount* Menu::regularCheckingAccountFactory(
    unsigned number, Person* person
) {
    RegularCheckingAccount* r = new RegularCheckingAccount(number, person);
    return r;
}

CheckingAccountWithLimit* Menu::checkingAccountWithLimitFactory(
    unsigned number, Person* person, double limit
) {
    CheckingAccountWithLimit* c = new CheckingAccountWithLimit(number, person, limit);
    return c;
}

double Menu::askLimit() {
    double limit;
    cout << "Insira o limite da conta: R$";
    cin >> limit;

    return limit;
}

void Menu::queryAccount(unsigned account_number) {
    if (this->bank->searchAccount(account_number)) {
        Account* account = this->bank->getAccountByNumber(account_number);
        cout << "Informações da conta " << account_number << endl;
        cout << "Proprietário: " << account->getOwnersName() << endl;
        cout << "Saldo: R$" << account->getBalance() << endl;
    } else {
        cantFindAccount();
    }
}

void Menu::updateAccount(unsigned account_number) {
    if (this->bank->searchAccount(account_number)) {
        Account* account = this->bank->getAccountByNumber(account_number);
        short int change = askChange();
        changeHandler(change, account);
    } else {
        cantFindAccount();
    }
}

short int Menu::askChange() {
    short int change;
    cout << "O que deseja alterar?" << endl;
    cout << "[0] número" << endl;
    cout << "[1] nome" << endl;
    cout << "[-1] cancelar operação" << endl;
    cin >> change;

    return change;
}

void Menu::changeHandler(short int number, Account* account) {
    if (number == 0) {
        unsigned new_number = askNewNumber();
        account->setAccountNumber(new_number);
        cout << "Número da conta alterado com sucesso" << endl;
    } else if (number == 1) {
        std::string new_name = askNewName();
        account->setOwnersName(new_name);
        cout << "Proprietário alterado com sucesso" << endl;
    } else if (number != 1) {
        errorMessage();
    }
}

unsigned Menu::askNewNumber() {
    unsigned number;
    cout << "Insira o novo número: ";
    cin >> number;

    return number;
}

std::string Menu::askNewName() {
    std::string name;
    cout << "Insira o novo proprietário: ";
    cin >> name;

    return name;
}

void Menu::deleteAccount(unsigned account_number) {
    if (this->bank->searchAccount(account_number)) {
        Account* account = this->bank->getAccountByNumber(account_number);
        std::vector<Account*>* vector = this->bank->getAccounts();
        for (unsigned i = 0; i < vector->size(); i++) {
            if ((*vector)[i] == account) {
                vector->erase(vector->begin() + i);
                cout << "Conta removida com sucesso" << endl;
            }
        }
    } else {
        cantFindAccount();
    }
}

void Menu::holderMenu() {
    unsigned account_number;
    cout << "Número da conta: ";
    cin >> account_number;
    if (bank->searchAccount(account_number)) {
        Account* account = bank->getAccountByNumber(account_number);
        holderLoop(account);
    } else {
        cantFindAccount();
    }
}

void Menu::holderLoop(Account* account) {
    while (true) {
        short int operation = chooseHolderOperation();
        if (operation == 0) {
            deposit(account);
        } else if (operation == 1) {
            withdraw(account);
        } else if (operation == 2) {
            seeStatement(account);
        } else if (operation == 3) {
            cout << account->getBalance() << endl;
        } else if (operation == 4) {
            account->seeStatement();
        } else if (operation == -1) {
            break;
        } else {
            errorMessage();
        }
    }
}

short int Menu::chooseHolderOperation() const {
    short int operation;
    cout << "O que deseja fazer?" << endl;
    cout << "[0] depósito" << endl;
    cout << "[1] retirada" << endl;
    cout << "[2] transferência" << endl;
    cout << "[3] ver saldo" << endl;
    cout << "[4] extrato" << endl;
    cout << "[-1] voltar ao menu principal" << endl;
    cin >> operation;

    return operation;
}

void Menu::deposit(Account* account) {
    double value;
    cout << "Insira o valor do depósito: R$";
    cin >> value;
    *account << value;
    cout << "Depósito concluído" << endl;
}

void Menu::withdraw(Account* account) {
    double value;
    cout << "Insira o valor da retirada: R$";
    cin >> value;
    *account >> value;
    cout << "Retirada concluída" << endl;
}

void Menu::seeStatement(Account* account) {
    unsigned destination_account_number;
    cout << "Digite o número da conta de destino: ";
    cin >> destination_account_number;
    transfer(account, destination_account_number);
}

void Menu::transfer(Account* source, unsigned number) {
    if (bank->searchAccount(number)) {
        Account* destination = bank->getAccountByNumber(number);
        double value;
        cout << "Insira o valor da transferência: R$";
        cin >> value;
        source->transfer(*destination, value);
        cout << "Transferência concluída" << endl;
    } else {
        cantFindAccount();
    }
}

void Menu::cantFindAccount() const {
    cout << "Conta não encontrada" << endl;
}
