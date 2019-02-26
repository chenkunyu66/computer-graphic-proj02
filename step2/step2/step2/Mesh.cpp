#include "stdafx.h"
#include "Mesh.h"
#include <fstream>      // For input streams from files
#include <string>       // For the string type
#include <sstream>      // For streams from strings

using namespace std;

CMesh::CMesh()
{
	m_texture = NULL;
}


CMesh::~CMesh()
{
}

void CMesh::Draw()
{
	if (m_texture != NULL)
	{
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glBindTexture(GL_TEXTURE_2D, m_texture->TexName());
	}

	glBegin(GL_TRIANGLES);

	for (PTV v = m_triangles.begin(); v != m_triangles.end(); v++)
	{
		if (v->t != -1)
		{
			glTexCoord2f(m_tvertices[v->t].X(), m_tvertices[v->t].Y());
		}

		glNormal3dv(m_normals[v->n]);
		glVertex3dv(m_vertices[v->v]);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void CMesh::AddTriangleVertex(int v, int n, int t)
{
	TV tv;
	tv.v = v;
	tv.n = n;
	tv.t = t;
	m_triangles.push_back(tv);
}

//
// Name :         CMesh::AddFlatQuad()
// Description :  Add a quadrangle to the triangle mesh.
//
void CMesh::AddFlatQuad(int a, int b, int c, int d, int n)
{
	// First triangle
	AddTriangleVertex(a, n, -1);
	AddTriangleVertex(b, n, -1);
	AddTriangleVertex(c, n, -1);

	// Second triangle
	AddTriangleVertex(a, n, -1);
	AddTriangleVertex(c, n, -1);
	AddTriangleVertex(d, n, -1);
}

//
// Name :         CMesh::AddQuad()
// Description :  Add a quadrangle to the triangle mesh with no 
//                assumption of flatness.
//
void CMesh::AddQuad(int a, int b, int c, int d)
{
		// First triangle
	AddTriangleVertex(a, a, -1);
	AddTriangleVertex(b, b, -1);
	AddTriangleVertex(c, c, -1);

	// Second triangle
	AddTriangleVertex(a, a, -1);
	AddTriangleVertex(c, c, -1);
	AddTriangleVertex(d, d, -1);
}

//
// Name :         CMesh::LoadOBJ()
// Description :  Load a file in OBJ format.
//
void CMesh::LoadOBJ(const char *filename)
{
	ifstream str(filename);
	if (!str)
	{
		AfxMessageBox(L"File not found");
		return;
	}
	string line;
	while (getline(str, line))
	{
		istringstream lstr(line);

		string code;
		lstr >> code;
		if (code == "v")
		{
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glBindTexture(GL_TEXTURE_2D, m_fish1.TexName());
			double x, y, z;
			lstr >> x >> y >> z;
			AddVertex(CGrVector(x, y, z, 1));
			glDisable(GL_TEXTURE_2D);
		}
		else if (code == "vn")
		{
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glBindTexture(GL_TEXTURE_2D, m_fish1.TexName());
			double x, y, z;
			lstr >> x >> y >> z;
			AddNormal(CGrVector(x, y, z));
			glDisable(GL_TEXTURE_2D);
		}
		else if (code == "vt")
		{
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glBindTexture(GL_TEXTURE_2D, m_fish1.TexName());
			double s, t;
			lstr >> s >> t;
			AddTexCoord(CGrVector(s, t));
			glDisable(GL_TEXTURE_2D);
		}
		else if (code == "f")
		{
			for (int i = 0; i<3; i++)
			{
				glEnable(GL_TEXTURE_2D);
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
				glBindTexture(GL_TEXTURE_2D, m_fish1.TexName());
				char slash;
				int v, t, n;
				lstr >> v >> slash >> t >> slash >> n;
				AddTriangleVertex(v - 1, n - 1, t - 1);
			}
			
		}
		
	}
}