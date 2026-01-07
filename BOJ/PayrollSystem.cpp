#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
	string name;
public:
	Employee(string name) { this->name = name; }
	virtual ~Employee() { cout << "[" << name << "] 님의 정보가 삭제되었습니다.\n"; }
	string getName() { return name; }
	virtual int getPay() = 0; // pure virtual function
};

class Permanent : public Employee {
private:
	int salary;
public:
	Permanent(string name, int salary) : Employee(name), salary(salary) {}
	int getPay() { return salary; }
};

class Hourly : public Employee {
private:
	int time;
	int pay_per_hour;
public:
	Hourly(string name, int time, int pay_per_hour) : Employee(name), time(time), pay_per_hour(pay_per_hour) {}
	int getPay() { return time * pay_per_hour; }
};

class Sales : public Employee {
private:
	int base_pay;
	int achiev;
	double incentives;
public:
	Sales(string name, int base_pay, int achiev, double incentives) :
		Employee(name), base_pay(base_pay), achiev(achiev), incentives(incentives) {}
	int getPay() { return base_pay + (achiev * incentives); }
};

int main() {
	vector<Employee*> employees;

	employees.push_back(new Permanent("김부장", 500));        // 월급 500
	employees.push_back(new Hourly("이알바", 10, 2));         // 10시간 * 2만원 = 20
	employees.push_back(new Sales("박영업", 200, 1000, 0.1)); // 200 + (1000 * 0.1) = 300

	int total_payroll = 0;

	cout << "=== 이번 달 급여 명세서 ===\n";

	for (Employee* e : employees) {
		int pay = e->getPay(); // 다형성
		total_payroll += pay;

		cout << "이름: " << e->getName() << " | 급여: " << pay << "만원" << endl;
	}

	cout << "---------------------------\n";
	cout << "총 지급액: " << total_payroll << "만원\n\n";

	for (Employee* e : employees) {
		delete e;
	}

	return 0;
}