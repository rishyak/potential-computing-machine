# Verification
## Notes
- Exercise 2 testing strategy was to provide a few inputs to the Fib LFSR and verify their output for several cycles.
  - Had to pick how many tests to do, which seeds to use, etc.
  - Facetiously, looked at how it's done before. Seriously, it makes intuitive sense to not exhaustively test a shift register - it's a linear function, if it hasn't gone wrong for a few good inputs, it **will not** go wrong for any other input.
- To test a don't care, set just about any value and it shouldn't break. If you want more peace of mind, set multiple values.
