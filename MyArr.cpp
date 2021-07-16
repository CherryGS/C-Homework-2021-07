#include "MyArr.h"
#include <iostream>
using std::cout;
using std::endl;
template <class T> int MyArr<T>::SetArrSiz(cint re_siz) {
    if (re_siz <= 0) {
        cout << "ERROR caused because value of 're_siz' is invalid." << endl;
        return 0;
    }

#ifdef DEBUG
    assert(re_siz > 0);
#endif

    T* tmp = new T[re_siz];
    if (tmp == NULL) {
        cout << "ERROR caused because of 'out of memory'" << endl;
        return 0;
    }
    for (int i = 0; i < re_siz; i++)
        tmp[i] = T(0);

#ifdef DEBUG
    assert(tmp != NULL);
#endif

    for (int i = 0; i < _min(usd, re_siz); i++)
        tmp[i] = bgn[i];
    lst = re_siz;
    usd = _min(usd, re_siz);
    delete[] bgn;
    bgn = tmp;
    return 1;
}

template<class T> void MyArr<T>::SetArrValue(cint loc, const T& val) {
    if (loc + 1 > lst) if (!SetArrSiz(loc * 2 + 2)) return;
    bgn[loc] = val;
    if (loc + 1 > usd) usd = loc + 1;
}

template<class T> void MyArr<T>::PrintArr() {
    for (int i = 0; i < usd; i++)
        cout << bgn[i] << ' ';
    cout << endl;
}