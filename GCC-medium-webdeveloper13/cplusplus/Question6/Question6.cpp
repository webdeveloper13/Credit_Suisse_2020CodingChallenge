#include <bits/stdc++.h>
using namespace std;

string removeSpaces(string s)  
{ 
    s.erase(remove(s.begin(), s.end(), ' '), s.end()); 
    return s; 
} 


string encrypt(string words) {
    // Participant's code will go here
    //string answer = "demo";
    words = removeSpaces(words);
    int x = words.size();
    int m = floor(sqrt(x));
    int n = ceil(sqrt(x));
    if(m*n<x)
    {
    	if(m<n)
    	{
    		m = m+1;
    	}

    	else
    	{
    		n = n+1;
    	}
    }
	vector<vector<char>> v1(m,vector<char>(n,'0'));
	int y = 0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			//y++;
			if(y>=x)
			{
				break;
			}

			v1[i][j] = words[y++];

		}
	}

	string answer = "";
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<m;i++)
		{
			if(v1[i][j]=='0')
			{
				continue;
			}
			answer += v1[i][j];
		}

		answer += " ";
	}


    return answer;
}


int main() {
    string words;
    getline(cin, words);

    string result = encrypt(words);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}