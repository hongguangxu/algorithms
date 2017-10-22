#include<vector>
#include<iostream>

using namespace std;

template<typename T>
int partition(vector<T> &v, int p, int r)
{
    T pivot = v[r];
    int i = p-1;
    int temp = 0;
    
    for(int j = p; j < r; j++)
    {
        if(v[j] < pivot)
	{
	    i = i+1;
	    swap(v[i], v[j]);
	}
    }
    i = i+1; 
    //temp = v[r];
    //v[r] = move(v[i]);
    //v[i] = move(temp);
    swap(v[r], v[i]);
  
    return i;
}
template <typename T>
void quickSort(vector<T> &v, int p, int r)
{
    int q = partition(v, p, r);
    if((q-1) > p)
        quickSort(v, p, q-1);
    if(r > (q+1))
        quickSort(v, q+1, r);
    return;
}

int main()
{
    vector<int> vi;
    int N = 7;
    int r[N] = {2,10,50,20,9,6,4};
   // cout << "please enter your numbers:" << endl;
    for(int i = 0; i < 7; i++)
    {
    	//cin >> input;
	vi.push_back(r[i]);
    }
    quickSort(vi, 0, N-1);
    for(int j = 0; j < N; j++)
	cout << vi[j] << " ";
    cout << endl;
    return 0;
}
