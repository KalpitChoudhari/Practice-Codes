#include <bits/stdc++.h>
#include <vector>
using namespace std;
int

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string res_S;
        string res_T;
        int T_C = 1;
        int S_C = 1;
        for(char s : S) {
            if(s == '#' && S_C != 1 && res_S != "")
                res_S.pop_back();
            else if(s != '#'){
            	res_S.push_back(s);
        	S_C = 0;
        }
        }
        for(char s1 : T) {
            if(s1 == '#' && T_C != 1 && res_T != "") {
                res_T.pop_back();
            }
            else if(s1 != '#'){
            	res_T.push_back(s1);
       		T_C = 0;
       	}
       	}
        if(res_S.compare(res_T) == 0)
            return true;
        return false;
    }
}; main()
{
	Solution S;
	cout<<S.backspaceCompare("a##c", "#a#c");
	return 0;
}
