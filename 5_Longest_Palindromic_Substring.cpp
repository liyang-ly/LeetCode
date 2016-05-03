#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    //一国外大神的解法
    string longestPalindromeL(string s)
    {
            int start,maxlen;
            int i,j,k;
            //空字符串或长度唯一则回文就是本身
            if(s.length()==0 || s.length()==1){
                    return s;
            }
            start = 0;
            maxlen = 1;
            for(i=0;i<s.length()-1;i++){
                    //比较以第i个字符为中心的回文
                    j = k = i;
                    //若一段序列相同则必定是回文，则k前移
                    while(k<s.length()-1 && s[k] == s[k+1] ){
                            k++;
                    }
                    //比较头和尾
                    while(j>0 && k<s.length()-1 && s[j-1] == s[k+1]){
                            k++;
                            j--;
                    }
                    if(k-j+1>maxlen){
                            maxlen = k-j+1;
                            start = j;
                    }
            }
            return s.substr(start,maxlen);
    }
    /*动态规划发，不过gg了，暂时没找出问题
    string longestPalindrome(string s) {
            int i,j,l,be,maxl;
            string str_p;
           vector< vector<int> > table(s.length());
            for(i=0; i<s.length(); i++){
                    table[i].resize(s.length(),0);
            }
            //初始状态
            for(i=0;i<s.length(); i++){
                    table[i][i] = 1;
            }
            for(i=0;i<s.length();i++){
                    if(s[i] == s[i+1]){
                            be = i;
                            table[i][i+1] = 1;
                            maxl = 2;
                    }
            }
            //填充剩下的列
            for(l=2; l<s.length(); l++){
                    for(i=0;i<s.length()-l; i++){
                            j = i + l;
                            if(s[i] == s[j] && table[i+1][j-1]){
                                    table[i][j] = 1;
                                    be = i;
                                    maxl = l+1;
                            }
                    }
            }
            if(s.length() == 1){
                return s;
            }
            return s.substr(be,maxl);

    }
    */
    /*Manacher算法,dt也gg了，暂时没找出问题所在
    string longestPalindromeL(string s)
    {
                int len,i,m_l,id;
                string s_t;
                s_t = "$#";
                len = s.length();
                //添加辅助字符
                for(i=0; i<len; i++){
                        s_t += s[i];
                        s_t += '#';
                }

                len = s_t.length();
                vector<int> p(len);
                id = 0;
                m_l = 0;
                for(i=1; i<len; i++){
                        if(i>m_l){
                                //超出最大回文边界
                                p[i] = 1;
                        }else{
                                //i在最大回文串中，先取对称点或最大长-i中最小者
                                p[i] = min(p[2*id - i],m_l-i);
                        }
                        //尝试向延生p[i]
                        while(s_t[i-p[i]] == s_t[i + p[i]] ){
                                p[i]++;
                        }
                        //判断最大回文是否增大了
                        if(i+p[i]>m_l){
                                m_l = i + p[i];
                                id = i;
                        }
                }
                int max = 0;
                //找出最大回文和其中点
                for(i=0; i<len;i++){
                        if(p[i]>max){
                                max = p[i];
                                id = i;
                        }
                }
                max--;
                string s_r;
                s_r = "";
                int start = id - max;
                int end = id + max;
                for(i=start; i<=end; i++){
                        if(s_t[i]!='#'){
                                s_r += s_t[i];
                        }
                }
                return s_r;
    }
*/

int main()
{
        string str = "dacbabcad";
        Solution sol;
        cout<<sol.longestPalindromeL1(str);
        return 0;
}
