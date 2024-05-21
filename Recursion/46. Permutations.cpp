class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        Permutation(nums, subset, res, 0);
        return res;
    }
private:
    void Permutation(vector<int> nums, vector<int>& subset, 
        vector<vector<int>>& res, int index){
            
        if(subset.size() == nums.size()){
            res.push_back(subset);
        }

        for(int i = index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            subset.push_back(nums[index]);
            Permutation(nums, subset, res, index+1);
            subset.pop_back();
            swap(nums[i], nums[index]);
        }
    }
};
