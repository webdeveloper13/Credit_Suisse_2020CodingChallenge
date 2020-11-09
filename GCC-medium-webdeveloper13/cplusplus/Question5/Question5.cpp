#include <bits/stdc++.h>

using namespace std;
long int calculateMinimumSession(long int numOfBankers, long int numOfParticipants, vector<vector<long int>> bankersPreferences, vector<vector<long int>> participantsPreferences) {
    // Participant's code will go here
    
    unordered_map<long int,set<long int>> um1;
    long int m = numOfBankers;
    long int o = 1;

    for(auto v1:bankersPreferences)
    {
        for(auto e:v1)
        {
            um1[o].insert(e);
        }

        o++;
    }
    long int p = 1;
    for(auto v1:participantsPreferences)
    {
        for(auto e:v1)
        {
            um1[e].insert(p);
        }
        p++;
    }
    
    /*for(auto it:um1)
    {
        cout<<it.first<<" ";
        set<long int> v1 = it.second;
        for(auto e:v1)
        {
            cout<<e<<" ";
        }

        cout<<"\n";
    }*/
    
    long int ans = 0;
    //long int a = 2;
    vector<bool> v2(numOfParticipants,1);
      while(!um1.empty())
      {
        map<long int,set<long int>> um2;
        for(auto it:um1)
        {
            um2.insert({it.first,it.second});
        }
        for(auto it=um2.begin();it!=um2.end();it++)
        {
            long int key = it->first;
            set<long int> s1 = it->second;
            auto it1 = s1.end();
            it1--;
            long int k = *it1;
            if(v2[k-1]==1)
            {
                v2[k-1] = 0;
                s1.erase(it1);
                if(s1.empty())
                {
                    um1.erase(key);
                }
                else
                {
                    um1[key] = s1;
                }

                if(um1.empty())
                {
                    break;
                }
                
            }
        }

        ans++;
        long int l = v2.size();
        for(long int i=0;i<l;i++)
        {
            v2[i] = 1;
        }

        if(um1.empty())
        {
            break;
        }
    }
    return ans;
}

vector<string> split(const string& str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

vector<long int> splitStringToInt(const string& str, char delim) {
    vector<long int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<long int> vec) {
    for (vector<long int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

void printVector(vector<string> vec) {
    for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    long int numOfBankers, numOfParticipants;
    vector<vector<long int>> bankersPreferences, participantsPreferences;

    cin >> numOfBankers;

    string bankersPreferencesStr;
    cin >> bankersPreferencesStr;
    vector<string> bankersPreferencesVecByComma = split(bankersPreferencesStr, ',');

    for (vector<string>::const_iterator i = bankersPreferencesVecByComma.begin(); i != bankersPreferencesVecByComma.end(); ++i) {
        vector<long int> bankerPreferenceVecByAnd = splitStringToInt(*i, '&');
        bankersPreferences.push_back(bankerPreferenceVecByAnd);
    }

    string participantsPreferencesStr;
    cin >> numOfParticipants;
    cin >> participantsPreferencesStr;
    vector<string> participantsPreferencesVecByComma = split(participantsPreferencesStr, ',');

    for (vector<string>::const_iterator i = participantsPreferencesVecByComma.begin(); i != participantsPreferencesVecByComma.end(); ++i) {
        vector<long int> participantPreferenceVecByAnd = splitStringToInt(*i, '&');
        participantsPreferences.push_back(participantPreferenceVecByAnd);
    }

    long int result = calculateMinimumSession(numOfBankers, numOfParticipants, bankersPreferences, participantsPreferences);

    // Do not remove below line
    cout << result << "\n";
    // Do not prlong int anything after this line

    return 0;
}