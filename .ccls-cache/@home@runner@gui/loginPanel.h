#include <wx/wx.h>

class LoginPanel : public wxPanel {
public:
  LoginPanel(wxWindow *parent) : wxPanel(parent, wxID_ANY) {
    // Create text controls and other widgets here

    // Set a smaller size for the text controls
    wxSize textCtrlSize(25, -1); // Adjust the width as needed

    usernameCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, textCtrlSize);
    passwordCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, textCtrlSize, wxTE_PASSWORD);

    // Arrange them using a sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText* userName = new wxStaticText(this, wxID_ANY, "Username");
      userName->SetForegroundColour(wxColour(250, 246, 240));
    wxFont myFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    userName->SetFont(myFont);
    sizer->Add(userName, 0, wxALL | wxALIGN_CENTER, 15);
    sizer->Add(usernameCtrl, 0, wxEXPAND | wxALL, 15);
    wxStaticText* password = new wxStaticText(this, wxID_ANY, "Password");
    password->SetForegroundColour(wxColour(250, 246, 240));
    password->SetFont(myFont);
    sizer->Add(password, 0, wxALL | wxALIGN_CENTER, 15);
    sizer->Add(passwordCtrl, 0, wxEXPAND | wxALL, 15);
    //this->SetBackgroundColour(wxColor(85, 124, 85));

    submitButton = new wxButton(this, wxID_ANY, "Login");
    sizer->Add(submitButton, 0, wxALIGN_CENTER | wxTOP, 25);
    this->SetForegroundColour(wxColour(250, 246, 240));
    
    this->SetSizer(sizer);
  }

  wxString GetUsername() const { return usernameCtrl->GetValue(); }
  wxString GetPassword() const { return passwordCtrl->GetValue(); }
  wxButton *GetButton() { return submitButton; }
  
private:
  wxTextCtrl *usernameCtrl;
  wxTextCtrl *passwordCtrl;
  wxButton *submitButton;
};


