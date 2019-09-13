#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;
#define MAX 11

//********************************************************  Hash function ***********************************************************************
//*************************************************** Hash functions for string ****************************************************************



class RKM_D{

	//use of function overloading
public:
	//DJB2 @ algorithm for hashing of strings
int Hash_func(string x){
	unsigned long  hash=5381;
	int c;
	const char *s=x.c_str();
	while(c=*s++)
		hash=((hash<<5)+hash)+c;
	return (int)(hash % MAX);
}

// hash function for int as key to spit the index of Bucket
int Hash_func(int key){
	//Mid square hashing

	// Squaring the key. 
    key = key * key; 
  
    // Extracting required number of digits ( here, 4 ). 
    
        key = key / 1000; 
        key = key % 1009; // 1009 is prime no.
        //key = key % 23;
     
  
    // Returning the key value. 
    return (key % MAX); 
}

int Hash_func(double key){
	//Mid square hashing

	// Squaring the key. 
    key = key * key; 
  
    // Extracting required number of digits ( here, 4 ). 
    
        key = key / 1000; 
        key = fmod(key ,1000); 
        //key = key % 23;
     
  
    // Returning the key value. 
    return (int)fmod(key,MAX); 
}

};


//***********************************************************************************************************************************************

template <class K,class T>
class pairKV
{
	public:
	K  key;
	T value;
	//pairKV *next;
};


template <class A,class B>
class Unordered_map{
	public:
		int BUCKET;
		list<pairKV<A,B>> *tab;
		int size;

		Unordered_map(){
			this->BUCKET=MAX;
			int size=0;
			tab=new list<pairKV<A,B>>[MAX];
		}


	public:
	void insert(A key,B value){
		RKM_D q;
 		int index=q.Hash_func(key);
		pairKV<A,B> temp;
		temp.key=key;
		temp.value=value;
		tab[index].push_back(temp);
		size++;
		
}

	void displayHash() { 
  	for (int i = 0; i < BUCKET; i++) { 
    cout << i;
    for (auto x : tab[i]) 
      cout << " --> " <<"("<<x.key<< " "<< x.value<<")"; 
    cout << endl; 
   
  } 
} 

	int getSize(){
		return size;
	}

	bool isEmpty(){
 		return size==0;
	}

	void checkEfficient(){
		 if(1.0*size/BUCKET >=0.9){
			cout <<"You need to increase the size of HASH TABLE"<<endl;
		}
	}

	void remove(A temp){
		RKM_D a;
	int index = a.Hash_func(temp); 

  	typename list <pairKV<A,B>> :: iterator i; 
  	for (i = tab[index].begin();i != tab[index].end(); i++) { 
    if ((*i).key == temp) 
      break; 
}
  	if (i != tab[index].end()) 
    {
    	tab[index].erase(i);
		size--;
}
	}


// find finction returning type of value
	B find(A temp){
         // Find head of chain for given key 
		RKM_D f;
        int ind = f.Hash_func(temp); 
     typename std::list<pairKV<A,B>> :: iterator i; 
	  	for (i = tab[ind].begin();i != tab[ind].end(); i++) { 
	    if ((*i).key == temp) 
	     break;
	}
	  	return (*i).value;
  
       
        
	}

};

int main(){
	//test1  (string,int)
	/*Unordered_map<string,int> mp;
	mp.insert("ishan",996);
	mp.insert("tyagi",54);
	mp.insert("venom",96);
	mp.insert("bond",007);
	mp.insert("james",7);
	mp.insert("chris",23);
	mp.insert("ding",56);
	mp.displayHash();
	mp.remove("ding");
	cout << endl;
	mp.displayHash();
	cout << mp.find("ishan")<<endl;*/




	//test2  (int,int)

	/*Unordered_map<int,int> mp;
	mp.insert(7,996);
	mp.insert(190,54);
	mp.insert(54,96);
	mp.insert(76,1000);
	mp.insert(89,875);
	mp.insert(49,23);
	mp.displayHash();
	mp.remove(76);
	cout << endl;
	mp.displayHash();
	cout << mp.find(7)<<endl;*/


//	test3  (int,string)
	/*Unordered_map<int,string> mp;

	mp.insert(324,"venom");
	mp.insert(467,"murphy");
	mp.insert(19,"DJ");
	mp.insert(76,"ishan");
	mp.insert(89,"tyagi");
	mp.insert(49,"ayush");
	mp.insert(11,"raja");
    mp.displayHash();
	mp.remove(76);
	cout << endl;
	mp.displayHash();
	cout << mp.find(89)<<endl;*/

	


	//test4  (string,string)
	/*Unordered_map<string,string> mp;

	mp.insert("ishan","tyagi");
	mp.insert("james","bond");
	mp.insert("chrios","gardner");
	mp.insert("detective","roy");
	mp.insert("heart","lion");
	mp.insert("DJ","manish");
	mp.insert("kulu","gucci");
	mp.insert("D","man");
	mp.insert("k00l","gusgi");
	mp.displayHash();
	mp.remove("detective");
	cout << endl;
	mp.displayHash();
	cout << mp.find("DJ")<<endl;
	cout <<mp.getSize()<<" "<<endl;
	mp.checkEfficient();*/


//test4 (string ,int)
	Unordered_map<double,string> mp;
	
	mp.insert(9.9,"manish");
	mp.insert(12.8,"DJ");
	mp.insert(76.09,"ishan");
	mp.insert(89997,"tyagi");
	mp.insert(49.56,"ayush");
	mp.insert(12.53,"raja");
    mp.displayHash();
	mp.remove(12.8);
	cout << endl;
	mp.displayHash();
	cout << mp.find(89997)<<endl;
	return 0;
}