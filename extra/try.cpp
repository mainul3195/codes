#include <bits/stdc++.h>
using namespace std;

string findLargestMultipleOfThree(vector<int>& digits) {
    int sum = 0;
    sort(digits.rbegin(), digits.rend());
    for(int i: digits)
        sum = (sum+i)%3;
    if(sum == 0)
    {
        string s = "";
        for(auto i: digits)
            s += (char)(i+'0');
        reverse(s.begin(), s.end());
        while(s.size() && (s.back() == '0'))
            s.pop_back();
        if(s.size() == 0)
            s.push_back('0');
        reverse(s.begin(), s.end());
        return s;
    }
    else if(sum == 1)
    {
        int banned = -1;
        for(int i = digits.size()-1; i>=0; i--)
            if((digits[i]%3) == 1)
            {
                banned = i;
                break;
            }
        if(banned != -1)
        {
            string s = "";
            for(int i = 0; i<digits.size(); i++)
                if(i!=banned)
                    s+= (char)(digits[i]+'0');
            reverse(s.begin(), s.end());
            while(s.size() &&(s.back() == '0'))
                s.pop_back();
            if(s.size() == 0)
                s.push_back('0');
            reverse(s.begin(), s.end());
            return s;
        }
        else
        {
            int b1 = -1, b2 = -1;
            for(int i = digits.size()-1; i>=0; i--)
            {
                if((digits[i]%3) == 2)
                {
                    if(b1 == -1)
                        b1 = i;
                    else if(b2 == -1)
                        b2 = i;
                }
                if(b2 != -1)
                    break;
            }
            string s = "";
            for(int i = 0; i<digits.size(); i++)
                if((i!=b1) && (i!=b2))
                    s+=(char)(digits[i]+'0');
            reverse(s.begin(), s.end());
            while(s.size() && (s.back() == '0'))
                s.pop_back();
            if(s.size() == 0)
                s.push_back('0');
            reverse(s.begin(), s.end());
            return s;
        }
    }
    else
    {
        int banned = -1;
        for(int i = digits.size()-1; i>=0; i--)
        {
            if((digits[i]%3) == 2)
            {
                banned = i;
                break;
            }
        }
        if(banned != -1)
        {
            string s = "";
            for(int i = 0; i<digits.size(); i++)
                if(i!=banned)
                    s+=(digits[i]+'0');
            reverse(s.begin(), s.end());
            while(s.size() && (s.back() == '0'))
                s.pop_back();
            if(s.size() == 0)
                s.push_back('0');
            reverse(s.begin(), s.end());
            return s;
        }
        else
        {
            int b1 = -1, b2 = -1;
            for(int i = digits.size()-1; i>=0; i--)
            {
                if((digits[i]%3) == 1)
                {
                    if(b1 == -1)
                        b1 = i;
                    else if(b2 == -1)
                        b2 = i;
                }
                if(b2 != -1)
                    break;
            }
            string s = "";
            for(int i = 0; i<digits.size(); i++)
                if((i!=b1) && (i!=b2))
                    s+=(digits[i]+'0');
            reverse(s.begin(), s.end());
            while(s.size() &&(s.back() == '0'))
                s.pop_back();
            if(s.size() == 0)
                s.push_back('0');
            reverse(s.begin(), s.end());
            return s;
        }
    }
    return "";
}

int main() {
        vector<int> digits1 = {1, 0, 1, 0, 0, 1, 0,0, 0, 0, 0, 0, 0, 0};
    cout << findLargestMultipleOfThree(digits1) << endl;

   // vector<int> digits1 = {8, 6, 7, 1, 0};
   // cout << findLargestMultipleOfThree(digits1) << endl; // Output: "8760"

   // vector<int> digits2 = {2, 1, 2, 1, 1};
   // cout << findLargestMultipleOfThree(digits2) << endl; // Output: "2211"

   // vector<int> digits3 = {0, 1, 2};
   // cout << findLargestMultipleOfThree(digits3) << endl; // Output: "210"

    return 0;
}
