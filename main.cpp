/* Ksenia Fefilova
CSC 211H
Fall 2023
Professor Azhar
Honors project */

#include "contentPanelbuy.h"
#include "loginPanel.h"
#include "welcomePanel.h"
#include "contentPanelsell.h"
#include "aboutUsPanel.h"
#include "bookGridPanel.h"
#include "bookPurchasePanel.h"
#include "myPage.h"
#include <iostream>
#include <wx/sizer.h>
#include <wx/wx.h>
#include <wx/image.h>

using namespace std;

class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
  MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
  LoginPanel *loginPanel;
  ContentPanelbuy *contentPanelbuy;
  WelcomePanel *welcomePanel;
  ContentPanelsell *contentPanelsell;
  AboutUsPanel *aboutUsPanel;
  BookPurchasePanel *bookPurchasePanel;
  BookGridPanel *bookGridPanel;
  MyPage *myPage;
  wxButton *submitButton;
  
  // Functions for events
  void OnSubmitButtonClick(wxCommandEvent &event);
  void OnWelcomeButtonClick(wxCommandEvent &event);
  void OnBuyRentbuttonClick(wxCommandEvent &event);
  void OnSellLendbuttonClick(wxCommandEvent &event);
  void OnAboutUsbuttonClick(wxCommandEvent &event);
  void OnBookClicked(wxCommandEvent& event);
  void OnMyPagebuttonClick(wxCommandEvent& event);

  // Background image
  wxBitmap backgroundImage;
  void OnPaint(wxPaintEvent &event);

  wxDECLARE_EVENT_TABLE();

};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_PAINT(MyFrame::OnPaint)
    EVT_BUTTON(wxID_ANY, MyFrame::OnBookClicked)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  MyFrame *frame = new MyFrame("BMCC Book Swap Application",
  wxDefaultPosition, wxDefaultSize);
  frame->Show(true);
  return true;
}

//Constructor
MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size), 
  backgroundImage(wxT("background.jpeg"), wxBITMAP_TYPE_JPEG) {

  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

  // Welcome Page
  welcomePanel = new WelcomePanel(this);
  mainSizer->Add(welcomePanel, 1, wxEXPAND | wxALL, 5);

  // Login panel
  loginPanel = new LoginPanel(this);
  mainSizer->Add(loginPanel, 1, wxEXPAND | wxALL, 5);
  loginPanel->Hide();

  // Content panel Buy(initially hidden)
  contentPanelbuy = new ContentPanelbuy(this);
  mainSizer->Add(contentPanelbuy, 1, wxEXPAND | wxALL, 5);
  contentPanelbuy->Hide();

  // Content panel Sell(initially hidden)
  contentPanelsell = new ContentPanelsell(this);
  mainSizer->Add(contentPanelsell, 1, wxEXPAND | wxALL, 5);
  contentPanelsell->Hide();

  // About Us Panel
  aboutUsPanel = new AboutUsPanel(this);
  mainSizer->Add(aboutUsPanel, 1, wxEXPAND | wxALL, 5);
  aboutUsPanel->Hide();

  // Book Purchase Panel
  bookPurchasePanel = new BookPurchasePanel(this);
  mainSizer->Add(bookPurchasePanel, 1, wxEXPAND | wxALL, 5);
  bookPurchasePanel->Hide();

  // BookGrid Panel
  bookGridPanel = new BookGridPanel(this);
  mainSizer->Add(bookGridPanel, 1, wxEXPAND | wxALL, 5);
  bookGridPanel->Hide();

  // My Page
  myPage = new MyPage(this);
  mainSizer->Add(myPage, 1, wxEXPAND | wxALL, 5);
  myPage->Hide();

  // Set main sizer
  this->SetSizer(mainSizer);

  // Binding events
  loginPanel->GetButton()->Bind(wxEVT_BUTTON, 
     &MyFrame::OnSubmitButtonClick, this);

  welcomePanel->GetWelcomeButton()->Bind(wxEVT_BUTTON,
     &MyFrame::OnWelcomeButtonClick, this);

  contentPanelbuy->GetsellLendbutton()->Bind(wxEVT_BUTTON,
     &MyFrame::OnSellLendbuttonClick, this);

  contentPanelsell->GetbuyRentbutton()->Bind(wxEVT_BUTTON,
     &MyFrame::OnBuyRentbuttonClick, this);

  welcomePanel->GetAboutUsButton()->Bind(wxEVT_BUTTON,
     &MyFrame::OnAboutUsbuttonClick, this);

  contentPanelsell->GetAboutUsButton()->Bind(wxEVT_BUTTON,
     &MyFrame::OnAboutUsbuttonClick, this);

  contentPanelbuy->GetAboutUsButton()->Bind(wxEVT_BUTTON,
     &MyFrame::OnAboutUsbuttonClick, this);

  aboutUsPanel->GetbuyRentbutton()->Bind(wxEVT_BUTTON,
     &MyFrame::OnBuyRentbuttonClick, this);

  aboutUsPanel->GetsellLendbutton()->Bind(wxEVT_BUTTON,
     &MyFrame::OnSellLendbuttonClick, this);

  aboutUsPanel->GetWelcomeButton()->Bind(wxEVT_BUTTON,
     &MyFrame::OnWelcomeButtonClick, this);

  bookGridPanel->GetPurchaseButton()->Bind(wxEVT_BUTTON,
     &MyFrame::OnBookClicked, this);

  bookPurchasePanel->GetbuyRentbutton()->Bind(wxEVT_BUTTON, 
     &MyFrame::OnBuyRentbuttonClick, this);

  contentPanelbuy->GetmyPagebutton()->Bind(wxEVT_BUTTON,
      &MyFrame::OnMyPagebuttonClick, this);

  contentPanelsell->GetmyPagebutton()->Bind(wxEVT_BUTTON,
      &MyFrame::OnMyPagebuttonClick, this);

  bookPurchasePanel->GetmyPagebutton()->Bind(wxEVT_BUTTON,
      &MyFrame::OnMyPagebuttonClick, this);

  myPage->GetbuyRentbutton()->Bind(wxEVT_BUTTON,
      &MyFrame::OnBuyRentbuttonClick, this);

  myPage->GetsellLendbutton()->Bind(wxEVT_BUTTON,
    &MyFrame::OnSellLendbuttonClick, this);

  //Setting background
  this->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
  this->Bind(wxEVT_PAINT, &MyFrame::OnPaint, this);

}
// Drawing the background
void MyFrame::OnPaint(wxPaintEvent &event) {
    wxPaintDC dc(this);
    if (backgroundImage.IsOk()) {
        dc.DrawBitmap(backgroundImage, 0, 0, false);
    }
    event.Skip();
}
// Describing functions to show or hide certain panels
void MyFrame::OnSubmitButtonClick(wxCommandEvent &event) {
  loginPanel->Hide();
  contentPanelbuy->Show();
  this->Layout();
}

