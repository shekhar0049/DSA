class Solution {
public:
    int singleNumber(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     int first,second,third;
     first;

     if(nums.size()<2)
     return nums[0];


     int i=0;
       while(i<=nums.size()-2){
     first=nums[i];
     second=nums[i+1];
     third=nums[i+2];

     if(first!=second)
     return first;

     i+=2;
        
    }
        return third;
    }
    
};