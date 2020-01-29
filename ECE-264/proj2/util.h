// #pragma once
#define MAX_SIZE1 101000
#define MAX_SIZE234 1010000


inline uint32_t toInt (string ssn) {
    return (ssn[0]-'0')*100000000 + (ssn[1]-'0')*10000000 + (ssn[2]-'0')*1000000 + (ssn[4]-'0')*100000 + (ssn[5]-'0')*10000
     + (ssn[7]-'0')*1000 + (ssn[8]-'0')*100 + (ssn[9]-'0')*10 + ssn[10]-'0';
}

struct DataMod {
    Data* data;
    string lastName;
    string firstName;
    int ssn;
    char last1;
    char last2;
    char last3;
    // char last4;
    char first1;
    char first2;
    char first3;
    // char first4;
};

static DataMod theData[MAX_SIZE234];

inline void toStr(uint32_t num, string str) {
    char arr[12];
    arr[11] = 0;
    for(int jj = 10; jj >= 7; jj--, num/=10) {
        arr[jj] = num%10 + '0';
    }
    arr[6] = '-';
    for(int jj = 5; jj >= 4; jj--, num/=10) {
        arr[jj] = num%10 + '0';
    }
    arr[3] = '-';
    for(int jj = 2; jj >= 0; jj--, num/=10) {
        arr[jj] = num%10 + '0';
    }
    str = arr;
}

inline bool sameNamesMod(DataMod &a, DataMod &b) {
    return a.firstName == b.firstName;
}

inline bool sameNames(Data* a, Data* b) {
    return a->firstName == b->firstName;
}

inline bool sameNamesModInd(int a, int b) {
    return sameNamesMod(theData[a], theData[b]);
}

struct {
    inline bool operator() (Data* a, Data* b) {
        return a->ssn < b->ssn;
    }
} compareSSN;

struct {
    inline bool operator() (list<Data*>::iterator it1, list<Data*>::iterator it2) {
        if(((*it1)->lastName) != ((*it2)->lastName)) {
            return (*it1)->lastName < (*it2)->lastName;
        }
        if((*it1)->firstName != (*it2)->firstName) {
            return (*it1)->firstName < (*it2)->firstName;
        }
        else {
            return (*it1)->ssn < (*it2)->ssn;
        }
    }
} indComp;

struct {
    inline bool operator() (Data* a, Data* b) {
        if((a->lastName) != (b->lastName)) {
            return a->lastName < b->lastName;
        }
        else if (a->firstName != b->firstName) {
            return a->firstName < b->firstName;
        }
        else {
            return a->ssn < b->ssn;
        }
    }
} compareData;

struct {
    inline bool operator() (DataMod &a, DataMod &b) {
        if(a.last1 != b.last1) {
            return a.last1 < b.last1;
        }
        else if(a.last2 != b.last2) {
            return a.last2 < b.last2;
        }
        if(a.lastName != b.lastName) {
            return a.lastName < b.lastName;
        }
        else if(a.first1 != b.first1) {
            return a.first1 < b.first1;
        }
        else if(a.first2 != b.first2) {
            return a.first2 < b.first2;
        }
        if(a.lastName != b.lastName) {
            return a.lastName < b.lastName;
        }
        else {
            return a.ssn < b.ssn;
        }
    }
} compareDataMod;

struct {
    inline bool operator() (int ind1, int ind2) {
        compareDataMod(theData[ind1],theData[ind2]);
    }
} compareDataInd;

struct {
    inline bool operator() (DataMod &a, DataMod &b) {
        if(a.last1 != b.last1) {
            return a.last1 < b.last1;
        }
        else if(a.last2 != b.last2) {
            return a.last2 < b.last2;
        }
        else if(a.last3 != b.last3) {
            return a.last3 < b.last3;
        }
        // else if(a.last4 != b.last4) {
        //     return a.last3 < b.last3;
        // }
        if(a.lastName != b.lastName) {
            return a.lastName < b.lastName;
        }
        else if(a.first1 != b.first1) {
            return a.first1 < b.first1;
        }
        else if(a.first2 != b.first2) {
            return a.first2 < b.first2;
        }
        else if(a.first3 != b.first3) {
            return a.first3 < b.first3;
        }
        // else if(a.first4 != b.first4) {
        //     return a.first4 < b.first4;
        // }
        else {
            return a.firstName < b.firstName;
        }
    }
} compareNames;

struct {
    inline bool operator() (int ind1, int ind2) {
        return compareNames(theData[ind1], theData[ind2]);
    }
} compareNamesInd;


/*
struct {
    inline bool operator() (Data* a, Data* b) {
        int ii = 0;
        if((a->lastName) != (b->lastName)) {
            while((a->lastName)[ii] == (b->lastName)[ii]) {
                ii++;
            }
            return (a->lastName)[ii] < (b->lastName)[ii];
        }
        if(a->firstName != b->firstName) {
            while((a->firstName)[ii] == (b->firstName)[ii]) {
                ii++;
            }
            return (a->firstName)[ii] < (b->firstName)[ii];
        }
        else {
            return a->ssn < b->ssn;
        }
    }
} compareDataChar;
*/
struct {
    inline bool operator() (DataMod &a, DataMod &b) {
        return a.ssn < b.ssn;
    }
} ModNumCompare;

struct {
    inline bool operator() (int ind1, int ind2) {
        return ModNumCompare(theData[ind1], theData[ind2]);
    }
} ModNumCompareInd;

int convToInt(string& str, int numChars) {
    int num = 0;
    size_t len = str.length();
    for(int ii = 0; ii < numChars; ii++) {
        num *= 27;
        if(ii < len) {
            num += str[ii]-'@';
        }
    }
    return num;
}
