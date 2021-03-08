#include <iostream>
#include "mpi.h"
using namespace std;

bool isPrime(int n)
{
	if (n == 0 or n == 1) return 0;
	else if (n == 2) return 1;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	
	MPI_Init(NULL, NULL);
	int n = 100, rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int nr = n / size;
	for (int i = rank * nr + 1; i <= (rank + 1) * nr; i++)
		if (isPrime(i))
			cout << i << " ";
	cout << "\n";
	MPI_Finalize();
}
