param(
  [Parameter(Mandatory)][string]$Bucket,   # e.g. patterns/sliding-window
  [Parameter(Mandatory)][string]$Name,     # e.g. longest-substring-no-repeat
  [switch]$Notes                           # add notes.md only when needed
)

$dir = Join-Path $PSScriptRoot "..\$Bucket\$Name"
New-Item -ItemType Directory -Force $dir | Out-Null

# Levels from the problem folder up to the repo root = bucket segments + 1 (the problem folder itself)
$segments = @($Bucket -split '[\\/]' | Where-Object { $_ })
$depth    = $segments.Count + 1
$include  = ('../' * $depth) + 'utils/dsa_utils.hpp'

$template = @'
#include "__INCLUDE__"
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
'@

$template.Replace('__INCLUDE__', $include) | Set-Content "$dir\solution.cpp"

if ($Notes) {
  "# $Name`n`n## Key pointers`n- " | Set-Content "$dir\notes.md"
}

Write-Host "Created $dir"