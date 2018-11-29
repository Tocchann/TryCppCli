// NativeCppLib.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"

EXTERN_C void APIENTRY NativeCppLibFunc( HWND hwndOwner, LPCWSTR caption )
{
	MessageBox( hwndOwner, _T( "NativeCppLibFunc で MessageBox" ), caption, MB_ICONINFORMATION|MB_OK );
}
