#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

/* Option A: keep a local copy here and paste your implementation.
   Option B (preferred): move Solution to a header (e.g., solution_0207.hpp) and #include it. */
class Solution {
public:
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

// Helper to build vector<vector<int>> nicely
static vector<vector<int>> VV(initializer_list<initializer_list<int>> il) {
    vector<vector<int>> v;
    v.reserve(il.size());
    for (auto &row : il) v.emplace_back(row);
    return v;
}

TEST(CourseSchedule, Example_True) {
    Solution s;
    int n = 2;
    auto pre = VV({{1,0}});
    EXPECT_TRUE(s.canFinish(n, pre));
}

TEST(CourseSchedule, Example_False_Cycle) {
    Solution s;
    int n = 2;
    auto pre = VV({{1,0},{0,1}});
    EXPECT_FALSE(s.canFinish(n, pre));
}

TEST(CourseSchedule, LinearChain_True) {
    Solution s;
    int n = 4;
    auto pre = VV({{1,0},{2,1},{3,2}});
    EXPECT_TRUE(s.canFinish(n, pre));
}

TEST(CourseSchedule, MixedComponents_OneCycle) {
    Solution s;
    int n = 4;
    auto pre = VV({{1,0},{0,1},{3,2}}); // cycle on 0↔1, plus independent edge 2→3
    EXPECT_FALSE(s.canFinish(n, pre));
}

TEST(CourseSchedule, NoPrereqs_AllFree) {
    Solution s;
    int n = 5;
    auto pre = VV({});
    EXPECT_TRUE(s.canFinish(n, pre));
}

TEST(CourseSchedule, SelfLoop_False) {
    Solution s;
    int n = 1;
    auto pre = VV({{0,0}});
    EXPECT_FALSE(s.canFinish(n, pre));
}

TEST(CourseSchedule, BranchingDAG_True) {
    Solution s;
    int n = 4;
    auto pre = VV({{1,0},{2,0},{3,1},{3,2}}); // 0→1→3 and 0→2→3
    EXPECT_TRUE(s.canFinish(n, pre));
}

TEST(CourseSchedule, DuplicatedEdges_True) {
    Solution s;
    int n = 3;
    auto pre = VV({{1,0},{1,0}}); // duplicate edge shouldn't break logic
    EXPECT_TRUE(s.canFinish(n, pre));
}
