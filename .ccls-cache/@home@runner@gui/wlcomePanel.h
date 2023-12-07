#include <wx/wx.h>

class WelcomePanel : public wxPanel {
public:
  WelcomePanelwxWindow *parent) : wxPanel(parent, wxID_ANY) {
    // Create text controls and other widgets here
    usernameCtrl = new wxTextCtrl(this, wxID_ANY);
    passwordCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition,
                                  wxDefaultSize, wxTE_PASSWORD);

    // Arrange them using a sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(usernameCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(passwordCtrl, 0, wxEXPAND | wxALL, 5);

    submitButton = new wxButton(this, wxID_ANY, "Submit");
    sizer->Add(submitButton, 0, wxALIGN_CENTER | wxALL, 5);

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