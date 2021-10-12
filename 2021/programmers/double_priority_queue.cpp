#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    string str;
    
    for (auto s:operations) {
        if (s[0] == 'I')
            ms.insert(stoi(s.substr(2)));
        else if (!ms.empty()) {
            if (s[2] == '1') {
                ms.erase(--ms.end());
            }
            else
                ms.erase(ms.begin());
        }
    }
    
    if (ms.empty())
        answer = {0, 0};
    else {
        answer.push_back(*(--ms.end()));
        answer.push_back(*(ms.begin()));
    }
    
    return answer;
}
