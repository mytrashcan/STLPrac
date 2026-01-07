#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Character {
private:
	int HP;
protected:
	string className;
public:
	int getHP() { return HP; }
	string getName() { return className; }
	void virtual attack() = 0; // pure virtual method
	Character() { HP = 100; className = "몰라"; }
	virtual ~Character() { cout << className << " 객체가 소멸.\n"; }
};

class Warrior : public Character {
public:
	Warrior() { className = "Warrior"; }
	~Warrior() { cout << "Warrior만의 뒷정리...\n"; } // 자식 소멸자 호출 확인용
	void attack() { cout << "검으로 공격!!!\n"; }
};

class Mage : public Character {
public:
	Mage() { className = "Mage"; }
	~Mage() { cout << "Mage만의 뒷정리...\n"; }
	void attack() { cout << "마법으로 공격!!!\n"; }

};

class Archer : public Character {
public:
	Archer() { className = "Archer"; }
	~Archer() { cout << "Archer만의 뒷정리...\n"; }
	void attack() { cout << "활로 공격!!!\n"; }
};

int main() {
	vector<Character*> party;

	party.push_back(new Warrior());
	party.push_back(new Mage());
	party.push_back(new Archer());
	
	for (Character* ch : party)
		ch->attack();

	for (int i = 0; i < party.size(); i++) 
		delete party[i];
}