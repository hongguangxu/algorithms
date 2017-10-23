#include<iostream>
#include<vector>

using namespace std;

template <typename T>
void bubbleSort(vector<T> &v)
{
    int N = v.size();
    while(N > 0)
    {
	int j = 0;
        for(int i = 1; i < N; i++)
	{
	    if(v[i-1] > v[i]) // swap the bigger element forward
	    {
	        T temp = v[i];
		v[i] = move(v[i-1]);
		v[i-1] = move(temp);
		j = i;
	    }
	}
	N = j;
    }
    return;
}

int main()
{
    vector<int> vi;
    cout << "enter your numbers: " << endl;
    for(int i = 0; i < 3; i++)
    {
	int in = 0;
        //cout << "enter your numbers: " << endl;
        cin >> in;
	vi.push_back(in);
    }
    for(int j = 0; j < vi.size(); j++)
        cout << vi[j] << " ";
    cout << endl;

    bubbleSort(vi);
    for(int j = 0; j < vi.size(); j++)
        cout << vi[j] << " ";
    cout << endl;
    return 0;
}
