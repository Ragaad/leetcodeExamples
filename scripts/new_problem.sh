#!/usr/bin/env bash
set -euo pipefail

# Usage:
#   ./scripts/new_problem.sh 0207 course-schedule
#   ./scripts/new_problem.sh 2 "Add Two Numbers"
#
# Creates:
#   problems/0207-course-schedule/
#     CMakeLists.txt
#     cpp/{main.cpp,test.cpp}
#     python/{solution.py,test_solution.py,__init__.py}

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PROBLEMS_DIR="$ROOT/problems"

if [[ $# -lt 2 ]]; then
  echo "Usage: $0 <id> <slug or title>"
  exit 1
fi

RAW_ID="$1"; shift
RAW_SLUG="$*"

# --- normalize id to 4 digits ---
if [[ ! "$RAW_ID" =~ ^[0-9]+$ ]]; then
  echo "Error: id must be numeric (got '$RAW_ID')"
  exit 1
fi
# avoid octal with leading zeros: 10# forces base-10
ID=$(printf "%04d" "$((10#$RAW_ID))")

# --- normalize slug: lowercase, non [a-z0-9-] -> -, collapse dashes ---
SLUG="$(printf "%s" "$RAW_SLUG" | tr '[:upper:]' '[:lower:]' | sed -E 's/[^a-z0-9]+/-/g; s/^-+//; s/-+$//; s/-+/-/g')"
if [[ -z "$SLUG" ]]; then
  echo "Error: slug/title normalization produced empty string."
  exit 1
fi

DEST="$PROBLEMS_DIR/${ID}-${SLUG}"
CPP_DIR="$DEST/cpp"
PY_DIR="$DEST/python"

if [[ -e "$DEST" ]]; then
  echo "Error: problem folder already exists: $DEST"
  exit 1
fi

mkdir -p "$CPP_DIR" "$PY_DIR"

# --- CMakeLists for this problem ---
cat > "$DEST/CMakeLists.txt" <<'CMAKE'
# Per-problem CMake
get_filename_component(PROB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE "-" "_" PROB_TARGET ${PROB_NAME})

add_executable(${PROB_TARGET} cpp/main.cpp)
target_link_libraries(${PROB_TARGET} PRIVATE lc_common)

add_executable(${PROB_TARGET}_tests cpp/test.cpp)
target_link_libraries(${PROB_TARGET}_tests PRIVATE lc_common GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROB_TARGET}_tests) # DISCOVERY_MODE defaults to POST_BUILD
CMAKE

# --- C++ main.cpp stub ---
cat > "$CPP_DIR/main.cpp" <<'CPP'
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    // TODO: implement for this problem
    void placeholder() {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // TODO: small demo if desired
    // Solution s; ...
    return 0;
}
CPP

# --- C++ test.cpp stub (GoogleTest) ---
cat > "$CPP_DIR/test.cpp" <<'CPP'
#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    void placeholder() {}
};

TEST(Template, Smoke) {
    Solution s;
    SUCCEED(); // replace with real tests
}
CPP

# --- Python skeleton ---
cat > "$PY_DIR/solution.py" <<'PY'
# TODO: implement the Python version for this problem.

class Solution:
    def placeholder(self):
        pass

def solve():
    # optional runner entrypoint
    pass

if __name__ == "__main__":
    print("Implement me!")
PY

cat > "$PY_DIR/test_solution.py" <<'PY'
# pytest skeleton. Replace with real tests.
def test_placeholder():
    assert True
PY

: > "$PY_DIR/__init__.py"

echo "✓ Created ${DEST}"
echo "  - cpp/: main.cpp, test.cpp"
echo "  - python/: solution.py, test_solution.py, __init__.py"
echo "  - CMakeLists.txt (targets derived from folder name)"

echo
echo "Next:"
echo "  1) Implement cpp/main.cpp and cpp/test.cpp"
echo "  2) Reconfigure & build:"
echo "       cmake --preset default && cmake --build --preset default && ctest --preset default --output-on-failure"
echo "  3) (Optional) Write Python solution/tests in python/"
