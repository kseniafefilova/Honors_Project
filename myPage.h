#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>

class MyPage : public wxPanel {
public:
        MyPage(wxWindow *parent) : wxPanel(parent, wxID_ANY) {

        // Main sizer
        wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
        
        wxStaticText* myPageText = new wxStaticText(this, wxID_ANY, "My Page");
        myPageText->SetForegroundColour(wxColour(250, 246, 240));
        wxFont myFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        myPageText->SetFont(myFont);
        sizer->Add(myPageText, 0, wxALL | wxALIGN_CENTER, 5);
        
        // Horizontal sizer for buttons
        wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
        sellLendbutton = new wxButton(this, wxID_ANY, "Sell/Lend");
        buttonSizer->Add(sellLendbutton, 0,  wxTOP | wxRIGHT, 5);
        buttonSizer->AddSpacer(700);
        buyRentbutton = new wxButton(this, wxID_ANY, "Buy/Rent");
        buttonSizer->Add(buyRentbutton, 0, wxTOP | wxLEFT, 5);

        sizer->Add(buttonSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);
        wxFont myTextFont(14, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
        // User's bookshelf
        wxStaticText* bookshelf = new wxStaticText(this, wxID_ANY, "My Bookshelf");
        bookshelf->SetFont(myTextFont);
        bookshelf->SetForegroundColour(wxColour(250, 246, 240));
                  bookshelfListCtrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
        bookshelfListCtrl->InsertColumn(0, "Title", wxLIST_FORMAT_LEFT, 150);
        bookshelfListCtrl->InsertColumn(1, "Author", wxLIST_FORMAT_LEFT, 120);
        bookshelfListCtrl->InsertColumn(2, "Status", wxLIST_FORMAT_LEFT, 80);

        // User's notifications
        wxStaticText* notifications = new wxStaticText(this, wxID_ANY, "Notifications");
        notificationsTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
        notifications->SetFont(myTextFont);
        notifications->SetForegroundColour(wxColour(250, 246, 240));

        // User's activity
        wxStaticText* userActivity = new wxStaticText(this, wxID_ANY, "User Activity");
        userActivityListCtrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
        userActivity->SetFont(myTextFont);
        userActivity->SetForegroundColour(wxColour(250, 246, 240));
        userActivityListCtrl->InsertColumn(0, "Action", wxLIST_FORMAT_LEFT, 120);
        userActivityListCtrl->InsertColumn(1, "Book Title", wxLIST_FORMAT_LEFT, 150);
        userActivityListCtrl->InsertColumn(2, "Timestamp", wxLIST_FORMAT_LEFT, 120);

        // Adding everything to the sizer
        sizer->Add(bookshelf, 0, wxALL, 5);
        sizer->Add(bookshelfListCtrl, 1, wxEXPAND | wxALL, 5);
        sizer->Add(notifications, 0, wxALL, 5);
        sizer->Add(notificationsTextCtrl, 1, wxEXPAND | wxALL, 5);
        sizer->Add(userActivity, 0, wxALL, 5);
        sizer->Add(userActivityListCtrl, 1, wxEXPAND | wxALL, 5);
         
        this->SetSizer(sizer);
    }

    wxButton *GetbuyRentbutton() { return buyRentbutton; }
    wxButton *GetsellLendbutton() { return sellLendbutton; }

private:
    wxButton *buyRentbutton;
    wxButton *sellLendbutton;
    wxListCtrl* bookshelfListCtrl;
    wxTextCtrl* notificationsTextCtrl;
    wxListCtrl* userActivityListCtrl;
};
