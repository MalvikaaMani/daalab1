class Solution {
public:
     void combinationSum(vector<int>& nums, int i, int target, vector<int>& temp, vector<vector<int>>& ans){
	    
	    if(target == 0){
		    ans.push_back(temp);
		    return;
	    }
	    if(i == nums.size()){
		    if(target == 0){
			    ans.push_back(temp);
		    }
		    return;
	    }

	   
	    if(nums[i] <= target){
		    temp.push_back(nums[i]);
		    combinationSum(nums, i, target-nums[i], temp, ans);
		    temp.pop_back();
	    }
        
	    combinationSum(nums, i+1, target, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
	    vector<vector<int>> ans;
	    combinationSum(nums, 0, target, temp, ans);
        return ans;
    }
};
