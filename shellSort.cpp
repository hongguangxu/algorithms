#include<iostream>
using namespace std;

template <typename T>
void shellSort(T r[], int N)
{
    for(int gap = N/2; gap > 0; gap /= 2)
    {
	for(int i = gap; i < N; i++)
	{
	    if(r[i] < r[i-gap])
            {
	        int j = 0;
	        T temp = r[i];
	        for(j=i-gap; j >= 0; j-=gap)
	        {
	            if(r[j] > temp)
		        r[j+gap] = r[j];
		    else 
		    {
		        r[j+gap] = temp;
		        break;
		    }
	        }
		if(j < 0)
	            r[j+gap] = temp;
	    }
	}
    }
}

int main()
{
    int A[13] = {123, 23, 345, 43, 89, 90, 76, 32, 45, 500, 122, 5, 30};
    shellSort(A, 13);
    for(int i = 0; i < 13; i++)
	cout << A[i] << " ";
    cout << endl;
    return 0;
}
