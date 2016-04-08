#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution{
public:
    	//时间复杂度n^2
        vector<int> twoSum(vector<int>& nums, int target)
        {
            vector<int> tmp(2);
            int i,j;
            for(i=0; i<nums.size();i++){
                    for(j=i+1;j<nums.size();j++){
                            if(nums[i]+nums[j] == target){
                                    tmp[0] = i;
                                    tmp[1] = j;
                                    break;
                            }
                    }
            }
             for(int i =0;i<tmp.size();i++){
                cout<<tmp[i]<<endl;
        }
            return tmp;
        }
	//时间复杂度为n
        vector<int> twoSumN(vector<int>& nums, int target)
        {
            vector<int> tmp(2);
            int i,j;
            map<int,int> m;

            for(i=0; i<nums.size(); i++){
                    if(m.count(target-nums[i]) != 0 ){
                            tmp[1] = i;
                            tmp[0] = m[nums[i]];
                    }
                    m[nums[i]] = i;
            }
            return tmp;
        }
};

int main()
{
        int n;
        cin>>n;
        vector<int> nums(n);
        vector<int> tmp(2);

        for(int i=0; i<n;i++){
                cin>>nums[i];
        }
        Solution s;
        tmp = s.twoSumN(nums,9);
        for(int i=0; i<tmp.size();i++){
                cout<<tmp[i]<<" ";
        }

        return 0;
}
