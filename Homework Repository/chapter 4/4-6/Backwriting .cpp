#include <iostream> 
#include <string>
using namespace std;

int main() {
	string s;
	cout << "아래에 한줄을 입력하세요.(exit을 입력하면 종료됩니다.)" << endl;

	while (true) { // exit 받을때까지 계속 반복하는 무한루프 생성
		cout << " >>";// 입력 문자 사용 
		getline(cin, s); // 한줄 입력받기, cin >>는 공백을 기준으로 입력받기 때문에 getline 사용

		if (s == "exit") { // exit 입력시 종료
			break; // 무한루프 탈출
		}

		// 입력받은 문자열을 거꾸로 출력
		for (int i = s.length() - 1; i >= 0; i--) { // 문자열 길이 -1 부터 0까지 거꾸로 출력
			cout << s[i]; // 거꾸로 출력
		}
		cout << endl; // 줄바꿈
	}
	return 0;
}
