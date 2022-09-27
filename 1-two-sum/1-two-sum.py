class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = dict()
        l = len(nums)
        for i in range(l):
            if nums[i] in d:
                return [d[nums[i]], i]
            else:
                d[target-nums[i]] = i