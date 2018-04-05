#include<bits/stdc++.h>
using namespace std;
int finding(vector<int> a,int k)
{
   int ret=0;
   for(int i=0;i<k;i++)
      ret+=a[i];
   return ret;
}

int fact(int k)
{
    if(k==0||k==1)
        return 1;
    return k*fact(k-1);
}

int main()
{
    vector<int> a(26,0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        a[int(c)-int('a')]=1;
    }
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int place=finding(a,int(s[i]-'a'));
        ans=ans+(place*fact(n-i-1));
        a[int(s[i]-'a')]=0;
    }
    cout<<ans+1;
    return 0;
}

