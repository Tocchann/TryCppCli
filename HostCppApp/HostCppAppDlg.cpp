
// HostCppAppDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "HostCppApp.h"
#include "HostCppAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

// CHostCppAppDlg ダイアログ



CHostCppAppDlg::CHostCppAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_HOSTCPPAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHostCppAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHostCppAppDlg, CDialog)
END_MESSAGE_MAP()

//EXTERN_C void APIENTRY NativeExportFunc( HWND hwndOwner, LPCWSTR caption );

// CHostCppAppDlg メッセージ ハンドラー

BOOL CHostCppAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}
#pragma comment(lib,"CppCliLib.lib")

EXTERN_C void APIENTRY NativeExportFunc( HWND hwndOwner, LPCWSTR caption );

void CHostCppAppDlg::OnOK()
{
	//	何もつないでないので問題ないけど、UpdateDataに失敗したら何もしない
	if( !UpdateData() )
	{
		return;
	}
#if 1
	NativeExportFunc( *this, theApp.m_pszAppName );
#else
	auto hDLL = LoadLibrary( L"CppCliLib.dll" );
	if( hDLL != nullptr )
	{
		void (APIENTRY *NativeExportFunc)(HWND, LPCWSTR);
		(FARPROC&)NativeExportFunc = GetProcAddress( hDLL, "NativeExportFunc" );
		if( NativeExportFunc != nullptr )
		{
			NativeExportFunc( *this, theApp.m_pszAppName );
		}
		FreeLibrary( hDLL );
	}
#endif
	//AfxMessageBox( _T( "--工事中--\nここでいきなりC++/CLIなDLLを呼び出してみようと思う。" ) );
}
