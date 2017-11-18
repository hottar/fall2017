///
/// vecAddKernel00.cu
/// For CSU CS575 Spring 2011
/// Instructor: Wim Bohm
/// Based on code from the CUDA Programming Guide
/// By David Newman
/// Created: 2011-02-16
/// Last Modified: 2011-02-16 DVN
///
/// This Kernel adds two Vectors A and B in C on GPU
/// without using coalesced memory access.
/// 

__global__ void AddVectors(const float* A, const float* B, float* C, int N)
{
    int tsize   = N;
    int bsize   = tsize * blockDim.x;
    int bid     = bsize * blockIdx.x;
    int tid     = threadIdx.x;
    
    int startAdr= bid + tid;
    int endAdr  = bid + bsize;
    int gap     = blockDim.x;
    int cur;
    for ( cur = startAdr; cur < endAdr; cur += gap )
        C[cur] = A[cur] + B[cur];
}

// blockIdx.x: i-th block in a grid that stores n threads
// blockDim.x: size of a block (ie. # threads per block)
// threadIdx.x: j-th element of a thread.
// gridDim.x: size of a grid (ie. # blocks per grid)
// threadDim.x: N values per thread

// 60/128/60000

// all threads in each block starts from 0~(blockDim.x-1)
// bid = loc * 1 block size
// 1 block size = # threads * 1 thread size
