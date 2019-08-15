
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START_BTN, &CMFCApplication1Dlg::OnBnClickedStartBtn)
	ON_BN_CLICKED(IDC_STOP_BTN, &CMFCApplication1Dlg::OnBnClickedStopBtn)
	ON_COMMAND(ID_START_CMD, &CMFCApplication1Dlg::OnStartCmd)
	ON_COMMAND(ID_STOP_CMD, &CMFCApplication1Dlg::OnStopCmd)
	ON_COMMAND(ID_EXIT_PROGRAM, &CMFCApplication1Dlg::OnExitProgram)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	OnBnClickedStopBtn();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		// CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedStartBtn()
{
	m_start_flag = 1;
	SetDlgItemText(IDC_STATIC_EDIT, L"시작했습니다.");
	GetDlgItem(IDC_START_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_STOP_BTN)->EnableWindow(TRUE);
	UpdateMenu();
}


void CMFCApplication1Dlg::OnBnClickedStopBtn()
{
	m_start_flag = 0;
	SetDlgItemText(IDC_STATIC_EDIT, L"중지했습니다.");
	GetDlgItem(IDC_START_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_STOP_BTN)->EnableWindow(FALSE);
	UpdateMenu();
}

void CMFCApplication1Dlg::UpdateMenu()
{
	CMenu * p_menu = GetMenu();
	if (p_menu != NULL) {
		CMenu * p_sub_menu = p_menu->GetSubMenu(0);	// 첫 번째 항목의 메뉴를 얻는다.
		if (p_sub_menu != NULL) {
			p_sub_menu->EnableMenuItem(ID_START_CMD, m_start_flag*2);
			p_sub_menu->EnableMenuItem(ID_STOP_CMD, !(m_start_flag)*2);

			/*
			if (m_start_flag == 1) {
				// 시작상태
				p_sub_menu->EnableMenuItem(ID_START_CMD, MF_BYCOMMAND | MF_DISABLED);
				p_sub_menu->EnableMenuItem(ID_STOP_CMD, MF_BYCOMMAND | MF_ENABLED);
			}
			else {
				// 종료상태
				p_sub_menu->EnableMenuItem(ID_START_CMD, MF_BYCOMMAND | MF_ENABLED );
				p_sub_menu->EnableMenuItem(ID_STOP_CMD, MF_BYCOMMAND | MF_DISABLED);
			}
			*/
		}
	}
	else {

	}
}

void CMFCApplication1Dlg::OnStartCmd()
{
	OnBnClickedStartBtn();
}


void CMFCApplication1Dlg::OnStopCmd()
{
	OnBnClickedStopBtn();
}


void CMFCApplication1Dlg::OnExitProgram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
