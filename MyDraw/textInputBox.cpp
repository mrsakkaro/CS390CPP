// textInputBox.cpp : implementation file
//

#include "stdafx.h"
#include "MyDraw.h"
#include "textInputBox.h"
#include "afxdialogex.h"


// textInputBox dialog

IMPLEMENT_DYNAMIC(textInputBox, CDialogEx)

textInputBox::textInputBox(CWnd* pParent /*=NULL*/)
	: CDialogEx(textInputBox::IDD, pParent)
{

}

textInputBox::~textInputBox()
{
}

void textInputBox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(textInputBox, CDialogEx)
END_MESSAGE_MAP()


// textInputBox message handlers
