#pragma once
#include "afxwin.h"


// textBoxGUI dialog

class textBoxGUI : public CDialogEx
{
	DECLARE_DYNAMIC(textBoxGUI)

public:
	textBoxGUI(CWnd* pParent = NULL);   // standard constructor
	virtual ~textBoxGUI();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	// TextBox String
	CEdit textBoxString;
	afx_msg void OnEnChangeEdit1();
};
