// fileRead.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "fileRead.h"
#include "fileReadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfileReadApp

BEGIN_MESSAGE_MAP(CfileReadApp, CBCGPWinApp)
	ON_COMMAND(ID_HELP, CBCGPWinApp::OnHelp)
END_MESSAGE_MAP()


// CfileReadApp construction

CfileReadApp::CfileReadApp()
{
	// Enable Office 2016 look (Colorful theme):
	SetVisualTheme(BCGP_VISUAL_THEME_OFFICE_2016_COLORFUL);

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CfileReadApp object

CfileReadApp theApp;


// CfileReadApp initialization

BOOL CfileReadApp::InitInstance()
{
	// InitCommonControls() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	InitCommonControls();

	CBCGPWinApp::InitInstance();

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();


	CfileReadDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
