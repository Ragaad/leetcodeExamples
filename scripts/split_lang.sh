#!/usr/bin/env bash
set -euo pipefail

# Repo root (this script sits in scripts/, we cd to ..)
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PROBLEMS="$ROOT/problems"

if [[ ! -d "$PROBLEMS" ]]; then
  echo "ERROR: '$PROBLEMS' not found. Run this from within your repo."
  exit 1
fi

# Use git moves if it's a git repo (to preserve history)
USE_GIT=false
if [[ -d "$ROOT/.git" ]]; then
  USE_GIT=true
fi

echo "Splitting problems into cpp/ and python/ ..."
echo

shopt -s nullglob
for DIR in "$PROBLEMS"/*-*/ ; do
  [[ -d "$DIR" ]] || continue
  BASE="$(basename "$DIR")"
  CPPDIR="$DIR/cpp"
  PYDIR="$DIR/python"

  # Skip if already split
  if [[ -d "$CPPDIR" || -d "$PYDIR" ]]; then
    echo "• Skipping $BASE (already has cpp/ or python/)"
    continue
  fi

  mkdir -p "$CPPDIR" "$PYDIR"

  # Move typical C++ sources if present
  moved_any=false
  for f in main.cpp test.cpp; do
    if [[ -f "$DIR/$f" ]]; then
      if $USE_GIT; then git mv "$DIR/$f" "$CPPDIR/$f"; else mv "$DIR/$f" "$CPPDIR/$f"; fi
      moved_any=true
    fi
  done

  # Update CMakeLists to refer to cpp/main.cpp and cpp/test.cpp if needed
  CMAKE="$DIR/CMakeLists.txt"
  if [[ -f "$CMAKE" && "$moved_any" == true ]]; then
    cp "$CMAKE" "$CMAKE.bak"  # backup
    # macOS sed: -i '' for in-place
    sed -i '' -e 's|\bmain\.cpp\b|cpp/main.cpp|g' -e 's|\btest\.cpp\b|cpp/test.cpp|g' "$CMAKE" || true
  fi

  # Create python skeleton
  if [[ ! -f "$PYDIR/solution.py" ]]; then
    cat > "$PYDIR/solution.py" <<'PY'
def solve(*args, **kwargs):
    """
    TODO: implement Python solution for this problem.

    Suggested structure:
      class Solution:
          def method(...): ...
    Then expose a tiny solve() or leave only the class and use tests to drive.
    """
    pass

if __name__ == "__main__":
    print("Implement me!")
PY
  fi

  if [[ ! -f "$PYDIR/test_solution.py" ]]; then
    cat > "$PYDIR/test_solution.py" <<'PY'
# pytest-style skeleton; adjust to the actual function/class you implement.
def test_placeholder():
    assert True  # replace with real tests
PY
  fi

  # Make it a package (optional, handy for imports)
  : > "$PYDIR/__init__.py"

  echo "✓ $BASE → created cpp/ & python/; moved C++ sources; updated CMakeLists (backup: CMakeLists.txt.bak)"
done

echo
echo "Done."
echo "Next steps:"
echo "  1) Reconfigure & build C++:"
echo "       cmake --preset default && cmake --build --preset default && ctest --preset default --output-on-failure"
echo "  2) (Optional) Run Python tests with pytest inside a problem's python/ folder."
