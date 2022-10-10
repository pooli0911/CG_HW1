#include "BossShip2.h"

BossShip2::BossShip2()
{
	_NumVertex = BOSSSHIP2_NUM;
	_Points = new vec4[BOSSSHIP2_NUM];

	//boss2
	_Points[0] = vec4(-0.8f, 2.4f, 0.0f, 1.0f); //a
	_Points[1] = vec4(-1.2f, 2.0f, 0.0f, 1.0f); //c
	_Points[2] = vec4(0.8f, 2.4f, 0.0f, 1.0f); //b

	_Points[3] = vec4(0.8f, 2.4f, 0.0f, 1.0f); //b
	_Points[4] = vec4(-1.2f, 2.0f, 0.0f, 1.0f); //c
	_Points[5] = vec4(-0.6f, 0.0f, 0.0f, 1.0f); //u

	_Points[6] = vec4(0.8f, 2.4f, 0.0f, 1.0f); //b
	_Points[7] = vec4(-0.6f, 0.0f, 0.0f, 1.0f); //u
	_Points[8] = vec4(0.6f, 0.0f, 0.0f, 1.0f); //v

	_Points[9] = vec4(0.8f, 2.4f, 0.0f, 1.0f); //b
	_Points[10] = vec4(0.6f, 0.0f, 0.0f, 1.0f); //v
	_Points[11] = vec4(1.2f, 2.0f, 0.0f, 1.0f); //d

	_Points[12] = vec4(-1.4f, 2.2f, 0.0f, 1.0f); //e
	_Points[13] = vec4(-0.6f, 0.0f, 0.0f, 1.0f); //u
	_Points[14] = vec4(-1.2f, 2.0f, 0.0f, 1.0f); //c

	_Points[15] = vec4(-1.4f, 2.2f, 0.0f, 1.0f); //e
	_Points[16] = vec4(-2.0f, 0.5f, 0.0f, 1.0f); //g1
	_Points[17] = vec4(-1.2f, 2.0f, 0.0f, 1.0f); //c

	_Points[18] = vec4(-1.2f, 2.0f, 0.0f, 1.0f); //c
	_Points[19] = vec4(-2.0f, 0.5f, 0.0f, 1.0f); //g1
	_Points[20] = vec4(-0.6f, 0.0f, 0.0f, 1.0f); //u

	_Points[21] = vec4(-2.0f, 2.4f, 0.0f, 1.0f); //g
	_Points[22] = vec4(-2.0f, 0.5f, 0.0f, 1.0f); //g1
	_Points[23] = vec4(-1.4f, 2.2f, 0.0f, 1.0f); //e

	_Points[24] = vec4(-2.0f, 2.4f, 0.0f, 1.0f); //g
	_Points[25] = vec4(-3.0f, 1.3f, 0.0f, 1.0f); //w
	_Points[26] = vec4(-2.0f, 0.5f, 0.0f, 1.0f); //g1

	_Points[27] = vec4(-2.4f, 2.6f, 0.0f, 1.0f); //i
	_Points[28] = vec4(-3.0f, 1.3f, 0.0f, 1.0f); //w
	_Points[29] = vec4(-2.0f, 2.4f, 0.0f, 1.0f); //g 

	_Points[30] = vec4(-2.8f, 3.3f, 0.0f, 1.0f); //m
	_Points[31] = vec4(-3.0f, 1.3f, 0.0f, 1.0f); //w
	_Points[32] = vec4(-2.2f, 3.0f, 0.0f, 1.0f); //k

	_Points[33] = vec4(-2.8f, 3.3f, 0.0f, 1.0f); //m
	_Points[34] = vec4(-3.8f, 2.0f, 0.0f, 1.0f); //o
	_Points[35] = vec4(-3.0f, 1.3f, 0.0f, 1.0f); //w

	_Points[36] = vec4(-3.8f, 2.0f, 0.0f, 1.0f); //o
	_Points[37] = vec4(-2.6f, -1.0f, 0.0f, 1.0f); //q
	_Points[38] = vec4(-1.0f, -0.5f, 0.0f, 1.0f); //s

	_Points[39] = vec4(-3.8f, 2.0f, 0.0f, 1.0f); //o
	_Points[40] = vec4(-1.0f, -0.5f, 0.0f, 1.0f); //s
	_Points[41] = vec4(-0.6f, 0.0f, 0.0f, 1.0f); //u

	_Points[42] = vec4(-3.0f, 1.3f, 0.0f, 1.0f); //w
	_Points[43] = vec4(-4.2f, 0.5f, 0.0f, 1.0f); //e1
	_Points[44] = vec4(-2.0f, 0.5f, 0.0f, 1.0f); //g1

	_Points[45] = vec4(-5.0f, 1.3f, 0.0f, 1.0f); //z
	_Points[46] = vec4(-4.2f, 0.5f, 0.0f, 1.0f); //e1
	_Points[47] = vec4(-3.0f, 1.3f, 0.0f, 1.0f); //w

	_Points[48] = vec4(-5.0f, 1.3f, 0.0f, 1.0f); //z
	_Points[49] = vec4(-6.0f, -0.6f, 0.0f, 1.0f); //c1
	_Points[50] = vec4(-4.2f, 0.5f, 0.0f, 1.0f); //e1

	_Points[51] = vec4(1.2f, 2.0f, 0.0f, 1.0f); //d
	_Points[52] = vec4(0.6f, 0.0f, 0.0f, 1.0f); //v
	_Points[53] = vec4(1.0f, -0.5f, 0.0f, 1.0f); //t

	_Points[54] = vec4(1.2f, 2.0f, 0.0f, 1.0f); //d
	_Points[55] = vec4(1.0f, -0.5f, 0.0f, 1.0f); //t
	_Points[56] = vec4(2.6f, -1.0f, 0.0f, 1.0f); //r

	_Points[57] = vec4(1.2f, 2.0f, 0.0f, 1.0f); //d
	_Points[58] = vec4(2.6f, -1.0f, 0.0f, 1.0f); //r
	_Points[59] = vec4(1.4f, 2.2f, 0.0f, 1.0f); //f

	_Points[60] = vec4(1.4f, 2.2f, 0.0f, 1.0f); //f
	_Points[61] = vec4(2.6f, -1.0f, 0.0f, 1.0f); //r
	_Points[62] = vec4(2.0f, 2.4f, 0.0f, 1.0f); //h

	_Points[63] = vec4(2.0f, 2.4f, 0.0f, 1.0f); //h
	_Points[64] = vec4(2.6f, -1.0f, 0.0f, 1.0f); //r
	_Points[65] = vec4(2.4f, 2.6f, 0.0f, 1.0f); //j

	_Points[66] = vec4(2.4f, 2.6f, 0.0f, 1.0f); //j
	_Points[67] = vec4(2.6f, -1.0f, 0.0f, 1.0f); //r
	_Points[68] = vec4(3.8f, 2.0f, 0.0f, 1.0f); //p

	_Points[69] = vec4(2.8f, 3.3f, 0.0f, 1.0f); //n
	_Points[70] = vec4(2.4f, 2.6f, 0.0f, 1.0f); //j
	_Points[71] = vec4(3.8f, 2.0f, 0.0f, 1.0f); //p

	_Points[72] = vec4(2.8f, 3.3f, 0.0f, 1.0f); //n
	_Points[73] = vec4(2.2f, 3.0f, 0.0f, 1.0f); //l
	_Points[74] = vec4(2.4f, 2.6f, 0.0f, 1.0f); //j

	_Points[75] = vec4(3.0f, 1.3f, 0.0f, 1.0f); //a1
	_Points[76] = vec4(2.0f, 0.5f, 0.0f, 1.0f); //h1
	_Points[77] = vec4(4.2f, 0.5f, 0.0f, 1.0f); //f1

	_Points[78] = vec4(3.0f, 1.3f, 0.0f, 1.0f); //a1
	_Points[79] = vec4(4.2f, 0.5f, 0.0f, 1.0f); //f1
	_Points[80] = vec4(5.0f, 1.3f, 0.0f, 1.0f); //b1

	_Points[81] = vec4(5.0f, 1.3f, 0.0f, 1.0f); //b1
	_Points[82] = vec4(4.2f, 0.5f, 0.0f, 1.0f); //f1
	_Points[83] = vec4(6.0f, -0.6f, 0.0f, 1.0f); //d1

	_Points[84] = vec4(-0.8f, 3.0f, 0.0f, 1.0f); //i1
	_Points[85] = vec4(-0.8f, 2.4f, 0.0f, 1.0f); //a
	_Points[86] = vec4(-0.4f, 2.4f, 0.0f, 1.0f); //k1

	_Points[87] = vec4(0.0f, 3.4f, 0.0f, 1.0f); //m1
	_Points[88] = vec4(-0.4f, 2.4f, 0.0f, 1.0f); //k1
	_Points[89] = vec4(0.4f, 2.4f, 0.0f, 1.0f); //l1

	_Points[90] = vec4(0.8f, 3.0f, 0.0f, 1.0f); //j1
	_Points[91] = vec4(0.4f, 2.4f, 0.0f, 1.0f); //l1
	_Points[92] = vec4(0.8f, 2.4f, 0.0f, 1.0f); //b


	_Colors = new vec4[BOSSSHIP2_NUM];

	for (int i = 0; i < BOSSSHIP2_NUM; i++) {
		_Colors[i] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	}



	// Create and initialize a buffer object 
	CreateBufferObject();
	_bUpdateProj = false;

	InitObject();

	posY = 15.0f;
	posX = rand() % 15 - 7.5f;
}

void BossShip2::OnUpdate(float delta)
{
	UpdateObject();
}


void BossShip2::draw()
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
	glDrawArrays(GL_TRIANGLES, 0, BOSSSHIP2_NUM);
}

void BossShip2::drawW()
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
	glDrawArrays(GL_TRIANGLES, 0, BOSSSHIP2_NUM);
}
