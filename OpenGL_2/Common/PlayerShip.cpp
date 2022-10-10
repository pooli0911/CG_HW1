#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
	_NumVertex = PLAYERSHIP_NUM;
	_Points = new vec4[PLAYERSHIP_NUM];

	//_Points[0] = vec4( 0.0f,  1.0f, 0.0f, 1.0f);
	//_Points[1] = vec4(-1.0f,  0.0f, 0.0f, 1.0f);
	//_Points[2] = vec4( 1.0f,  0.0f, 0.0f, 1.0f);


	// Left Wing
	_Points[0] = vec4(-0.6f, 1.0f, 0.0f, 1.0f); // G
	_Points[1] = vec4(-2.2f, -0.4f, 0.0f, 1.0f); // H
	_Points[2] = vec4(-1.6f, -1.0f, 0.0f, 1.0f); // K
	_Points[3] = _Points[0]; // G
	_Points[4] = vec4(-0.6f, -0.6f, 0.0f, 1.0f); // M
	_Points[5] = _Points[2]; // K

	// Right Wing
	_Points[6] = vec4(0.6f, 1.0f, 0.0f, 1.0f); // I
	_Points[7] = vec4(2.2f, -0.4f, 0.0f, 1.0f); // J
	_Points[8] = vec4(1.6f, -1.0f, 0.0f, 1.0f); // L
	_Points[9] = _Points[6]; // I
	_Points[10] = vec4(0.6f, -0.6f, 0.0f, 1.0f); // N
	_Points[11] = _Points[8]; // L

	// Ship Body
	_Points[12] = vec4(-0.2f, 2.0f, 0.0f, 1.0f); // A
	_Points[13] = vec4(-1.0f, 0.0f, 0.0f, 1.0f); // C
	_Points[14] = vec4(-0.3f, -1.0f, 0.0f, 1.0f); // E
	_Points[15] = _Points[12]; // A
	_Points[16] = _Points[14]; // E
	_Points[17] = vec4(0.3f, -1.0f, 0.0f, 1.0f); // F
	_Points[18] = _Points[12]; // A
	_Points[19] = _Points[17]; // F
	_Points[20] = vec4(1.0f, 0.0f, 0.0f, 1.0f); // D
	_Points[21] = _Points[12]; // A
	_Points[22] = _Points[20]; // D
	_Points[23] = vec4(0.2f, 2.0f, 0.0f, 1.0f); // B

	// Ship Core
	_Points[24] = vec4(0.0f, 1.0f, 0.0f, 1.0f); // S
	_Points[25] = vec4(-0.4f, 0.0f, 0.0f, 1.0f); // T
	_Points[26] = vec4(0.4f, 0.0f, 0.0f, 1.0f); // U

	// Left Tail
	_Points[27] = vec4(-1.0f, -0.8f, 0.0f, 1.0f); // O
	_Points[28] = vec4(-0.8f, -1.4f, 0.0f, 1.0f); // R
	_Points[29] = _Points[4]; // M

	// Reft Tail
	_Points[30] = vec4(1.0f, -0.8f, 0.0f, 1.0f); // P
	_Points[31] = vec4(0.8f, -1.4f, 0.0f, 1.0f); // Q
	_Points[32] = _Points[10];; // N 

	_Colors = new vec4[PLAYERSHIP_NUM];

	_Colors[0]  = vec4(1.0f, 1.0f, 1.0f, 1.0f);  // (r, g, b, a)
	_Colors[1]  = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	_Colors[2]  = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	_Colors[3] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[4]  = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	_Colors[5]  = vec4(0.0f, 0.0f, 1.0f, 1.0f);
	_Colors[6]  = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[7]  = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	_Colors[8]  = vec4(0.0f, 0.0f, 1.0f, 1.0f);
	_Colors[9]  = vec4(1.0f, 1.0f, 1.0f, 1.0f);
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
	_Colors[27] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[28] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[29] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[30] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[31] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[32] = vec4(1.0f, 1.0f, 1.0f, 1.0f);

	// Create and initialize a buffer object 
	CreateBufferObject();
	_bUpdateProj = false;

	InitObject();

	posY = -8;
}

void PlayerShip::OnUpdate(float delta)
{
	UpdateObject();
}


void PlayerShip::draw()
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
	glDrawArrays(GL_TRIANGLES, 0, PLAYERSHIP_NUM);
}

void PlayerShip::drawW()
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
	glDrawArrays(GL_TRIANGLES, 0, PLAYERSHIP_NUM);
}
