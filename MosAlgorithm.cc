// https://practice.geeksforgeeks.org/problems/interesting-queries/0

// Mo's Algorithm

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,q,K,maxe=0,blocksize;
        cin>>n>>q>>K;
        vector<int> arr(n,0);
        blocksize=ceil((float)sqrt(n));
        if(blocksize==0)
            blocksize=1;
        vector<vector<int> > queries(q,vector<int>(3,0));
        vector<int> ans(q,0);
        for(int i=0; i<n; ++i)
        {
            cin>>arr[i];
            maxe=max(maxe,arr[i]);
        }
        vector<int> freq(maxe+1,0);    
        for(int i=0; i<q; ++i)
        {
            cin>>queries[i][0]>>queries[i][1];
            queries[i][2]=i;
        }
        sort(queries.begin(),queries.end(),[&](vector<int> a,vector<int> b){
            if((a[0]/blocksize)==(b[0]/blocksize))
                return a[1]<b[1];
            return (a[0]/blocksize)<(b[0]/blocksize);
        });
        int start=0,end=0,count=0;
        for(int i=0; i<q; ++i)
        {
            int currx=queries[i][0]-1,curry=queries[i][1]-1;
            while(start<currx)
            {
                freq[arr[start]]--;
                if(freq[arr[start]]==K-1)
                    count--;
                start++;
            }
            while(start>currx)
            {
                freq[arr[start-1]]++;
                if(freq[arr[start-1]]==K)
                    count++;
                start--;
            }
            while(end<=curry)
            {
                freq[arr[end]]++;
                if(freq[arr[end]]==K)
                    count++;
                end++;
            }
            while(end>curry+1)
            {
                freq[arr[end-1]]--;
                if(freq[arr[end-1]]==K-1)
                    count--;
                end--;
            }
            ans[queries[i][2]]=count;
        }
        for(int i=0; i<q; ++i)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
	return 0;
}