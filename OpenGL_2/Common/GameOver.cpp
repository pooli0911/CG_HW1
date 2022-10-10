#include "GameOver.h"

GameOver::GameOver()
{
	_NumVertex = GAMEOVER_NUM;
	_Points = new vec4[GAMEOVER_NUM];

	//_Points[0] = vec4( 0.0f,  1.0f, 0.0f, 1.0f);
	//_Points[1] = vec4(-1.0f,  0.0f, 0.0f, 1.0f);
	//_Points[2] = vec4( 1.0f,  0.0f, 0.0f, 1.0f);


	//G
	_Points[0] = vec4(-2.2f, 1.4f, 0.0f, 1.0f); // c
	_Points[1] = vec4(-1.5f, 1.2f, 0.0f, 1.0f); // w
	_Points[2] = vec4(-1.5f, 1.4f, 0.0f, 1.0f); // z

	_Points[3] = vec4(-2.2f, 1.4f, 0.0f, 1.0f); // c
	_Points[4] = vec4(-2.2f, 1.2f, 0.0f, 1.0f); // d
	_Points[5] = vec4(-1.5f, 1.2f, 0.0f, 1.0f); // w

	_Points[6] = vec4(-2.4f, 1.2f, 0.0f, 1.0f); // e
	_Points[7] = vec4(-1.3f, 1.2f, 0.0f, 1.0f); // v
	_Points[8] = vec4(-2.1f, 1.0f, 0.0f, 1.0f); // t

	_Points[9] = vec4(-1.3f, 1.2f, 0.0f, 1.0f); // v
	_Points[10] = vec4(-2.1f, 1.0f, 0.0f, 1.0f); // t
	_Points[11] = vec4(-1.3f, 1.0f, 0.0f, 1.0f); // u

	_Points[12] = vec4(-2.4f, 1.2f, 0.0f, 1.0f); // e
	_Points[13] = vec4(-2.1f, 1.0f, 0.0f, 1.0f); // t
	_Points[14] = vec4(-2.4f, 0.2f, 0.0f, 1.0f); // f

	_Points[15] = vec4(-2.1f, 1.0f, 0.0f, 1.0f); // t
	_Points[16] = vec4(-2.4f, 0.2f, 0.0f, 1.0f); // f
	_Points[17] = vec4(-2.1f, 0.4f, 0.0f, 1.0f); // s

	_Points[18] = vec4(-2.1f, 0.4f, 0.0f, 1.0f); // s
	_Points[19] = vec4(-2.4f, 0.2f, 0.0f, 1.0f); // f
	_Points[20] = vec4(-2.2f, 0.2f, 0.0f, 1.0f); // g

	_Points[21] = vec4(-2.1f, 0.4f, 0.0f, 1.0f); // s
	_Points[22] = vec4(-2.2f, 0.2f, 0.0f, 1.0f); // g
	_Points[23] = vec4(-1.7f, 0.4f, 0.0f, 1.0f); // r

	_Points[24] = vec4(-1.7f, 0.4f, 0.0f, 1.0f); // r
	_Points[25] = vec4(-2.2f, 0.2f, 0.0f, 1.0f); // g
	_Points[26] = vec4(-1.6f, 0.3f, 0.0f, 1.0f); // j

	_Points[27] = vec4(-1.6f, 0.3f, 0.0f, 1.0f); // j
	_Points[28] = vec4(-2.2f, 0.2f, 0.0f, 1.0f); // g
	_Points[29] = vec4(-2.2f, 0.0f, 0.0f, 1.0f); // h

	_Points[30] = vec4(-1.6f, 0.3f, 0.0f, 1.0f); // j
	_Points[31] = vec4(-2.2f, 0.0f, 0.0f, 1.0f); // h
	_Points[32] = vec4(-1.6f, 0.0f, 0.0f, 1.0f); // i

	_Points[33] = vec4(-1.7f, 0.4f, 0.0f, 1.0f); // r
	_Points[34] = vec4(-1.6f, 0.3f, 0.0f, 1.0f); // j
	_Points[35] = vec4(-1.3f, 0.3f, 0.0f, 1.0f); // k

	_Points[36] = vec4(-1.3f, 0.7f, 0.0f, 1.0f); // l
	_Points[37] = vec4(-1.7f, 0.4f, 0.0f, 1.0f); // r
	_Points[38] = vec4(-1.3f, 0.3f, 0.0f, 1.0f); // k

	_Points[39] = vec4(-1.3f, 0.7f, 0.0f, 1.0f); // l
	_Points[40] = vec4(-1.7f, 0.6f, 0.0f, 1.0f); // q
	_Points[41] = vec4(-1.7f, 0.4f, 0.0f, 1.0f); // r

	_Points[42] = vec4(-1.3f, 0.7f, 0.0f, 1.0f); // l
	_Points[43] = vec4(-1.5f, 0.7f, 0.0f, 1.0f); // m
	_Points[44] = vec4(-1.7f, 0.6f, 0.0f, 1.0f); // q

	_Points[45] = vec4(-1.5f, 0.7f, 0.0f, 1.0f); // m
	_Points[46] = vec4(-1.9f, 0.6f, 0.0f, 1.0f); // p
	_Points[47] = vec4(-1.7f, 0.6f, 0.0f, 1.0f); // q

	_Points[48] = vec4(-1.9f, 0.8f, 0.0f, 1.0f); // o
	_Points[49] = vec4(-1.9f, 0.6f, 0.0f, 1.0f); // p
	_Points[50] = vec4(-1.5f, 0.7f, 0.0f, 1.0f); // m

	_Points[51] = vec4(-1.5f, 0.8f, 0.0f, 1.0f); // n
	_Points[52] = vec4(-1.9f, 0.8f, 0.0f, 1.0f); // o
	_Points[53] = vec4(-1.5f, 0.7f, 0.0f, 1.0f); // m



	//A
	_Points[54] = vec4(-0.8f, 1.3f, 0.0f, 1.0f); // f1
	_Points[55] = vec4(-0.3f, 1.1f, 0.0f, 1.0f); // h1
	_Points[56] = vec4(-0.3f, 1.3f, 0.0f, 1.0f); // g1

	_Points[57] = vec4(-0.8f, 1.3f, 0.0f, 1.0f); // f1
	_Points[58] = vec4(-0.8f, 1.1f, 0.0f, 1.0f); // e1
	_Points[59] = vec4(-0.3f, 1.1f, 0.0f, 1.0f); // h1

	_Points[60] = vec4(-1.0f, 1.1f, 0.0f, 1.0f); // d1
	_Points[61] = vec4(-0.1f, 0.8f, 0.0f, 1.0f); // j1
	_Points[62] = vec4(-0.1f, 1.1f, 0.0f, 1.0f); // i1


	_Points[63] = vec4(-1.0f, 1.1f, 0.0f, 1.0f); // d1
	_Points[64] = vec4(-1.0f, 0.8f, 0.0f, 1.0f); // c1
	_Points[65] = vec4(-0.1f, 0.8f, 0.0f, 1.0f); // j1

	_Points[66] = vec4(-1.2f, 0.8f, 0.0f, 1.0f); // b1
	_Points[67] = vec4(-1.2f, 0.0f, 0.0f, 1.0f); // a1
	_Points[68] = vec4(-0.8f, 0.0f, 0.0f, 1.0f); // p1

	_Points[69] = vec4(-1.2f, 0.8f, 0.0f, 1.0f); // b1
	_Points[70] = vec4(-0.8f, 0.8f, 0.0f, 1.0f); // fic1
	_Points[71] = vec4(-0.8f, 0.0f, 0.0f, 1.0f); // p1

	_Points[72] = vec4(-1.2f, 0.8f, 0.0f, 1.0f); // b1
	_Points[73] = vec4(0.1f, 0.6f, 0.0f, 1.0f); // fic2
	_Points[74] = vec4(0.1f, 0.8f, 0.0f, 1.0f); // k1

	_Points[75] = vec4(-1.2f, 0.8f, 0.0f, 1.0f); // b1
	_Points[76] = vec4(-1.2f, 0.6f, 0.0f, 1.0f); // fic3
	_Points[77] = vec4(0.1f, 0.6f, 0.0f, 1.0f); // fic2

	_Points[78] = vec4(-0.3f, 0.8f, 0.0f, 1.0f); // fic4
	_Points[79] = vec4(0.1f, 0.0f, 0.0f, 1.0f); // l1
	_Points[80] = vec4(0.1f, 0.8f, 0.0f, 1.0f); // k1

	_Points[81] = vec4(-0.3f, 0.8f, 0.0f, 1.0f); // fic4
	_Points[82] = vec4(-0.3f, 0.0f, 0.0f, 1.0f); // m1
	_Points[83] = vec4(0.1f, 0.0f, 0.0f, 1.0f); // l1


	//M
	_Points[84] = vec4(0.3f, 1.3f, 0.0f, 1.0f); // t1
	_Points[85] = vec4(0.5f, 1.1f, 0.0f, 1.0f); // v1
	_Points[86] = vec4(0.5f, 1.3f, 0.0f, 1.0f); // u1

	_Points[87] = vec4(0.3f, 1.3f, 0.0f, 1.0f); // t1
	_Points[88] = vec4(0.3f, 1.0f, 0.0f, 1.0f); // s1
	_Points[89] = vec4(0.5f, 1.1f, 0.0f, 1.0f); // v1

	_Points[90] = vec4(0.5f, 1.1f, 0.0f, 1.0f); // v1
	_Points[91] = vec4(0.3f, 1.0f, 0.0f, 1.0f); // s1
	_Points[92] = vec4(0.5f, 0.8f, 0.0f, 1.0f); // i2

	_Points[93] = vec4(0.3f, 1.0f, 0.0f, 1.0f); // s1
	_Points[94] = vec4(0.2f, 1.0f, 0.0f, 1.0f); // q1
	_Points[95] = vec4(0.5f, 0.8f, 0.0f, 1.0f); // i2

	_Points[96] = vec4(0.2f, 1.0f, 0.0f, 1.0f); // q1
	_Points[97] = vec4(0.2f, 0.0f, 0.0f, 1.0f); // r1
	_Points[98] = vec4(0.5f, 0.8f, 0.0f, 1.0f); // i2

	_Points[99] = vec4(0.5f, 0.8f, 0.0f, 1.0f); // i2
	_Points[100] = vec4(0.2f, 0.0f, 0.0f, 1.0f); // r1
	_Points[101] = vec4(0.5f, 0.0f, 0.0f, 1.0f); // h2

	_Points[102] = vec4(0.5f, 1.1f, 0.0f, 1.0f); // v1
	_Points[103] = vec4(0.5f, 0.8f, 0.0f, 1.0f); // i2
	_Points[104] = vec4(1.0f, 0.8f, 0.0f, 1.0f); // f2

	_Points[105] = vec4(0.5f, 1.1f, 0.0f, 1.0f); // v1
	_Points[106] = vec4(1.0f, 1.1f, 0.0f, 1.0f); // w1
	_Points[107] = vec4(1.0f, 0.8f, 0.0f, 1.0f); // f2

	_Points[108] = vec4(0.6f, 0.8f, 0.0f, 1.0f); // j2
	_Points[109] = vec4(0.7f, 0.6f, 0.0f, 1.0f); // k2
	_Points[110] = vec4(0.8f, 0.6f, 0.0f, 1.0f); // l2

	_Points[111] = vec4(0.6f, 0.8f, 0.0f, 1.0f); // j2
	_Points[112] = vec4(0.8f, 0.6f, 0.0f, 1.0f); // l2
	_Points[113] = vec4(0.9f, 0.8f, 0.0f, 1.0f); // g2

	_Points[114] = vec4(1.0f, 1.3f, 0.0f, 1.0f); // z1
	_Points[115] = vec4(1.2f, 1.0f, 0.0f, 1.0f); // b2
	_Points[116] = vec4(1.2f, 1.3f, 0.0f, 1.0f); // a1

	_Points[117] = vec4(1.0f, 1.3f, 0.0f, 1.0f); // z1
	_Points[118] = vec4(1.0f, 1.1f, 0.0f, 1.0f); // w1
	_Points[119] = vec4(1.2f, 1.0f, 0.0f, 1.0f); // b2

	_Points[120] = vec4(1.0f, 1.1f, 0.0f, 1.0f); // w1
	_Points[121] = vec4(1.0f, 0.8f, 0.0f, 1.0f); // f2
	_Points[122] = vec4(1.2f, 1.0f, 0.0f, 1.0f); // b2

	_Points[123] = vec4(1.2f, 1.0f, 0.0f, 1.0f); // b2
	_Points[124] = vec4(1.0f, 0.8f, 0.0f, 1.0f); // f2
	_Points[125] = vec4(1.3f, 1.0f, 0.0f, 1.0f); // c2

	_Points[126] = vec4(1.3f, 1.0f, 0.0f, 1.0f); // c2
	_Points[127] = vec4(1.0f, 0.8f, 0.0f, 1.0f); // f2
	_Points[128] = vec4(1.3f, 0.0f, 0.0f, 1.0f); // d2

	_Points[129] = vec4(1.0f, 0.8f, 0.0f, 1.0f); // f2
	_Points[130] = vec4(1.0f, 0.0f, 0.0f, 1.0f); // e2
	_Points[131] = vec4(1.3f, 0.0f, 0.0f, 1.0f); // d2


	//E
	_Points[132] = vec4(1.6f, 1.2f, 0.0f, 1.0f); // c3
	_Points[133] = vec4(2.5f, 0.8f, 0.0f, 1.0f); // a3
	_Points[134] = vec4(2.5f, 1.2f, 0.0f, 1.0f); // b3

	_Points[135] = _Points[132]; // c3
	_Points[136] = vec4(1.6f, 0.8f, 0.0f, 1.0f); // fic5
	_Points[137] = vec4(2.5f, 0.8f, 0.0f, 1.0f); // a3

	_Points[138] = vec4(1.4f, 1.0f, 0.0f, 1.0f); // m2
	_Points[139] = vec4(1.4f, 0.2f, 0.0f, 1.0f); // n2
	_Points[140] = vec4(1.8f, 0.2f, 0.0f, 1.0f); // fic6

	_Points[141] = vec4(1.4f, 1.0f, 0.0f, 1.0f); // m2
	_Points[142] = vec4(1.8f, 1.0f, 0.0f, 1.0f); // fic6
	_Points[143] = vec4(1.8f, 0.2f, 0.0f, 1.0f); // fic7

	_Points[144] = vec4(1.8f, 0.7f, 0.0f, 1.0f); // w2
	_Points[145] = vec4(2.2f, 0.5f, 0.0f, 1.0f); // u2
	_Points[146] = vec4(2.2f, 0.7f, 0.0f, 1.0f); // v2

	_Points[147] = vec4(1.8f, 0.7f, 0.0f, 1.0f); // w2
	_Points[148] = vec4(1.8f, 0.5f, 0.0f, 1.0f); // t2
	_Points[149] = vec4(2.2f, 0.5f, 0.0f, 1.0f); // u2

	_Points[150] = vec4(1.6f, 0.4f, 0.0f, 1.0f); // fic8
	_Points[151] = vec4(1.6f, 0.0f, 0.0f, 1.0f); // p2
	_Points[152] = vec4(2.5f, 0.0f, 0.0f, 1.0f); // q2

	_Points[153] = vec4(1.6f, 0.4f, 0.0f, 1.0f); // fic8
	_Points[154] = vec4(2.5f, 0.0f, 0.0f, 1.0f); // q2
	_Points[155] = vec4(2.5f, 0.4f, 0.0f, 1.0f); // r2

	//O
	_Points[156] = vec4(-2.2f, -0.1f, 0.0f, 1.0f); // e3
	_Points[157] = vec4(-2.2f, -0.5f, 0.0f, 1.0f); // f3
	_Points[158] = vec4(-1.4f, -0.5f, 0.0f, 1.0f); // o3

	_Points[159] = vec4(-2.2f, -0.1f, 0.0f, 1.0f); // e3
	_Points[160] = vec4(-1.4f, -0.5f, 0.0f, 1.0f); // o3
	_Points[161] = vec4(-1.4f, -0.1f, 0.0f, 1.0f); // p3

	_Points[162] = vec4(-2.4f, -0.3f, 0.0f, 1.0f); // g3
	_Points[163] = vec4(-2.4f, -1.3f, 0.0f, 1.0f); // h3
	_Points[164] = vec4(-2.0f, -1.3f, 0.0f, 1.0f); // fic9

	_Points[165] = vec4(-2.4f, -0.3f, 0.0f, 1.0f); // g3
	_Points[166] = vec4(-2.0f, -1.3f, 0.0f, 1.0f); // fic9
	_Points[167] = vec4(-2.0f, -0.3f, 0.0f, 1.0f); // fic10

	_Points[168] = vec4(-1.6f, -0.3f, 0.0f, 1.0f); // fic11
	_Points[169] = vec4(-1.6f, -1.3f, 0.0f, 1.0f); // fic12
	_Points[170] = vec4(-1.2f, -1.3f, 0.0f, 1.0f); // m3

	_Points[171] = vec4(-1.6f, -0.3f, 0.0f, 1.0f); // fic11
	_Points[172] = vec4(-1.2f, -1.3f, 0.0f, 1.0f); // m3
	_Points[173] = vec4(-1.2f, -0.3f, 0.0f, 1.0f); // n3

	_Points[174] = vec4(-2.2f, -1.1f, 0.0f, 1.0f); // i3
	_Points[175] = vec4(-2.2f, -1.5f, 0.0f, 1.0f); // j3
	_Points[176] = vec4(-1.4f, -1.5f, 0.0f, 1.0f); // k3

	_Points[177] = vec4(-2.2f, -1.1f, 0.0f, 1.0f); // i3
	_Points[178] = vec4(-1.4f, -1.5f, 0.0f, 1.0f); // k3
	_Points[179] = vec4(-1.4f, -1.1f, 0.0f, 1.0f); // l3

	//V
	_Points[180] = vec4(-1.1f, -0.1f, 0.0f, 1.0f); // q3
	_Points[181] = vec4(-1.1f, -1.1f, 0.0f, 1.0f); // r3
	_Points[182] = vec4(-0.6f, -1.1f, 0.0f, 1.0f); // fic13

	_Points[183] = vec4(-1.1f, -0.1f, 0.0f, 1.0f); // q3
	_Points[184] = vec4(-0.6f, -1.1f, 0.0f, 1.0f); // fic13
	_Points[185] = vec4(-0.6f, -0.1f, 0.0f, 1.0f); // g4

	_Points[186] = vec4(-0.3f, -0.1f, 0.0f, 1.0f); // e4
	_Points[187] = vec4(-0.3f, -1.1f, 0.0f, 1.0f); // fic14
	_Points[188] = vec4(0.2f, -1.1f, 0.0f, 1.0f); // c4

	_Points[189] = vec4(-0.3f, -0.1f, 0.0f, 1.0f); // e4
	_Points[190] = vec4(0.2f, -1.1f, 0.0f, 1.0f); // c4
	_Points[191] = vec4(0.2f, -0.1f, 0.0f, 1.0f); // d4

	_Points[192] = vec4(-0.6f, -0.8f, 0.0f, 1.0f); // h4
	_Points[193] = vec4(-0.8f, -1.1f, 0.0f, 1.0f); // s3
	_Points[194] = vec4(-0.1f, -1.1f, 0.0f, 1.0f); // b4

	_Points[195] = vec4(-0.6f, -0.8f, 0.0f, 1.0f); // h4
	_Points[196] = vec4(-0.1f, -1.1f, 0.0f, 1.0f); // b4
	_Points[197] = vec4(-0.3f, -0.8f, 0.0f, 1.0f); // f4

	_Points[198] = vec4(-0.8f, -1.1f, 0.0f, 1.0f); // s3
	_Points[199] = vec4(-0.8f, -1.3f, 0.0f, 1.0f); // t3
	_Points[200] = vec4(-0.1f, -1.3f, 0.0f, 1.0f); // a4

	_Points[201] = vec4(-0.8f, -1.1f, 0.0f, 1.0f); // s3
	_Points[202] = vec4(-0.1f, -1.3f, 0.0f, 1.0f); // a4
	_Points[203] = vec4(-0.1f, -1.1f, 0.0f, 1.0f); // b4

	_Points[204] = vec4(-0.6f, -1.3f, 0.0f, 1.0f); // u3
	_Points[205] = vec4(-0.6f, -1.5f, 0.0f, 1.0f); // v3
	_Points[206] = vec4(-0.3f, -1.5f, 0.0f, 1.0f); // w3

	_Points[207] = vec4(-0.6f, -1.3f, 0.0f, 1.0f); // u3
	_Points[208] = vec4(-0.3f, -1.5f, 0.0f, 1.0f); // w3
	_Points[209] = vec4(-0.3f, -1.3f, 0.0f, 1.0f); // z3

	//E
	_Points[210] = vec4(0.4f, -0.1f, 0.0f, 1.0f); // i4
	_Points[211] = vec4(0.4f, -0.4f, 0.0f, 1.0f); // fic15
	_Points[212] = vec4(1.2f, -0.4f, 0.0f, 1.0f); // w4

	_Points[213] = vec4(0.4f, -0.1f, 0.0f, 1.0f); // i4
	_Points[214] = vec4(1.2f, -0.4f, 0.0f, 1.0f); // w4
	_Points[215] = vec4(1.2f, -0.1f, 0.0f, 1.0f); // z4

	_Points[216] = vec4(0.3f, -0.3f, 0.0f, 1.0f); // k4
	_Points[217] = vec4(0.3f, -1.3f, 0.0f, 1.0f); // l4
	_Points[218] = vec4(0.7f, -1.3f, 0.0f, 1.0f); // fic16

	_Points[219] = vec4(0.3f, -0.3f, 0.0f, 1.0f); // k4
	_Points[220] = vec4(0.7f, -1.3f, 0.0f, 1.0f); // fic16
	_Points[221] = vec4(0.7f, -0.3f, 0.0f, 1.0f); // fic17

	_Points[222] = vec4(0.7f, -0.6f, 0.0f, 1.0f); // u4
	_Points[223] = vec4(0.7f, -0.9f, 0.0f, 1.0f); // r4
	_Points[224] = vec4(0.9f, -0.9f, 0.0f, 1.0f); // s4

	_Points[225] = vec4(0.7f, -0.6f, 0.0f, 1.0f); // u4
	_Points[226] = vec4(0.9f, -0.9f, 0.0f, 1.0f); // s4
	_Points[227] = vec4(0.9f, -0.6f, 0.0f, 1.0f); // t4

	_Points[228] = vec4(0.5f, -1.1f, 0.0f, 1.0f); // fic18
	_Points[229] = vec4(0.5f, -1.5f, 0.0f, 1.0f); // n4
	_Points[230] = vec4(1.2f, -1.5f, 0.0f, 1.0f); // o4

	_Points[231] = vec4(0.5f, -1.1f, 0.0f, 1.0f); // fic18
	_Points[232] = vec4(1.2f, -1.5f, 0.0f, 1.0f); // o4
	_Points[233] = vec4(1.2f, -1.1f, 0.0f, 1.0f); // p4

	//R
	_Points[234] = vec4(1.3f, -0.1f, 0.0f, 1.0f); // a5
	_Points[235] = vec4(1.3f, -1.5f, 0.0f, 1.0f); // b5
	_Points[236] = vec4(1.7f, -1.5f, 0.0f, 1.0f); // c5

	_Points[237] = vec4(1.3f, -0.1f, 0.0f, 1.0f); // a5
	_Points[238] = vec4(1.7f, -0.1f, 0.0f, 1.0f); // fic19
	_Points[239] = vec4(1.7f, -1.5f, 0.0f, 1.0f); // c5

	_Points[240] = vec4(1.3f, -0.1f, 0.0f, 1.0f); // a5
	_Points[241] = vec4(1.3f, -0.4f, 0.0f, 1.0f); // fic20
	_Points[242] = vec4(2.3f, -0.4f, 0.0f, 1.0f); // fic21

	_Points[243] = vec4(1.3f, -0.1f, 0.0f, 1.0f); // a5
	_Points[244] = vec4(2.3f, -0.4f, 0.0f, 1.0f); // fic21
	_Points[245] = vec4(2.3f, -0.1f, 0.0f, 1.0f); // n5

	_Points[246] = vec4(2.1f, -0.3f, 0.0f, 1.0f); // m5
	_Points[247] = vec4(2.1f, -0.9f, 0.0f, 1.0f); // fic22
	_Points[248] = vec4(2.5f, -0.9f, 0.0f, 1.0f); // k5

	_Points[249] = vec4(2.1f, -0.3f, 0.0f, 1.0f); // m5
	_Points[250] = vec4(2.5f, -0.9f, 0.0f, 1.0f); // k5
	_Points[251] = vec4(2.5f, -0.3f, 0.0f, 1.0f); // l5

	_Points[252] = vec4(1.3f, -0.8f, 0.0f, 1.0f); // fic23
	_Points[253] = vec4(1.3f, -1.1f, 0.0f, 1.0f); // fic24
	_Points[254] = vec4(2.3f, -1.1f, 0.0f, 1.0f); // i5

	_Points[255] = vec4(1.3f, -0.8f, 0.0f, 1.0f); // fic23
	_Points[256] = vec4(2.3f, -1.1f, 0.0f, 1.0f); // i5
	_Points[257] = vec4(2.3f, -0.8f, 0.0f, 1.0f); // j5

	_Points[258] = vec4(1.9f, -1.1f, 0.0f, 1.0f); // e5
	_Points[259] = vec4(1.9f, -1.5f, 0.0f, 1.0f); // f5
	_Points[260] = vec4(2.5f, -1.5f, 0.0f, 1.0f); // g5

	_Points[261] = vec4(1.9f, -1.1f, 0.0f, 1.0f); // e5
	_Points[262] = vec4(2.5f, -1.5f, 0.0f, 1.0f); // g5
	_Points[263] = vec4(2.5f, -1.1f, 0.0f, 1.0f); // h5

	_Colors = new vec4[GAMEOVER_NUM];

	for (int i = 0; i < GAMEOVER_NUM; i++) {
		_Colors[i] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	}
	
	// Create and initialize a buffer object 
	CreateBufferObject();
	_bUpdateProj = false;

	InitObject();

}

void GameOver::OnUpdate(float delta)
{
	UpdateObject();
}


void GameOver::draw()
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
	glDrawArrays(GL_TRIANGLES, 0, GAMEOVER_NUM);
}

void GameOver::drawW()
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
	glDrawArrays(GL_TRIANGLES, 0, GAMEOVER_NUM);
}