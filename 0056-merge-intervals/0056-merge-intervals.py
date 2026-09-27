class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals.sort()

        result = []

        for interval in intervals:

            if not result:
                result.append(interval)

            elif interval[0] <= result[-1][1]:
                result[-1][1] = max(result[-1][1], interval[1])

            else:
                result.append(interval)

        return result
        