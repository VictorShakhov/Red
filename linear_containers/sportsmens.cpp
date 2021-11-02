#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    const int MAX_NUMBER = 100'000;
    int n, number, position;
    cin >> n;
    list<int> row;
    vector<list<int>::iterator> positions(MAX_NUMBER, row.end());
    for(int i = 0; i < n; ++i) {
        cin >> number >> position;
        positions[number] = row.insert(positions[position], number);
    }
    for(int x : row) {
        cout << x << "\n";
    }
    return 0;
}
