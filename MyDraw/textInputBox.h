#pragma once


// textInputBox dialog

class textInputBox : public CDialogEx
{
	DECLARE_DYNAMIC(textInputBox)

public:
	textInputBox(CWnd* pParent = NULL);   // standard constructor
	virtual ~textInputBox();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
