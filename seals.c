/* Compute the average weight for a population of elephant seals read into an array
   Ian Brown
   May 25 2020
*/

#include <stdio.h>
#include <stdlib.h>

// Returns the average of all values in an array
double averageWeight(int *weights, int len)
{
	double sum = 0.0;
	double avg = 0.0;
	int i = 0;
	for(; i < len; i++)
	{
		sum += (double)weights[i];
	}
	avg = sum * 1.0 / i;
	return avg;
}

// weights is the empty array where the data will be stored
int fileToArray(int *weights)
{
	FILE *seals;
	seals = fopen("sealData.txt", "r");
	if(seals == NULL)
	{
		fprintf(stderr, "Can't open file in.list\n");
		exit(1);
	}
	int i = 0;
	while(fscanf(seals, "%u\t", &weights[i]) != EOF)
	{
		i++;
	}
	fclose(seals);
	
	// returns i, the length of the array
	return i; 
}

int main(void)
{
	double average;
	int sealWeights[10000];
	int sealWeightsLen = fileToArray(sealWeights);
	average = averageWeight(sealWeights, sealWeightsLen);
	printf("Average weight = %lf\n", average);
	return 0;
}
