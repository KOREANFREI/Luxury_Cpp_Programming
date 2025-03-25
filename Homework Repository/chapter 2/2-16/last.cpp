//cin.getline(buf,10000,';');을 이용하여 텍스트를 키보드로 부터 읽으면 된다. 
// 문자를 소문자로 바꿀 때 tolower(char c)함수를 이용하고,
//알파벳인지 검사하기 위해 isalpha(charc) 함수를 이용하라, 텍스트 입력을 쉽게 하려면
//입력할 텍스트를 메모장에 입력한후 ctrl-c로 복사하고 ,DOS 실행창에 마우스 오른쪽 버튼을 누르고 붙혀넣기를 선택하면 된다.

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char buf[10000];
    int alpha[26] = { 0 };
    int total = 0;

    
    cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다.\n" << "텍스트의 끝은 ;입니다. 10000개까지 가능합니다.\n";
    cin.getline(buf, 10000, ';');

    for (int i = 0; buf[i] != '\0'; i++) {
        if (isalpha(buf[i])) {
            char lower = tolower(buf[i]);
            alpha[lower - 'a']++;
            total++;
        }
    }

    cout << "총 알파벳 수 " << total << "\n\n";

    for (int i = 0; i < 26; i++) {
        cout << (char)(i + 'a') << " (" << alpha[i] << ")\t: ";
        for (int j = 0; j < alpha[i]; j++) {
            cout << '*';
        }
        cout << "\n";
    }

    return 0;
}
