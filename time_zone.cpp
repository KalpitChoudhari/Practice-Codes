#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
       string str;
    string hr, min, sec, zone;
    int hour, minutes, seconds;
    int i = 0;
    hr = s.substr(0,2);
    zone = s.substr(s.size()-2);
    str = s.substr(0, 8);   
    for(int i=3;i<(s.size()-2);i++)
    {
        str[i] = s[i];
    }
  
    if(zone == "PM" && hr != "12")
    {
        hour = stoi(hr);
        hour = (hour + 12) % 24;
        
        stringstream ss;
        ss << hour;
        str[0] = ss.str()[0];
        str[1] = ss.str()[1];
    }
    else if(zone == "AM" && hr == "12")
    {
        str[0] = str[1] = '0';
    }
   return str;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

