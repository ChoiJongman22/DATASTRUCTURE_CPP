#include <iostream>
using namespace std;

int sequentialSearch(int array[],int n,int key){
	for (int i = 0; i < n; i++) {
		if(array[i]==key){
			return i;
		}
		/*else {
			return -1;
		}*/
		
	}
	return -1;
}

int main() {
	int array[] = { 3,5,4,1,2,6,7 };
	cout<< sequentialSearch(array, 7, 5);
	return 0;
}