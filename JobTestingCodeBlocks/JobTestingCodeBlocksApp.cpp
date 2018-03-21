/***************************************************************
 * Name:      JobTestingCodeBlocksApp.cpp
 * Purpose:   Code for Application Class
 * Author:    jjalvarezl ()
 * Created:   2018-03-19
 * Copyright: jjalvarezl ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "JobTestingCodeBlocksApp.h"
#include "JobTestingCodeBlocksMain.h"

IMPLEMENT_APP(JobTestingCodeBlocksApp);

bool JobTestingCodeBlocksApp::OnInit()
{
    
    JobTestingCodeBlocksDialog* dlg = new JobTestingCodeBlocksDialog(0L);
    
    dlg->Show();
    return true;
}
