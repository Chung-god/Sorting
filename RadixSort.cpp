// RadixSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//연결기반 큐를 이용하여 만든 기수정렬
//

#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10

void RadixSort(int arr[], int num, int maxLen) {//배열,정렬대상의 수,가장 긴 데이터 길이
	//매개변수 maxlen 에는 정렬 대상 중 가장 긴 데이터 길이 정보 저장
	Queue buckets[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	//10개의 버킷 초기화
	for (bi = 0; bi < BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	//가장 긴 데이터 만큼 반복
	for (pos = 0; pos < maxLen; pos++) {
		//정렬대상의 수만큼 반복
		for (di = 0; di < num; di++) {
			radix = (arr[di] / divfac) % 10; //N번째 자리의 숫자 추출

			Enqueue(&buckets[radix], arr[di]); //추출한 숫자를 버킷에 저장
		}

		//버킷 수 만큼 반복
		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++) {
			//버킷에 저장된 것 순서대로 다 꺼내서 다시 arr에 저장
			while (!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}
		//N번째 자리의 숫자 추출을 위한 피제수의 증가
		divfac *= 10;
		//다시 저장한 배열로 피제수를 증가하여 정렬
	}


}
int main()
{
	int arr[7] = { 13,212,14,7141,10987,6,15 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	RadixSort(arr, len, 5);
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
