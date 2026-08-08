/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#pragma GCC optimize("O3, unroll-loops")
typedef __uint128_t u128;

int* findMissingElements(int* nums, int n, int* returnSize) {
    u128 hasX=0;
    int xMin=101, xMax=0;
    for (int i=0; i<n; i++) {
        const int x=nums[i];
        hasX|=((u128)1<<x);
        xMin+=(-(xMin>x) & (x-xMin));
        xMax+=(-(xMax<x) & (x-xMax));
    }

    u128 rangeMask=(((u128)1<<(xMax-xMin+1))-1)<<xMin;
    u128 missing=(~hasX)&rangeMask;

    uint64_t lo=(uint64_t)missing;
    uint64_t hi=(uint64_t)(missing>>64);

    int* ans=(int*)malloc(sizeof(int)*100);
    int sz=0;

    // Extract low bits [0, 63]
    for (; lo; lo &=(lo-1)) {
        const int x=__builtin_ctzll(lo);
        ans[sz++]=x;
    }

    // Extract high bits [64, 127]
    for (; hi; hi &=(hi-1)) {
        const int x=__builtin_ctzll(hi);
        ans[sz++]=x+64;
    }

    *returnSize=sz;
    if (sz==0) {
        free(ans);
        return NULL;
    }
    ans=realloc(ans, sz*sizeof(int));
    return ans;
}