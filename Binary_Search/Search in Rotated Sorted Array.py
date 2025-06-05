class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start, last = 0, len(nums) - 1
        
        while start <= last:
            mid = (start + last) // 2
            
            if nums[mid] == target:
                return mid
            
            if nums[start] <= nums[mid]:
                # Target in the sorted left half
                if nums[start] <= target < nums[mid]:
                    last = mid - 1
                else:
                    start = mid + 1
            else:
                # Right half must be sorted
                if nums[mid] < target <= nums[last]:
                    start = mid + 1
                else:
                    last = mid - 1
        
        return -1
