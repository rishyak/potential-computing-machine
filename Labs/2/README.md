# System Verilog

## Notes
- Module 1's dv tests exhaustively since the modules are simple enough to do so
  - It's easy to verify all possible values in this scenario 
  - It might not be this easy in other scenarios or perhaps even unrequited
- Module 2 is a Fibonacci LFSR. As long as it works for a few seeds, you can safely guarantee that it works for the others too; each input bit is a just a linear function of the previous state
  - Verifying LFSRs seems time consuming so fewer tests makes sense
  - Might miss a weird bug maybe which will most certainly show up in prod
- Module 3's tests are fuzz tests, providing random inputs to see if you can break things
  - It's easy to avoid tester bias or preconceived notions on how the thing should work
  - If there aren't many tests, you could end up with a series of random tests that just happened to work fine when things are really not fine

## Resources
- Fibonacci LFSRs:
  - [Wikipedia](https://en.wikipedia.org/wiki/Linear-feedback_shift_register)
  - [Computerphile](https://www.youtube.com/watch?v=Ks1pw1X22y4)