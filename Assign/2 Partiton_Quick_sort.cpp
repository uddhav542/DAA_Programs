#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
class QuickSort
{
	public:
	void swap(int* a, int* b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}
	int Partition(int input[], int low, int high,int pivot1)
	{
		int pivot = pivot1;
		int i = (low - 1);
		for (int j = low; j <= high- 1; j++)
		{
			if (input[j] <= pivot)
			{
				i++;
				swap(&input[i], &input[j]);
			}
		}
		swap(&input[i + 1], &input[high]);
		return (i + 1);
	}
	//-----------------------------------------Medians of Median------------------------------------
	
	//--------------------------------------------------------------------------------------------------------------------
	void quickSort1(int input[],int low,int high)
	{
		if (low < high)
		{
			int pi = Partition(input, low, high, input[high]);
			quickSort1(input, low, pi - 1);
			quickSort1(input, pi + 1, high);
		}
	}
	void printinputay(int input[],int isize)
	{
		int i;
		for (i=0; i < isize; i++)
		cout<<" "<<input[i];
		cout<<"\n";
	}
};
int main()
{
	int n,i,ch;

		auto start = high_resolution_clock::now();
		cout<<"\nEnter value of (n) for generating 10^n inputs(Enter 0 to exit)=";
		cin>>n;
		int isize;
		isize=pow(10,n);
		int input[isize];
		for(i=0;i<isize;i++)
		{
			input[i]=rand();
		}
		for(i=0;i<isize;i++)
		{
			cout<<input[i]<<"\t";
		}
		
		QuickSort q;
	
			 q.quickSort1(input, 0, isize-1);
			cout<<"\nSorted output using Partition Method : \n";
			q.printinputay(input, isize);
			
	
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		cout<<"Execution time="<<duration.count()<< endl;
	
	return 0;

}
