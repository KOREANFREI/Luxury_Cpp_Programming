#include <vector>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius;
		this->name = name;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

int main() {
	vector<Circle*> v;

	cout << "원을 삽입하고 삭제하는 프로그램입니다." << endl;
	bool run = true;
	int b, r; string n;
	vector<Circle*>::iterator it;
	Circle* tmp;
	while (run) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> b;
		switch (b) {
		case 1:
			cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
			cin >> r >> n;
			tmp = new Circle(r, n);
			v.push_back(tmp);
			break;
		case 2:
			cout << "삭제하고자 하는 원의 이름은 >> ";
			cin >> n;
			it = v.begin();
			while (it != v.end()) {
				tmp = *it;
				if (tmp->getName() == n) {
					it = v.erase(it);
				}
				else { it++; }
			}
			break;
		case 3:
			it = v.begin();
			while (it != v.end()) {
				tmp = *it++;
				cout << tmp->getName() << endl;
			}
			break;
		case 4:
			run = false;
		}
	}
}