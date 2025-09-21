#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    int T[N];
    unordered_map<int, int> arr;
    
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
        int total = 100 - T[i];
        
        if (arr.count(total)) {
            cout << arr[total] << endl;
            cout << i + 1 << endl;
            return 0;
        }
        
        arr[T[i]] = i + 1;
    }
    
    return 0;
}
