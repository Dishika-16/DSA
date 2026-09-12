class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();

        // Store the index of the rightmost robot
        // of each initial group.
        vector<int> leaders;

        for (int i = 0; i < n; i++) {

            // If this is the last robot OR
            // next robot is more than 'distance' away,
            // then i is the rightmost robot of an initial group.
            if (i == n - 1 ||
                (long long)position[i + 1] - position[i] > distance) {
                
                leaders.push_back(i);
            }
        }

        int groups = 0;

        // Minimum speed among groups that survive on the right.
        long long minSpeed = LLONG_MAX;

        // Process groups from right to left.
        for (int i = leaders.size() - 1; i >= 0; i--) {

            int currentSpeed = speed[leaders[i]];

            // This group cannot catch any group on its right
            // if its speed is <= the minimum speed on the right.
            if (currentSpeed <= minSpeed) {
                groups++;
                minSpeed = currentSpeed;
            }
        }

        return groups;
    }
};