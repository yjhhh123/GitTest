// fileReadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "fileRead.h"
#include "fileReadDlg.h"
#include <locale.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfileReadDlg dialog



CfileReadDlg::CfileReadDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CfileReadDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	EnableVisualManagerStyle(TRUE, TRUE);
}

void CfileReadDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FILES, m_listFiles);
	DDX_Control(pDX, IDC_CONTENT, m_editContent);
}

BEGIN_MESSAGE_MAP(CfileReadDlg, CBCGPDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_LOAD, &CfileReadDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_SHOW, &CfileReadDlg::OnBnClickedBtnShow)
END_MESSAGE_MAP()


// CfileReadDlg message handlers
BOOL CfileReadDlg::OnInitDialog()
{
	CBCGPDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//초기화 뭘로 한건지
	m_listFiles.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_listFiles.InsertColumn(0, _T("파일 이름"), LVCFMT_LEFT, 350);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CfileReadDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CBCGPDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CfileReadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CfileReadDlg::OnBnClickedBtnLoad()
{
	CFolderPickerDialog dlg(NULL, OFN_FILEMUSTEXIST, this);
	if (dlg.DoModal() == IDOK)
	{
		m_folderPath = dlg.GetPathName();
		LoadFileList(m_folderPath);
	}
}

void CfileReadDlg::LoadFileList(CString folderPath)
{
	m_listFiles.DeleteAllItems();

	CFileFind finder;
	CString searchPath = folderPath + _T("\\*.csv");
	BOOL bWorking = finder.FindFile(searchPath);

	int index = 0;
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		if (!finder.IsDots() && !finder.IsDirectory())
		{
			CString fileName = finder.GetFileName();
			m_listFiles.InsertItem(index, fileName);
			index++; 
		}

		
	}
	finder.Close();
}


void CfileReadDlg::OnBnClickedBtnShow()
{
	int sel = m_listFiles.GetNextItem(-1, LVNI_SELECTED);
	if (sel == -1)
	{
		AfxMessageBox(_T("먼저 파일을 선택하세요."));
		return;
	}

	CString fileName = m_listFiles.GetItemText(sel, 0);
	CString fullPath = m_folderPath + _T("\\") + fileName;

	ShowFileContent(fullPath);
}

void CfileReadDlg::ShowFileContent(CString filePath)
{
	CStdioFile file;
	if (!file.Open(filePath, CFile::modeRead | CFile::typeText))
	{
		AfxMessageBox(_T("파일을 열 수 없습니다."));
		return;
	}

	CString line, content;
	setlocale(LC_ALL, "korean");
	while (file.ReadString(line))
	{
		content += line + _T("\r\n");
	}
	file.Close();

	m_editContent.SetWindowText(content);

}