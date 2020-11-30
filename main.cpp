#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "func.h"

using namespace std;


char* Change (char *str)
{
    if (strlen (str) < 5)
        return str;
    char *tmp = new char[strlen (str) * 2 / 5 + 1];
    char *t = tmp;
    tmp[0] = '\0';
    int i = 0;
    while (str[i + 2] != 0)
    {
        if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e')
        {
            strcat (t, "**");
            t += 2;
            i += 5;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';
    strcpy (str, tmp);
    return tmp;
}

int main ()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline (str, 100);
    cout << "String contained " << Check(str) << "'while'" << endl;
    char *dest = new char[151];
    dest = Change (str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}