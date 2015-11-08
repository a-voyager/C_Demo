#include <stdio.h>
#include <stdlib.h>
void getNextArr(char *pattern, int pLen, int nextVal[]){
	int i = 1, j = 0;
	nextVal[1] = 0;
	while(i<pLen){
		if(j==0 || pattern[i]==pattern[j]){
			i++;
			j++;
			if(pattern[i] != pattern[j]){
				nextVal[i] = j;
			}else {
				nextVal[i] = nextVal[j];
			}
		}else {
			j = nextVal[j];
		}
	}
}

	int indexKMP(char* text, int tLen, char* pattern, int pLen, int pos, int nextVal[]){
	int i = pos, j = 1;
	while(i<=tLen && j<=pLen){
		if(j==0 || text[i]==pattern[j]){
			i++;
			j++;
		}else {
			j = nextVal[j];
		}
	}
	if(j>tLen){
		return i-tLen;
	}else {
		return 0;
	}

	return 0;
}


int main(){
	// char *text = (char*)malloc(100*sizeof(char));
	// char *pattern = (char*)malloc(20*sizeof(char));
	int nextVal[3];
	// while(true){
		char text[10];
		char pattern[3];
		gets(text);
		gets(pattern);
		getNextArr(pattern, 3, nextVal);
		printf("index is %d\n", indexKMP(text,10,pattern,3,0,nextVal));
	// }
	return 0;
}