#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int i, tmp, insert = 0;
    
    for (i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            tmp = stoi(operations[i].substr(2));
            maxheap.push(tmp);
            minheap.push(tmp);
            insert++;
        }
        else {
            if (insert == minheap.size() + maxheap.size()) {
                continue;
            }
            
            if (operations[i][2] == '1') {
                maxheap.pop();
            }
            else
                minheap.pop();
            
            if (insert == minheap.size() + maxheap.size()) {
                while (!maxheap.empty())
                    maxheap.pop();
                while (!minheap.empty())
                    minheap.pop();
                insert = 0;
            }
        }
    }

    if (insert == minheap.size() + maxheap.size())
        answer = {0,0};
    else {
        answer.push_back(maxheap.top());
        answer.push_back(minheap.top());
    }
    
    return answer;
}
