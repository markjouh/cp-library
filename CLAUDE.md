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

## Documentation Guidelines

### Structure
Each documentation file must follow this exact structure:
1. **Front matter**: YAML with `title` and `documentation_of`
2. **Brief description**: One concise paragraph explaining purpose
3. **Operations**: Bulleted list of available functions/members
4. **Complexity**: Time and space complexity using LaTeX notation
5. **Usage**: Minimal practical example
6. **Notes**: Implementation details (optional)

### Formatting Rules
- **Function references**: Use backticks for all code elements (`find()`, `comp[u]`)
- **Mathematical notation**: Use LaTeX for complexities ($O(\log n)$, $O(V + E)$)
- **Variable names**: Use backticks (`n`, `MOD`)
- **Code blocks**: Use ```cpp with proper indentation
- **Lists**: Use `-` for bullets, no nested lists
- **Tone**: Technical, precise, concise - avoid AI-generated phrasing
- **Length**: Be concise, no repetition or verbosity