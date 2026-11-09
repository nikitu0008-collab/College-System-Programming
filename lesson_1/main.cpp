// lesson_1: минимальное wxWidgets приложение.
// Собирается CMakeLists.txt из этого каталога (find_package(wxWidgets) требует установленной библиотеки).

#include <wx/wx.h>

class HelloFrame : public wxFrame {
public:
    HelloFrame() : wxFrame(nullptr, wxID_ANY, "lesson_1: wxWidgets says hello") {
        auto* panel = new wxPanel(this);
        auto* text = new wxStaticText(panel, wxID_ANY,
            "Hello from wxWidgets!",
            wxDefaultPosition, wxDefaultSize,
            wxALIGN_CENTRE_HORIZONTAL);

        auto* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(text, 1, wxALIGN_CENTRE | wxALL, 32);
        panel->SetSizer(sizer);
    }
};

class HelloApp : public wxApp {
public:
    auto OnInit() -> bool override {
        (new HelloFrame())->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(HelloApp);
