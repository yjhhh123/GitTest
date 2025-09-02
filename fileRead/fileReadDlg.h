// fileReadDlg.h : header file
//

#pragma once
#include <afxcmn.h>
#include <afxwin.h>

// CfileReadDlg dialog
class CfileReadDlg : public CBCGPDialog
{
// Construction
public:
	CfileReadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FILEREAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	CListCtrl m_listFiles;   // 파일 목록
	CEdit m_editContent;     // 파일 내용 표시
	CString m_folderPath;    // 현재 선택한 폴더 경로 저장

	void LoadFileList(CString folderPath);
	void ShowFileContent(CString filePath);

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedBtnLoad(); // 불러오기 버튼 
	afx_msg void OnBnClickedBtnShow(); // 내용 보기 버튼 
};
