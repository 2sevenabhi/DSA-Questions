class Solution {
private:
	/**
	 * Recursively search for node in graph
	 *
	 * @param val current value, will be multiplied by next edge
	 * @param node current node to search from
	 * @param dest final node to stop at
	 * @param visited nodes visited already
	 * @param graph graph[A][B] = A/B
	 *
	 * @return product of all edges of found path, or -1.0 if dest not found
	 */
	double recurse(double val, string node, string dest, set<string>& visited,
		unordered_map<string, unordered_map<string, double>>& graph) {
		// if destination found, return value
		if (node == dest and graph.find(node) != graph.end()) {
			return val;
		}

		// else recurse through all unvisited neighbours
		double tmp;
		for (auto it : graph[node]) {
			if (visited.find(it.first) == visited.end()) {
				visited.insert(it.first);
				tmp = recurse(val * it.second, it.first, dest, visited, graph);
				if (tmp != -1.0) return tmp; // if destination found, echo value
			}
		}

		// destination not found in all neighbours, return -1
		return -1.0;
	}

public:
	/**
	 * Evaulates the fractions b/w two algebraic variables based on a set of
	 * other known fractions
	 *
	 * @param equations known equations[i] = [numerator[i], denominator[i]]
	 * @param values known values[i] = numerator[i] / denominator[i]
	 * @param queries unknown queries[i] = [qnumerator[i], qdenominator[i]]
	 *
	 * @return unknown qvalues[i] = qnumerator[i] / qdenominator[i]
	 */
	vector<double> calcEquation(
		vector<vector<string>>& equations,
		vector<double>& values,
		vector<vector<string>>& queries) {
		// build graph (graph[A][B] = A/B)
		unordered_map<string, unordered_map<string, double>> graph;
		for (int i = 0; i < equations.size(); i++) {
			graph[equations[i][0]][equations[i][1]] = values[i];
			graph[equations[i][1]][equations[i][0]] = 1 / values[i];
		}

		// answer queries
		set<string> visited;
		vector<double> answers;
		for (int i = 0; i < queries.size(); i++) {
			visited.clear();
			answers.push_back(recurse(1, queries[i][0], queries[i][1], visited,
				graph));
		}

		return answers;
	}
};