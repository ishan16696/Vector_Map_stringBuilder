#include<iostream>
using namespace std;


class vector{
	public:
		vector(){
			this->arr =new int[1];
			this->capacity=1;
			this->sizeofVector=0;
		}
		
		//initialize a vector of length n with all values as x.
		vector(int n,int x){
		  	allocate(n,-1);
		  	for(int i=0;i<capacity;++i)
		  	arr[i]=x;
		  	sizeofVector=capacity;
		}
		
	public:
		int capacity; // total available space;
		int sizeofVector;// no of elements;
		int *arr; // pointer to dynamic array;
		
	int & operator [ ] (unsigned int i)
   {
   	 if(i<sizeofVector)
     return arr[i];
   }
		
	void push_back(int x){
	/*	if(size==0){
			allocate(1,0);
		}
	*/	if(sizeofVector==capacity){
			allocate(2*capacity,1);
		}
		
		arr[sizeofVector++]=x;
	}

		int pop_back(){
		
		int temp= arr[--sizeofVector];
		if(sizeofVector==capacity/2){
			allocate(sizeofVector,1);
		}
		return temp;
}
	
	void allocate(int n,int  copy){
	int i;
	int *z= new int[n];
	if(copy==1){
		for(i=0;i<sizeofVector;++i)
		z[i]=arr[i];
		capacity=n;
	    int *temp=arr;
	    arr=z;
	    delete(temp);
	}
	else
	    if(copy==-1)
		{
	    arr=z;
	    capacity=n;
	    }
	
	}
	
	void insert(int index,int x){
		for(int i=sizeofVector-1;i>=index;i--){
			arr[i+1]=arr[i];
		}
		arr[index]=x;
		sizeofVector++;
		if(sizeofVector==capacity)
		allocate(capacity,1);
	}
	
	void erase(int index){
		for(int i=index;i<sizeofVector;i++)
		arr[i]=arr[i+1];	
		
		sizeofVector--;	
		if(sizeofVector==capacity/2)
		allocate(sizeofVector,1);
	}
	
		
	int size(){
		return this->sizeofVector;
	}
	
	int front(){
		return this->arr[0];
	}
	
	int back(){
		return this->arr[sizeofVector-1];
	}
};

int main(){
	
	vector a ;
	a.push_back(2);
	a.push_back(3);
	a.push_back(6);
	cout << a.size() << endl;
	cout << a.pop_back() << endl;
	cout << a.front() << endl;
	cout << a.back() << endl;
	cout << a[0] << endl;
	cout << a.size() << endl;
	a.push_back(6);
	a.push_back(43);
	a.push_back(8);
	a.push_back(90);
	cout << a.size() << endl;
	a.insert(4,50);
	
	for(int i=0;i<a.size();i++)
	cout << a[i] << " ";
	a.erase(3);
	cout << endl;
	for(int i=0;i<a.size();i++)
	cout << a[i] << " ";
	
	
	
	return 0;
}
