// Sd3Doc.cpp : implementation of the CSd3Doc class
//

#include "stdafx.h"
#include "Sd3.h"
#include "Sd3View.h"
#include "Sd3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSd3Doc

IMPLEMENT_DYNCREATE(CSd3Doc, CDocument)

BEGIN_MESSAGE_MAP(CSd3Doc, CDocument)
	//{{AFX_MSG_MAP(CSd3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSd3Doc construction/destruction

CSd3Doc::CSd3Doc()
{
	// TODO: add one-time construction code here

}

CSd3Doc::~CSd3Doc()
{
}

BOOL CSd3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSd3Doc serialization

void CSd3Doc::Serialize(CArchive& ar)
{
	POSITION pos = GetFirstViewPosition();
	if(pos)
		GetNextView(pos) ->Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CSd3Doc diagnostics

#ifdef _DEBUG
void CSd3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSd3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSd3Doc commands

void CSd3Doc::DeleteContents() 
{
	POSITION pos = GetFirstViewPosition();
	if(pos)
	{
		CSd3View* pView = (CSd3View*)GetNextView(pos);
		pView ->DeleteContents();
	}
	
	CDocument::DeleteContents();
}
