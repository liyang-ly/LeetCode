#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        int length,i,j,last,t, w;
        length = s.length();

        if(numRows >= length || numRows == 1){
                return s;
        }

        string r = "";
        //r = new char[length+1];

        j = 0;
        last = 0;
        //first row
        while(j<length){
            r += s[j];
            last++;
            j += 2*numRows-2;
        }
        //cout<<endl;
        if(last == length){
                return r;
        }

        //mid rows
        for(i=1; i<numRows-1; i++){
            j = i;
            while(j<length){
                r += s[j];
                last++;
                t = j + 2*numRows - 2 - 2*i;
                if(t<length){
                    r += s[t];
                    last++;
                }
                j += 2*numRows-2;
            }
        }
         if(last == (length)){
                return r;
        }
        /* last row */
        j = numRows - 1;
        while(j<length){
            r += s[j];
            last++;
            j += 2*numRows-2;
        }
        return r;
        }
};

int main(void)
{
     Solution slu;
     cout<<slu.convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.",2);
    return 0;
}

