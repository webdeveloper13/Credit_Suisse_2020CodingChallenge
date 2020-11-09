#include<bits/stdc++.h>
using namespace std;
string find_min_days(vector<int> profit, vector<int> price)
{
	//Participants code will be here
	int n = price.size();
	int d = profit.size();
	string pro = "";
	//vector<vector<int>> ans;
	unordered_map<int,vector<int>> ans;
	
	for(int i=0;i<d;i++)
	{
		int find = profit[i];
		vector<int> temp;
		int flag = 0;
		for(int j=0;j<n-1;j++)
		{
			int search = find+price[j];
			for(int k=j+1;k<n;k++)
			{
				if(search==price[k])
				{
					flag = 1;
					if(temp.size()==0)
					{
						temp.push_back(j+1);
						temp.push_back(k+1);
					}

					else
					{
						if(temp[1]>k+1 || ((temp[1]==k+1) && (temp[1]-temp[0]>k-j)))
						{
							temp.clear();
							temp.push_back(j+1);
							temp.push_back(k+1);
						}
					}
				}
			}



		}

		if(flag==0)
		{
			ans[i].push_back(-1);
		}

		else
		{
			ans[i].push_back(temp[0]);
			ans[i].push_back(temp[1]);
			temp.clear();
		}

		
	}

	for(int i=0;i<d-1;i++)
	{
		vector<int> v1 = ans[i];
		if(v1.size()==1)
		{
			pro += to_string(-1);
			pro += ',';

		}

		else
		{
			pro += to_string(v1[0]);
			pro += " ";
			pro += to_string(v1[1]);
			pro += ',';
		}
	}

	vector<int> v2 = ans[d-1];
	if(v2.size()==1)
	{
			pro += to_string(-1);
			//pro += ',';

	}

	else
	{
		pro += to_string(v2[0]);
		pro += " ";
		pro += to_string(v2[1]);
		//pro += ',';
	}

	return pro;

}

int main ()
{
	int n,d,i;
	string answer="";
	cin>>n>>d;
	vector<int> price(n,0);
	vector<int> profit(d,0);
	for(i=0;i<n;i++)
	{
		cin>>price[i];
	}
	for (i=0;i<d;i++)
	{
		cin>>profit[i];
	}
    answer = find_min_days(profit,price);

    // Do not remove below line
	cout<<answer<<endl;
    // Do not print anything after this line
	return 0;
}