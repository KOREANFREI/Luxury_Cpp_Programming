#include <iostream>
#include <string>
using namespace std;

class Circle {
    int radius;  // 반지름 저장
    string name;  // 원 이름 저장
public:
    void setCircle(string name, int radius) {  // 이름이랑 반지름 설정했음
        this->radius = radius;
        this->name = name;
    }
    double getArea() {  // 면적 계산해서 반환했음
        return radius * radius * 3.14;
    }
    string getName() {  // 이름 알려줌
        return name;
    }
};

class CircleManager {
    Circle* p;  // 원 객체 배열
    int size;  // 원 개수
public:
    CircleManager(int size) {  // 생성자에서 원 정보 입력받았음
        this->size = size;
        p = new Circle[size];
        string name;
        int radius;
        for (int i = 0; i < size; i++) {
            cout << "원 " << i + 1 << "의 이름과 반지름 >>";
            cin >> name >> radius;  // 이름이랑 반지름 입력받았음
            p[i].setCircle(name, radius);  // 객체에 저장했음
        }
    }
    ~CircleManager() {  // 소멸자에서 메모리 해제했음
        delete[] p;
    }
    void searchByName() {  // 이름으로 검색하는 기능
        string target;
        bool found = false;  // 찾았는지 체크용
        cout << "검색하고자 하는 원의 이름 >> ";
        cin >> target;  // 찾을 이름 입력받았음
        for (int i = 0; i < size; i++) {
            if (p[i].getName() == target) {  // 이름 비교했음
                cout << target << "의 면적은 " << p[i].getArea() << endl;  // 면적 출력했음
                found = true;
                break;
            }
        }
        if (!found) {  // 못 찾았을 때
            cout << target << "을 찾을 수 없습니다." << endl;
        }
    }
    void searchByArea() {  // 면적으로 검색하는 기능
        int minArea;
        bool first = true;  // 첫 번째 항목 체크용
        cout << "최소 면적을 정수로 입력하세요 >> ";
        cin >> minArea;  // 최소 면적 입력받았음
        cout << minArea << "보다 큰 원을 검색합니다." << endl;
        for (int i = 0; i < size; i++) {
            if (p[i].getArea() > minArea) {  // 조건 만족하는지 확인
                if (!first) cout << ", ";  // 콤마로 구분
                cout << p[i].getName() << "의 면적은 " << p[i].getArea();  // 결과 출력
                first = false;
            }
        }
        if (first) {  // 검색 결과 없을 때
            cout << "조건에 맞는 원이 없습니다.";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "원의 개수 >> ";
    cin >> n;  // 원 개수 입력받았음
    CircleManager manager(n);  // 매니저 객체 생성
    manager.searchByName();  // 이름 검색 실행
    manager.searchByArea();  // 면적 검색 실행
}
