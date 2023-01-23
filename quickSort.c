#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b);
void quickSort(int *arr,int start,int stop);
void printArr(int *arr,int start,int stop);
int main(){
	int arr[10] = {3,9,2,4,1,8,6,0,5,7};	
	quickSort(arr,0,9);
	printArr(arr,0,9);
}

void quickSort(int *arr,int start,int stop){
	int mid;
	if(start>=stop){
		return;
	}
	mid = partition(arr,start,stop);
	printf("mid = %d\n",mid);
	printArr(arr,start,stop);
	quickSort(arr,start,mid-1);
	quickSort(arr,mid+1,stop);
	printf("mid = %d",mid);
}
int partition(int *arr,int start,int stop){
	int pivot = arr[start],i=start+1,j=stop;
	while(i<=j){
		if(arr[i]<pivot)
			i++;
		if(arr[j]>pivot)
			j--;
		if(arr[i]>pivot&&arr[j]<pivot&&i<j)
			swap(&arr[i],&arr[j]);
	}
	swap(&arr[start],&arr[i-1]);
	return i-1;
}
void swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void printArr(int *arr,int start,int stop){
	int i;
	printf("\n Start %d, stop %d: ",start,stop);
	for(i = start;i<=stop;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
