class Solution {
public:
	int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
		// visited cells will be marked by grid[i][j] > 1
		std::queue<std::pair<int, int>> qq; // queue of cells to visit next
		std::pair<int, int> crawler(0, 0); // cell being visited
		int nsteps = 1; // number of steps

		// enqueue first cell
		if (grid[0][0] == 0) qq.push(std::pair<int, int>(0, 0));
		grid[0][0] = 2; // mark as visited

		// breadth-first search
		while (!qq.empty()) {
			// pop only the current nsteps
			int qsize = qq.size();
			for (int i = 0; i < qsize; i++) {
				// visit next cell
				crawler = qq.front();
				qq.pop();
				// if destination reached, return
				if (crawler == std::pair<int, int>(grid[0].size() - 1, grid.size() - 1)) return nsteps;
				// else queue neighbours
				for (int nx : {crawler.first - 1, crawler.first, crawler.first + 1}) {
					for (int ny : {crawler.second - 1, crawler.second, crawler.second + 1}) {
						// check if new indices are valid
						if (nx == crawler.first && ny == crawler.second) continue;
						if (nx < 0 || nx >= grid[0].size()) continue;
						if (ny < 0 || ny >= grid[0].size()) continue;
						if (grid[nx][ny] != 0) continue;
						if (grid[nx][ny] > 1) continue; // means visited
						// queue neighbours
						qq.push(std::pair<int, int>(nx, ny));
						grid[nx][ny] = 2; //mark as visited
					}
				}
			}
			// increment nsteps
			nsteps++;
		}

		// no path found
		return -1;
	}
};