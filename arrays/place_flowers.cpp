class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int a) {
        int n = fb.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if ((fb[i] == 0) && (i == 0 || fb[i - 1] == 0) &&
                (i == n - 1 || fb[i + 1] == 0)) {
                fb[i] = 1;
                count++;
            }
        }

        return (count >= a) ? true : false;
    }
};