#include <iostream>
#include <stdlib.h>
using namespace std;

int* mergeArr(int a[], int lenA, int b[], int lenB){
	int *result = new int[lenA + lenB];
//	int maxLen = lenA > lenB ? lenA : lenB;			//假设a数组更大
/*	int *a = src_a;
	int *b = src_b;
	if (lenA < lenB){
		a = src_b;
		b = src_a;
		lenA = lenA ^ lenB;
		lenB = lenA ^ lenB;
		lenA = lenA ^ lenB;
		}*/
	
	int i = 0, j = 0, k = 0;
	//int t = 0;
	
	for (; i < lenA; i++){
		for (; b[k] <= a[i] && k<k+lenB; k++){
			result[j] = b[k];
			j++;
			//t++;
		}
		//cout << "a["<<i<<"]:"<<a[i]<<"{"<<"i="<<i<<",j="<<j<<",k="<<k<<"}"<<endl;
		result[j] = a[i];
		j++;
	}
	//k--;
	
	for (; j < lenA + lenB;){
		result[j] = b[k];
		k++;
		j++;
	}
	return result;
}

int main(){
	int a[] = {2, 3, 4, 5, 5, 7, 8, 9};
	int b[] = {1, 3, 6, 7, 7, 9, 11};
	int *result = mergeArr(a, 8, b, 7);
	for (int i = 0; i < 15; i++){
		cout << result[i] << " ";
	}
	system("pause");
	return 0;
}