#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {60, 20, 50, 40, 50, 10, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    vector <int> left;
    stack <pair<int, int>> s;
    int psudo_index = -1;
    // NSL***********************************
    for(int i=0; i<n; i++){
        if (s.size()==0){
            left.push_back(psudo_index);
        }
        else if(s.size()>0 && s.top().first<arr[i]){
            left.push_back(s.top().second);
        }
        else if(s.size()>0 && s.top().first>=arr[i]){
            while(s.size()>0 && s.top().first>=arr[i]){
                s.pop();
            }
            if (s.size()==0){
                left.push_back(psudo_index);
            }
            else{
                left.push_back(s.top().second);
            }
        }
        s.push(make_pair(arr[i], i));
    }
    
    vector <int> right;
    stack <pair<int, int>> s1;
    psudo_index = n+1;
    // NSR**************************************
    for(int i=n-1; i>=0; i--){
        if (s1.size()==0){
            right.push_back(psudo_index);
        }
        else if(s1.size()>0 && s1.top().first<arr[i]){
            right.push_back(s1.top().second);
        }
        else if(s1.size()>0 && s1.top().first>=arr[i]){
            while(s1.size()>0 && s1.top().first>=arr[i]){
                s1.pop();
            }
            if (s1.size()==0){
                right.push_back(psudo_index);
            }
            else{
                right.push_back(s1.top().second);
            }
        }
        s1.push(make_pair(arr[i], i));

    }
    reverse(right.begin(), right.end());
    
    vector<int> breadth(n);
    vector<int> result(n);

    
    for(int i=0; i<n; i++){
        breadth[i] = right[i]-left[i]-1;
        result[i] = breadth[i]*arr[i];
    }
    
    int maxArea = *max_element(result.begin(), result.end());
    cout << "Maximum Area: " << maxArea << endl;

    
    
    return 0;
}
