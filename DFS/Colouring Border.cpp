
class Solution {
public:
		int dr[4]{-1, 0, 1, 0};
		int dc[4]{0, 1, 0, -1};
		bool SubIsland;
		bool isvalid(int r, int c, vector<vector<int>> &grid2) {
				return r > 0 && r < (int) grid2.size() && c > 0 && c < (int) grid2.size();
		}
		void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &visited, int oldcolor) {
				if (!isvalid(r, c, grid) || visited[r][c] || grid[r][c] != oldcolor)
						return;
				visited[r][c] = 1;
				for (int d = 0; d < 4; ++d)
						dfs(r + dr[d], c + dc[d], grid, visited, oldcolor);
		}
		void createBoundries(vector<vector<int>> &grid, vector<vector<bool>> &visited, int newColor) {
				int rows = grid.size(), cols = grid[0].size();
				for (int r = 0; r < rows; ++r) {
						for (int c = 0; c < cols; ++c) {
								for (int d = 0; d < 4; ++d) {
										if(!visited[r][c])
												continue;
										int nr = r + dr[d], nc = c + dc[d];
										if (!isvalid(nr, nc, grid) || !visited[nr][nc])
												grid[r][c] = newColor;
								}
						}
				}
		}
		vector<vector<int>> colorBorder(vector<vector<int>> &grid, int sr, int sc, int newColor) {
				vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
				dfs(sr, sc, grid, visited, grid[sr][sc]);
				createBoundries(grid, visited, newColor);
				return grid;
		}
};