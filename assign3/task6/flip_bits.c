#include <stdio.h>
#include <stdlib.h>

// Note, the bits are counted from right to left. 
// Flip the bits of x within range [start, end], in which both are inclusive.
// Assume 0 <= start & end <= 31
void flip_bits(unsigned * x,
              unsigned start,
              unsigned end) {
    // YOUR CODE HERE

    int len = end - start + 1;
    for(int i = 0; i < len; i++){
        *x = (*x ^ (1<<(start+i)));
    }
}
