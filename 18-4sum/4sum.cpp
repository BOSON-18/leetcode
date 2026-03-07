class Solution {
public:
   vector<vector<int>> fourSum(vector<int>& nums, int target) {

sort(nums.begin(),nums.end());
vector<vector<int>> ans;

	// Brute force is to use for loop 
	// Better is to use hashmap
	
	//optimal we will use 4 varibles
	int n=nums.size();
	for(int i=0;i<n-3;i++){
		if(i!=0 && nums[i-1]==nums[i]) continue;
		
		for(int j=i+1;j<n-2;j++){
		
			int c=j+1;
			int d = n-1;
			
			if(j>i+1 && nums[j] == nums[j-1]) continue;
			
			while(c<d){
			long long sum =(long long) nums[i]+ (long long) nums[j]+(long long) nums[c]+(long long) nums[d];
			if(sum==target){
			 ans.push_back({nums[i],nums[j],nums[c],nums[d]});
				d--;
				c++;
				while(c<d && nums[c] == nums[c-1]) c++;
				while(c<d && nums[d] == nums[d+1]) d--; 
			}else if(sum>target) d--;
			else c++;
			}
			
			
			
		}
	}
			return ans;
        
    }
};