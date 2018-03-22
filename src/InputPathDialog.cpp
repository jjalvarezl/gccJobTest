#include "InputPathDialog.h"

InputPathDialog::InputPathDialog(const wxString& title) : wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 150), wxDEFAULT_DIALOG_STYLE)
{
    wxBoxSizer* boxSizerMain = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizerMain);

    staticTextInfo = new wxStaticText(this, wxID_ANY, wxT("Por favor ingrese la ruta del archivo .zip \n\n Cuando acepte espera un poco mientras carga el archivo en la aplicación."), wxDefaultPosition, wxSize(200,50) , wxALIGN_CENTRE);

    boxSizerMain->Add(staticTextInfo, 0, wxEXPAND);

    textCtrlZipPath = new wxTextCtrl(this, wxID_ANY, wxT("/etc/Aranda/Aranda Agent 9/Aranda.zip"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    #if wxVERSION_NUMBER >= 3000
    textCtrlZipPath->SetHint(wxT("Escriba la ruta absoluta al archivo .zip"));
    #endif

    boxSizerMain->Add(textCtrlZipPath, 0, wxEXPAND);

    wxBoxSizer* boxSizerButtons = new wxBoxSizer(wxHORIZONTAL);

    boxSizerMain->Add(boxSizerButtons, 1, wxALIGN_RIGHT);

    buttonAccept = new wxButton(this, wxID_ANY, _("Aceptar"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);

    boxSizerButtons->Add(buttonAccept, 0, wxEXPAND);

    buttonCancel = new wxButton(this, wxID_ANY, _("Cancelar"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);

    boxSizerButtons->Add(buttonCancel, 0, wxEXPAND);

    SetName(wxT("getInputBase"));
    /*SetSize(500,175);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }*/
/*#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif*/
    // Connect events
    buttonAccept->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InputPathDialog::acceptButtonEvent), NULL, this);
    buttonCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InputPathDialog::cancelButtonEvent), NULL, this);

}

InputPathDialog::~InputPathDialog()
{
    //dtor
}

void InputPathDialog::acceptButtonEvent(wxCommandEvent& event){
    //wxMessageBox( wxT("Aceptar Presionado"), wxT("HOLA MUNDO"), wxICON_INFORMATION);


    //staticTextInfo = new wxStaticText(this, wxID_ANY, _("Por favot espere."), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxALIGN_CENTRE);

    ZlibManagement::getInstance()->setCompressedFilePath(new std::string("/etc/Aranda/Aranda Agent 9/Aranda.zip"));
    ZlibManagement::getInstance()->uncompressFile();

    this->Show(false);

    MainView *mainView = new MainView(wxT("Job Test Solution"));
    mainView->Show(true);
}

void InputPathDialog::cancelButtonEvent(wxCommandEvent& event){
    exit(0);
}

//Getters and setters
wxStaticText* InputPathDialog::getStaticTextInfo(){
    return this->staticTextInfo;
}

void InputPathDialog::setStaticTextInfo(wxStaticText* staticTextInfo){
}

wxTextCtrl* InputPathDialog::getTextCtrlZipPath (){
    return this->textCtrlZipPath;
}
void InputPathDialog::setTextCtrlZipPath(wxTextCtrl* textCtrlZipPath){
}

wxButton* InputPathDialog::getButtonAccept(){
    return this->buttonAccept;
}
void InputPathDialog::setButtonAccept(wxButton* buttonAccept){
}

wxButton* InputPathDialog::getButtonCancel(){
    return this->buttonCancel;
}
void InputPathDialog::setButtonCancel(wxButton* buttonCancel){
}
