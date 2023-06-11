#include <bits/stdc++.h>
using namespace std;

typedef long long lol;

vector<lol> arr;
vector<bool> used;
lol sum;

bool isKPartsPosbl(lol bk, lol currSm) {
	if(bk==1) return true;
	if(currSm == sum) return isKPartsPosbl(bk-1,0);
	for(int i=0;i<arr.size();i++) {
		if(currSm+arr[i] <= sum && !used[i]) {
			used[i]=true;
			if(isKPartsPosbl(bk,currSm+arr[i])) return true;
			used[i]=false;
		}
	}
	return false;
}

int main() {
	lol t,n,k;
	cin>>t;
	while(t--) {
		cin>>n>>k; sum=0; arr=vector<lol>(n); used=vector<bool>(n,false);
		for(int i=0;i<n;i++) {
			cin>>arr[i];
			sum+=arr[i];
		}
		if(n<k || sum%k) {
			cout<<"no"<<endl;
			continue;
		}
		sum/=k;
		cout<<(isKPartsPosbl(k,0) ? "yes" : "no")<<endl;
	}
	return 0;
}
