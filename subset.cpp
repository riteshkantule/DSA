#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void solve(string in, string out){
    
    if (in.length()==0){
        cout<< out << " ";
        return;
    }
    
    string out1 = out;
    string out2 = out;
    
    out2.push_back(in[0]);
    in.erase(in.begin()+0);
    
    solve(in, out1);
    solve(in, out2);
    
    return;
    
}
// In repeted char - for unique subsets use maps
int main()
{
    string in;
    cin >> in;
    
    string out = " ";
    
    solve(in, out);

    return 0;
}
