#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 19

int list[MAX_SIZE];
int sorted[MAX_SIZE];
int MoveCount = 0; //이동 횟수 
int CompareCount = 0; //비교 횟수 
int n;


//합병
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;

	//분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) {
			sorted[k++] = list[i++];
			CompareCount++;
		}
		else {
			sorted[k++] = list[j++];
			CompareCount++;
		}
	}
	if (i > mid) //남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else //남아 있는 레코드의 일괄 복사
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
		MoveCount++;
	}

}


void merge_print(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;

	//분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
		printf("\n");
	}
	if (i > mid) //남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else //남아 있는 레코드의 일괄 복사
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
		//정렬 과정 출력
		for (int i = 0; i < n; i++)
		{
			printf("%3d", list[i]);
		}

	}
}


//합병 정렬
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2; //리스트의 균등 분할
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
		printf("\n");
	}
}


//합병 정렬(정렬 과정 포함)
void merge_sort_print(int list[], int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2; //리스트의 균등 분할
		merge_sort_print(list, left, mid);
		merge_sort_print(list, mid + 1, right);
		merge_print(list, left, mid, right);
	}
}


int main(void)
{
	int i, j;

	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99
	printf("Original List\n");
	for (i = 0; i < n; i++)
		printf("%d", list[i]);
	printf("\n");

	printf("Merge Sort\n");

	merge_sort_print(list, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d", list[i]);
	printf("\n"); 

	for (int j = 0; j <= 20; j++)
	{
		n = MAX_SIZE;
		srand(time(NULL));
		for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
			list[i] = rand() % 100; // 난수 발생 범위 0~99
		merge_sort(list, 0, n - 1);

	}
	printf("Avergage MoveCount:%d", MoveCount / 20);
	printf("Average CompareCount:%d", CompareCount / 20);



}