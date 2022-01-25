class Solution {
    bool check(vector<int>&v,int m,int mid)
    {
        int count=0;
        int sum=0;
        for(int i=0;i<v.size();++i)
        {
            sum+=v[i];
            if(sum>mid)
            {
                 sum=v[i];
                count++;
            
            }
             
        }   
         count++;
             return count<=m;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        
         // l is max element of nums vector 
		 // r is sum of nums vector
        int l=*max_element(nums.begin(),nums.end())  ,  r=accumulate(nums.begin(),nums.end(),0LL);
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
             if(check(nums,m,mid)) 
            {
                ans=mid; 
                r=mid-1;
            }else{ 
                l=mid+1;
                ans=l;
            }
        }
        
        return ans;
    }
};