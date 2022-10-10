#include "PlayerShip3.h"

PlayerShip3::PlayerShip3()
{
	_NumVertex = PLAYERSHIP3_NUM;
	_Points = new vec4[PLAYERSHIP3_NUM];

	//player3
	_Points[0] = vec4(0.0f, 3.0f, 0.0f, 1.0f); //a
	_Points[1] = vec4(-1.0f, 0.0f, 0.0f, 1.0f); //b
	_Points[2] = vec4(1.0f, 0.0f, 0.0f, 1.0f); //c

	_Points[3] = vec4(-1.0f, 0.0f, 0.0f, 1.0f); //b
	_Points[4] = vec4(0.0f, -1.0f, 0.0f, 1.0f); //d
	_Points[5] = vec4(1.0f, 0.0f, 0.0f, 1.0f); //c

	_Points[6] = vec4(-1.2f, 2.0f, 0.0f, 1.0f); //u
	_Points[7] = vec4(-1.5f, 0.3f, 0.0f, 1.0f); //q
	_Points[8] = vec4(-0.2f, 0.0f, 0.0f, 1.0f); //w

	_Points[9] = vec4(-1.5f, 0.3f, 0.0f, 1.0f); //q
	_Points[10] = vec4(-1.0f, 0.0f, 0.0f, 1.0f); //b
	_Points[11] = vec4(-0.2f, 0.0f, 0.0f, 1.0f); //w

	_Points[12] = vec4(-2.0f, 1.0f, 0.0f, 1.0f); //i
	_Points[13] = vec4(-2.0f, 0.5f, 0.0f, 1.0f); //m
	_Points[14] = vec4(-1.0f, 0.0f, 0.0f, 1.0f); //b

	_Points[15] = vec4(-2.0f, 1.0f, 0.0f, 1.0f); //i
	_Points[16] = vec4(-3.8f, 0.4f, 0.0f, 1.0f); //k
	_Points[17] = vec4(-2.0f, 0.5f, 0.0f, 1.0f); //m

	_Points[18] = vec4(-2.0f, 0.5f, 0.0f, 1.0f); //m
	_Points[19] = vec4(-3.5f, -0.3f, 0.0f, 1.0f); //s
	_Points[20] = vec4(-1.5f, 0.3f, 0.0f, 1.0f); //q

	_Points[21] = vec4(-1.5f, 0.3f, 0.0f, 1.0f); //q
	_Points[22] = vec4(-2.4f, -1.0f, 0.0f, 1.0f); //o
	_Points[23] = vec4(-1.0f, 0.0f, 0.0f, 1.0f); //b

	_Points[24] = vec4(-1.0f, 0.0f, 0.0f, 1.0f); //b
	_Points[25] = vec4(-1.0f, -1.4f, 0.0f, 1.0f); //e
	_Points[26] = vec4(-0.6f, -0.4f, 0.0f, 1.0f); //g

	_Points[27] = vec4(1.2f, 2.0f, 0.0f, 1.0f); //v
	_Points[28] = vec4(0.2f, 0.0f, 0.0f, 1.0f); //z
	_Points[29] = vec4(1.5f, 0.3f, 0.0f, 1.0f); //r

	_Points[30] = vec4(1.5f, 0.3f, 0.0f, 1.0f); //r
	_Points[31] = vec4(0.2f, 0.0f, 0.0f, 1.0f); //z
	_Points[32] = vec4(1.0f, 0.0f, 0.0f, 1.0f); //c

	_Points[33] = vec4(2.0f, 1.0f, 0.0f, 1.0f); //j
	_Points[34] = vec4(1.0f, 0.0f, 0.0f, 1.0f); //c
	_Points[35] = vec4(2.0f, 0.5f, 0.0f, 1.0f); //n

	_Points[36] = vec4(2.0f, 1.0f, 0.0f, 1.0f); //j
	_Points[37] = vec4(2.0f, 0.5f, 0.0f, 1.0f); //n
	_Points[38] = vec4(3.8f, 0.4f, 0.0f, 1.0f); //l

	_Points[39] = vec4(2.0f, 0.5f, 0.0f, 1.0f); //n
	_Points[40] = vec4(1.5f, 0.3f, 0.0f, 1.0f); //r
	_Points[41] = vec4(3.5f, -0.3f, 0.0f, 1.0f); //t

	_Points[42] = vec4(1.5f, 0.3f, 0.0f, 1.0f); //r
	_Points[43] = vec4(1.0f, 0.0f, 0.0f, 1.0f); //c
	_Points[44] = vec4(2.4f, -1.0f, 0.0f, 1.0f); //p

	_Points[45] = vec4(1.0f, 0.0f, 0.0f, 1.0f); //c
	_Points[46] = vec4(0.6f, -0.4f, 0.0f, 1.0f); //h
	_Points[47] = vec4(1.0f, -1.4f, 0.0f, 1.0f); //f

	_Colors = new vec4[PLAYERSHIP3_NUM];

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

void PlayerShip3::OnUpdate(float delta)
{
	UpdateObject();
}


void PlayerShip3::draw()
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
	glDrawArrays(GL_TRIANGLES, 0, PLAYERSHIP3_NUM);
}

void PlayerShip3::drawW()
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
	glDrawArrays(GL_TRIANGLES, 0, PLAYERSHIP3_NUM);
}
