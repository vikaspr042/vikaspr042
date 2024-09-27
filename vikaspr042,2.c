
typedef struct { int key; int val; UT_hash_handle hh; } Map_t;

int subarraySum(int* nums, int numsSize, int k) {
    int result=0, sum=0, sub; Map_t *map=NULL, *m, *t;

    m=malloc(sizeof(Map_t)); m->key=0; m->val=1;
    HASH_ADD_INT(map, key, m);

    for(int i=0; i<numsSize; i++) {
        sum+=nums[i]; sub=sum-k;

        HASH_FIND_INT(map, &sub, m);
        result+=m?m->val:0;

        HASH_FIND_INT(map, &sum, m);
        if(!m) {
            m=malloc(sizeof(Map_t)); m->key=sum; m->val=1;
            HASH_ADD_INT(map, key, m);
        } else { m->val++; }
    }
    
    HASH_ITER(hh, map, m, t){ HASH_DEL(map, m); free(m); }

    return result;
}