#include<iostream>
using namespace std;

class maxHeap{
    public:
    int arr[100];
    int size;

    maxHeap()
    {
        arr[0]=-1;
        size=0;
    }

    void insert(int val)    // O(logn)
    {
         // add element to the end 
         size=size+1;
         int index=size;
         arr[size]=val;

         // now take the element to its correct position
         while(index>1)
         {
            int parent=index/2;

            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else break;
         }
    }

    void deleteFromHeap()   // O(logn)
    {
        if(size==0)
        {
            cout<<"nothing to deleted"<<endl;
            return ;
        }
        arr[1]=arr[size];
        size--;

        // take root to its correct position
        int i=1;

        while(i<size)
        {
            int leftIndex=2*i;
            int rightIndex=2*i+1;

             // if root is less than left node value
            if(leftIndex<size && arr[i]<arr[leftIndex] && arr[leftIndex]>arr[rightIndex])
            {
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }

            // if root is less than right index value
            else if(rightIndex<size && arr[i]<arr[rightIndex] && arr[leftIndex]<arr[rightIndex])
            {
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else {
                break;
            }
        }
    }

    void print()
    {
        for(int i=1;i<=size;i++)cout<<arr[i]<<" ";

        cout<<endl;
    }

};

// buiild heap from an array 
// taking an element to its correct position in heap
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;

   // 1 based indexing hence we are taking left<=n
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right])
    {
        largest=right;
    }

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }

}

// T(N)=O(nlogn)

void heapSort(int arr[],int n)
{
    int size=n;

    while(size>1)  // O(n)
    {
        // swap the largest element with the element in last index
        // largest element is present in the first index
        swap(arr[size],arr[1]);
        size--;

        // take the root element to its correct position
        heapify(arr,size,1);  // O(logn)
    }
   
}

int main()
{
    maxHeap maxheap;
    maxheap.insert(60);
    maxheap.insert(50);
    maxheap.insert(40);
    maxheap.insert(30);
    maxheap.insert(20);
    
    maxheap.print();

    maxheap.insert(95);
    maxheap.print();

    maxheap.deleteFromHeap();
    maxheap.print();

    int arr[6]={-1,54,53,55,52,50};
    int n=5;

   // we are doing from n/2 only 
   // as nodes from n/2+1 to n are leaf nodes
   // they are already in their correct position

    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
    cout<<"array: ";
    for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
    cout<<endl;

   
   // NOTE: heap sort function is only called on a heap
   // so when given a array convert into heap 
   // then call heap sort on the array
    heapSort(arr,5);
    cout<<"heap sort: ";
    for(int i=1;i<=5;i++)cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}