#include <iostream>
#include <string>
using namespace std;


void RemoveDuplicatedChar (std::string &strIn)
{

    for( auto i = 0 ; i < strIn.size() ; ++i)
    {
        while (  i != strIn.find_last_of(strIn[i]) )
        {
            int tmpInt = strIn.find_last_of(strIn[i])-1;
            //cout <<tmpInt<<endl;
            strIn.erase( tmpInt, 1 );
            //cout <<strIn<<endl;
        }
    }
   
}

void Replace( char* szIn, const char cFindInString, const char cReplace )
{
    if(szIn)
    {
        for( int i = 0 ;  szIn[i] != '\0' ; ++i )
        {
            if(cFindInString == szIn[i])
                szIn[i] = cReplace;
        }
    }
}

int FindFirstNotMatch(const char* szIn, char cTarget)
{
    if(szIn)
    {
        for( auto i = 0 ;  szIn[i] != '\0'; ++i )
        {
            if( szIn[i] != cTarget )
                return i;
        }
    }
    
    return -1;
}

int GetLength(const char* szIn)
{
    if( szIn == NULL )
        return -1;

    int counter = 0;
    
    while(szIn[counter] != '\0')
    {
        ++counter;
    }

    return counter;
}

int RemoveDupChar_cstyle ( char* szIn )
{
    
    int length = GetLength(szIn);
    if( length <= 1 )
        return 0;
        
    const char cFirst = szIn[0];
    char temp = '0';
    
    int i = 1;
    
    while( szIn[i] != '\0')
    {
        int index = FindFirstNotMatch(&szIn[i], cFirst);
        
        if( index < 0 )
        {
            break;
        }
        else
        {
            temp = szIn[i+index];
            Replace(&szIn[i], temp, cFirst);
            szIn[i] = temp;
        }
        
        ++i;
    }
    
    szIn[i] = '\0';
    
    return 0;
}

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
