/***************************************************************
 * Name:      JobTestingCodeBlocksMain.h
 * Purpose:   Defines Application Frame
 * Author:    jjalvarezl ()
 * Created:   2018-03-19
 * Copyright: jjalvarezl ()
 * License:
 **************************************************************/

#ifndef JOBTESTINGCODEBLOCKSMAIN_H
#define JOBTESTINGCODEBLOCKSMAIN_H



#include "JobTestingCodeBlocksApp.h"



#include "GUIDialog.h"

class JobTestingCodeBlocksDialog: public GUIDialog
{
    public:
        JobTestingCodeBlocksDialog(wxDialog *dlg);
        ~JobTestingCodeBlocksDialog();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};
#endif // JOBTESTINGCODEBLOCKSMAIN_H
