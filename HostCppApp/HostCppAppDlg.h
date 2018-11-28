
// HostCppAppDlg.h : ヘッダー ファイル
//

#pragma once


// CHostCppAppDlg ダイアログ
class CHostCppAppDlg : public CDialog
{
// コンストラクション
public:
	CHostCppAppDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOSTCPPAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
};
