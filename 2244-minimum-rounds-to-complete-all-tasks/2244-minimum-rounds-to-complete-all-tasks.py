class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        cnt=Counter(tasks)
        ans=0

        for freq in cnt.values():
            if freq==1:
                return -1

            if freq%3==0:
                ans+=freq//3
            elif freq%3==1:
                ans+=(freq-4)//3+2
            else:
                ans+=freq//3+1

        return ans