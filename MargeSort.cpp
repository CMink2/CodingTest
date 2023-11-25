#include<iostream>
#include<vector>

using namespace std;

//merge sort
void MergeSort(int s, int e);
static vector<int> A;
static vector<int> tmp;

int main()
{
	//input num's count
	int N;
	cin >> N;

	A = vector<int>(N + 1, 0);
	tmp = vector<int>(N + 1, 0);

	//enter value
	for (size_t i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	//mergeSrot
	MergeSort(1, N);

	//print result
	for (size_t i = 1; i <= N; i++)
	{
		cout << A[i] << "\t";
	}
}


void MergeSort(int s, int e)
{
	//if e = s => already divide
	if (e - s < 1)
	{
		return;
	}
	//find divide point
	int m = s + (e - s) / 2;
	MergeSort(s, m);
	MergeSort(m + 1, e);
	//tmp array setting
	for (size_t i = s; i <= e; i++)
	{
		tmp[i] = A[i];
	}
	//k = set array index
	int k = s;
	//compare index
	int index1 = s;
	int index2 = m + 1;
	//compare process
	while (index1 <= m && index2 <= e)
	{
		//index2's array small case
		if (tmp[index1] > tmp[index2])
		{
			A[k] = tmp[index2];
			k++;
			index2++;
		}
		//index1's array small case
		else 
		{
			A[k] = tmp[index1];
			k++;
			index1++;
		}
	}
	//rest process
	while (index1 <= m)
	{
		A[k++] = tmp[index1++];
	}
	while (index2 <= m)
	{
		A[k++] = tmp[index2++];
	}
}