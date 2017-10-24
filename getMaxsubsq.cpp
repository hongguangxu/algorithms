#include<iostream>
using namespace std;

int get_max_sub_squ(int a[], int N)
{
    int i = 0;
    int max = 0;
    int sum = 0;
    while(i < N)
    {
        sum += a[i];
	max = ((max > sum)? max:sum);
	if(sum < 0)
            sum = 0;
	i++;
    }
    return max;
}

int main()
{
    int a[10] = {-10, 1, 3, 6, -5, 7, 8, -30, 20, 4};
    int max = get_max_sub_squ(a, 10);
    cout << max << endl;
    return 0;
}
