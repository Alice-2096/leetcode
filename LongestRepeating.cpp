#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int _max, curr, ptr, head;
        _max = ptr = curr = head = 0; 
        char rep = s[0]; 
        int len = s.length(); 
        vector<int> vec;  
        int original_k = k; 

        if (len == 1) return 1; 

        while (ptr < len){
            // same letter 
            if (s[ptr] == rep){
                curr++; 
                ptr++; 
            } else {
                if (k > 0){
                    vec.push_back(ptr); 
                    curr++;
                    ptr++; 
                    k--; 
                } else {
                    _max = max(_max, curr); //update max 
                    curr = 1; 
                    k = original_k; 
                    if (vec.size() != 0){
                        rep = s[vec[0]]; 
                        head = vec[0]; 
                        ptr = head + 1;
                        vec.clear(); 
                    } else {
                        rep = s[ptr]; 
                        head = ptr; 
                        ptr++; 
                    }
                }
            }
        }
        while (k > 0 && head - 1 >= 0){
            curr++; 
            head--; 
            k--; 
        }
        _max = max(_max, curr);  

        return _max; 
    }
};

int main()
{
    Solution s;
    string str = "BAAA"; 
    cout << s.characterReplacement(str, 2) << endl;

    return 0;
}
