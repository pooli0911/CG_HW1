#include "EnemyShip2.h"

EnemyShip2::EnemyShip2()
{
	_NumVertex = ENEMYSHIP2_NUM;
	_Points = new vec4[ENEMYSHIP2_NUM];

	//_Points[0] = vec4( 0.0f,  1.0f, 0.0f, 1.0f);
	//_Points[1] = vec4(-1.0f,  0.0f, 0.0f, 1.0f);
	//_Points[2] = vec4( 1.0f,  0.0f, 0.0f, 1.0f);


	// Left Wing
	_Points[0] = vec4(-1.4f, 0.2f, 0.0f, 1.0f); // H
	_Points[1] = vec4(-0.8f, -1.2f, 0.0f, 1.0f); // J
	_Points[2] = vec4(-1.0f, -0.2f, 0.0f, 1.0f); // L
	_Points[3] = _Points[0]; // H
	_Points[4] = vec4(-0.6f, 0.0f, 0.0f, 1.0f); // C
	_Points[5] = _Points[2]; // L
	_Points[6] = _Points[3]; // H
	_Points[7] = _Points[4]; // C
	_Points[8] = vec4(-0.8f, 0.4f, 0.0f, 1.0f); // F

	// Right Wing
	_Points[9] = vec4(1.4f, 0.2f, 0.0f, 1.0f); // I
	_Points[10] = vec4(0.8f, -1.2f, 0.0f, 1.0f); // K
	_Points[11] = vec4(1.0f, -0.2f, 0.0f, 1.0f); // M
	_Points[12] = _Points[9]; // I
	_Points[13] = vec4(0.6f, 0.0f, 0.0f, 1.0f); // D
	_Points[14] = _Points[11]; // M
	_Points[15] = _Points[12]; // I
	_Points[16] = vec4(0.8f, 0.4f, 0.0f, 1.0f); // G
	_Points[17] = _Points[13]; // D

	// Ship Body
	_Points[18] = vec4(-1.0f, 1.0f, 0.0f, 1.0f); // A
	_Points[19] = _Points[4]; // C
	_Points[20] = _Points[17]; // D
	_Points[21] = _Points[18]; // A
	_Points[22] = _Points[20]; // D
	_Points[23] = vec4(1.0f, 1.0f, 0.0f, 1.0f); // B
	_Points[24] = _Points[21]; // A
	_Points[25] = _Points[23]; // B
	_Points[26] = vec4(0.0f, 1.4f, 0.0f, 1.0f); // E


	_Colors = new vec4[ENEMYSHIP2_NUM];

	_Colors[0] = vec4(1.0f, 1.0f, 1.0f, 1.0f);  // (r, g, b, a)
	_Colors[1] = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	_Colors[2] = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	_Colors[3] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[4] = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	_Colors[5] = vec4(0.0f, 0.0f, 1.0f, 1.0f);
	_Colors[6] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[7] = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	_Colors[8] = vec4(0.0f, 0.0f, 1.0f, 1.0f);
	_Colors[9] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[10] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[11] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[12] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[13] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[14] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[15] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[16] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[17] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[18] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[19] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[20] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[21] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[22] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[23] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[24] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[25] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[26] = vec4(1.0f, 1.0f, 1.0f, 1.0f);


	// Create and initialize a buffer object 
	CreateBufferObject();
	_bUpdateProj = false;

	InitObject();

	posY = 15.0f;
	posX = rand() % 15 - 7.5f;
}

void EnemyShip2::OnUpdate(float delta)
{
	UpdateObject();
}


void EnemyShip2::draw()
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
	glDrawArrays(GL_TRIANGLES, 0, ENEMYSHIP2_NUM);
}

void EnemyShip2::drawW()
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
	glDrawArrays(GL_TRIANGLES, 0, ENEMYSHIP2_NUM);
}