#include <iostream>
#include <string>
#include "hw_1_3.h"

using namespace std;


int main()
{
   string strIn = "aabccccccccfffffffggggwee";
   char szIn[]  = "bbbbbnnnnnnnoussssssss tiiiiiiiimmmmmmmme";
   char szEmpty[] = "";
   
   
   cout << "Before removing : " << szIn << endl;

   
   // RemoveDuplicatedChar(strIn);
   RemoveDupChar_cstyle(szIn);
   
   cout << "After removing : " << szIn << endl;
   
   return 0;
}
