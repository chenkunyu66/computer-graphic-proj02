
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "graphics/OpenGLWnd.h"
#include "graphics/GrTexture.h"
#include "graphics/GrCamera.h"
#include "Mesh.h"

// CChildView window

class CChildView : public COpenGLWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);


// Implementation
public:
	virtual ~CChildView();
	
	// Generated message map functions
protected:
	//afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	void OnGLDraw(CDC * pDC);
	void Box(GLdouble p_x, GLdouble p_y, GLdouble p_z, const GLdouble *p_color);
	void left(GLdouble p_x, GLdouble p_y, GLdouble p_z, const GLdouble *p_color);
	void up(GLdouble p_x, GLdouble p_y, GLdouble p_z, const GLdouble *p_color);
	void down(GLdouble p_x, GLdouble p_y, GLdouble p_z, const GLdouble *p_color);
	void CChildView::trigial(GLdouble p_x, GLdouble p_y, GLdouble p_z, const GLdouble *p_color);
	void CChildView::CreateMesh();
	
private:
	double m_spinAngle;
	int m_scene;
	UINT_PTR m_spinTimer;
	CGrCamera m_camera;
	CGrTexture m_wood;
	CGrTexture m_fish1;
	CMesh m_mesh;
	CMesh m_surface;
	CMesh m_fish;
	CGrTexture m_bluegill;
	CGrTexture m_map;
	CGrTexture m_marble;
public:
	afx_msg void OnStepSpin();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnStepMesh();
	afx_msg void OnStepName();
};

