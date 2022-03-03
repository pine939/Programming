#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> mp;
    string answer = "";
    
    for (int i = 0; i < participant.size(); i++) {
        mp[participant[i]]++;
    }
    
    for (int i = 0; i < completion.size(); i++) {
        if (mp[completion[i]] > 0) {
            mp[completion[i]]--;
        }
    }
    
    for (auto i:mp) {
        if (i.second != 0) {
            answer = i.first;
        }
    }
    return answer;
}