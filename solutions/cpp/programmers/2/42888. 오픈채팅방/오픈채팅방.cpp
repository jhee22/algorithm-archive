#include <string>
#include <vector>
#include <unordered_map>
#include <sstream> 
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> m;
    vector<pair<string, string>> v; 
    for (int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]); 
        string command, uid, nickname; 
        ss >> command; 
        ss >> uid; 
        
        // 닉변 
        if(command == "Enter" || command == "Change") {
            ss >> nickname; 
            m[uid] = nickname; 
        } 
        
        // 출력 
        if (command == "Enter" || command== "Leave") {
            v.push_back({command, uid}); 
        }        
    }
    
    // answer 벡터에 닉네임 매칭 
    for (int i = 0; i < v.size(); i++) {
        string n = m[v[i].second]; 
        if (v[i].first == "Enter") {
            answer.push_back(n + "님이 들어왔습니다.");
        } else {
            answer.push_back(n + "님이 나갔습니다.");
        }
    }
    return answer;
}