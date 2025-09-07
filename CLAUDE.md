# Claude Code Guidelines

## Compilation
- Use `g++-15 -std=c++20` for all compilation

## Code Style Rules
- **Indentation**: 2 spaces (no tabs, no 4-spaces)
- **Classes**: PascalCase (e.g., `KosarajuScc`, `BinaryLifting`)
- **Conservative changes**: Only modify what's explicitly requested
- **No additional comments** unless asked

## Testing
- Test files located in `src/verify/library_checker/`
- Compile tests: `g++-15 -std=c++20 -I src -c <test_file>`