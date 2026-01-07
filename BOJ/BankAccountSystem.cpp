#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Bank {
private:
	static int account;
	int money;
	string owner;
public:
	Bank(string owner, int money = 0) {
		this->owner = owner;
		this->money = money;
		account++; // ÃÑ °èÁÂ ¼ö
	}

	void deposit(int a) {
		this->money += a;
	}

	void withdraw(int a) {
		if (this->money <= a) {
			cout << "ÀÜ¾× ºÎÁ·\n";
			exit(1);
		}
		this->money -= a;
	}

	int getMoney() {
		return this->money;
	}

	string getOwner() {
		return this->owner;
	}

	static int getAccountCount() {
		return account;
	}
};

int Bank::account = 0;

int main() {
	vector<Bank> v;
	string name;
	int money;

	while (true) {
		cout << "ÀÌ¸§, ÀÜ¾× ÀÔ·Â: ";
		getline(cin, name, ' ');
		cin >> money;
		cin.ignore();
		if (money == -1) break;

		Bank temp = Bank(name, money);
		v.push_back(temp);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].getOwner() << " " << v[i].getMoney() << endl;
	}
	
	cout << "ÃÑ °èÁÂ ¼ö: " << Bank::getAccountCount();
}