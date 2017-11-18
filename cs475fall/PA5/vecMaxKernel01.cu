///
/// vecMaxKernel00.cu : code computes partiol answer per each thread. 
/// By Waruna Ranasinghe 
/// Created: 15 Aug 2017
/// Last Modified: 

/// The code computes partial answer for reduction over max per a thread. 
/// Each thread computes max of a consective chunck of data of size C.
/// The memory loads are not coalesced. 

#include <stdio.h>
/*
 * A - input vector of floats of size G*B*C
 * reductions - output of partial answers compted by each thread
 * C - chunck size - number of elements processed by ech thread
 */
__global__ void reduce(const float* A, float* reductions, int C) {
    int tsize   = 125000; // units per thread
    int bsize   = tsize * blockDim.x; // units per block
    int bid     = bsize * blockIdx.x; // pos of cur block
    int tid     = threadIdx.x; // initial pos of thread
    int startAdr= tid + bid;
    int endAdr  = bid + bsize;
    int reducAt = blockIdx.x * blockDim.x + threadIdx.x;
    int gap     = blockDim.x;
    int k;
    for ( k = startAdr; k < endAdr; k+=gap )
        reductions[reducAt] = max(reductions[reducAt],A[k]);
}
