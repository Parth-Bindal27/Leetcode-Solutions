class Solution(object):
    def isPrefixString(self, s, words):
        t = ""

        for word in words:
            t += word

            if s == t:
                return True

            if len(t) > len(s):
                return False

        return False