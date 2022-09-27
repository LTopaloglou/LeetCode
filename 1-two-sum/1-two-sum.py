class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = len(nums)
        for j in range(l):
            for i in range(j+1, l):
                if nums[i] + nums[j] == target:
                    return [j, i]
        