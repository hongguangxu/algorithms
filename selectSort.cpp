#include<vector>
#include<iostream>
using namespace std;

template<typename T>
void selectSort(vector<T> &v)
{
    int N = v.size();
    int step = 0;
    while(step < N)
    {
	int mi = step;
        for(int i = step; i < N; i++)
	{
	    if(v[i] < v[mi])
		mi = i;
	}
	swap(v[step], v[mi]);
	step++;
    }
    return;
}

int main()
{
    vector<int> v;
    int r[7] = {3, 1, 90, 54, 22, 300, 11};
    for(int i = 0; i < 7; i++)
	v.push_back(r[i]);
    selectSort(v);
    for(int i = 0; i < v.size(); i++)
	cout << v[i] << " ";
    cout << endl;
    return 0;
}