void MyFrame::OnWelcomeButtonClick(wxCommandEvent &event) {
  loginPanel->Show();
  contentPanelbuy->Hide();
  welcomePanel->Hide();
  aboutUsPanel->Hide();
  this->Layout();
}

void MyFrame::OnSellLendbuttonClick(wxCommandEvent &event) {
  loginPanel->Hide();
  contentPanelbuy->Hide();
  welcomePanel->Hide();
  bookPurchasePanel->Hide();
  contentPanelsell->Show();
  aboutUsPanel->Hide();
  myPage->Hide();
  this->Layout();
}

void MyFrame::OnBuyRentbuttonClick(wxCommandEvent &event) {
  loginPanel->Hide();
  contentPanelbuy->Show();
  welcomePanel->Hide();
  contentPanelsell->Hide();
  aboutUsPanel->Hide();
  bookPurchasePanel->Hide();
  myPage->Hide();
  this->Layout();
}

void MyFrame::OnAboutUsbuttonClick(wxCommandEvent &event) {
  loginPanel->Hide();
  contentPanelbuy->Hide();
  welcomePanel->Hide();
  contentPanelsell->Hide();
  bookPurchasePanel->Hide();
  aboutUsPanel->Show();
  myPage->Hide();
  this->Layout();
}

void MyFrame::OnBookClicked(wxCommandEvent& event) {
  bookGridPanel->Hide();
  loginPanel->Hide();
  contentPanelbuy->Hide();
  welcomePanel->Hide();
  contentPanelsell->Hide();
  aboutUsPanel->Hide();
  bookPurchasePanel->Show();
  myPage->Hide();
  this->Layout();
  this->Refresh();
}

void MyFrame::OnMyPagebuttonClick(wxCommandEvent& event) {
  bookGridPanel->Hide();
  loginPanel->Hide();
  contentPanelbuy->Hide();
  welcomePanel->Hide();
  contentPanelsell->Hide();
  aboutUsPanel->Hide();
  bookPurchasePanel->Hide();
  myPage->Show();
  this->Layout();
};

