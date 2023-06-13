
#include <bits/stdc++.h>
using namespace std;

int minDifference(int arr[], int n){
    
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum+=arr[i];
    }
    int t[n+1][sum+1];  //Initializing Subset Sum Table
    
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
    // If there is no element in the array, no subset sum is possible except one case when sum=0
            if(i == 0) t[i][j] = 0; 
            if(j==0) t[i][j] = 1; //Sum zero is possible for every array size
        }
    }
    
    //Filling up the table
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    int ans = INT_MAX;
    //All the subset sum which is possible for this n sized array will have true value in table in nth row
    for(int j = 0; j<sum+1; j++)//Iterating last row where the sum exists
    {
    // abs(sum - 2*(subset_sum) will give subset sum difference
        if(t[n][j] == 1) ans = min(ans, abs(sum - 2*j));
    }
    return ans;
}

int main() {
    int n;
    int sum=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		sum+=arr[i];
	}
	
	cout<<(minDifference(arr,n))<<endl;
	return 0;
}
