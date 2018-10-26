//d3d surface
/*
#include <Windows.h>
#include <iostream>
#include <d3d9.h>
#include <time.h>

using namespace std;

#pragma comment(lib, "d3d9.lib")
//#pragma comment(lib, "d3dx9.lib")

const string APP_TITLE = "Direct3D_Windowed";
const int SCREENW = 1024;
const int SCREENH = 768;

LPDIRECT3D9 d3d = NULL;
LPDIRECT3DDEVICE9 d3ddev = NULL;

//modify
LPDIRECT3DSURFACE9 backbuffer = NULL;
LPDIRECT3DSURFACE9 surface = NULL;

bool gameover = false;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

bool Game_Init(HWND hwnd) {
    ///d3d_obj
    d3d = Direct3DCreate9(D3D_SDK_VERSION);
    if (d3d == NULL) {
        MessageBox(hwnd, "Error initializing Direct3D", "Error", MB_OK);
        return false;
    }
    ///d3d_pp -> d3d_device
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    //modify
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
    d3dpp.BackBufferCount = 1;
    d3dpp.BackBufferWidth = SCREENW;
    d3dpp.BackBufferHeight = SCREENH;
    d3dpp.hDeviceWindow = hwnd;
    d3d->CreateDevice(
        D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hwnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp,
        &d3ddev
    );

    if (d3ddev == NULL) {
        MessageBox(hwnd, "Error creating Direct3D device", "Error", MB_OK);
        return false;
    }
    //modify
    srand((unsigned int)time(NULL));
    d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
    d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer); //get back buffer
    HRESULT result = d3ddev->CreateOffscreenPlainSurface(
        100,
        100,
        D3DFMT_X8R8G8B8,
        D3DPOOL_DEFAULT,
        &surface,
        NULL
    );
    if (result != D3D_OK)
        return false;

    return true;
}

void Game_Run(HWND hwnd) {
    if (!d3ddev)
        return;
    
    if (d3ddev->BeginScene()) {
        //m
        int r = rand() % 255;
        int g = rand() % 255;
        int b = rand() % 255;
        d3ddev->ColorFill(surface, NULL, D3DCOLOR_XRGB(r, g, b));
        RECT rect;
        rect.left = rand() % SCREENW / 2;
        rect.right = rect.left + rand() % SCREENW / 2;
        rect.top = rand() % SCREENH;
        rect.bottom = rect.top + rand() % SCREENH / 2;
        d3ddev->StretchRect(surface, NULL, backbuffer, &rect, D3DTEXF_NONE);

        d3ddev->EndScene();
        ///swap double buffer
        d3ddev->Present(NULL, NULL, NULL, NULL);
    }
    if (KEY_DOWN(VK_ESCAPE))
        PostMessage(hwnd, WM_DESTROY, 0, 0);
}

void Game_End(HWND hwnd) {
    if (d3ddev) {
        d3ddev->Release();
        d3ddev = NULL;
    }
    if (d3d) {
        d3d->Release();
        d3d = NULL;
    }
}

LRESULT WINAPI WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_DESTROY:
        gameover = true;
        break;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    MSG msg;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = (WNDPROC)WinProc;
    wc.style = 0;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hIcon = NULL;
    wc.hIconSm = NULL;
    wc.lpszMenuName = NULL;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszClassName = "MainWindowClass";
    if (!RegisterClassEx(&wc))
        return false;
    //HWND hwnd = CreateWindow(
    //    "MainWindowClass",
    //    APP_TITLE.c_str(),
    //    WS_OVERLAPPEDWINDOW,
    //    CW_USEDEFAULT, CW_USEDEFAULT,
    //    SCREENW, SCREENH,
    //    (HWND)NULL,
    //    (HMENU)NULL,
    //    hInstance,
    //    (LPVOID)NULL
    //);
    HWND hwnd = CreateWindow(
        "MainWindowClass",
        APP_TITLE.c_str(),
        WS_EX_TOPMOST | WS_POPUP,
        0, 0,
        SCREENW, SCREENH,
        (HWND)NULL,
        (HMENU)NULL,
        hInstance,
        (LPVOID)NULL
    );
    if (!hwnd)
        return 0;
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    if (!Game_Init(hwnd))
        return 0;

    while (!gameover) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        Game_Run(hwnd);
    }
    Game_End(hwnd);
    return msg.wParam;
}
*/