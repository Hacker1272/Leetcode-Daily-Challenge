class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0,j=1;
        while(i<nums.size() && j<nums.size())
        {
            while(i<nums.size() && nums[i]%2==0)
            {
                i+=2;
            }
            while(j<nums.size() && (nums[j]%2)!=0)
            {
                j+=2;
            }
            //cout<<i<<" "<<j<<endl;
            if(i<nums.size() && j<nums.size())
            {
                swap(nums[i],nums[j]);
            }
        }
        return nums;
    }
};

//TC = O(n)
//SC=O(1)
