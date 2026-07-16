class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        s = str(x)
        z = s[::-1]
        for i in range(len(s)):
            if s[i] != z[i]:
                return False

        return True
        