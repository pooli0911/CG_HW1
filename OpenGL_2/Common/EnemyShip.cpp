#include "EnemyShip.h"

EnemyShip::EnemyShip()
{
	_NumVertex = ENEMYSHIP_NUM;
	_Points = new vec4[ENEMYSHIP_NUM];

	//_Points[0] = vec4( 0.0f,  1.0f, 0.0f, 1.0f);
	//_Points[1] = vec4(-1.0f,  0.0f, 0.0f, 1.0f);
	//_Points[2] = vec4( 1.0f,  0.0f, 0.0f, 1.0f);


	// Left Wing
	_Points[0] = vec4(-2.8f, 0.8f, 0.0f, 1.0f); // F
	_Points[1] = vec4(-2.0f, -1.0f, 0.0f, 1.0f); // G
	_Points[2] = vec4(-0.6f, -0.4f, 0.0f, 1.0f); // K
	_Points[3] = _Points[0]; // F
	_Points[4] = vec4(-0.6f, 0.4f, 0.0f, 1.0f); // E
	_Points[5] = _Points[2]; // K

	// Right Wing
	_Points[6] = vec4(2.8f, 0.8f, 0.0f, 1.0f); // I
	_Points[7] = vec4(2.0f, -1.0f, 0.0f, 1.0f); // J
	_Points[8] = vec4(0.6f, -0.4f, 0.0f, 1.0f); // L
	_Points[9] = _Points[6]; // I
	_Points[10] = vec4(0.6f, 0.4f, 0.0f, 1.0f); // H
	_Points[11] = _Points[8]; // L

	// Ship Body
	_Points[12] = vec4(0.0f, 1.0f, 0.0f, 1.0f); // A
	_Points[13] = vec4(-1.0f, 0.0f, 0.0f, 1.0f); // B
	_Points[14] = vec4(0.0f, -1.0f, 0.0f, 1.0f); // C
	_Points[15] = _Points[12]; // A
	_Points[16] = _Points[14]; // C
	_Points[17] = vec4(1.0f, 0.0f, 0.0f, 1.0f); // D
	

	_Colors = new vec4[ENEMYSHIP_NUM];

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
	

	// Create and initialize a buffer object 
	CreateBufferObject();
	_bUpdateProj = false;

	InitObject();

	posY = 15.0f;
	posX = rand() % 15 - 7.5f;
}

void EnemyShip::OnUpdate(float delta)
{
	UpdateObject();
}


void EnemyShip::draw()
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
	glDrawArrays(GL_TRIANGLES, 0, ENEMYSHIP_NUM);
}

void EnemyShip::drawW()
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
	glDrawArrays(GL_TRIANGLES, 0, ENEMYSHIP_NUM);
}
