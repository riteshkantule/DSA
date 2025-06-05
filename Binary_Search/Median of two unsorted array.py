class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n = len(nums1)
        m = len(nums2)
        
        itr1, itr2 = 0, 0
        
        prev, curr = 0, 0
        
        total_len = n + m
        
        for _ in range(total_len // 2 + 1):
            prev = curr
            
            if itr1 < n and (itr2 >= m or nums1[itr1] <= nums2[itr2]):
                curr = nums1[itr1]
                itr1 += 1
            else:
                curr = nums2[itr2]
                itr2 += 1
        
        if total_len % 2 == 1:
            return curr
        else:
            return (prev + curr) / 2
