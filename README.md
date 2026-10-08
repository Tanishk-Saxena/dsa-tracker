# DSA Tracker

My DSA progress, in C++. One folder per problem.

## Layout
- `patterns/<pattern>/<problem>/` – problems grouped by technique
- `stl/<container-or-algo>/<problem>/` – STL-focused problems

## Per-problem folder
- `solution.cpp` – the solution
- `notes.md` – optional; key pointers, edge cases, "why I got this wrong the first time"

## Adding a problem
`.\scripts\new.ps1 <bucket/category> <problem-name> [-Notes]`

## Conventions
- Folder names: lowercase-kebab-case
- C++20

## Commit Convention
Format: `<verb> <problem-name> [<bucket>]`

```
Add longest-substring-no-repeat [patterns]
Add group-anagrams [stl]
Add two-sum [<sheet-folder-name>]
Update two-sum [patterns]
Setup README and scripts
```

### Rules
- **One problem, one commit.**
- **Imperative verb + lowercase-kebab problem name**, same as the folder name.
- **Bucket tag is required** (`patterns`, `stl`, or the sheet's folder name), because the same problem can appear in more than one bucket. `Setup` commits don't need one.
- **Verbs:**
  - `Add`: new problem
  - `Update`: revisited it, improved the solution or notes
  - `Fix`: the old solution was wrong
  - `Setup`: repo, scripts, README, `.vscode` changes
- **No Conventional Commits** (`feat:`, `chore:`, etc.).

### Filtering the log
- By bucket: `git log --oneline -- patterns/`
- By pattern: `git log --oneline -- patterns/sliding-window`
- One problem across buckets: `git log --oneline --grep="two-sum"`

### Optional
- For revisits, add a short body if something is worth remembering.
- Grinding several problems in one sitting? One commit listing them is fine, as long as they share a bucket: `Add three-sum, two-sum-ii [patterns]`. Don't mix buckets in one commit.