#include <iostream>
using namespace std;

int main()

     {
         int T;
         cin >> T;
         while (T--)
         {
             int X, Y;
             cin >> X >> Y;
             int i = X * Y;
             if (i <= 500 && X<= 8)
             {
                 cout << "Yes" << endl;
             } 
             else { 
                 
               cout << "No" << endl;
               
                  }
          }
               return 0;
          }