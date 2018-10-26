/*

#include <Windows.h>
#include <iostream>
using namespace std;

const string ProgramTitle = "Hello Windows";

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    RECT drawRect;
    PAINTSTRUCT ps;
    HDC hdc;
    switch (message) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        for (int n = 0; n != 20; ++n) {
            int x = n * 20;
            int y = n * 20;
            drawRect = { x, y, x + 100, y + 20 };
            DrawText(hdc, ProgramTitle.c_str(), ProgramTitle.length(), &drawRect, DT_CENTER);
        }
        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

ATOM MyRegisterClass(HINSTANCE hInstance) {
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = (WNDPROC)WinProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = ProgramTitle.c_str();
    wc.hIconSm = NULL;
    return RegisterClassEx(&wc);
}

bool InitInstance(HINSTANCE hInstance, int nCmdShow) {
    HWND hWnd = CreateWindow(
        ProgramTitle.c_str(),
        ProgramTitle.c_str(),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        640, 480,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    if (hWnd == 0)
        return 0;
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    return 1;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    MyRegisterClass(hInstance);
    if (!InitInstance(hInstance, nCmdShow))
        return 0;
    
    MSG msg;
    
    
    //while (GetMessage(&msg, NULL, 0, 0)) {
    //    TranslateMessage(&msg);
    //    DispatchMessage(&msg);
    //}
    //return msg.wParam;
    

    if (!Game_Init())
        return 0;
    bool gameover = false;
    while (!gameover) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            Game_Loop();
        }
    }
    Game_End();
    return msg.wParam;
}

*/