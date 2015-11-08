#include <iostream>
#include <stdlib.h>
using namespace std;
int* reSort(int arr[], int len){
	int *result = new int[len];
	for (int i = 0, j = 0, k = 0; i < len; i++){
		if (arr[i] % 2 != 0){
			result[k] = arr[i];
			k++;
		}
		else {
			result[len - j - 1] = arr[i];
			j++;
		}
	}

	return result;
}

/*
int main(){
	int arr[] = {1, 5, 64, 3 ,2, 9, 89, 34, 23, 54, 12, 91};
	int *result = reSort(arr, 12);
	for (int i = 0; i < 12; i++)
	{
		cout << result[i] << " ";
	}
	system("pause");
	return 0;
}
*/