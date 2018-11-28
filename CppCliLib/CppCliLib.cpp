#include "stdafx.h"

#include "CppCliLib.h"

using namespace System::Windows::Forms;

EXTERN_C void APIENTRY NativeExportFunc( HWND hwndOwner, LPCWSTR caption )
{
	MessageBox::Show( L"テストだぜ！", gcnew String( caption ), MessageBoxButtons::OK, MessageBoxIcon::Information );
}
