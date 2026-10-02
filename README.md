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