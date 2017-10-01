//
// File name   : knap.c
// Author      : DaeGon
// Modified by : Sanjay and Wim
// Date        : Sep 20
// Description : Dynamic Programming for the 0/1 knapsack
//               problem.  The entire table is saved.
//

#include <stdio.h>
#include <stdlib.h>
#include "timer.h"


#define    MAX(x,y)   ((x)>(y) ? (x) : (y))
#define    table(i,j)    table[(i)*(C+1)+(j)]

long* get_last_row(long* weights, long* profits, long start, long end, long C ){
  long i,j;
  long N = (end-start)+1;

  long *table;
  long size  = (C+1) * N * sizeof(long);
  table = (long *)malloc(size);
  if ( table == NULL ) {
     printf("[ERROR] : Failed to allocate memory for the whole table.\n");
     exit(1);
  }

  // initialize table
  for (j=0; j<=C; j++) {
    if (j<weights[start])
      table(0, j)= 0;
    else
      table(0, j)= profits[start];
  }

  for ( i= 1 ; i < N; i++ ) {     // Enumerating objects
    for ( j=0 ; j <= C ; j++ ) {
      if(j<weights[start+i])
        table(i,j) = table(i-1,j);
      else
        table(i,j)=MAX(table(i-1,j),profits[start+i]+table(i-1,j-weights[start+i]));
    }
  }

  long* last_row = (long*) malloc(sizeof(long)*(C+1));
  if ( last_row == NULL ) {
     printf("[ERROR] : Failed to allocate memory for the last row.\n");
     exit(1);
  }

  for(i = 0; i <= C; i++)
    last_row[i] = table(N-1, i);

  free(table);
  table = 0;

  return last_row;
}

void solve_kp(long* weights, long* profits, int* solution, long start, long end, long C ){
  // base case
  if(start==end){
    solution[start] = (C<weights[start]) ? 0 : 1;
	  // printf("C*=%d: n=%d : w=%d\n",C, start, weights[start]);
  }

  // induction
  else
  {
    long lower_start = start + (end-start)/2 + (end-start)%2, lower_end = end;
    long upper_start = start, upper_end = lower_start-1;

    long upper_size = (C+1) * (upper_end-upper_start+1) * sizeof(long),
    lower_size = (C+1) * (lower_end-lower_start+1) * sizeof(long);

    long* upper_row = (long*) malloc(upper_size);
    long* lower_row = (long*) malloc(lower_size);
    if ( upper_row == NULL || lower_row == NULL ) {
       printf("[ERROR] : Failed to allocate memory for the two rows.\n");
       exit(1);
    }

    // get two last rows
    lower_row = get_last_row(weights, profits, lower_start, lower_end, C);
    upper_row = get_last_row(weights, profits, upper_start, upper_end, C);

    // find C* (midpoint)
    long k, max = 0;
    for(k = 0; k <= C; k++)
      max = (upper_row[k]+lower_row[C-k] > upper_row[max]+lower_row[C-max]) ? k : max;

    // recursion
    solve_kp(weights, profits, solution, upper_start, upper_end, max);
    solve_kp(weights, profits, solution, lower_start, lower_end, C-max);

    free(upper_row);
    free(lower_row);
    upper_row=0;
    lower_row=0;
  }
}

int main(int argc, char **argv) {

   FILE   *fp;
   long    N, C;                   // # of objects, capacity
   long    *weights, *profits;     // weights and profits
   int    verbose,count;

   // Temp variables
   long    i, j, size;

   // Time
   double time;

   // Read input file (# of objects, capacity, (per line) weight and profit )
   if ( argc > 1 ) {
      fp = fopen(argv[1], "r");
      if ( fp == NULL) {
         printf("[ERROR] : Failed to read file named '%s'.\n", argv[1]);
         exit(1);
      }
   } else {
      printf("USAGE : %s [filename].\n", argv[0]);
      exit(1);
   }

   if (argc > 2) verbose = atoi(argv[2]); else verbose = 0;

   fscanf(fp, "%d %d", &N, &C);
   printf("The number of objects is %d, and the capacity is %d.\n", N, C);

   size    = N * sizeof(long);
   weights = (long *)malloc(size);
   profits = (long *)malloc(size);

   if ( weights == NULL || profits == NULL ) {
      printf("[ERROR] : Failed to allocate memory for weights/profits.\n");
      exit(1);
   }

   for ( i=0 ; i < N ; i++ ) {
      count = fscanf(fp, "%d %d", &(weights[i]), &(profits[i]));
      if ( count != 2 ) {
         printf("[ERROR] : Input file is not well formatted.\n");
         exit(1);
      }
   }

   fclose(fp);

   // Solve for the optimal profit
    size = N * sizeof(int);

    int* solution = (int*) malloc(size);
    if ( solution == NULL ) {
      printf("[ERROR] : Failed to allocate memory for the solution table.\n");
      exit(1);
    }

   initialize_timer ();
   start_timer();

   solve_kp(weights, profits, solution, 0, N-1, C);

   stop_timer();
   time = elapsed_time ();

   // End of "Solve for the optimal profit"

   // Backtracking
   long opt_profit = 0;
   for ( i=0; i < N ; i++ )
     opt_profit += solution[i]==0 ? 0 : profits[i];

    printf("The optimal profit is %d \nTime taken : %lf.\n", opt_profit, time);


      if (verbose==1) {

      printf("Solution vector is: ");
      for (i=0 ; i<N ; i++ ) {
         printf("%d ", solution[i]);
      }
      printf("\n");
      }

    free(solution);
    free(weights);
    free(profits);

   return 0;
}
