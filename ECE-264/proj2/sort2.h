// #define BUCKETS 14350000

void sort2(list<Data *> &data) {
    const size_t size = data.size();
    static uint32_t inds[MAX_SIZE234];
    for(int ii = 0; ii < size; ii++) {
        inds[ii] = ii;
    }
    int jj = 0;
    Data* deref;
    Data deref2;
    for(auto it = data.begin(); it != data.end(); it++) {
        deref = *it;
        theData[jj].data = deref;
        deref2 = *deref;
        theData[jj].lastName = deref2.lastName;
        theData[jj].firstName = deref2.firstName;
        theData[jj].ssn = toInt(deref2.ssn);
        theData[jj].last1 = (deref2.lastName)[0];
        theData[jj].last2 = (deref2.lastName)[1];
        theData[jj].last3 = (deref2.lastName)[2];
        // theData[jj].last4 = (deref2.lastName)[3];
        theData[jj].first1 = (deref2.firstName)[0];
        theData[jj].first2 = (deref2.firstName)[1];
        theData[jj].first3 = (deref2.firstName)[2];
        // theData[jj].first4 = (deref2.firstName)[3];
        jj++;
    }

    sort(inds, inds + size, compareNamesInd);
    int a = 0, b = 0;
    while(b < size - 1) {
        while(sameNamesModInd(inds[a], inds[b]) && b < size -1) {
            b++;
        }
        sort(inds + a, inds + b, ModNumCompareInd);
        a = b;
    }
    if(theData[inds[size-2]].ssn > theData[inds[size-1]].ssn) {
        swap(inds[size-2],inds[size-1]);
    }

    jj = 0;
    for(auto it = data.begin(); it != data.end(); it++) {
        *it = theData[inds[jj++]].data;
    }
}
