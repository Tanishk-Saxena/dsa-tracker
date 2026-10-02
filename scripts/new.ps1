param(
  [Parameter(Mandatory)][string]$Bucket,   # e.g. patterns/sliding-window
  [Parameter(Mandatory)][string]$Name,     # e.g. longest-substring-no-repeat
  [switch]$Notes                           # add notes.md only when needed
)

$dir = Join-Path $PSScriptRoot "..\$Bucket\$Name"
New-Item -ItemType Directory -Force $dir | Out-Null

@'
#include <bits/stdc++.h>
using namespace std;

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
'@ | Set-Content "$dir\solution.cpp"

if ($Notes) {
  "# $Name`n`n## Key pointers`n- " | Set-Content "$dir\notes.md"
}

Write-Host "Created $dir"