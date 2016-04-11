#include<iostream>
#include<vector>
#include <stdlib.h>
#include<stdio.h>
#include<malloc.h>
using namespace std;

class Solution {
public:
    //获取第K大的数
    int getK(int *n1, int n1_s, int *n2, int n2_s, int k)
    {
            //使得n1的长度总是大于n2
            if(n2_s>n1_s){
                return getK(n2, n2_s, n1, n1_s, k);
            }
            //较小的为0，直接选取较大的
            if(n2_s == 0){
                return n1[k-1];
            }
            //都只有一个数时，选取较小的
            if(k==1){
                return min(n1[0], n2[0]);
            }

            int p2 = min(k/2, n2_s);
            int p1 = k - p2;

            if(n1[p1-1] == n2[p2-1]){
                return n1[p1-1];
            }else if(n1[p1-1]>n2[p2-1]){
                //舍弃较小的部分
                return getK(n1, n1_s, n2+p2, n2_s-p2, k-p2);
            }else{
                return getK(n1-p1, n1_s+p1, n2, n2_s, k-p1);
            }
    }
    //时间n(log(n+m))
     double findMedianSortedArraysL(vector<int>& nums1, vector<int>& nums2)
     {
                int n1_s,n2_s,i,k,n;
                int *n1,*n2;
                double res;
                n1_s = nums1.size();
                n2_s = nums2.size();
                //大于0分配内存（转化为数组）
                if(n1_s>0){
                    n1 = (int*)malloc(n1_s*sizeof(int));
                }
                if(n2_s>0){
                    n2 = (int*)malloc(n2_s*sizeof(int));
                }
                //赋值
                for(i=0;i<n1_s;i++){
                    n1[i] = nums1[i];
                }
                for(i=0;i<n2_s;i++){
                    n2[i] = nums2[i];
                }
                n = n1_s + n2_s;
                if(n%2 == 1){
                        //奇数直接求第(n+1)/2大的数
                        return 1.0*getK(n1,n1_s,n2,n2_s,(n+1)/2);
                }else{
                        //偶数个，返回中间的两个数
                        return ( 1.0*getK(n1,n1_s,n2,n2_s,n/2)+1.0*getK(n1,n1_s,n2,n2_s,n/2+1) )/2;
                }
                if(n1_s>0){
                        free(n1);
                }
                if(n2_s>0){
                        free(n2);
                }
     }
     //n(n+m)
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
        cout<<S.findMedianSortedArraysL(n1,n2)<<endl;

        return 0;
}

