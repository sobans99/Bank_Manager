#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
	
	string password;

public:
	string accountNumber;
	string accountHolderName;
	double balance;

	BankAccount( string& number,  string& holderName,  string& accPassword)
		: accountNumber(number), accountHolderName(holderName), balance(0.0), password(accPassword) {}

	~BankAccount() {}

	void displayBalance()  {
		cout << "Account Balance: " << balance << endl;
	}

	void deposit(double amount) {
		balance += amount;
		cout << "Deposit of " << amount << " successful." << endl;
	}

	bool withdraw(double amount) {
		if (balance >= amount) {
			balance -= amount;
			cout << "Withdrawal of " << amount << " successful." << endl;
			return true;
		}
		else {
			cout << "Insufficient funds. Withdrawal failed." << endl;
			return false;
		}
	}

	bool transfer(BankAccount* destination, double amount) {
		if (balance >= amount) {
			balance -= amount;
			destination->balance += amount;
			cout << "Transfer of " << amount << " successful." << endl;
			return true;
		}
		else {
			cout << "Insufficient funds. Transfer failed." << endl;
			return false;
		}
	}

	bool validatePassword( string& inputPassword)  {
		return (password == inputPassword);
	}
};

class SavingsAccount : public BankAccount {
private:
	double interestRate;

public:
	SavingsAccount( string& number,  string& holderName,  string& accPassword, double rate)
		: BankAccount(number, holderName, accPassword), interestRate(rate) {}

	~SavingsAccount() {}

	void addInterest() {
		double interest = balance * interestRate / 100;
		balance += interest;
		cout << "Added interest of " << interest << " to the account." << endl;
	}
};

class CurrentAccount : public BankAccount {
public:
	CurrentAccount( string& number,  string& holderName, const string& accPassword)
		: BankAccount(number, holderName, accPassword) {}

	~CurrentAccount() {}

	void overdraft() {
		cout << "Account is eligible for overdraft facility." << endl;
	}
};

class Bank {
private:
	BankAccount* accounts[10];  
	int accountCount;          

public:
	Bank() : accountCount(0) {}

	~Bank() {
		
		for (int i = 0; i < accountCount; i++) {
			delete accounts[i];
		}
	}

	void createSavingsAccount( string& accountNumber,  string& accountHolderName,  string& password, double interestRate) {
		if (accountCount >= 10) {
			cout << "Account limit reached. Cannot create more accounts." << endl;
			return;
		}

		accounts[accountCount] = new SavingsAccount(accountNumber, accountHolderName, password, interestRate);
		accountCount++;

		cout << "Savings account created" << endl;
	}

	void createCurrentAccount( string& accountNumber,  string& accountHolderName,  string& password) {
		if (accountCount >= 10) {
			cout << "Account limit reached. Cannot create more accounts." << endl;
			return;
		}

		accounts[accountCount] = new CurrentAccount(accountNumber, accountHolderName, password);
		accountCount++;

		cout << "Current account created" << endl;
	}

	BankAccount* getAccount( string& accountNumber,  string& password) {
		for (int i = 0; i < accountCount; i++) {
			if (accounts[i]->accountNumber == accountNumber && accounts[i]->validatePassword(password)) {
				return accounts[i];
			}
		}

		return nullptr;
	}
};

int main() {
	Bank bank;

	int choice;

	do {
		cout << "Banking Management System" << endl;
		cout << "------------------------" << endl;
		cout << "1. Create Savings Account" << endl;
		cout << "2. Create Current Account" << endl;
		cout << "3. Access Account" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
					string accountNumber, accountHolderName, password;
					double interestRate;

					cout << "Enter account number: ";
					cin >> accountNumber;
					cout << "Enter account holder name: ";
					cin >> accountHolderName;
					cout << "Enter password: ";
					cin >> password;
					cout << "Enter interest rate: ";
					cin >> interestRate;

					bank.createSavingsAccount(accountNumber, accountHolderName, password, interestRate);
					break;
		}

		case 2: {
					string accountNumber, accountHolderName, password;

					cout << "Enter account number: ";
					cin >> accountNumber;
					cout << "Enter account holder name: ";
					cin >> accountHolderName;
					cout << "Enter password: ";
					cin >> password;

					bank.createCurrentAccount(accountNumber, accountHolderName, password);
					break;
		}

		case 3: {
					string accountNumber, password;

					cout << "Enter account number: ";
					cin >> accountNumber;
					cout << "Enter password: ";
					cin >> password;

					BankAccount* account = bank.getAccount(accountNumber, password);

					if (account) {
						int accountChoice;

						do {
							cout << "Account Operations" << endl;
							cout << "------------------" << endl;
							cout << "1. Display Balance" << endl;
							cout << "2. Deposit" << endl;
							cout << "3. Withdraw" << endl;
							cout << "4. Exit" << endl;
							cout << "Enter your choice: ";
							cin >> accountChoice;

							switch (accountChoice) {
							case 1:
								account->displayBalance();
								break;

							case 2: {
										double amount;
										cout << "Enter deposit amount: ";
										cin >> amount;
										account->deposit(amount);
										break;
							}

							case 3: {
										double amount;
										cout << "Enter withdrawal amount: ";
										cin >> amount;
										account->withdraw(amount);
										break;
							}

							case 4:
								cout << "Exiting account..." << endl;
								break;

							default:
								cout << "Invalid choice. Please try again." << endl;
								break;
							}
						} while (accountChoice != 4);
					}
					else {
						cout << "Invalid account number or password." << endl;
					}

					break;
		}

		case 0:
			cout << "Exiting..." << endl;
			break;

		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 0);

	return 0;
}
