#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int A[] = {6,5,3,2,8,9,10};
	int n = sizeof(A)/sizeof(A[0]);
	int k = 3;

	priority_queue <int, vector<int> , greater<int>> minh;
	vector<int> v;

	for(int i=0;i<n;i++){    // If size of heap > k, pop the top element (smallest) and store it in the vector
		minh.push(A[i]);

		if(minh.size() > k){
			v.push_back(minh.top());
			minh.pop();
		}

	}
	while(minh.size() > 0){      // After the loop, minh will have k elements left, push them in the vector 
		v.push_back(minh.top());
		minh.pop();
	}

	for(int j=0;j<n;j++){
		cout << v[j] << " ";
	}
}