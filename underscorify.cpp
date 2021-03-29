#include<vector>
#include<iostream>
#include<numeric>
using namespace std;
string underscorifySub(string s,string substring);
vector<vector<int>> collapse(vector<vector<int>> locations);
vector<vector<int>> getLocations(string s,string substring);
string underscorify(string s, vector<vector<int>> locations);

int main()
{
	string s;
	cout<<"enter string"<<endl;
	cin>>s;
	string substring;
	cout<<"enter sub string"<<endl;
	cin>>substring;
	string ans=underscorifySub(s,substring);
	cout<<ans<<endl;
	return 0;	
	
}

string underscorifySub(string s,string substring)
{	
	vector<vector<int>> locations=collapse(getLocations(s,substring));
	return underscorify(s,locations);
}

vector<vector<int>> getLocations(string s, string substring)
{
	vector<vector<int>> locations{};
	int start=0;
	while(start<s.length())
	{
		int next=s.find(substring,start);
		if(next!=string::npos)
		{
			locations.push_back(vector<int>{next,int(next+substring.length())});
			start=next+1;
		}
		else
		{
			break;
		}
	}
	return locations;
}

vector<vector<int>> collapse(vector<vector<int>> locations)
{
	if(locations.empty())
	{
		return locations;
	}
	vector<vector<int>> newlocations{locations[0]};
	vector<int> *previous=&locations[0];
	for(int i=1;i<locations.size();i++)
	{
		vector<int> *current=&locations[i];
		if(current->at(1)<=previous->at(1))
		{
			previous->at(1)=current->at(1);
		}
		else
		{
			newlocations.push_back(*current);
			previous=&newlocations[newlocations.size()-1];
		}
	}
	return newlocations;
}

string underscorify(string str, vector<vector<int>> locations) {
int locationsIdx = 0;
int stringIdx = 0;
bool inBetweenUnderscores = false;
vector<string> finalChars{};
int i = 0;
while (stringIdx < str.length() && locationsIdx < locations.size()) {
if (stringIdx == locations[locationsIdx][i]) {
finalChars.push_back("_");
inBetweenUnderscores = !inBetweenUnderscores;
if (!inBetweenUnderscores) {
locationsIdx++;
}
i = i == 1 ? 0 : 1;
}
string s(1, str[stringIdx]);
finalChars.push_back(s);
stringIdx++;
}
if (locationsIdx < locations.size()) {
finalChars.push_back("_");
} else if (stringIdx < str.length()) {
finalChars.push_back(str.substr(stringIdx));
}
return accumulate(finalChars.begin(), finalChars.end(), string());
}








