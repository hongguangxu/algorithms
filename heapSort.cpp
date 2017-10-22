#include<iostream>
#include<vector>

using namespace std;


int left(int i)
{
    return 2*(i+1)-1;
}
int right(int i)
{
    return (2*(i+1)); 
}
template<typename T>
void max_heapify(T v[], int L, int i)
{
    int l = left(i);
    int r = right(i);
    int largest = 0;
    if((l < L)&&(v[l] > v[i]))
	largest = l;
    else
	largest = i;
    if((r < L)&&(v[r] > v[largest]))
	largest = r;
    if(largest != i)
    {
        T temp = v[i];
	v[i] = move(v[largest]);
	v[largest] = move(temp);
	max_heapify(v, L, largest);
    }
    return;
}
template<typename T>
void build_max_heap(T v[], int L)
{
    for(int i = (L/2)-1; i >= 0; i--)
    {
        max_heapify(v, L, i);
    }
    return;
}
template<typename T>
void heapSort(T v[], int L)
{
    build_max_heap(v, L);
    for(int i = 0; i < L; i++)
	cout << v[i] << " ";
    cout << endl;
    int len = L;
    for(int i = L-1; i > 0; i--)
    {
        T temp = v[i];
	v[i] = move(v[0]);
	v[0] = move(temp);
        len--;
        max_heapify(v, len, 0);
    }
    return;
}

int main()
{
     int a[7] = {3, 1, 24, 15, 9, 5, 10};
     heapSort(a, 7);
     for(int i = 0; i < 7; i++)
	 cout << a[i] << " ";
     cout << endl;
     return 0;
}
