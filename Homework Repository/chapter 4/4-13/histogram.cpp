#include <iostream>
#include <string>
using namespace std;

class TextAnalyzer {  // 글자 분석 클래스
    string textBuffer;  // 분석할 텍스트 저장
    int letterCounts[26] = { 0 };  // a-z 개수 세기용
    int totalLetters = 0;  // 전체 알파벳 수
public:
    TextAnalyzer(string s) {  // 생성자에서 초기 텍스트 설정
        textBuffer = s;
        cout << s;  // 초기 텍스트 출력했음
    }
    void addText(string s) {  // 텍스트 추가했음
        textBuffer += s;
        cout << s;
    }
    void addChar(char c) {  // 문자 하나 추가했음
        textBuffer += c;
        cout << c;
    }
    void showResult() {  // 결과 출력 메서드
        cout << "\n\n[Text Analysis Result]\n";

        // 전체 글자 수 계산
        for (char ch : textBuffer) {  // 모든 문자 순회
            if (isalpha(ch)) {  // 알파벳인지 확인
                totalLetters++;
                char lowerCh = tolower(ch);  // 소문자로 통일
                letterCounts[lowerCh - 'a']++;  // 해당 알파벳 카운트 증가
            }
        }

        cout << "Total letters: " << totalLetters << "\n\n";

        // 히스토그램 출력
        for (int i = 0; i < 26; i++) {
            char currentChar = 'a' + i;
            cout << currentChar << " (" << letterCounts[i] << ")\t| ";
            for (int j = 0; j < letterCounts[i]; j++) {
                cout << "*"; 
            }
            cout << endl;
        }
    }
};

int main() {
    TextAnalyzer analyzer("Wise men say, only fools rush in But I can't help, ");
    analyzer.addText("falling in love with you");
    analyzer.addChar('-');
    analyzer.addText("Elvis Presley");
    analyzer.showResult();
}
