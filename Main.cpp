#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 3 vectors = 3 towers
    vector<int> t[3];
    int n, candidate, to, from, move = 0;
    // Ask user how many rings
    cout << "Enter the number of rings: ";
    cin >> n;

    // Initialize the towers with 'n+1' to ensure a bottom limit
    for (int i = n + 1; i >= 1; i--)
    t[0].push_back(i);
    t[1].push_back(n + 1);
    t[2].push_back(n + 1);
    // start from tower 0
    from = 0;
    if (n % 2 == 1) {
        // If odd, set "to" to 1
        to = 1;
    }
    // If odd, set 'to' to 2
    else {
        to = 2;
    }
    candidate = 1;

    // while loop to all move loops to tower 1
    while (t[1].size() < n + 1) {
        // print
        cout << "Move number " << ++move << ": Transfer Ring " << candidate<< " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
        t[to].push_back(t[from].back());
        t[from].pop_back();
        if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back())
            from = (to + 1) % 3;
        else
            from = (to + 2) % 3;
        // change 'to' based on the number of rings and 'from'
        if (n % 2 == 1) {
            if (t[from].back() < t[(from + 1) % 3].back())
                to = (from + 1) % 3;
            else
                to = (from + 2) % 3;
        } else {
            if (t[from].back() < t[(from + 2) % 3].back())
                to = (from + 2) % 3;
            else
                to = (from + 1) % 3;
        }
        candidate = t[from].back();
    }
    return 0;
}
