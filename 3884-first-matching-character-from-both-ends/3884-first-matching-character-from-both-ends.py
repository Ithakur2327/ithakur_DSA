class Solution:
    def firstMatchingIndex(self, s: str) -> int:
        l, h = 0, len(s) - 1
        
        while l<=h:
            if s[l] == s[h]:
                return l
            l += 1
            h -= 1
        
        return -1