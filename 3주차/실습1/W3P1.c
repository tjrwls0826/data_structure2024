#include <time.h>
#include <stdio.h>


int main()
{
	int i;
	double start, end;

	//for ���� ���� �ð�
	start = (double)clock() / CLOCKS_PER_SEC;

	//for loop 100000000�� ���ƺ���
	int sum = 0;
	for (i = 0; i < 100000000; i++) {
		sum++;
	}

	//for loop end time
	end = (((double)clock()) / CLOCKS_PER_SEC);
	printf("program running time :%lf\n", (end - start));
}