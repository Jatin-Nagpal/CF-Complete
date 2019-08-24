#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <iomanip>
#define ff first
#define ss second
using namespace std;
#include <queue>
#define ll long long
#define f(i,x,n) for(int i=x;i<n;i++)
int b[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a;
    f(i,0,n)
    {
        cin>>a;
        b[a+100000]++;
    }
    int ans=0;
    f(i,0,200002)
    {
        if(b[i]>0&&i!=100000)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}