#include "PlayerSmallShip.h"

PlayerSmallShip::PlayerSmallShip()
{
	_NumVertex = PLAYERSMALLSHIP_NUM;
	_Points = new vec4[PLAYERSMALLSHIP_NUM];

	_Points[0] = vec4(-0.8f, -0.5f, 0.0f, 1.0f); //a
	_Points[1] = vec4(0.8f, -0.5f, 0.0f, 1.0f); //c
	_Points[2] = vec4(0.0f, 1.0f, 0.0f, 1.0f); //i


	_Colors = new vec4[PLAYERSMALLSHIP_NUM];

	for (int i = 0; i < _NumVertex; i++)
	{
		_Colors[i] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	}


	// Create and initialize a buffer object 
	CreateBufferObject();
	_bUpdateProj = false;

	InitObject();

	posY = -8;
}

void PlayerSmallShip::OnUpdate(float delta)
{
	UpdateObject();
}


void PlayerSmallShip::draw()
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
	glDrawArrays(GL_TRIANGLES, 0, PLAYERSMALLSHIP_NUM);
}

void PlayerSmallShip::drawW()
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
	glDrawArrays(GL_TRIANGLES, 0, PLAYERSMALLSHIP_NUM);
}
