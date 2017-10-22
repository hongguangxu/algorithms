#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void merge(vector<T>&v, int p, int q, int r)
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
    if(p < r)
    {
        int q = (p+r)/2;
        mergeSort(v, p, q);
        mergeSort(v, q+1, r);
        merge(v, p, q, r);
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
    vector<int> v;
    int r[7] = {3, 1, 90, 54, 22, 300, 11};
    for(int i = 0; i < 7; i++)
	v.push_back(r[i]);
    //mergeSort(v, 0, 6);
    mergeSort1(v);
    for(int i = 0; i < 7; i++)
	cout << v[i] << " ";
    cout << endl;
    return 0;
}
