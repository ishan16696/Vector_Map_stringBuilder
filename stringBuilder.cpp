#include <bits/stdc++.h>
using namespace std;


char forKMP[1000000];   

class String_Builder
{
public:
	String_Builder *left,*right;
	char str[1000000]; 

};


class StringBuilder
{
public:
	StringBuilder(){
		
				//root.str=NULL;
	}

	String_Builder* stringInitialize(const char *input){
		String_Builder *root=new String_Builder();
		root->left=NULL;
		root->right=NULL;

		strcpy(root->str,input);
		//cout << root->str <<" "<<endl;
		return root;
	}

	String_Builder *append(String_Builder *s1,String_Builder *s2){
		String_Builder *temp=new String_Builder();
		temp->left=s1;
		temp->right=s2;

		return temp;

	}


	void printstring(String_Builder *r) 
	{ 
	    if (r==NULL) 
	        return; 
	    printstring(r->left); 
	    if (r->left==NULL && r->right==NULL) 
	        cout << r->str; 
	    
	    printstring(r->right);
	   // cout<<endl;
	} 
//****************************************************  used in KMP *************************************************************************
	void computeArray(string pat,int useful[]){
    int j=0,i=1;
    useful[0]=0;
    int n=pat.length();
    while(i<n){
    	if(pat[j]==pat[i])
    	{
    		useful[i]=j+1;
    		i++;
    		j++;
    	}
    	else{
    		if(j==0)
    			{
    				useful[i]=0;
    				i++;
    			}
    		else{
    			j=useful[j-1];
    		}
    	}
    	}


	}


    /**
     ********************************* KMP algorithm of pattern matching and return the index ************************************************
     */

	int KMP(string txt,string pat){
		int len=pat.length();
		int useful[len]={0};
		computeArray(pat,useful);
		/*for(int i=0;i<len;i++)
			cout << useful[i]<<" ";
	*/
	  int i=0;  // pointer to txt
	  int j=0;  // pointer to pattern
	while(j<len && i< txt.length()){
			if(txt[i]==pat[j]){
				j++;
				i++;
			}
			else{
				if(j==0){
					i++;
				}
				else{
					j=useful[j-1];
				}
			}
	}

	if(j==len)
	{
		return  (i-len);
	}

	return -1;

	}




	int findSubstring(String_Builder *r,const char *s){
		if (r==NULL) 
	        return -1;

	    // traversing the tree in inorder 
	    findSubstring(r->left,s); 
	    if (r->left==NULL && r->right==NULL) 
	         strcat(forKMP,r->str); 
	    findSubstring(r->right,s); 


	    string help(forKMP);

	    string temp(s);
	    int ind=KMP(help,s);
	    return ind;
	}

};



//*******************************************************  main() *****************************************************************************

int main(){
StringBuilder a;
String_Builder *s1=a.stringInitialize("Hello");   
String_Builder *s2=a.stringInitialize("hellotyagisgssgsdsisisjsjdjdjdjjdkdkkkskskslllalalallalalalishan37h");
s1=a.append(s1,s2);
a.printstring(s1);

cout <<endl;

int index=a.findSubstring(s1,"hell");
cout << index<<"\n";
memset(forKMP,0,sizeof(forKMP));   // clear the global char array , so that it can be reused

String_Builder *s3=a.stringInitialize("ishan");   
String_Builder *s4=a.stringInitialize("hellotyaayushtyagi77337h");

s3=a.append(s4,s1);
a.printstring(s3);
cout << endl;


index=a.findSubstring(s3,"ty");
cout << index<<"\n";
memset(forKMP,0,sizeof(forKMP));

return 0;
}