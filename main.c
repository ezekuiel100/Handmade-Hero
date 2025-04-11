#include <windows.h>

LRESULT CALLBACK  MainWindowCallback(
   HWND    hWnd,
   UINT    Msg,
   WPARAM  wParam,
   LPARAM  lParam
){

  switch (Msg) {
    case WM_SIZE:
      OutputDebugStringA("WM_SIZE\n");
      break;
    case WM_DESTROY:
    OutputDebugStringA("WM_DESTROY\n");
    DestroyWindow(hWnd);
    return 0;
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


  RegisterClassA(&windowsClass);

 HWND WindowHandle = CreateWindowA("HandmadeHeroWindowClass", "Handmade Hero", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL , hInstance, NULL);

 if(WindowHandle){
  ShowWindow(WindowHandle, nShowCmd);   
  UpdateWindow(WindowHandle);   

  MSG Message;

 while(GetMessage(&Message , NULL ,0, 0)){
  TranslateMessage(&Message);       
  DispatchMessageA(&Message); 
 }

 }

    return 0;
  };
