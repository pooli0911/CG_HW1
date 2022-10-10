#include "GameObject.h"

GameObject::GameObject()
{
	_Points = nullptr;
	_Colors = nullptr;
	_NumVertex = DEF_VAR;

	_uiVao = DEF_VAR;
	_uiBuffer = DEF_VAR;
	_bUpdateMV = false;
	_bUpdateProj = false;
}

GameObject::~GameObject()
{
	if (_Points != nullptr)	delete[] _Points;
	if (_Colors != nullptr)	delete[] _Colors;
}

void GameObject::InitObject()
{
	posX = posY = rot = 0.0f;
	scaleX = scaleY = 1.0f;
	setColor(color);
	ObjPosition = Translate(posX, posY, 0.0f);
	ObjRotation = RotateZ(rot);
	ObjScale = Scale(scaleX, scaleY, 1);

	setTRSMatrix(ObjPosition * ObjRotation * ObjScale);
}

void GameObject::UpdateObject()
{
	ObjPosition = Translate(posX, posY, 0.0f);
	ObjRotation = RotateZ(rot);
	ObjScale = Scale(scaleX, scaleY, 1);

	setTRSMatrix(ObjPosition * ObjRotation * ObjScale);
}

void GameObject::OnUpdate(float delta)
{

}

void GameObject::CreateBufferObject()
{
	glGenVertexArrays(1, &_uiVao);
	glBindVertexArray(_uiVao);

	// Create and initialize a buffer object

	glGenBuffers(1, &_uiBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _uiBuffer);
	glBufferData(GL_ARRAY_BUFFER, _NumVertex * sizeof(vec4) * 2, NULL, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, _NumVertex * sizeof(vec4), _Points);
	glBufferSubData(GL_ARRAY_BUFFER, _NumVertex * sizeof(vec4), _NumVertex * sizeof(vec4), _Colors);
}

void GameObject::setShader(mat4& mxView, mat4& mxProjection, GLuint uiShaderHandle)
{
	// Load shaders and use the resulting shader program
	if (uiShaderHandle == MAX_UNSIGNED_INT) _uiProgram = InitShader("vsVtxColor.glsl", "fsVtxColor.glsl");
	else _uiProgram = uiShaderHandle;

	// set up vertex arrays
	GLuint vPosition = glGetAttribLocation(_uiProgram, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	GLuint vColor = glGetAttribLocation(_uiProgram, "vColor");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(_NumVertex * sizeof(vec4)));

	_uiModelView = glGetUniformLocation(_uiProgram, "ModelView");
	_mxView = mxView;
	glUniformMatrix4fv(_uiModelView, 1, GL_TRUE, _mxView);

	_uiProjection = glGetUniformLocation(_uiProgram, "Projection");
	_mxProjection = mxProjection;
	glUniformMatrix4fv(_uiProjection, 1, GL_TRUE, _mxProjection);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void GameObject::setViewMatrix(mat4& mat)
{
	_mxView = mat;
	_bUpdateMV = true;
}

void GameObject::setProjectionMatrix(mat4& mat)
{
	_mxProjection = mat;
	_bUpdateProj = true;
}

void GameObject::setTRSMatrix(mat4& mat)
{
	_mxTRS = mat;
	_bUpdateMV = true;
}

void GameObject::setColor(GLfloat vColor[4])
{
	for (int i = 0; i < _NumVertex; i++) {
		_Colors[i].x = vColor[0];
		_Colors[i].y = vColor[1];
		_Colors[i].z = vColor[2];
		_Colors[i].w = vColor[3];
	}
	glBindBuffer(GL_ARRAY_BUFFER, _uiBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, _NumVertex * sizeof(vec4), _NumVertex * sizeof(vec4), _Colors);
}

void GameObject::setVtxColors(GLfloat vLFColor[], GLfloat vLRColor[], GLfloat vTRColor[], GLfloat vTLColor[])
{
	_Colors[0].x = vLFColor[0];
	_Colors[0].y = vLFColor[1];
	_Colors[0].z = vLFColor[2];
	_Colors[0].w = vLFColor[3];
	_Colors[3] = _Colors[0];

	_Colors[1].x = vLRColor[0];
	_Colors[1].y = vLRColor[1];
	_Colors[1].z = vLRColor[2];
	_Colors[1].w = vLRColor[3];

	_Colors[2].x = vTRColor[0];
	_Colors[2].y = vTRColor[1];
	_Colors[2].z = vTRColor[2];
	_Colors[2].w = vTRColor[3];
	_Colors[4] = _Colors[2];

	_Colors[3].x = vTLColor[0];
	_Colors[3].y = vTLColor[1];
	_Colors[3].z = vTLColor[2];
	_Colors[3].w = vTLColor[3];

	glBindBuffer(GL_ARRAY_BUFFER, _uiBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, _NumVertex * sizeof(vec4), _NumVertex * sizeof(vec4), _Colors);
}