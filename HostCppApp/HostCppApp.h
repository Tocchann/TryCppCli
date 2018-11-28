
// HostCppApp.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CHostCppAppApp:
// このクラスの実装については、HostCppApp.cpp を参照してください
//

class CHostCppAppApp : public CWinApp
{
public:
	CHostCppAppApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CHostCppAppApp theApp;
