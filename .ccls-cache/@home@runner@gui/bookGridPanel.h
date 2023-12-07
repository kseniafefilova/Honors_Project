#ifndef BOOK_GRID_PANEL_H
#define BOOK_GRID_PANEL_H
#include "book.h"
#include <vector>
#include <wx/generic/gridctrl.h>
#include <wx/grid.h>
#include <wx/image.h>
#include <wx/sizer.h>
#include <wx/wx.h>
using namespace std;

class BookGridPanel : public wxPanel {
public:
  BookGridPanel(wxWindow *parent);
  wxButton* purchase_button() { return purchase_button; }

  vector<Book> books{
      Book{"Digital Design, with an introduction to the Verilog HDL, VHDL and "
           "system Verilog",
           "Morris Mano, Michael Ciletti", "CSC215", "boo.jpg"},
      Book{"Introduction To MIPS Assembly Language Programming",
           "Charles W. Kann", "CSC215", "boo.jpg"},
      Book{"Discrete Mathematics and Its Applications, 7th Edition",
           "Kenneth H. Rosen", "CSC231", "boo.jpg"},
      Book{"Starting Out with C++", "Tony Gaddis", "CSC211",
           "boo.jpg"},
      Book{"Physics for scientists and engineers", "Douglas C. Giancoli",
           "PHY215", "boo.jpg"},
      Book{"The Advanced Reading-Writing Connection", "John Langan", "CRT100",
           "boo.jpg"}};

private:
  void CreateImageGrid();
  wxButton* purchase_button;
};

BookGridPanel::BookGridPanel(wxWindow *parent) : wxPanel(parent, wxID_ANY) {
  // Create and set up the image grid
  CreateImageGrid();

}

void BookGridPanel::CreateImageGrid() {
  wxGridSizer *gridSizer =
      new wxGridSizer(2, 3, 15, 15); // 2x3 grid with 15-pixel padding

  for (Book book : books) {
    string imagePath = book.GetImageName();

    wxStaticBitmap *bitmap = new wxStaticBitmap(
        this, wxID_ANY, wxBitmap(imagePath, wxBITMAP_TYPE_JPEG),
    wxDefaultPosition, wxSize(120, 120));
    purchase_button = new wxBitmapButton(side_panel, wxID_ANY, wxBitmap("boo.jpg",wxBITMAP_TYPE_JPEG), wxPoint(150,30), wxSize(120, 120),wxBORDER_NONE);
    // Create a static text with the book title
    wxStaticText *titleText = new wxStaticText(
        this, wxID_ANY, book.GetTitle(),
        wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    wxFont myFont(10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    titleText->SetFont(myFont);
    titleText->SetForegroundColour(wxColour(250, 246, 240));
    titleText->Wrap(300);
    // Create a vertical box sizer to arrange bitmap and text vertically
    wxBoxSizer *verticalSizer = new wxBoxSizer(wxVERTICAL);
    verticalSizer->Add(bitmap, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 5); // Add a bottom margin
    verticalSizer->Add(titleText, 0, wxALIGN_CENTER_HORIZONTAL);

    // Add the vertical sizer to the grid sizer
    gridSizer->Add(verticalSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 5);
    
  }

  this->SetSizer(gridSizer);
  gridSizer->Layout();
}
#endif