#include <Windows.h>
#include <tchar.h>
#include <ctime>
#include "resource.h"

HWND hList, hB, hBox, hR1, hR2, hR3, hResult;
TCHAR str[32];
short num; short result;
short arr[32];

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG), NULL, (DLGPROC)DlgProc);
}

void randNum()
{
	num = rand() % 21;
	wsprintf(str, TEXT("%d"), num);
}

void fillList()
{
	SendMessage(hList, LB_RESETCONTENT, NULL, NULL);
	for (int i = NULL; i < 10; i++)
	{
		SendMessage(hList, LB_ADDSTRING, NULL, LPARAM(str));
		randNum();
		arr[i] = num;
	}
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	srand(time(NULL));
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, NULL);
		return(TRUE);
	case WM_INITDIALOG:
		hList = GetDlgItem(hWnd, IDC_LIST);
		hB = GetDlgItem(hWnd, IDC_BUTTON);
		hBox = GetDlgItem(hWnd, IDC_BOX);
		hR1 = GetDlgItem(hWnd, IDC_RADIO1);
		hR2 = GetDlgItem(hWnd, IDC_RADIO2);
		hR3 = GetDlgItem(hWnd, IDC_RADIO3);
		hResult = GetDlgItem(hWnd, IDC_RESULT);
		fillList();
		return(TRUE);
	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTON)
		{
			fillList();
			SendMessage(hResult, WM_SETTEXT, NULL, LPARAM(TEXT("RESULT")));
		}
		else if (LOWORD(wParam) == IDC_RADIO1)
		{
			for (int i = NULL; i < 9; i++)
			{
				result += arr[i];
			}
			wsprintf(str, TEXT("%d"), result);
			SendMessage(hResult, WM_SETTEXT, NULL, LPARAM(str));
			result = NULL;
		}
		else if (LOWORD(wParam) == IDC_RADIO2)
		{
			for (int i = NULL; i < 9; i++)
			{
				result *= arr[i];
			}
			wsprintf(str, TEXT("%d"), result);
			SendMessage(hResult, WM_SETTEXT, NULL, LPARAM(str));
			result = NULL;
		}
		else if (LOWORD(wParam) == IDC_RADIO3)
		{
			for (int i = NULL; i < 9; i++)
			{
				result += arr[i];
			}
			wsprintf(str, TEXT("%d"), result / 10);
			SendMessage(hResult, WM_SETTEXT, NULL, LPARAM(str));
			result = NULL;
		}
		return(TRUE);
	}
	return(FALSE);
}








