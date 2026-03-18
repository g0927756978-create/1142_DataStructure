#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        
        // 計算每個數字在陣列中出現的次數
        for (int num : arr) {
            freqMap[num]++;
        }
        
        int maxLucky = -1;
        
        // 檢查，尋找幸運整數
        for (auto& pair : freqMap) {
            int value = pair.first;
            int count = pair.second;
            
            if (value == count) {
                // 持續檢查並更新最大的幸運整數
                maxLucky = max(maxLucky, value); 
            }
        }
        
        // 回傳結果，如果沒有找到則會回傳初始值 -1
        return maxLucky;
    }
};
