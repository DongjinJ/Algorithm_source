#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(string &str1, string &str2){
    if(str1.size() == str2.size()){
        return str1 < str2;
    }
    return str1.size() < str2.size();
}

int main(){
    int N;
    scanf("%d", &N);

    vector<string> str;
    string temp;

    for(int i = 0;i < N;i++){
        cin >> temp;
        str.push_back(temp);
    }

    sort(str.begin(), str.end(), comp);

    vector<string>::iterator iter;
    vector<string>::iterator end_iter;

    end_iter = unique(str.begin(), str.end());

    for(iter = str.begin();iter != end_iter;iter++)
        cout << *iter << endl;


    return 0;
}