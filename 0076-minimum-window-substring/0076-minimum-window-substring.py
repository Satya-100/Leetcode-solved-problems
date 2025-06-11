class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""
        
        countT, wind = {}, {}

        for c in t:
            countT[c] = 1 + countT.get(c, 0)
        
        have, need = 0, len(countT)
        res, resL = [-1, -1], float("infinity")
        l = 0

        for r in range(len(s)):
            wind[s[r]] = 1 + wind.get(s[r], 0)

            if s[r] in countT and wind[s[r]] == countT[s[r]]:
                have += 1
            
            while have == need:
                if (r - l + 1) < resL:
                    resL = r - l + 1
                    res = [l, r]
                
                wind[s[l]] -= 1
                if s[l] in countT and wind[s[l]] < countT[s[l]]:
                    have -= 1
                
                l += 1
        
        l, r = res
        return s[l:r+1] if resL != float("infinity") else ""