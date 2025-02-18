#ifndef YDS_WINDOWS_WINDOW_H
#define YDS_WINDOWS_WINDOW_H

#include "yds_window.h"

#define NOMINMAX
#include <Windows.h>

class ysWindowsWindowSystem;

class ysWindowsWindow : public ysWindow {
    friend ysWindowsWindowSystem;

public:
    ysWindowsWindow();
    virtual ~ysWindowsWindow();

    // Overrides

    virtual ysError
    InitializeWindow(ysWindow *parent, const wchar_t *title, WindowStyle style,
                     int x, int y, int width, int height,
                     ysMonitor *monitor, const ysVector &color) override;
    virtual ysError InitializeWindow(ysWindow *parent, const wchar_t *title, WindowStyle style, ysMonitor *monitor) override;
    virtual void CaptureMouse() override;
    virtual void ReleaseMouse() override;

    virtual bool SetWindowStyle(WindowStyle style);

    virtual void ScreenToLocal(int &x, int &y) const;

    virtual bool IsVisible();

    virtual int GetScreenWidth() const;
    virtual int GetScreenHeight() const;

public:
    // Windows Specific

    // Set the windows instance to use
    void SetInstance(HINSTANCE instance) { m_instance = instance; }
    HINSTANCE GetInstance() const { return m_instance; }

    // Get Win32 window handle
    HWND GetWindowHandle() const { return m_hwnd; }

    static int GetWindowsStyle(WindowStyle style);

protected:
    // Abstraction Layer

    virtual void Close() override;
    virtual void SetTitle(const wchar_t *title) override;
    virtual void SetState(WindowState state = WindowState::Visible) override;

    virtual void AL_SetSize(int width, int height) override;
    virtual void AL_SetLocation(int x, int y) override;

protected:
    ATOM RegisterWindowsClass(const ysVector &color);

    HINSTANCE m_instance;
    HWND m_hwnd;
    int m_previousCmdShow;
};

#endif /* YDS_WINDOWS_WINDOW_H */
