
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int size, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int globaldata[size];
    int localdata;
    int i;
    
       localdata = rank;

    
    MPI_Gather(&localdata, 1, MPI_INT, globaldata, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("root Processor has data: ");
        for (i=0; i<size; i++)
            printf("%d ", globaldata[i]);
        printf("\n");
    }


    MPI_Finalize();
    return 0;
}