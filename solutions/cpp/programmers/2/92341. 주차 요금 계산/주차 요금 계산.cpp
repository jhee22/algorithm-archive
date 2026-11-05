#include <string> 
#include <vector>
#include <sstream> 
#include <map> 

using namespace std;

/*
    Solution : vector<int> 자동차별 주차요금 
*/

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer; 
    
    map<string, int> inTime; 
    map<string, int> totalTime; 
    
    // fees = [기본시간, 시본요금, 추가시간, 추가요금]
    int baseTime = fees[0]; 
    int baseFee = fees[1]; 
    int addTime = fees[2]; 
    int addFee = fees[3]; 
    
    // 1. 입/출차 차량 기록 (시간계산)
    for (int i = 0; i < records.size(); i++) {
        // stringstream 
        stringstream ss(records[i]);
        string time, number, action; 
        ss >> time >> number >> action; 
        
        // time to minutes 
        stringstream ss2(time);
        string hour, minute; 
        getline(ss2, hour, ':'); 
        getline(ss2, minute); 
        
        int value = stoi(hour) * 60 + stoi(minute); 
        
        if (action == "IN") {
            inTime[number] = value; 
        }
        
        else if (action == "OUT") {
            totalTime[number] += value - inTime[number]; 
            inTime.erase(number); 
        }

    }
    // 2. 미출차 차량 기록 : 입차 ~ 23:59 
    for (const auto&[number, time] : inTime) {
        int end = 23 * 60 + 59; 
        totalTime[number] += end - time; 
    }
    
    // 3. 머니 
    for (auto&[number, time] : totalTime) {
        int money = 0; 
        // 기본 요금 정산 
        if (time <= baseTime) {
            answer.push_back(baseFee); 
            continue; 
        } 
        
        money += baseFee; 
        time -= baseTime; 
        // 추가 요금 정산 
        // 올림계산 : 나누는 수보다 1 작은 수를 더 할 것. 
        money += (time + addTime - 1) / addTime * addFee; 
        answer.push_back(money); 
    }
    

    
    return answer;
}