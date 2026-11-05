#include <string>
#include <vector>
#include <iostream> 
using namespace std;

/* 
    (1-based)1 ~ n : 개인정보 n 개 
    
*/
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    // return : 파기해야할 정보를 담은 인덱스 (1-based) 
    vector<int> answer;
    
    // Convert today into dateSum 
    int y = stoi(today.substr(0,4)); 
    int m = stoi(today.substr(5, 2)); 
    int d = stoi(today.substr(8, 2));
    int todaySum = (y * 12 * 28) + ((m - 1) * 28) + (d - 1);
    
    for (int i = 0; i < privacies.size(); i++) {
        // "2021.05.02 A"
        string s = privacies[i]; 
        int year = stoi(s.substr(0,4)); 
        int month = stoi(s.substr(5, 2)); 
        int date = stoi(s.substr(8, 2)); 
        string type = s.substr(11);  
        
        // Conver to date, * 1 Month = 28 Date, *아직 하루 안지남 
        int expireSum = (year * 12 * 28) + ((month - 1) * 28) + (date - 1); 
        
        // "A 6"
        int addSum = 0; 
        for (int j = 0; j < terms.size(); j++) {
            string t = terms[j]; 
            string term = t.substr(0, 1); 
            // type 비교를 안함
            if (type == term) {
                addSum = stoi(t.substr(2)) * 28; 
                break; 
            }
        }
        
        // Condition Check 
        if (expireSum + addSum <= todaySum) {
            answer.push_back(i + 1);
        }
        
    }
    return answer;
}