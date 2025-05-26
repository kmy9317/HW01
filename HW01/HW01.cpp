// HW01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

constexpr int ARRAY_SIZE = 5;

// 퀵정렬을 위한 분할 함수
int partition(int arr[], int low, int high, int dir)
{
    // 마지막 요소를 pivot으로
    int pivot = arr[high]; 
    // 큰/작은 요소들 정렬을 위한 인덱스
    int i = low - 1; 

    for (int j = low; j < high; j++) 
    {
        // 삼항 연산자로 dir이 1인 경우 오름차순, 2인 경우 내림차순 로직이 실행되도록 bool값 조건을 입력에 따라 다르게 처리
        bool condition = (dir == 1) ? (arr[j] <= pivot) : (arr[j] >= pivot);

        if (condition)
        {
            i++;
            // arr[i]와 arr[j] 교환
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } 

    /* 
    * 예시로 dir = 1일 때 for문 종료후 pivot을 기준으로 최종적으로
    * pivot왼쪽은 더 작은숫자, pivot 오른쪽은 더 큰 숫자들이 자리잡게 됨(여기 숫자들은 정렬된 상태x)
    */
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // 최종적으로 pivot이 위치한 index를 반환
    return i + 1;
}

// 퀵정렬 재귀 함수: 평균적으로 O(nlog(n))-> 왼쪽 오른쪽 잘 분산될 경우
// 최악의 경우 O(n^2)-> 한쪽으로 pivot이 계속해서 배치되는 경우
void quickSort(int arr[], int low, int high, int dir)
{
    if (low < high) 
    {
        int pi = partition(arr, low, high, dir);

        // 피벗을 기준으로 왼쪽과 오른쪽 부분을 재귀적으로 정렬
        quickSort(arr, low, pi - 1, dir);
        quickSort(arr, pi + 1, high, dir);
    }
}

void sortFunc(int arr[], int dir)
{
    quickSort(arr, 0, ARRAY_SIZE - 1, dir);

    for (int i = 0; i < ARRAY_SIZE; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sumFunc(int arr[])
{
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) sum += arr[i];
    return sum;
}

float avgFunc(int arr[])
{
    int sum = sumFunc(arr);
    return static_cast<float>(sum) / ARRAY_SIZE;
}

int main()
{
    // 필수 기능
    int arr[ARRAY_SIZE];
    int sum = 0;
    float avg = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i) cin >> arr[i];
    for (int i = 0; i < ARRAY_SIZE; ++i) cout << arr[i] << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) sum += arr[i];
    avg = sum / ARRAY_SIZE;

    cout << "sum: " << sum << " avg: " << avg << endl;

    int sumF = sumFunc(arr);
    float avgF = avgFunc(arr);

    cout << "sumF: " << sumF << " avgF: " << avgF << endl;

    // 도전 기능
    int dir = 0;
    cin >> dir;
    sortFunc(arr, dir);
}

