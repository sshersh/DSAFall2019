void sort3(list<Data*> &data) {
    list<Data*>::iterator a = data.begin(), b = data.begin();
    int ind = 0;
    Data* temp[100];
    list<Data*>::iterator secondToLast = prev(data.end());
    while(b != secondToLast) {
        while(sameNames(*a,*b) && (b != secondToLast)) {
            b++;
            // ind2++;
        }
        for(auto it = a; it != b; ++it) {
            temp[ind++] = *it;
        }
        sort(temp, temp + ind, compareSSN);
        ind = 0;
        for(auto it = a; it != b; ++it) {
            *it = temp[ind++];
        }
        a = b;
        ind = 0;
    }
    if((*secondToLast)->ssn < (*prev(secondToLast))->ssn) {
        swap(*prev(secondToLast), *secondToLast);
    }
}
