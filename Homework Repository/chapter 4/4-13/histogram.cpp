#include <iostream>
#include <string>
using namespace std;

class TextAnalyzer {  // ���� �м� Ŭ����
    string textBuffer;  // �м��� �ؽ�Ʈ ����
    int letterCounts[26] = { 0 };  // a-z ���� �����
    int totalLetters = 0;  // ��ü ���ĺ� ��
public:
    TextAnalyzer(string s) {  // �����ڿ��� �ʱ� �ؽ�Ʈ ����
        textBuffer = s;
        cout << s;  // �ʱ� �ؽ�Ʈ �������
    }
    void addText(string s) {  // �ؽ�Ʈ �߰�����
        textBuffer += s;
        cout << s;
    }
    void addChar(char c) {  // ���� �ϳ� �߰�����
        textBuffer += c;
        cout << c;
    }
    void showResult() {  // ��� ��� �޼���
        cout << "\n\n[Text Analysis Result]\n";

        // ��ü ���� �� ���
        for (char ch : textBuffer) {  // ��� ���� ��ȸ
            if (isalpha(ch)) {  // ���ĺ����� Ȯ��
                totalLetters++;
                char lowerCh = tolower(ch);  // �ҹ��ڷ� ����
                letterCounts[lowerCh - 'a']++;  // �ش� ���ĺ� ī��Ʈ ����
            }
        }

        cout << "Total letters: " << totalLetters << "\n\n";

        // ������׷� ���
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
