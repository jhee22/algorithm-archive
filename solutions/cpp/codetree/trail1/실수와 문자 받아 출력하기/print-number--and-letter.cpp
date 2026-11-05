#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

int main() {
    // Please write your code here.
    string c; 
    double a, b; 

    cin >> c; 
    cin >> a; 
    cin >> b; 
    cout << c << "\n"; 
    cout << fixed << setprecision(2) << a << "\n"; 
    cout << fixed << setprecision(2) << b << "\n";
    return 0;
}