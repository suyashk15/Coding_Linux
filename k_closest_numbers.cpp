#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

	int A[] = {5,6,7,8,9};
	int n = sizeof(A)/sizeof(A[0]);
	int k =3;
	int x =7; // Print k closest numbers to x from A

	priority_queue<pair<int,int>> maxh; // we dont want max difference elements, so we pop them

	for(int i=0;i<n;i++){
		maxh.push({abs(A[i]-x), A[i]}); // pair< abs(A[i] - x) , A[i]>

		if(maxh.size() > k){
			maxh.pop();     // Sorting is done based on first integer of pair
		}

	}
	while(maxh.size() > 0){                // At last, we have k closest elements in the heap
		cout << maxh.top().second << " " ;
		maxh.pop();
	}

}