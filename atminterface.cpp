#include <iostream>
#include <fstream>
#include <cmath>
int balance = 0;
using namespace std;
const int pin = 1234;

void showMenu();
void withdraw(int &balance);
void deposit(int &balance);
void checkBalance(int &balance);
bool login();
int loadBalance();
void saveBalance(int &balance);

int main () {
	
	cout << "======Welcome to GNB=======" << endl;
	
	if(!login()) {
		cout << "Too many attempts! Please try again later." << endl;
	} 
	
	int balance = loadBalance();
	int choice;
	do {
		showMenu();
		cin >> choice;
		
		switch (choice) {
			case 1: checkBalance(balance); break;
			case 2: deposit(balance); break;
			case 3: withdraw(balance); break;
			case 4: cout << "Goodbye, have a nice day!";
			default : cout << "Invalid input, Please try again";
			
			saveBalance(balance);
		}
	} while (choice != 4);
	return 0;
}

bool login() {
	int attempts;
	int userPin;
	
	while(attempts <= 5) {
		cout << "Please enter your PIN (5 attempts):";
		cin >> userPin;
		
		if (userPin == pin) {
			cout <<"Pin entered successfully!";
			return true;
		} else {
			cout << "Incorrect PIN, Please try again";
		}
	}
	
	return false;
	
}

void showMenu () {
	cout << "\n----- Menu -----\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

void checkBalance(int &balance) {
	cout << "Your current balance is: " << balance << endl; 
}

void withdraw(int &balance) {
	int amount;
	cout << "PLease enter amont to withdraw: ";
	cin >> amount;
	
	if(amount > 0 && amount <= balance) {
		balance -= amount;
		cout << amount << " Successfully withdrawn!" << endl;
	} else {
		cout << "Invalid or insufficient funds";
	}
}

void deposit(int &balance) {
	int amount;
	cout << "Please enter an amount to deposit: ";
	cin >> amount;
	
	if(amount > 0) {
		balance += amount;
		cout << amount << " Successfully deposited." << endl;
	} else {
		cout << "Invalid amount";
	}
}

int loadBalance() {
    int balance;
    ifstream file("balance.txt");
    if (file.is_open()) {
        file >> balance;
        file.close();
    }
    return balance;
}

void saveBalance(int &balance) {
    ofstream file("balance.txt");
    if (file.is_open()) {
        file << balance;
        file.close();
    }
}

