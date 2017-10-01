for t in `seq 1 6`
do 
    export OMP_NUM_THREADS=$t
    echo "NUM_THREADS: $t"
    for i in `seq 1 5`
    do 
#           stencil_1D 10000 200000
#         stencil_1D_SEQ 4000 200000
#         stencil_2D_SEQ 3000 3000
        mat_vec_SEQ 25000 10000
    done 
done
