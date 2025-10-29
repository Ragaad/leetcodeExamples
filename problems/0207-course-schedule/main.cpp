#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    // Return true if you can finish all courses given prerequisites.
    // Each pair [a,b] means you must take b before a (edge b -> a).
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // TODO (Kahn's algorithm, O(V+E)):
        // 1) Build adj list: for [a,b] do adj[b].push_back(a), indeg[a]++
        vector<vector<int>> adj;
        vector<int> indeg(numCourses, 0);
        for (const auto& e : prerequisites) {
             int a = e[0], b = e[1];   // b -> a
             adj[b].push_back(a);
             indeg[a]++;               // in-degree of a
           }
           queue<int> q;
        for (int v = 0; v < numCourses; ++v)
            if (indeg[v] == 0) q.push(v);

        int seen = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ++seen;
            for (int v : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }
        return seen == numCourses;  // all nodes processed ⇒ no cycle
    }
        
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    int numCourses = 2;
    vector<vector<int>> prereq{{1,0}};
    cout << boolalpha << s.canFinish(numCourses, prereq) << "\n"; // expect true
    return 0;
}
