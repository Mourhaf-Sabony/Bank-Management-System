#pragma once
#include <iostream>

using namespace std;

class clsScreen
{
protected:

    static void _draw_screen_header(string title, string sub_title = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << title;
        if (sub_title != "")
        {
            cout << "\n\t\t\t\t\t  " << sub_title;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
    }
};

