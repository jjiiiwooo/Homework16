#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int list[MAX_SIZE];
int moveCount = 0; //이동 횟수 
int compareCount = 0; //비교 횟수 
int sorted[MAX_SIZE]; //추가 공간 필요 
int n;

//정렬 과정 출력
void Print(int list[], int n) {
	for (int i = 0; i < n; i++)
		printf("%3d", list[i]);
	printf("\n");
}

//0~99범위의 랜덤 숫자 생성
void Random(int array[], int n) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		array[i] = rand() % 100;
		//중복없이
		for (int j = 0; j < i; j++) {
			if (array[i] == array[j])i--;
		}
	}
}

//합병
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;

	//분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		compareCount++;
		if (list[i] <= list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
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
		moveCount++;
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
	}
}


//합병 정렬(정렬 결과 포함)
void merge_sort_print(int list[], int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2; //리스트의 균등 분할
		merge_sort_print(list, left, mid); //왼쪽 반 정렬
		merge_sort_print(list, mid + 1, right); //오른쪽 반 정렬
		merge(list, left, mid, right); //정렬된 두 반 합치기
		//정렬 과정 출력
		for (int i = left; i <= right; i++) {
			printf("%3d", list[i]);;
		}
		printf("\n");
	}
}


int main(void)
{
    //20개 20회 생성한 난수를 담을 2차원 배열
    int array[MAX_SIZE][MAX_SIZE];
    int n = sizeof(array[0]) / sizeof(array[0][0]);

    for (int i = 0; i < 20; i++) {
        Random(array[i], n);
    }
    printf("Original List\n");
    Random(list, n);
    Print(list, n);
    printf("\n");
    printf("merge sort\n");
    printf("재귀적 구현 정렬결과:\n");
	merge_sort_print(list, 0, n - 1);
    Print(list, n);

    //20회의 합병정렬 수행
    for (int i = 0; i < 20; i++) {
		merge_sort(list, 0, n - 1);
    }
    printf("Average Move Count: %d\n", moveCount / 20);
    printf("Average Compare Count:%d\n", compareCount / 20);

}
