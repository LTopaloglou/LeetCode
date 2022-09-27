class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for j in range(len(nums)):
            for i in range(j+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [j, i]
        