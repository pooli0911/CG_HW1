#include "HealthPointBar.h"

HealthPointBar::HealthPointBar()
{

	_NumVertex = BAR_NUM;
	_Points = new vec4[_NumVertex];
	_Colors = new vec4[_NumVertex];



	_Points[0] = vec4(-0.1f, 0.2f, 0.0f, 1.0f); // Left Top
	_Points[1] = vec4(-0.1f, -0.2f, 0.0f, 1.0f); // Letf Bottom
	_Points[2] = vec4(0.1f, -0.2f, 0.0f, 1.0f); // Right Bottom

	_Points[3] = _Points[0]; // Left Top
	_Points[4] = _Points[2]; // Right Bottom
	_Points[5] = vec4(0.1f, 0.2f, 0.0f, 1.0f); // Right Top


	for (int i = 0; i < _NumVertex; i++) {
		_Colors[i] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	}


	// Create and initialize a buffer object 
	CreateBufferObject();
	_bUpdateProj = false;

	InitObject();
	posX = 0.0f;
	posY = 0.0f;

}

void HealthPointBar::OnUpdate(float delta)
{
	UpdateObject();
}

void HealthPointBar::draw()
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
	glDrawArrays(GL_TRIANGLES, 0, BAR_NUM);
}

void HealthPointBar::drawW()
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
	glDrawArrays(GL_TRIANGLES, 0, BAR_NUM);
}