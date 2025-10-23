#!/usr/bin/env bash
set -euo pipefail

# ─────────────────────────────────────────────────────────────
# CONFIGURATION — EDIT THESE
# ─────────────────────────────────────────────────────────────
GITHUB_USER="Ragaad"   # ← your GitHub username
REPO_NAME="leetcodeExamples"           # ← your repo name on GitHub
USE_SSH_REMOTE=true                    # set to false to use HTTPS

# ─────────────────────────────────────────────────────────────
# INIT GIT (if needed) & ADD REMOTE
# ─────────────────────────────────────────────────────────────
if [ ! -d .git ]; then
  echo "Initializing new git repository..."
  git init
  git branch -m main || true
fi

# Add remote if not already set
if git remote get-url origin >/dev/null 2>&1; then
  echo "Remote 'origin' already set: $(git remote get-url origin)"
else
  if [ "${USE_SSH_REMOTE}" = true ]; then
    git remote add origin "git@github.com:${GITHUB_USER}/${REPO_NAME}.git"
  else
    git remote add origin "https://github.com/${GITHUB_USER}/${REPO_NAME}.git"
  fi
  echo "Added remote 'origin'."
fi

# ─────────────────────────────────────────────────────────────
# FIRST COMMIT & PUSH
# ─────────────────────────────────────────────────────────────
echo "Creating initial commit..."
git add .
git commit -m "Initial C++20 + CMake LeetCode scaffold (gtest + presets + scripts)" || true

echo "Pushing to GitHub..."
git push -u origin main

echo "✅ Done. Repo pushed to GitHub: ${GITHUB_USER}/${REPO_NAME}"