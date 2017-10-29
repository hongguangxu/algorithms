/*this code is a comparation of running time between merge sort and merge-insert-sort,
 generally, merge sort:Θ(nlgn), insert-sort:Θ(n^2), there exist m and k for  m*n^2 < k*n*lgn*/
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<ctime>
using namespace std;
#define THRESHOLD 5
template<typename T>
void InsertSort(vector<T> &r, int p, int q)
{
    T pivot = 0;
    for(int i = p; i < q+1; i++)
    {
        if(r[i] < r[i-1])
        {
            pivot = r[i];
            int j = 0;
            for(j = i-1; j >= p; j--)
            {
                if(r[j] > pivot)
                    r[j+1] = r[j];
                else
                {
                    r[j+1] = pivot;
                    break;
                }
            }
            if(j < p)
                r[p] = pivot;
        }
    }
    return;
}
template<typename T>
void  merge(vector<T>&v, int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int r1[n1] = {0};
    int r2[n2] = {0};
    int begin = p;
    for(int i = 0; i < n1; i++)
    {
        r1[i] = move(v[p+i]);
    }
    for(int i = 0; i < n2; i++)
    {
        r2[i] = move(v[q+i+1]);
    }
    int i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(r1[i] < r2[j])
	{
	    v[begin++] = move(r1[i++]);
	    //i++;
	}
	else if(r1[i] > r2[j])
	{
	    v[begin++] = move(r2[j++]);
	    //inversion += n1-i;
            //j++;
	}
	else
	{
	    v[begin++] = move(r1[i++]);
            //i++;
	    v[begin++] = move(r2[j++]);
	    //j++;
	}
    }
    if(i < n1)
    {
        for(int k = i; k < n1; k++)
	    v[begin++] = move(r1[k]);
    }
    if(j < n2)
    {
        for(int k = j; k < n2; k++)
	    v[begin++] = move(r2[k]);
    }
    return;
}
template<typename T>
void mergeSort(vector<T>&v, int p, int r)
{
    //cout << p << " " << r << endl;
    //int inversion = 0;
    if(r-p>0)
    {
        int q = (p+r)/2;
        mergeSort(v, p, q);
        mergeSort(v, q+1, r);
        merge(v, p, q, r);
    }
    else
    {
        InsertSort(v, p, r);
    }
    return;
}
template<typename T>
void mergeSort1(vector<T> &v)
{
    int N = v.size();
    int step = 1;
    while(step < N)
    {
        for(int i = 0; i < N; i = i + 2*step)
	{
	    if((i+step) < N)
	    {
		if((i+2*step-1) < N)
	            merge(v, i, i+step-1, i+2*step-1);
		else
	            merge(v, i, i+step-1, N-1);
	    }
	        //merge(v, i, i + step-1, i + 2*step - 1);
	}
	step = 2*step;
    }
    return;
}
int main()
{
    clock_t start = 0, end = 0;
    int N = 1000000;
    vector<int> v;
    srand((unsigned)time(NULL));
    //int r[N] = {0};
    for(int i = 0; i < N; i++)
	v.push_back(rand()%1000);
    start = clock();
    mergeSort(v, 0, N);
    end = clock();
    //cout << end-start << "/" << CLOCKS_PER_SEC << "(s)" << endl;
    // mergeSort1(v);
    //cout << end-start << "/" << CLOCKS_PER_SEC << "(s)" << endl;
    for(int i = 0; i < N; i++)
	cout << v[i] << " ";
    cout << endl;
    cout << end-start << "/" << CLOCKS_PER_SEC << "(s)" << endl;
    //cout << inversion << endl;
    return 0;
}
