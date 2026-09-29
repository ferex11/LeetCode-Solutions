#define pb push_back
class Solution {
public:
  void dfs(string &source, string &destination, unordered_map<string, vector<pair<string, double>>> &adjList, unordered_set<string> &vis, double& prod, double& ans) {
    if (vis.find(source) != vis.end()) return;
    vis.insert(source);
    if (source == destination) {
      ans = prod;
      return;
    }
    for (auto it : adjList[source]) {
      string adjNode = it.first;
      double adjValue = it.second;
      prod *= adjValue;
      dfs(adjNode, destination, adjList, vis, prod, ans);
      prod /= adjValue;
    }
  }
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    int n = equations.size();
    unordered_map<string, vector<pair<string, double>>> adjList;
    for (int i = 0; i < n; i++) {
      string u = equations[i][0];
      string v = equations[i][1];
      double val = values[i];
      adjList[u].pb({v, val});
      adjList[v].pb({u, 1.0 / val});
    }
    vector<double> res;
    for (auto it : queries) {
      string source = it[0];
      string destination = it[1];
      double ans = -1.0;
      double prod = 1.0;
      if (adjList.find(source) != adjList.end()) {
        unordered_set<string> vis;
        dfs(source, destination, adjList, vis, prod, ans);
      }
      res.pb(ans);
    }
    return res;
  }
};
