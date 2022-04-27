// C++ program to solve fractional
// Knapsack Problem
#include <bits/stdc++.h>

using namespace std;

// Structure for an item which stores
// weight & corresponding value of Item
class Item {
	public:
	int value, weight;

};

// Comparison function to sort Item
// according to val/weight ratio
bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(Item arr[],
						int N, int size)
{
	// Sort Item on basis of ratio
	sort(arr, arr + size, cmp);

	// Current weight in knapsack
	int curWeight = 0;

	// Result (value in Knapsack)
	double finalvalue = 0.0;

	// Looping through all Items
	for (int i = 0; i < size; i++) {

		// If adding Item won't overflow,
		// add it completely
		if (curWeight + arr[i].weight <= N) {
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		}

		// If we can't add current Item,
		// add fractional part of it
		else {
			int remain = N - curWeight;
			finalvalue += arr[i].value
						* ((double)remain
							/ arr[i].weight);

			break;
		}
	}

	// Returning final value
	return finalvalue;
}

// Driver Code
int main()
{
	// Weight of knapsack
	int N = 60;
	int n;
	cout<<"Enter Total items:";
	cin>>n;
	Item arr[n];
	for(int i=0;i<n;i++){
		cout<<"Enter value:";
		cin>>arr[i].value;
		cout<<"Enter Weight:";
		cin>>arr[i].weight;
		
		cout<<endl;
	}
	// Given weights and values as a pairs


	

	// Function Call
	cout << "Maximum profit earned = "
		<< fractionalKnapsack(arr, N, n);
	return 0;
}

/*
{ 100, 10 },
{ 280, 40 },
{ 120, 20 },
{ 120, 24 }
*/

