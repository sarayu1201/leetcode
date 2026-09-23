class Solution:
    def commonChars(self, words: list[str]) -> list[str]:

        common = {}

        for ch in words[0]:
            common[ch] = common.get(ch, 0) + 1

        for word in words[1:]:

            current = {}

            for ch in word:
                current[ch] = current.get(ch, 0) + 1

            for ch in common:
                common[ch] = min(common[ch], current.get(ch, 0))

        result = []

        for ch in common:
            for i in range(common[ch]):
                result.append(ch)

        return result