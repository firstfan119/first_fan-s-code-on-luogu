#include <bits/stdc++.h>
using namespace std;
int num[111111];
void Merge(int arr[], int left, int mid, int right)
{
    //merge arr[L,M](sorted) and arr(M,R](sorted) into arr[L,R]
    static int p = 1, que[123456] = { 0 };
    int pl = left, pr = mid;
    int ql = mid + 1, qr = right;

    while (pl <= pr || ql <= qr) {
        if ((ql > qr) || (pl <= pr && arr[pl] <= arr[ql])) //有点麻烦的判断，要考虑arr已提取完的情况
            que[p++] = arr[pl++];
        else
            que[p++] = arr[ql++];
    }
    while (left <= right)
        arr[right--] = que[--p];
}

void MergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);//二分递归
}
int main()
{
	int times;
	scanf("%d",&times);
	for(int i=1;i<=times;i++)
	{
		scanf("%d",&num[i]);
	}
	MergeSort(num,1,times);
	for(int i=1;i<=times;i++)
	{
		printf("%d ",num[i]);
	}
}
