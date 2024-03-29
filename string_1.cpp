
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character left in the buffer
    
    string shapes[5]= {"Tetrahedron", "Cube", "Octahedron", "Dodecahedron", "Icosahedron"};
    string *str = new string[n]; // Allocate memory dynamically using new
    int faces[5]= {4, 6, 8, 12, 20};
    
    for(int i=0; i<n; i++){
        getline(cin, str[i]);
    }
    
    int total_faces = 0;
    
    
    
    for(int j=0; j<n; j++){
        for(int k=0; k<5; k++){
            if(str[j] == shapes[k]){
               total_faces+= faces[k];
            }
        }
    }
    
    cout << total_faces;
    
    delete[] str; // Free the dynamically allocated memory
    
    return 0;
}
