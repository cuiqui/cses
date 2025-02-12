#include <iostream>
#include <set>
using namespace std;


int main() {

    int n, m, hi, ti;
    cin >> n >> m;

    multiset<int> ms;
    while (n--) {
        cin >> hi;
        ms.insert(hi);
    }

    while (m--) {
        cin >> ti;
        multiset<int>::iterator smol = ms.lower_bound(ti);

        if (smol != ms.end() && *smol == ti) {
            cout << *smol << endl;
            ms.erase(smol);
        } else {
            if (smol != ms.begin()) {
                smol--;
                cout << *smol << endl;
                ms.erase(smol);
            } else {
                cout << "-1" << endl;
            }
        }
    }

    return 0;
}