#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    vector<int> vec = {2, 3, 5, 22, 1, -9};
    sort(vec.begin(), vec.end());
    for (int num : vec)
        cout << num << " ";
    cout << endl;
    return 0;
    
}