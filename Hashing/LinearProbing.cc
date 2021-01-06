#include<bits/stdc++.h>
using namespace std; 
#define hashFunction(k) (2*k)+3
void Display(vector<pair<int,int>> &hashTable, int hashSize)
{
	int count=0;
	for(int i=0; i<hashSize; ++i)
	{
		if(hashTable[i].second==-1)
			cout<<"At Index: "<<i<<" Empty\n";
		else
		{
			cout<<"At Index: "<<i<<" Key is:---->>> "<<hashTable[i].first<<endl;
			count+=hashTable[i].second;
		}
	}
	cout<<"Total Probing:->"<<count<<endl;

}
int main(int argc, char const *argv[])
{
	vector<int> keys={3,2,9,6,11,13,7,12};
	int hashSize=10,N=keys.size();
	vector<pair<int,int>> hashTable(10,pair<int,int>(-1,-1));
	for(int i=0; i<N; ++i)
	{
		int key=keys[i];
		int location=(hashFunction(key))%hashSize;
		if(hashTable[location].second==-1)
		{
			hashTable[location].first=key;
			hashTable[location].second=1;
		}
		else
		{
			int probe=1;
			for(int j=(location+1)%hashSize; ; j=((j+1)%hashSize))
			{
				probe++;
				if(hashTable[j].second==-1)
				{
					hashTable[j].first=key;
					hashTable[j].second=probe;
					break;
				}
			}
		}
	}
	Display(hashTable,hashSize);
	return 0;
}