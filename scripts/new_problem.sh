#!/usr/bin/env bash
set -euo pipefail

if [ $# -lt 2 ]; then
  echo "Usage: $0 <id: 4-digit> <slug-kebab-case>"
  echo "Example: $0 0123 best-time-to-buy-and-sell-stock"
  exit 1
fi

ID="$1"
SLUG="$2"
DIR="problems/${ID}-${SLUG}"

if [[ ! "$ID" =~ ^[0-9]{4}$ ]]; then
  echo "ID must be 4 digits, e.g. 0001"
  exit 1
fi

mkdir -p "$DIR"

cat > "${DIR}/CMakeLists.txt" <<'EOF'
# Auto-generated problem
get_filename_component(PROB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE "-" "_" PROB_TARGET ${PROB_NAME})

add_executable(${PROB_TARGET} main.cpp)
target_link_libraries(${PROB_TARGET} PRIVATE lc_common)

add_executable(${PROB_TARGET}_tests test.cpp)
target_link_libraries(${PROB_TARGET}_tests PRIVATE lc_common GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROB_TARGET}_tests)
EOF

cat > "${DIR}/main.cpp" <<'EOF'

#include "leetcode.hpp"
using namespace std;

// Replace with the actual solution for this problem
class Solution {
public:
    int placeholder(int x) { return x; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    cout << s.placeholder(42) << "\n";
    return 0;
}
EOF

cat > "${DIR}/test.cpp" <<'EOF'

#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

// Mirror the class you implement in main.cpp or move it to a header
class Solution {
public:
    int placeholder(int x) { return x; }
};

TEST(Template, Works){
    Solution s;
    EXPECT_EQ(s.placeholder(42), 42);
}
EOF

echo "Created ${DIR}"
