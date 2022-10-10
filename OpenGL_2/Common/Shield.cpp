#include "Shield.h"

Shield::Shield()
{
	_NumVertex = SHIELD_NUM;
	_Points = new vec4[SHIELD_NUM];
	_Colors = new vec4[SHIELD_NUM];

	for (int i = 0; i < SHIELD_NUM; i++) {
		_Points[i].x = RADIUS * cosf(M_PI * 2.0f * i / SHIELD_NUM);
		_Points[i].y = RADIUS * sinf(M_PI * 2.0f * i / SHIELD_NUM);
		_Points[i].z = 0.0f;
		_Points[i].w = 1.0f;
		_Colors[i] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	}

	// Create and initialize a buffer object 
	CreateBufferObject();
	_bUpdateProj = false;

	InitObject();

	posY = -10;
}

void Shield::OnUpdate(float delta)
{
	UpdateObject();
}


void Shield::draw()
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
	glDrawArrays(GL_LINE_LOOP, 0, SHIELD_NUM);
}

void Shield::drawW()
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
	glDrawArrays(GL_LINE_LOOP, 0, SHIELD_NUM);
}
