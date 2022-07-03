#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

	int A[] = {7,10,4,3,20,15};
	int n;
	int k;

	cin>>n>>k;

	priority_queue <int , vector<int> , greater<int>> minh;

	for(int i=0;i<n;i++){
		minh.push(A[i]);

		if(minh.size() > k){
			minh.pop();
		}
	}
	for(int j=0;j<k;j++){
		cout << minh.top() << " ";
		minh.pop();
	}

}