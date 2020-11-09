#include<bits/stdc++.h>
using namespace std;
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();
double maximumExpectedMoney(int n, int m, double p[], double x[], double y[] )
{
    vector<double> ans;
    for(int i=0;i<n;i++)
    {
        double diff = ((p[i]*x[i])-((1-p[i])*y[i]));
        ans.push_back(diff); 
    }
    sort(ans.begin(),ans.end(),greater<double>());
    double sum = 0;
    for(int i=0;i<m;i++)
    {
        sum = max(sum,sum+ans[i]);
    }
    return sum;
    
}


int main(){
    int n, m;
    cin>>n>> m;
    double p[n], x[n], y[n];

    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n; i++)
        cin >> y[i];
    double result=maximumExpectedMoney(n,m,p,x,y);
    cout <<setprecision(2)<<fixed<<result<< endl;
    return 0;
}
