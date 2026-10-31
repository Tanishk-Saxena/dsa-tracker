#!/usr/bin/env bash
# Usage: ./scripts/new.sh <bucket/category> <problem-name> [--notes]
set -euo pipefail

if [ $# -lt 2 ]; then
  echo "Usage: $0 <bucket/category> <problem-name> [--notes]" >&2
  exit 1
fi

bucket="$1"      # e.g. patterns/sliding-window
name="$2"        # e.g. longest-substring-no-repeat
notes="${3:-}"   # --notes to add notes.md

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
dir="$script_dir/../$bucket/$name"
mkdir -p "$dir"

# Levels from the problem folder up to the repo root = bucket segments + 1 (the problem folder itself)
bucket_trimmed="${bucket//\\//}"          # normalise backslashes to slashes
bucket_trimmed="${bucket_trimmed#/}"
bucket_trimmed="${bucket_trimmed%/}"
IFS='/' read -ra segments <<< "$bucket_trimmed"
depth=$(( ${#segments[@]} + 1 ))

prefix=""
for ((i = 0; i < depth; i++)); do prefix+="../"; done
include="${prefix}utils/dsa_utils.hpp"

cat > "$dir/solution.cpp" <<EOF
#include "$include"
using namespace std;
using namespace dsa;

class Solution {
public:
    // TODO: rename and set the real signature
    int solve() {
        return 0;
    }
};

int main() {
    Solution sol;
    // TODO: add test cases
    // cout << sol.solve() << "\n";
    return 0;
}
EOF

if [ "$notes" = "--notes" ]; then
  printf '# %s\n\n## Key pointers\n- \n' "$name" > "$dir/notes.md"
fi

echo "Created $dir"