#include <Windows.h>

int main(int argc, char **argv)
{
	bool hide = true;

	if (argc > 1 && !_stricmp(argv[1], "SHOW"))
	{
		hide = false;
	}

	for (int i = 0; i < 10 ; i++)
	{
		keybd_event(VK_VOLUME_UP, 0, 0, 0);
		keybd_event(VK_VOLUME_DOWN, 0, 0, 0);

		HWND wnd = FindWindowEx(NULL, NULL, "NativeHWNDHost", "");

		if (wnd && FindWindowEx(wnd, NULL, "DirectUIHWND", ""))
		{
			if (ShowWindow(wnd, hide ? SW_MINIMIZE : SW_RESTORE)) break;
		}

		Sleep(i * 2 * 1000);
	}

	return 0;
}
