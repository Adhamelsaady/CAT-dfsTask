
class Solution {
public:
		int dr[4]{-1, 0, 1, 0};
		int dc[4]{0, 1, 0, -1};
		bool TB;
		bool isvalid(int r, int c, vector<vector<int>> &grid2) {
				return r > 0 && r < (int) grid2.size() && c > 0 && c < (int) grid2.size();
		}
		bool isGridBoundry(int r, int c, vector<vector<int>> &grid) {
		if (r == 0 || r == (int) grid.size() - 1)
			return true;
		if (c == 0 || c == (int) grid[0].size() - 1)
			return true;
		return false;
	}
	void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &ccIDs, int ccid) {
		if (!isvalid(r, c, grid) || ccIDs[r][c] || grid[r][c] == 1)
			return;
		if (isGridBoundry(r, c, grid))
			TB = true;
		ccIDs[r][c] = ccid;	
		for (int d = 0; d < 4; ++d)
			dfs(r + dr[d], c + dc[d], grid, ccIDs, ccid);
	}

	int closedIsland(vector<vector<int>> &grid) {
		vector<vector<int>> ccIDs(grid.size(), vector<int>(grid[0].size()));
		int rows = grid.size(), cols = grid[0].size(), ccid = 0, count = 0;
		for (int r = 0; r < rows; ++r) {
			for (int c = 0; c < cols; ++c) {
				if (!grid[r][c] && !ccIDs[r][c]) {
					TB = false;
					dfs(r, c, grid, ccIDs, ++ccid);
					count += !TB;
				}
			}
		}
		return count;
	}
};