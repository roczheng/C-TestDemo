#include <iostream>
#include "string"
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

void trim(string &s)
 {
     int index = 0;
     if( !s.empty())
     {
        while((index = s.find(' ',index)) != string::npos)
        {
            s.erase(index,1);
        }
    }
    return s;
}

vector<string> split(string str,string pattern)
{
  string::size_type pos;
  vector<string> result;
  str += pattern;
  int size = str.size();

  for(int i = 0; i < size; i++)
  {
    pos = str.find(pattern,i);
    if(pos < size)
    {
      string s = str.substr(i,pos - i);
      if(s != " ")
      {
          result.push_back(s);
      }

      i = pos + pattern.size() - 1;
    }
  }
    trim(result[result.size()-1]);
  return result;
}


int main()
{
    string str1 = "helloworld";
    string str2 = " hello     world ";
    vector<string> strv = split(str2," ");
    int i = 0;
    for(vector<string>::iterator itor = strv.begin();itor < strv.end();itor++,i++)
    {
        if(trim(*itor) == "")
            continue;
        cout << *itor << i << endl;
    }
    trim(str2);
    cout << str2 << endl;
    if(str1.find(str2) != 0)
    {
        cout << "Hello world!" << endl;
    }
    else
    {
        cout << "hello" << endl;
    }

    return 0;
}
