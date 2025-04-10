#include <windows.h>

LRESULT CALLBACK  MainWindowCallback(
   HWND    hWnd,
   UINT    Msg,
   WPARAM  wParam,
   LPARAM  lParam
){

  switch (Msg) {
    case WM_SIZE:
      OutputDebugStringA("WM_SIZE");
      break;
    case WM_DESTROY:
    OutputDebugStringA("WM_DESTROY\n");
      break;
    case WM_CLOSE:
    OutputDebugStringA("WM_CLOSE\n");
      break;
    case WM_ACTIVATEAPP:
    OutputDebugStringA("WM_ACTIVATEAPP\n");
      break;
    default:
    OutputDebugStringA("Default\n");
    return DefWindowProc(hWnd, Msg, wParam, lParam);
  }

  return 0;
}


int WINAPI WinMain(
            HINSTANCE hInstance,
            HINSTANCE hPrevInstance,    
            LPSTR     lpCmdLine,
            int       nShowCmd
  ){

  WNDCLASSA windowsClass = {0};

  windowsClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
  windowsClass.lpfnWndProc = MainWindowCallback;
  windowsClass.hInstance = hInstance;
  windowsClass.lpszClassName = "HandmadeHeroWindowClass";


  

    return 0;
  };
