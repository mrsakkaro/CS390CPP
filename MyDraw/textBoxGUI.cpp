// textBoxGUI.cpp : implementation file
//

#include "stdafx.h"
#include "MyDraw.h"
#include "textBoxGUI.h"
#include "afxdialogex.h"


// textBoxGUI dialog

IMPLEMENT_DYNAMIC(textBoxGUI, CDialogEx)

textBoxGUI::textBoxGUI(CWnd* pParent /*=NULL*/)
	: CDialogEx(textBoxGUI::IDD, pParent)
{

}

textBoxGUI::~textBoxGUI()
{
}

void textBoxGUI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, textBoxString);
}


BEGIN_MESSAGE_MAP(textBoxGUI, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &textBoxGUI::OnEnChangeEdit1)
END_MESSAGE_MAP()


// textBoxGUI message handlers


void textBoxGUI::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
