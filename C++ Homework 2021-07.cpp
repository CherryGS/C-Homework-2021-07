#include <iostream>
#include "MyArr.h"
#include <assert.h>

using std::cout;
using std::endl;
MyArr<double> r;

double test_arr[10010];

int main() {
#ifdef DEBUG
    cout << "DEBUG Mode" << endl;
#endif

    r.SetArrSiz(2);
    assert(r.GetSize() == 2);
    assert(r[0] == 0);

    r.SetArrValue(0, 1.0);
    r.SetArrValue(1, 2.0);

    assert(r[1] == 2.0);

    r.PrintArr();
    r.FreeArr();

    assert(r.GetSize() == 0);
    assert(r.GetPointer() == 0);

    srand(time(0));
    for (int n = 1; n <= 3; n++) {
        cout << endl << "----- Test " << n << " -----" << endl;
        int len = 10;
        for (int i = 0; i < len; i++) {
            test_arr[i] = double(rand() % int(1e4)) * 1.1;
            r.SetArrValue(i, test_arr[i]);
        }
        for (int i = 0; i < len; i++)
            cout << test_arr[i] << ' ';
        cout << endl;
        for (int i = 0; i < len; i++)
            cout << r[i] << ' ';
        cout << endl;
    }

    return 0;
}
