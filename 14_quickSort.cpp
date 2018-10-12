#include <iostream>
#include <cstdlib>
# define SIZE 10
using namespace std;

void quick(int arr[],int,int);
int partition(int arr[],int,int);
void swap(int arr[],int ,int);

int main()
{
	int nos;
	int low,high;


	cout<<"\nEnter Number Of Students :\t";
	cin>>nos;
        
	int arr[SIZE];

	//storing sgpa of students of first year
	cout<<"\nEnter Students SGPA :\n";
	for(int p=0;p<nos;p++)
		cin>>arr[p];
	low=0;
	high=(nos-1);

	quick(arr,low,nos-1);


	cout<<"\nSorted Order :\t";
	for(int p=0;p<nos;p++)
	cout<<arr[p]<<"\t";
        
    cout<<"\nDisplaying top five scores :";
	for(int i=nos-1;i>=nos-5;i--)
	cout<<arr[i]<<"\t";
	cout<<"\n";
}

void quick(int arr[],int low,int high)
{
	int m;
	if(low<high)
	{
		m=partition(arr,low,high);
		quick(arr,low,m-1);
		quick(arr,m+1,high);
	}
}

int partition(int arr[],int low,int high)
{
	int pivot,i,j;
	pivot=arr[low];
	i=low+1;
	j=high;

	while(i<=j)
	{
		while(arr[i]<pivot)
			i++;

		while(arr[j]>pivot)
			j--;

		if(i<j)
                {
                   swap(arr,i,j);
                }

	}           
                    swap(arr,low,j);
                    return j;
        
        
}


void swap( int arr[SIZE],int i,int j)
{
    float temp;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}