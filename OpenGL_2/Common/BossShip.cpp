#include "BossShip.h"

BossShip::BossShip()
{
	_NumVertex = BOSSSHIP_NUM;
	_Points = new vec4[BOSSSHIP_NUM];

	_Points[0] = vec4(-1.4f, 1.4f, 0.0f, 1.0f); //g
	_Points[1] = vec4(-1.8f, 0.4f, 0.0f, 1.0f); //c
	_Points[2] = vec4(-1.2f, 1.0f, 0.0f, 1.0f); //a

	_Points[3] = vec4(0.0f, 2.0f, 0.0f, 1.0f); //q
	_Points[4] = vec4(-0.6f, 1.0f, 0.0f, 1.0f); //o
	_Points[5] = vec4(0.6f, 1.0f, 0.0f, 1.0f); //p

	_Points[6] = vec4(-2.4f, 0.8f, 0.0f, 1.0f); //i
	_Points[7] = vec4(-1.8f, 0.4f, 0.0f, 1.0f); //c
	_Points[8] = vec4(-1.4f, -0.2f, 0.0f, 1.0f); //m

	_Points[9] = vec4(-2.4f, 0.8f, 0.0f, 1.0f); //i
	_Points[10] = vec4(-2.0f, -2.0f, 0.0f, 1.0f); //k
	_Points[11] = vec4(-1.4f, -0.2f, 0.0f, 1.0f); //m

	_Points[12] = vec4(-1.2f, 1.0f, 0.0f, 1.0f); //a
	_Points[13] = vec4(-1.8f, 0.4f, 0.0f, 1.0f); //c
	_Points[14] = vec4(-0.8f, -1.0f, 0.0f, 1.0f); //e

	_Points[15] = vec4(-1.2f, 1.0f, 0.0f, 1.0f); //a
	_Points[16] = vec4(-0.8f, -1.0f, 0.0f, 1.0f); //e
	_Points[17] = vec4(0.8f, -1.0f, 0.0f, 1.0f); //f

	_Points[18] = vec4(-1.2f, 1.0f, 0.0f, 1.0f); //a
	_Points[19] = vec4(0.8f, -1.0f, 0.0f, 1.0f); //f
	_Points[20] = vec4(1.2f, 1.0f, 0.0f, 1.0f); //b

	_Points[21] = vec4(1.2f, 1.0f, 0.0f, 1.0f); //b
	_Points[22] = vec4(0.8f, -1.0f, 0.0f, 1.0f); //f
	_Points[23] = vec4(1.8f, 0.4f, 0.0f, 1.0f); //d

	_Points[24] = vec4(1.4f, 1.4f, 0.0f, 1.0f); //h
	_Points[25] = vec4(1.2f, 1.0f, 0.0f, 1.0f); //b
	_Points[26] = vec4(1.8f, 0.4f, 0.0f, 1.0f); //d

	_Points[27] = vec4(2.4f, 0.8f, 0.0f, 1.0f); //j
	_Points[28] = vec4(1.8f, 0.4f, 0.0f, 1.0f); //d
	_Points[29] = vec4(1.4f, -0.2f, 0.0f, 1.0f); //n

	_Points[30] = vec4(2.4f, 0.8f, 0.0f, 1.0f); //j
	_Points[31] = vec4(1.4f, -0.2f, 0.0f, 1.0f); //n
	_Points[32] = vec4(2.0f, -2.0f, 0.0f, 1.0f); //l


	_Colors = new vec4[BOSSSHIP_NUM];

	for (int i = 0; i < BOSSSHIP_NUM; i++) {
		_Colors[i] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	}



	// Create and initialize a buffer object 
	CreateBufferObject();
	_bUpdateProj = false;

	InitObject();

	posY = 15.0f;
	posX = rand() % 15 - 7.5f;
}

void BossShip::OnUpdate(float delta)
{
	UpdateObject();
}


void BossShip::draw()
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
	glDrawArrays(GL_TRIANGLES, 0, BOSSSHIP_NUM);
}

void BossShip::drawW()
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
	glDrawArrays(GL_TRIANGLES, 0, BOSSSHIP_NUM);
}
