#include "stdafx.h"

#include "CppCliLib.h"

using namespace System::Windows::Forms;

EXTERN_C void APIENTRY CppCliLibFunc( HWND hwndOwner, LPCWSTR caption )
{
	MessageBox::Show( L"CppCliLibFunc �� MessageBox::Show", gcnew String( caption ), MessageBoxButtons::OK, MessageBoxIcon::Information );
}
