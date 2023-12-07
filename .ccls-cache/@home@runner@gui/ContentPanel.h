#include <wx/wx.h>

class ContentPanel : public wxPanel {
public:
  ContentPanel(wxWindow *parent) : wxPanel(parent, wxID_ANY) {
    // Create text controls and other widgets here

    // Arrange them using a sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    this->SetBackgroundColour(*wxGREEN);

    sizer->Add(new wxStaticText(contentPanel, wxID_ANY, "Content Page!"), 0,
               wxALL | wxALIGN_CENTER, 5);

    this->SetSizer(sizer);
  }
};