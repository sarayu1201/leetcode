class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        while len(stones) > 1:
            stones.sort(reverse=True)
            x = stones[0]
            y = stones[1]
            del stones[0:2]
            if x != y:
                stones.append(x - y)
        if len(stones) == 0:
            return 0
        return stones[0]
        