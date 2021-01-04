#include <iostream>
using namespace std ;

int midSearchSmall(int a[], int n, int key) {
	int low = 0 ,high = n-1;
	int mid;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(a[mid]==key && a[mid-1]<key) return mid;
		else if(a[mid]>key) high = mid-1;
		else if(a[mid]<key)  low = mid +1;
		else if(a[mid]==key && a[mid-1]==key) 
	}
	return -1;
}

int midSearchlarge(int a[], int n, int key) {
	int low = 0, high = n - 1;
	int mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(a[mid]==key && a[mid+1]>key) return mid;
		else if(a[mid]>key) high = mid - 1;
		else if(a[mid]<key)  low = mid + 1 ;
		else if(a[mid]==key && a[mid+1]==key)	high = mid + 2;
	}
	return -1;
}


void find(int a[], int n, int *pos,int key) {
	if(a[0]==a[n-1] && a[0] == key) {
	  	pos[0] = 0;
	  	pos[1] = n-1;
	  	return ;
	}
	else if(a[n-1]<key || a[0]>key) {
		pos[0] = -1;
	  	pos[1] = -1;
	  	return ;
	}
	int low = 0;
	if(a[0]<key)  	low = midSearchSmall(a,n,key);
    int high = n-1;
	if(a[n-1]>key)	high = midSearchlarge(a,n,key);
	pos[0] = low;
	pos[1] = high;
}


int main()
{
	int a[] ={1,3,3,3,3,3,60,60,60,100,101,101};
	int pos[2];
	int key = 1;
	find(a,12,pos,key);
	cout<<pos[0]<< endl <<pos[1];
	
	
}