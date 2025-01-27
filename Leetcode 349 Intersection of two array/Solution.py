class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        Nums1=list(nums1)
        Nums2=list(nums2)
        n1=set(Nums1)
        n2=set(Nums2)
        commmon=n1&n2
        return list(commmon)


        
