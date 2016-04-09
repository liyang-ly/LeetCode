#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int max,curmax,b,e,i;
            max = curmax = 1;
            if(s.length() == 0){
                    return 0;
            }
            b = e = 0;
            while(e != s.length()-1){
                    e++;
                    curmax++;
                    for(i=b; i<e; i++){
                            if(s[i] == s[e]){
                                    curmax = e-i;
                                    b = i+1;
                                    break;
                            }
                    }
                    if(curmax>max){
                            max = curmax;
                    }
            }
            return max;
    }
};

int main()
{
        string str = "abcabcbb";
        Solution sol;
        cout<<sol.lengthOfLongestSubstring(str);
        return 0;
}

