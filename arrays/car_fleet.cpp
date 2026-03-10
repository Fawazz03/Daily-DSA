class Solution {
public:
    int carFleet(int target, vector<int>& positions, vector<int>& speed) {
        int n = positions.size();

        // Prevent out-of-bounds access if inputs are mismatched
        if (speed.size() != n)
            return 0;

        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = make_pair(positions[i],
                                (double)(target - positions[i]) / speed[i]);
        }

        sort(cars.begin(), cars.end());
        stack<double> st;

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty() || st.top() < cars[i].second) {
                st.push(cars[i].second);
            }
        }

        return st.size();
    }
};
