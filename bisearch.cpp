#include<iostream>
using namespace std;

int BINARY_SEARCH(int A[], int v, int p, int r)
{
    int q = (p+r)/2, index = -1;
    cout << p << " " << r << endl;
    if(v==A[q])
        return q;
    if(r>p)
    {
        if(v<=A[q])
	    index = BINARY_SEARCH(A, v, p, q);
        else if(v>A[q])
	    index = BINARY_SEARCH(A, v, q+1, r);
    }
    return index;
}

int main()
{
    int a[8] = {1,2,3,4,5,6,7,8};
    int index = BINARY_SEARCH(a, 3, 0, 7);
    cout << index << endl;
    return 0;
}
