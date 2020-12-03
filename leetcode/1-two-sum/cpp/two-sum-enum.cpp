#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size()-1;i++)
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]+nums[j]==target)
            {
                
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
        return result;
    }
};

int main(){    
    vector<int> nums={2,7,11,15};
    int target=9;

    auto sln=Solution();
    auto twoSum=sln.twoSum(nums,target);
    
    for(const auto &c:twoSum)
    cout<<c<<" ";


}