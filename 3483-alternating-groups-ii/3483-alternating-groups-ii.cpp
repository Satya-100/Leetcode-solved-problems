class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int res = 0;
        int lastColor = colors[0];
        int alter = 1;

        for (int i = 1; i < n + k - 1; i++) {
            int ind = i % n;
            if (colors[ind] == lastColor) {
                alter = 1;
                lastColor = colors[ind];
                continue;
            }
            alter++;
            if (alter >= k)
                res++;
            lastColor = colors[ind];
        }

        return res;
    }
};