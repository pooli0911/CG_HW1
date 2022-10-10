#include "Treasure.h"

Treasure::Treasure()
{

	_NumVertex = TREASURE_NUM;
	_Points = new vec4[_NumVertex];
	_Colors = new vec4[_NumVertex];

	//upgrade
	_Points[0] = vec4(0.0f, 2.5f, 0.0f, 1.0f); //a
	_Points[1] = vec4(-1.2f, 1.8f, 0.0f, 1.0f); //c
	_Points[2] = vec4(-1.1f, 1.3f, 0.0f, 1.0f); //d

	_Points[3] = vec4(0.0f, 2.5f, 0.0f, 1.0f); //a
	_Points[4] = vec4(-1.1f, 1.3f, 0.0f, 1.0f); //d
	_Points[5] = vec4(0.0f, 2.0f, 0.0f, 1.0f); //b

	_Points[6] = vec4(0.0f, 2.5f, 0.0f, 1.0f); //a
	_Points[7] = vec4(0.0f, 2.0f, 0.0f, 1.0f); //b
	_Points[8] = vec4(1.1f, 1.3f, 0.0f, 1.0f); //e

	_Points[9] = vec4(0.0f, 2.5f, 0.0f, 1.0f); //a
	_Points[10] = vec4(1.1f, 1.3f, 0.0f, 1.0f); //e
	_Points[11] = vec4(1.2f, 1.8f, 0.0f, 1.0f); //f

	_Points[12] = vec4(0.0f, 1.4f, 0.0f, 1.0f); //g
	_Points[13] = vec4(-1.1f, 0.6f, 0.0f, 1.0f); //i
	_Points[14] = vec4(-1.0f, 0.2f, 0.0f, 1.0f); //k

	_Points[15] = vec4(0.0f, 1.4f, 0.0f, 1.0f); //g
	_Points[16] = vec4(-1.0f, 0.2f, 0.0f, 1.0f); //k
	_Points[17] = vec4(0.0f, 0.9f, 0.0f, 1.0f); //h

	_Points[18] = vec4(0.0f, 1.4f, 0.0f, 1.0f); //g
	_Points[19] = vec4(0.0f, 0.9f, 0.0f, 1.0f); //h
	_Points[20] = vec4(1.0f, 0.2f, 0.0f, 1.0f); //l

	_Points[21] = vec4(0.0f, 1.4f, 0.0f, 1.0f); //g
	_Points[22] = vec4(1.0f, 0.2f, 0.0f, 1.0f); //l
	_Points[23] = vec4(1.1f, 0.6f, 0.0f, 1.0f); //j


	for (int i = 0; i < _NumVertex; i++) {
		_Colors[i] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	}


	// Create and initialize a buffer object 
	CreateBufferObject();
	_bUpdateProj = false;

	InitObject();
	posY = 8.0f;
	scaleX = scaleY = 0.3f;

}

void Treasure::OnUpdate(float delta)
{
	UpdateObject();
}

void Treasure::draw()
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
	glDrawArrays(GL_TRIANGLES, 0, TREASURE_NUM);
}

void Treasure::drawW()
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
	glDrawArrays(GL_TRIANGLES, 0, TREASURE_NUM);
}