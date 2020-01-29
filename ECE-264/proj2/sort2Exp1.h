void sort2(list<Data *> &data) {
    const int size = data.size();
    static DataMod theData[MAX_SIZE234];
    int jj = 0;
    Data* deref;
    Data deref2;
    for(auto it = data.begin(); it != data.end(); it++) {
        deref = *it;
        theData[jj].data = deref;
        deref2 = *deref;
        theData[jj].lastName = deref2.lastName;
        theData[jj].firstName = deref2.firstName;
        theData[jj].ssn = deref2.ssn;
        theData[jj].last1 = (deref2.lastName)[0];
        theData[jj].last2 = (deref2.lastName)[1];
        theData[jj].first1 = (deref2.firstName)[0];
        theData[jj].first2 = (deref2.firstName)[1];
        jj++;
    }
    sort(theData, theData + size, compareDataMod);
    jj = 0;
    for(auto it = data.begin(); it != data.end(); it++) {
        *it = theData[jj++].data;
    }
}
