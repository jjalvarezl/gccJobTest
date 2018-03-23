#ifndef MAIN_H
#define MAIN_H
#include<iostream>
#include "MainView.h"
#include "ZlibManagement.h"
#include "InputPathDialog.h"

using namespace std;

class Main : public wxApp
{
    public:
        bool OnInit();
        virtual ~Main();
    protected:

    private:
};



#endif // MAIN_H
