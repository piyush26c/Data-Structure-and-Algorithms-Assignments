#include<bits/stdc++.h>
#define SIZE 20
using namespace std;

class Searching
{
        private :
                int arr[SIZE];
                int nts;//number want to search
                int n;// total number of students attending training program
                
        public :
                void getRollNumbers();
                void sequentialSearch();
                void sort();
                void binarySearch();
                //for fibonacci
                //void get();
                int fibo(int k);
                int fiboSearch(int key);
                void displaySort();
};

void Searching::getRollNumbers()
{
        cout << "\nEnter Total Number Of Students : ";
        cin >> n;
        cout<<"\nEnter the Roll Numbers Of Students \n";
        for(int p=0; p<n; p++)
        {
                cin>>arr[p];
        }
}

void Searching::sequentialSearch()
{
        int flag;
        cout<<"\nEnter The Roll Number TO Be Searched(Sequential Searching) :\t";
        cin>>nts;
        for(int y=0; y<n; y++)
        {
                flag=0;
                if(arr[y]==nts)
                {
                        flag=1;
                        break;
                }
        }
        
        if(flag==1)
        cout<<"\nStudent attended Training Program"<<endl;
        else
        cout<<"\nStudent not attended Training Program"<<endl;
}

void Searching::binarySearch()
{
        int first;
         int flag;
       
        int last;
        int middle;
        first=0;
        last=n-1;
         
         //sorting the array as for binarySearching array should be sorted(constrain)   
         
         cout<<"\nEnter The Roll Number TO Be Searched(Binary Searching)     :\t";
        cin>>nts;

        while(first<=last)
        {
                flag=0;
                middle=(last+first)/2;    
                if(arr[middle]==nts)
                {
                        flag = 1;
                         
                        break;
                       
                }
                
                else 
                {
                 if(nts<arr[middle])
                 last=middle-1;
                  
                 else
                        first=middle+1;
                 }     
               
         }
        
         if(flag==1)
            cout<<"\nStudent attended Training Program"<<endl;
        else
         cout<<"\nStudent not attended Training Program"<<endl;
         
         
                
}
                        
void Searching::sort()
{
                int min;
                int i,j,temp;
                /*for( i=0;i<n-1;i++)
                {
                    min=i;
                    for( j=i+1;j<n;j++)
                    {   
                        if(arr[j]<arr[min])
                        min=j;
                    }
                    int temp;
                    temp=arr[i];
                    arr[i]=arr[min];
                    arr[min]=temp;
                }*/
                
                for (i = 0; i < n - 1; i++) {
                min = i;
                for (j = i + 1; j < n; j++) {
                    if (arr[min] > arr[j]) {
                        min = j;
                    }
                }

                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }

                
        
}

void Searching::displaySort(){
                cout<<"\nSorted array : ";
                for(int p=0;p<n;p++)
                {
                    cout<<arr[p]<<"\t";
                }
}

//fibonacci functions
int Searching::fibo(int k) {
    /*this function calculate fibonacci number 
     * at k-th position.
     */

    if (k == 0)
        return 0;
    if (k == 1)
        return 1;
    else
        return (fibo(k - 1) + fibo(k - 2));
}

int Searching::fiboSearch(int key) {
    int f1, f2, temp, mid, j, f;
    j = 0;
    while (fibo(j) <= n) {
        //find fibo(j) such that fibo(j) >= n
        j++;
    }
    f = fibo(j);
    f1 = fibo(j - 2);
    f2 = fibo(j - 3);
    mid = n - f1 + 1;

    while (key != arr[mid]) {
        if ( key > arr[mid - 1]) {
            if (f1 == 1) 
                return (-1);
                mid = mid + f2;
                f1 = f1 - f2;
                f2 = f2 - f1;
            } else {
                if (f2 == 0) 
                    return (-1);
                    mid = mid - f2;
                    temp = f1 - f2;
                    f1 = f2;
                    f2 = temp;

                
            }

        }
    
    cout << "\nmid = " << mid;
    return mid;
    
}



int main (int argc, char const* argv[])
{
        Searching s1;
        
        int s,d;
        //fibonacci vaariables
        int key,loc;
        
        do
        {
                d=1;
                cout<<"\n(1).Enter Roll Numbers whoe attended Trainig Program";
                cout<<"\n(2).Search Roll Number by Sequential Search Method";
                cout<<"\n(3).Search Roll Number by Binary Search Method";
                cout<<"\n(4).Search Roll Number by Fibonacci Search Method";
                cout<<"\n(5).Display Sorted Elements";
                cout<<"\n(6).Exit\n";
                cin>>s;
                
                switch(s)
                {
                        case 1:
                        s1.getRollNumbers();
                        break;
                        
                        case 2:
                        s1.sequentialSearch();
                        break;
                        
                        case 3:
                        s1.sort();
                        s1.binarySearch();
                        break;
                        
                        case 4:
                        s1.sort();
                        cout << "\nEnter RollNo. To Be Searched : ";
                        cin >>key;
                        loc = s1.fiboSearch(key);
                        if(loc >= 0){
                            cout << "\nRollNo. " << key << "have attended Training & present at Location " << loc;
                        }
                        else{
                            cout << "Not Found ";
                        }
                        break;
                        
                        case 5:
                        s1.sort();
                        s1.displaySort();
                        break;
                        
                        case 6:
                        d=0;
                        break;
                        
                 }
                 
          } while(d);
        return 0;
}


