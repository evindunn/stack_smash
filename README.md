# Smashing the Stack
Me trying to get the examples from 
[aleph1's paper](https://inst.eecs.berkeley.edu/~cs161/fa08/papers/stack_smashing.pdf)
working on x64. Requires disabling a whole bunch of modern protections, see
the Makefiles for details. Another big thing I got stuck on was gcc's default 
16-byte stack alignment for x64. This differs from the 4-byte alignment in the
original paper.

## Requirements
```
make
gcc
gdb
```

The [gef plugin](https://github.com/hugsy/gef) for gdb helped a whole lot 
figuring this out
