#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int T, N;
    int i, j, cnt1, cnt7;
    string answer;
    
    cin >> T;
    for (i = 0; i < T; i++) {
        cin >> N;
        cnt1 = N / 2;
        cnt7 = 0;
        answer = "";
        if (N % 2) {
            cnt1--;
            answer += '7';
        }
        for (j = 0; j < cnt1; j++)
            answer += '1';
        cout << answer << endl;
    }
}
