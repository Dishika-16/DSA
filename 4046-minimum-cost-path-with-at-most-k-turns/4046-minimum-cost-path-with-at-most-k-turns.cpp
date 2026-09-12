class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // direction:
        // 0 = up
        // 1 = down
        // 2 = left
        // 3 = right
        // 4 = no previous direction (starting cell)

        const long long INF = 1e18;

        // dist[row][col][turns][direction]
        vector<vector<vector<vector<long long>>>> dist(
            m,
            vector<vector<vector<long long>>>(
                n,
                vector<vector<long long>>(
                    k + 1,
                    vector<long long>(5, INF)
                )
            )
        );

        // {cost, row, col, turns, direction}
        using State = tuple<long long, int, int, int, int>;

        priority_queue<State, vector<State>, greater<State>> pq;

        // Start at (0,0), no direction yet, 0 turns
        dist[0][0][0][4] = grid[0][0];

        pq.push({grid[0][0], 0, 0, 0, 4});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto [cost, r, c, turns, dir] = pq.top();
            pq.pop();

            // Ignore outdated state
            if (cost != dist[r][c][turns][dir]) {
                continue;
            }

            // Reached destination
            if (r == m - 1 && c == n - 1) {
                return (int)cost;
            }

            for (int newDir = 0; newDir < 4; newDir++) {

                int nr = r + dr[newDir];
                int nc = c + dc[newDir];

                // Outside grid
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

                int newTurns = turns;

                // If direction changes, one turn occurs.
                // At starting cell there is no previous direction,
                // so the first move does NOT count as a turn.
                if (dir != 4 && dir != newDir) {
                    newTurns++;
                }

                // More than k turns is not allowed
                if (newTurns > k) {
                    continue;
                }

                long long newCost = cost + grid[nr][nc];

                if (newCost < dist[nr][nc][newTurns][newDir]) {

                    dist[nr][nc][newTurns][newDir] = newCost;

                    pq.push({
                        newCost,
                        nr,
                        nc,
                        newTurns,
                        newDir
                    });
                }
            }
        }

        return -1;
    }
};