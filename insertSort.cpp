#include<iostream>
#include<string>

using namespace std;
template<typename T>
void InsertSort(T r[], int num)
{
    T pivot = 0;
    for(int i = 1; i < num; i++)
    {
        if(r[i] < r[i-1])
	{
	    pivot = r[i];
	    int j = 0;
	    for(j = i-1; j >= 0; j--)
	    {
	        if(r[j] > pivot)
		    r[j+1] = r[j];
		else
		{
		    r[j+1] = pivot;
		    break;
		}
	    }
	    if(j < 0)
		r[0] = pivot;
	}
    }
    return;
}

int main()
{
    int arr[10] = {0};
    cout << "please anter 10 numbers:" << endl;
    for(int i = 0; i < 10; i++)
	cin >> arr[i];
    InsertSort(arr, 10);
    for(int i=0; i < 10; i++)
	cout << arr[i] << " ";
    cout << endl;
    return 0;
}
