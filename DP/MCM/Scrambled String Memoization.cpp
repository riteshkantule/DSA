#include <bits/stdc++.h>
using namespace std;

unordered_map <string, bool> mp;
// key str = "a"+' '+"b"

bool solve (string a, string b){
    
    if (a.compare(b)==0){
        return true;
    }
    if (a.length()<=1){
        return false;
    }
    string key = a;
    key.push_back(' ');
    key.append(b);
    
    if (mp.find(key)!=mp.end()){
        return mp[key];
    }
    
    int n = a.length();
    bool flag = false;
    for (int i = 1; i<=n-1; i++){
        bool condition1 = ((solve(a.substr(0, i), b.substr(n-i, i))==true)&&(solve(a.substr(i, n-i), b.substr(0, n-i))==true));
        bool condition2 = ((solve(a.substr(0, i), b.substr(0, i))==true)&&(solve(a.substr(i, n-i), b.substr(i, n-i))==true));
        if (condition1 || condition2){
            flag = true;
            break;
        }
    }
    return mp[key] = flag;
}

int main(){
    
	string a = "great";
	string b = "rgeat";
	
	if (a.length()!=b.length()){
        return false;
    }
    if (a.length()==0){
        return true;
    }
	cout << solve(a, b);

	return 0;
}
