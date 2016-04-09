#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int i,j,n,m,s;
            double result;
            n = nums1.size();
            m = nums2.size();
            vector<int> tmp(n+m);
            i = j = s =0;
            result = 0;
            while(i<n && j<m){
                    if(nums1[i] <= nums2[j]){
                            tmp[s] = nums1[i];
                            i++;
                    }else{
                            tmp[s] = nums2[j];
                            j++;
                    }
                    s++;
            }

            while(i<n){
                    tmp[s] = nums1[i];
                    i++;
                    s++;
            }
            while(j<m){
                    tmp[s] = nums2[j];
                    j++;
                    s++;
            }
            if(tmp.size()%2 != 1){
                    result = ((double)tmp[(tmp.size()/2)-1] + (double)tmp[(tmp.size()/2)])/2;
            }else{
                    result = tmp[tmp.size()/2];
            }
            return result;
    }
};

int main()
{
        int i,s1,s2;
        cin>>s1;
        cin>>s2;
        vector<int> n1(s1);
        vector<int> n2(s2);
        for(i=0; i<s1; i++){
                cin>>n1[i];
        }
        for(i=0; i<s2; i++){
            cin>>n2[i];
        }
        Solution S;
        cout<<S.findMedianSortedArrays(n1,n2)<<endl;

        return 0;
}

