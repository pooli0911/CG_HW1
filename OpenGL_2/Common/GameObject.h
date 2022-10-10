#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "../Header/Angel.h"

#define DEF_VAR 0

typedef Angel::vec4 color4;
typedef Angel::vec4 point4;

class GameObject
{
protected:
	void InitObject();
	void UpdateObject();

public:
	GameObject();
	virtual ~GameObject();

	float posX = 0.0f;
	float posY = 0.0f;
	float rot = 0.0f;
	float scaleX = 1.0f;
	float scaleY = 1.0f;

	mat4 ObjPosition;
	mat4 ObjRotation;
	mat4 ObjScale;

	GLfloat color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	vec4* _Points;
	vec4* _Colors;
	int _NumVertex;

	// VAO
	GLuint _uiVao;
	// VBO
	GLuint _uiBuffer;
	//  for Shader
	GLuint _uiProgram;
	// Vertex Position Attribute
	GLuint _uiModelView, _uiProjection;
	// Matrix 
	mat4 _mxView, _mxProjection;
	mat4 _mxMVFinal, _mxTRS;

	// record if there is any matrix refresh
	bool  _bUpdateMV;
	bool  _bUpdateProj;

	virtual void OnUpdate(float delta);


	void CreateBufferObject();

	void setShader(mat4& mxModelView, mat4& mxProjection, GLuint uiShaderHandle = MAX_UNSIGNED_INT);
	GLuint getShaderHandle() { return _uiProgram; }
	void setViewMatrix(mat4& mat);
	void setProjectionMatrix(mat4& mat);
	void setTRSMatrix(mat4& mat);
	void setColor(GLfloat vColor[4]); // Single color
	void setVtxColors(GLfloat vLFColor[], GLfloat vLRColor[], GLfloat vTRColor[], GLfloat vTLColor[]); // four Vertices' Color
	virtual void draw() = 0;
	virtual void drawW() = 0;
};

#endif
