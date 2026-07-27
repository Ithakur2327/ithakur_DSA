class Solution:
    def minimumSteps(self, s: str) -> int:
        ans=0
        target=0

        for i in range(len(s)):
            if s[i]=='0':
                ans+=i-target
                target+=1

        return ans 