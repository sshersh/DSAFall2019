#define NUM_BUCKETS 100000

void sort4(list<Data *> &data) {
    uint32_t occur[NUM_BUCKETS] = {};
    uint32_t offset[NUM_BUCKETS] = {};
    static uint32_t nums[MAX_SIZE234];

    int ii = 0;
    for(auto it : data) {
        nums[ii++] = toInt(it->ssn);
    }

    int size = data.size();

    for(int jj = 0; jj < size; jj++) {
        ++occur[nums[jj]/10000];
    }

    for(int ii = 1; ii < NUM_BUCKETS; ii++) {
        //measure offset from beginning
        offset[ii] = offset[ii-1] + occur[ii-1];
    }

    static uint32_t buckets[MAX_SIZE234] = {};

    uint32_t temp;
    for(int kk = 0; kk < size; kk++) {
        buckets[offset[nums[kk]/10000]++] = nums[kk];
    }

    sort(buckets, buckets + offset[0]);
    for(int ll = 0; ll < NUM_BUCKETS - 1; ll++) {
        sort(buckets + offset[ll], buckets + offset[ll+1]);
    }

    ii = 0;
    for(auto it : data) {
        toStr(buckets[ii++], it->ssn);
    }
}
