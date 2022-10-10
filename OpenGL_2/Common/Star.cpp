#include "Star.h"

Star::Star()
{
	_NumVertex = STAR_NUM;
	_Points = new vec4[STAR_NUM];

	_isEnd = false;


	/*_Points[0] = vec4(-1.0f, 0.0f, 0.0f, 1.0f); // A
	_Points[1] = vec4(0.118034f, -0.363271f, 0.0f, 1.0f); // I
	_Points[2] = vec4(0.809017f, 0.587785f, 0.0f, 1.0f); // B
	_Points[3] = vec4(-0.309017f, 0.951057f, 0.0f, 1.0f); // E
	_Points[4] = vec4(-0.309017f, -0.951057f, 0.0f, 1.0f); // D
	_Points[5] = vec4(0.381966f, 0.0f, 0.0f, 1.0f); // J
	_Points[6] = _Points[3]; // E
	_Points[7] = vec4(0.809017f, -0.587785f, 0.0f, 1.0f); // C
	_Points[8] = vec4(-0.309017f, -0.224514f, 0.0f, 1.0f); // H*/

	_Points[0] = vec4(-1.0f, 0.0f, 0.0f, 1.0f); // A
	_Points[1] = vec4(0.11f, -0.36f, 0.0f, 1.0f); // I
	_Points[2] = vec4(0.80f, 0.58f, 0.0f, 1.0f); // B
	_Points[3] = vec4(-0.30f, 0.95f, 0.0f, 1.0f); // E
	_Points[4] = vec4(-0.30f, -0.95f, 0.0f, 1.0f); // D
	_Points[5] = vec4(0.38f, 0.0f, 0.0f, 1.0f); // J
	_Points[6] = _Points[3]; // E
	_Points[7] = vec4(0.80f, -0.58f, 0.0f, 1.0f); // C
	_Points[8] = vec4(-0.30f, -0.22f, 0.0f, 1.0f); // H

	_Colors = new vec4[STAR_NUM];

	_Colors[0] = vec4(1.0f, 1.0f, 1.0f, 1.0f);  // (r, g, b, a)
	_Colors[1] = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	_Colors[2] = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	_Colors[3] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[4] = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	_Colors[5] = vec4(0.0f, 0.0f, 1.0f, 1.0f);
	_Colors[6] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[7] = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	_Colors[8] = vec4(0.0f, 0.0f, 1.0f, 1.0f);

	// Create and initialize a buffer object 
	CreateBufferObject();
	_bUpdateProj = false;

	InitObject();

	posY = rand() % 30 - 10;
	posX = rand() % 20 - 10;
	scaleX = scaleY = 0.3f;
	//posY = 0.0f;
	//posX = 0.5f;
}

void Star::OnUpdate(float delta)
{
	UpdateObject();
}


void Star::draw()
{
	glUseProgram(_uiProgram);
	glBindVertexArray(_uiVao);
	if (_bUpdateMV) {
		_mxMVFinal = _mxView * _mxTRS;
		_bUpdateMV = false;
	}
	glUniformMatrix4fv(_uiModelView, 1, GL_TRUE, _mxMVFinal);

	if (_bUpdateProj) {
		glUniformMatrix4fv(_uiProjection, 1, GL_TRUE, _mxProjection);
		_bUpdateProj = false;
	}
	glDrawArrays(GL_TRIANGLES, 0, STAR_NUM);
}

void Star::drawW()
{
	glBindVertexArray(_uiVao);

	if (_bUpdateMV) {
		_mxMVFinal = _mxView * _mxTRS;
		_bUpdateMV = false;
	}

	glUniformMatrix4fv(_uiModelView, 1, GL_TRUE, _mxMVFinal);
	if (_bUpdateProj) {
		glUniformMatrix4fv(_uiProjection, 1, GL_TRUE, _mxProjection);
		_bUpdateProj = false;
	}
	glDrawArrays(GL_TRIANGLES, 0, STAR_NUM);
}