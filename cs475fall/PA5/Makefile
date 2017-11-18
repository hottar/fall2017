###
### CS475 Fall 17
### Makefile for CUDA PA5 matmult
### By Wim Bohm, and Waruna Ranasinghe
###

OPTIONS   :=  -O3 --ptxas-options -v --gpu-architecture=sm_61 --compiler-bindir /usr/local/gcc-4.6.3/bin/gcc
EXECS :=  matmult00 matmult01 vecMax00 vecMax01 vecadd01
all:$(EXECS)

clean:
	rm -f $(EXECS) *.o

timer.o : timer.cu timer.h
	nvcc $< -c -o $@ $(OPTIONS)

matmultKernel00.o : matmultKernel00.cu matmultKernel.h 
	nvcc $< -c -o $@ $(OPTIONS)

matmult00 : matmult.cu  matmultKernel.h matmultKernel00.o timer.o
	nvcc $< matmultKernel00.o -o $@ $(LIB) timer.o $(OPTIONS)

vecMaxKernel00.o : vecMaxKernel00.cu vecMaxKernel.h 
	nvcc $< -c -o $@ $(OPTIONS)

vecMax00 : vecMax.cu  vecMaxKernel.h vecMaxKernel00.o timer.o
	nvcc $< vecMaxKernel00.o -o $@ $(LIB) timer.o $(OPTIONS)

tar: matmultKernel00.cu matmultKernel01.cu matmultKernel.h matmult.cu Makefile vecMax.cu vecMaxKernel00.cu vecMaxKernel01.cu vecMaxKernel.h report.pdf vecadd.cu vecaddKernel.h vecaddKernel01.h
	tar cf PA5.tar $^

matmultKernel01.o : matmultKernel01.cu matmultKernel.h 
	nvcc $< -c -DFOOTPRINT_SIZE=32 -o $@ $(OPTIONS)

matmult01 : matmult.cu  matmultKernel.h matmultKernel01.o timer.o
	nvcc $< matmultKernel01.o -DFOOTPRINT_SIZE=32 -o $@ $(LIB) timer.o $(OPTIONS)

vecMaxKernel01.o : vecMaxKernel01.cu vecMaxKernel.h 
	nvcc $< -c -o $@ $(OPTIONS)

vecMax01 : vecMax.cu  vecMaxKernel.h vecMaxKernel01.o timer.o
	nvcc $< vecMaxKernel01.o -o $@ $(LIB) timer.o $(OPTIONS)
	
vecaddKernel01.o : vecaddKernel01.cu
	nvcc $< -c -o $@ $(OPTIONS)
	
vecadd01 : vecadd.cu vecaddKernel.h vecaddKernel01.o timer.o
	nvcc $< vecaddKernel01.o -o $@ $(LIB) timer.o $(OPTIONS)

testmax : 
	vecMax01 80 128 1280000000
	vecMax00 80 128 1280000000
