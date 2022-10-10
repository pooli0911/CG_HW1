#include "Bullet.h"

Bullet::Bullet(float x, float y) 
{
	_isCollide = false;
	_isShoot = false;
	//BulletSpeed = 30.0f;

	_NumVertex = BULLET_NUM;

	_Points = new vec4[BULLET_NUM];

	_Points[0] = vec4(-0.1f, 0.2f, 0.0f, 1.0f);
	_Points[1] = vec4(-0.1f, -0.2f, 0.0f, 1.0f);
	_Points[2] = vec4(0.1f, -0.2f, 0.0f, 1.0f);
	_Points[3] = vec4(-0.1f, 0.2f, 0.0f, 1.0f);
	_Points[4] = vec4(0.1f, -0.2f, 0.0f, 1.0f);
	_Points[5] = vec4(0.1f, 0.2f, 0.0f, 1.0f);

	_Colors = new vec4[BULLET_NUM];

	_Colors[0] = vec4(1.0f, 1.0f, 1.0f, 1.0f);  // (r, g, b, a)
	_Colors[1] = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	_Colors[2] = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	_Colors[3] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_Colors[4] = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	_Colors[5] = vec4(0.0f, 0.0f, 1.0f, 1.0f);

	// Create and initialize a buffer object 
	CreateBufferObject();
	_bUpdateProj = false;

	InitObject();

	posY = y;
	posX = x;
}

void Bullet::OnUpdate(float delta)
{
	UpdateObject();
}

void Bullet::ShootUp(float delta, float passive_x)
{
	if (!_isShoot) {
		//posX = passive_x;
		_isShoot = true;
	}
	posY += delta * BulletSpeed;
}

void Bullet::ShootDown(float delta, float passive_x)
{
	if (!_isShoot) {
		posX = passive_x;
		_isShoot = true;
	}
	posY += delta * BulletSpeed * -1;
}

void Bullet::ResetBullet(float x, float y) 
{
	if ( this->posY > 800.0f)	_isShoot = false;
	posY = y;
	posX = x;
}


void Bullet::draw()
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
	glDrawArrays(GL_TRIANGLES, 0, BULLET_NUM);
}

void Bullet::drawW()
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
	glDrawArrays(GL_TRIANGLES, 0, BULLET_NUM);
}