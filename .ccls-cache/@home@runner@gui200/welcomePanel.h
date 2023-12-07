#include <wx/wx.h>

class WelcomePanel : public wxPanel {
public:
    WelcomePanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
        
        // Main sizer
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        
        wxStaticText* titleText = new wxStaticText(this, wxID_ANY, "BMCC BOOK SWAP");
        wxStaticText* subTitleText = new wxStaticText(this, wxID_ANY, "Small changes for a big future");

        this->SetForegroundColour(wxColour(250, 246, 240));
        wxFont myFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        titleText->SetFont(myFont);

        // Center text both horizontally and vertically
        sizer->Add(titleText, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxTOP, 100);
        sizer->Add(subTitleText, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxBOTTOM | wxTOP, 10);

        // Creating 2 buttons and adding them to the sizer
        welcomeButton = new wxButton(this, wxID_ANY, "Click this Button to login and save the Earth");
        aboutUs = new wxButton(this, wxID_ANY, "About Us");
        sizer->Add(welcomeButton, 0, wxALIGN_CENTER | wxTOP, 10);

        // Spacer to push aboutUs button to the bottom
        sizer->AddStretchSpacer();
        sizer->Add(aboutUs, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 10);

        this->SetSizer(sizer);
    }

    wxButton* GetWelcomeButton() { return welcomeButton; }
    wxButton* GetAboutUsButton() { return aboutUs; }

private:
    wxButton* welcomeButton;
    wxButton* aboutUs;
};
