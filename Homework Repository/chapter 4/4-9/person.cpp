#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;  // 이름 저장용
    string tel;   // 전화번호 저장용
public:
    Person() {  // 생성자 호출 시 초기화했음
        name = "";
        tel = "";
    }
    string getName() {  // 이름 반환하는 함수임
        return name;
    }
    string getTel() {  // 전화번호 반환하는 함수임
        return tel;
    }
    void set(string name, string tel) {  // 이름이랑 전화번호 설정했음
        this->name = name;
        this->tel = tel;
    }
};

int main() {
    Person p[3];  // Person 객체 배열 만들었음

    cout << "이름과 전화번호를 입력해 주세요\n" << endl;
    for (int i = 0; i < 3; i++) {
        string name, tel;
        cout << "사람 " << i + 1 << ">> ";
        cin >> name >> tel;  // 입력받았음
        p[i].set(name, tel);  // 객체에 저장했음
    }

    cout << "모든 사람의 이름: "
        << p[0].getName() << " "
        << p[1].getName() << " "
        << p[2].getName() << endl;  // 저장된 이름 출력했음

    cout << "전화번호 검색할 이름>> ";
    string target;
    cin >> target;  // 검색할 이름 입력받았음

    for (int i = 0; i < 3; i++) {
        if (p[i].getName() == target) {  // 입력한 이름이랑 비교했음
            cout << "전화번호: " << p[i].getTel() << endl;  // 찾으면 전화번호 출력함
            return 0;  // 찾았으니 끝냄
        }
    }

    cout << "검색 실패" << endl;  // 못 찾으면 실패 메시지 출력했음
    return 0;
}
