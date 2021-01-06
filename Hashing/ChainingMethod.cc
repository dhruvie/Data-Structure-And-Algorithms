#include<bits/stdc++.h>
using namespace std; 
#define hashFunction(k) (2*k)+3
class List
{
	public:
		int key;
		List *next;
	List(int data)
	{
		key=data;
		next=NULL;
	}
};
void Display(vector<List *> hashTable, int hashSize)
{
	for(int i=0; i<hashSize; ++i)
	{
		List *p=hashTable[i];
		cout<<"\nAt Index: "<<i<<" Keys are:---->>  ";
		while(p)
		{
			cout<<p->key<<" ";
			p=p->next;
		}
	}	cout<<endl;
}
int main(int argc, char const *argv[])
{
	vector<int> keys={3,2,9,6,11,13,7,12};
	int hashSize=10,N=keys.size();
	vector<List *> hashTable(10,NULL);
	for(int i=0; i<N; ++i)
	{
		int key=keys[i];
		int location=(hashFunction(key))%hashSize;
		if(!hashTable[location])
		{
			List *p=new List(key);
			hashTable[location]=p;
		}
		else
		{
			List *temp=hashTable[location];
			while(temp->next)
				temp=temp->next;
			List *p=new List(key);
			temp->next=p;
		}
	}
	Display(hashTable,hashSize);
	return 0;
}