int ketch_walk_count;
float ketch_walk_verts[99];
int ketch_walk_types[33];
int ketch_walk_graph[66];

void ketch_walk_init()
{
	ketch_walk_count = 33;

	ketch_walk_verts[0 ] = 0.374000;
	ketch_walk_verts[1 ] = 2.089804;
	ketch_walk_verts[2 ] = 7.779035;
	ketch_walk_verts[3 ] = -0.638456;
	ketch_walk_verts[4 ] = 2.089804;
	ketch_walk_verts[5 ] = 7.779035;
	ketch_walk_verts[6 ] = -1.011251;
	ketch_walk_verts[7 ] = 1.663175;
	ketch_walk_verts[8 ] = 5.974492;
	ketch_walk_verts[9 ] = -1.163730;
	ketch_walk_verts[10] = 1.616762;
	ketch_walk_verts[11] = 0.882729;
	ketch_walk_verts[12] = 1.307656;
	ketch_walk_verts[13] = 1.642421;
	ketch_walk_verts[14] = 4.923527;
	ketch_walk_verts[15] = 1.300822;
	ketch_walk_verts[16] = 1.618308;
	ketch_walk_verts[17] = 1.718463;
	ketch_walk_verts[18] = 1.231508;
	ketch_walk_verts[19] = 1.603239;
	ketch_walk_verts[20] = -0.732337;
	ketch_walk_verts[21] = -1.281406;
	ketch_walk_verts[22] = 1.609183;
	ketch_walk_verts[23] = -1.035262;
	ketch_walk_verts[24] = -0.240077;
	ketch_walk_verts[25] = 1.600435;
	ketch_walk_verts[26] = -3.414232;
	ketch_walk_verts[27] = 1.343369;
	ketch_walk_verts[28] = 1.663175;
	ketch_walk_verts[29] = 5.824089;
	ketch_walk_verts[30] = 1.702992;
	ketch_walk_verts[31] = 1.612553;
	ketch_walk_verts[32] = 2.827250;
	ketch_walk_verts[33] = -0.50;
	ketch_walk_verts[34] = 12.25;
	ketch_walk_verts[35] = -5.2;
	ketch_walk_verts[36] = -1.446804;
	ketch_walk_verts[37] = 1.602105;
	ketch_walk_verts[38] = -2.947752;
	ketch_walk_verts[39] = -1.634545;
	ketch_walk_verts[40] = 1.894689;
	ketch_walk_verts[41] = -1.250406;
	ketch_walk_verts[42] = -1.686755;
	ketch_walk_verts[43] = 1.609269;
	ketch_walk_verts[44] = 2.812350;
	ketch_walk_verts[45] = -3.610826;
	ketch_walk_verts[46] = 2.529057;
	ketch_walk_verts[47] = 2.162372;
	ketch_walk_verts[48] = 3.660943;
	ketch_walk_verts[49] = 2.466656;
	ketch_walk_verts[50] = 2.126006;
	ketch_walk_verts[51] = -0.499831;
	ketch_walk_verts[52] = 15.258181;
	ketch_walk_verts[53] = 2.203545;
	ketch_walk_verts[54] = 0.498679;
	ketch_walk_verts[55] = 15.258181;
	ketch_walk_verts[56] = 2.203545;
	ketch_walk_verts[57] = 2.50;
	ketch_walk_verts[58] = 3.25;
	ketch_walk_verts[59] = -5.5;
	ketch_walk_verts[60] = 0.50;
	ketch_walk_verts[61] = 12.25;
	ketch_walk_verts[62] = -5.2;
	ketch_walk_verts[63] = 0.014345;
	ketch_walk_verts[64] = 1.608144;
	ketch_walk_verts[65] = -4.749418;
	ketch_walk_verts[66] = 0.014345;
	ketch_walk_verts[67] = 1.608144;
	ketch_walk_verts[68] = -4.650524;
	ketch_walk_verts[69] = -1.105530;
	ketch_walk_verts[70] = 3.050513;
	ketch_walk_verts[71] = -7.626241;
	ketch_walk_verts[72] = 1.154252;
	ketch_walk_verts[73] = 3.050856;
	ketch_walk_verts[74] = -8.284465;
	ketch_walk_verts[75] = -2.50;
	ketch_walk_verts[76] = 3.25;
	ketch_walk_verts[77] = -5.5;
	ketch_walk_verts[78] = 1.858300;
	ketch_walk_verts[79] = 1.609367;
	ketch_walk_verts[80] = -4.073115;
	ketch_walk_verts[81] = 1.686738;
	ketch_walk_verts[82] = 3.057135;
	ketch_walk_verts[83] = -6.272120;
	ketch_walk_verts[84] = -1.712606;
	ketch_walk_verts[85] = 3.057136;
	ketch_walk_verts[86] = -6.268388;
	ketch_walk_verts[87] = -1.912651;
	ketch_walk_verts[88] = 1.609368;
	ketch_walk_verts[89] = -4.208207;
	ketch_walk_verts[90] = -1.686755;
	ketch_walk_verts[91] = 1.609269;
	ketch_walk_verts[92] = 4.295124;
	ketch_walk_verts[93] = 1.686241;
	ketch_walk_verts[94] = 1.614861;
	ketch_walk_verts[95] = 4.316991;
	ketch_walk_verts[96] = 1.439372;
	ketch_walk_verts[97] = 1.933928;
	ketch_walk_verts[98] = -2.931143;

	ketch_walk_types[0 ] = 0;
	ketch_walk_types[1 ] = 0;
	ketch_walk_types[2 ] = 0;
	ketch_walk_types[3 ] = 0;
	ketch_walk_types[4 ] = 0;
	ketch_walk_types[5 ] = 0;
	ketch_walk_types[6 ] = 0;
	ketch_walk_types[7 ] = 0;
	ketch_walk_types[8 ] = 0;
	ketch_walk_types[9 ] = 1;
	ketch_walk_types[10] = 1;
	ketch_walk_types[11] = 4;
	ketch_walk_types[12] = 1;
	ketch_walk_types[13] = 1;
	ketch_walk_types[14] = 1;
	ketch_walk_types[15] = 5;
	ketch_walk_types[16] = 5;
	ketch_walk_types[17] = 4;
	ketch_walk_types[18] = 4;
	ketch_walk_types[19] = 5;
	ketch_walk_types[20] = 4;
	ketch_walk_types[21] = 3;
	ketch_walk_types[22] = 2;
	ketch_walk_types[23] = 0;
	ketch_walk_types[24] = 0;
	ketch_walk_types[25] = 5;
	ketch_walk_types[26] = 0;
	ketch_walk_types[27] = 0;
	ketch_walk_types[28] = 0;
	ketch_walk_types[29] = 0;
	ketch_walk_types[30] = 1;
	ketch_walk_types[31] = 1;
	ketch_walk_types[32] = 1;

	ketch_walk_graph[0 ] = (21)*256 + (22);
	ketch_walk_graph[1 ] = (22)*256 + (8);
	ketch_walk_graph[2 ] = (22)*256 + (26);
	ketch_walk_graph[3 ] = (22)*256 + (29);
	ketch_walk_graph[4 ] = (29)*256 + (8);
	ketch_walk_graph[5 ] = (26)*256 + (8);
	ketch_walk_graph[6 ] = (29)*256 + (28);
	ketch_walk_graph[7 ] = (26)*256 + (27);
	ketch_walk_graph[8 ] = (28)*256 + (23);
	ketch_walk_graph[9 ] = (27)*256 + (24);
	ketch_walk_graph[10] = (23)*256 + (25);
	ketch_walk_graph[11] = (24)*256 + (19);
	ketch_walk_graph[12] = (23)*256 + (24);
	ketch_walk_graph[13] = (29)*256 + (12);
	ketch_walk_graph[14] = (8)*256 + (12);
	ketch_walk_graph[15] = (12)*256 + (13);
	ketch_walk_graph[16] = (13)*256 + (7);
	ketch_walk_graph[17] = (25)*256 + (11);
	ketch_walk_graph[18] = (12)*256 + (6);
	ketch_walk_graph[19] = (19)*256 + (20);
	ketch_walk_graph[20] = (8)*256 + (13);
	ketch_walk_graph[21] = (7)*256 + (3);
	ketch_walk_graph[22] = (6)*256 + (5);
	ketch_walk_graph[23] = (3)*256 + (5);
	ketch_walk_graph[24] = (7)*256 + (5);
	ketch_walk_graph[25] = (3)*256 + (6);
	ketch_walk_graph[26] = (7)*256 + (6);
	ketch_walk_graph[27] = (3)*256 + (14);
	ketch_walk_graph[28] = (5)*256 + (10);
	ketch_walk_graph[29] = (14)*256 + (15);
	ketch_walk_graph[30] = (10)*256 + (16);
	ketch_walk_graph[31] = (16)*256 + (18);
	ketch_walk_graph[32] = (-1)*256 + (-1);
	ketch_walk_graph[33] = (15)*256 + (17);
	ketch_walk_graph[34] = (-1)*256 + (-1);
	ketch_walk_graph[35] = (14)*256 + (2);
	ketch_walk_graph[36] = (10)*256 + (4);
	ketch_walk_graph[37] = (4)*256 + (9);
	ketch_walk_graph[38] = (2)*256 + (9);
	ketch_walk_graph[39] = (2)*256 + (4);
	ketch_walk_graph[40] = (14)*256 + (10);
	ketch_walk_graph[41] = (4)*256 + (14);
	ketch_walk_graph[42] = (2)*256 + (1);
	ketch_walk_graph[43] = (1)*256 + (0);
	ketch_walk_graph[44] = (0)*256 + (9);
	ketch_walk_graph[45] = (2)*256 + (10);
	ketch_walk_graph[46] = (26)*256 + (13);
	ketch_walk_graph[47] = (24)*256 + (28);
	ketch_walk_graph[48] = (23)*256 + (27);
	ketch_walk_graph[49] = (10)*256 + (31);
	ketch_walk_graph[50] = (31)*256 + (4);
	ketch_walk_graph[51] = (2)*256 + (30);
	ketch_walk_graph[52] = (14)*256 + (30);
	ketch_walk_graph[53] = (31)*256 + (30);
	ketch_walk_graph[54] = (26)*256 + (32);
	ketch_walk_graph[55] = (32)*256 + (8);
	ketch_walk_graph[56] = (-1)*256 + (-1);
	ketch_walk_graph[57] = (-1)*256 + (-1);
	ketch_walk_graph[58] = (-1)*256 + (-1);
	ketch_walk_graph[59] = (-1)*256 + (-1);
	ketch_walk_graph[60] = (-1)*256 + (-1);
	ketch_walk_graph[61] = (-1)*256 + (-1);
	ketch_walk_graph[62] = (-1)*256 + (-1);
	ketch_walk_graph[63] = (-1)*256 + (-1);
	ketch_walk_graph[64] = (-1)*256 + (-1);
	ketch_walk_graph[65] = (-1)*256 + (-1);
}
