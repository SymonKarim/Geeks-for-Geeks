class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
       int x_or = nums[0];
       int x = 0, y = 0;
       for(int i=1;i<nums.size();i++) x_or^=nums[i];
       int setBits = x_or & ~(x_or-1);
       
       for(auto i:nums){
           if(i & setBits) x^=i;
           else y^=i;
       }
       if(x>y) swap(x,y);
        return {x,y};
    }
};
