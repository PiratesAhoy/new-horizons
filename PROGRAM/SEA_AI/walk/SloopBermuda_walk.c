int SloopBermuda_walk_count;
float SloopBermuda_walk_verts[123];
int SloopBermuda_walk_types[41];
int SloopBermuda_walk_graph[82];

void SloopBermuda_walk_init()
{
	SloopBermuda_walk_count = 41;


        
	SloopBermuda_walk_verts[0] = 0.973271;

	SloopBermuda_walk_verts[1] = 0.903048;

	SloopBermuda_walk_verts[2] = -5.998527;

	SloopBermuda_walk_verts[3] = -0.997910;

	SloopBermuda_walk_verts[4] = 0.900660;

	SloopBermuda_walk_verts[5] = -3.990386;

	SloopBermuda_walk_verts[6] = 1.005426;

	SloopBermuda_walk_verts[7] = 0.953623;

	SloopBermuda_walk_verts[8] = 6.472787;

	SloopBermuda_walk_verts[9] = -3.009682;

	SloopBermuda_walk_verts[10] = 0.907753;

	SloopBermuda_walk_verts[11] = 1.024633;

	SloopBermuda_walk_verts[12] = 2.999749;

	SloopBermuda_walk_verts[13] = 0.907753;

	SloopBermuda_walk_verts[14] = 1.014700;

	SloopBermuda_walk_verts[15] = 1.996522;

	SloopBermuda_walk_verts[16] = 0.901883;

	SloopBermuda_walk_verts[17] = 0.472702;

	SloopBermuda_walk_verts[18] = -2.006455;

	SloopBermuda_walk_verts[19] = 0.901883;

	SloopBermuda_walk_verts[20] = 0.512434;

	SloopBermuda_walk_verts[21] = 1.470076;

	SloopBermuda_walk_verts[22] = 0.917963;

	SloopBermuda_walk_verts[23] = 2.737413;

	SloopBermuda_walk_verts[24] = -0.014965;

	SloopBermuda_walk_verts[25] = 1.103717;

	SloopBermuda_walk_verts[26] = -10.507892;

	SloopBermuda_walk_verts[27] = 1.769218;

	SloopBermuda_walk_verts[28] = 0.999325;

	SloopBermuda_walk_verts[29] = 6.703773;

	SloopBermuda_walk_verts[30] = -3.219506;

	SloopBermuda_walk_verts[31] = 0.911979;

	SloopBermuda_walk_verts[32] = 3.262492;

	SloopBermuda_walk_verts[33] = 0.996220;

	SloopBermuda_walk_verts[34] = 0.973621;

	SloopBermuda_walk_verts[35] = -8.951859;

	SloopBermuda_walk_verts[36] = -1.745069;

	SloopBermuda_walk_verts[37] = 1.002062;

	SloopBermuda_walk_verts[38] = 6.719941;

	SloopBermuda_walk_verts[39] = -1.675391;

	SloopBermuda_walk_verts[40] = 0.892170;

	SloopBermuda_walk_verts[41] = -1.656678;

	SloopBermuda_walk_verts[42] = 3.210905;

	SloopBermuda_walk_verts[43] = 0.917385;

	SloopBermuda_walk_verts[44] = 3.226582;

	SloopBermuda_walk_verts[45] = 4.413267;

	SloopBermuda_walk_verts[46] = 2.458494;

	SloopBermuda_walk_verts[47] = 3.240628;

	SloopBermuda_walk_verts[48] = -4.416772;

	SloopBermuda_walk_verts[49] = 2.458494;

	SloopBermuda_walk_verts[50] = 3.258094;

	SloopBermuda_walk_verts[51] = 0.698996;

	SloopBermuda_walk_verts[52] = 22.165152;

	SloopBermuda_walk_verts[53] = -1.153488;

	SloopBermuda_walk_verts[54] = -0.751186;

	SloopBermuda_walk_verts[55] = 22.165152;

	SloopBermuda_walk_verts[56] = -1.153488;

	SloopBermuda_walk_verts[57] = 0.517790;

	SloopBermuda_walk_verts[58] = 25.900507;

	SloopBermuda_walk_verts[59] = -2.340938;

	SloopBermuda_walk_verts[60] = -0.495351;

	SloopBermuda_walk_verts[61] = 25.900507;

	SloopBermuda_walk_verts[62] = -2.331141;

	SloopBermuda_walk_verts[63] = -0.861877;

	SloopBermuda_walk_verts[64] = 1.380279;

	SloopBermuda_walk_verts[65] = -12.607646;

	SloopBermuda_walk_verts[66] = 0.779537;

	SloopBermuda_walk_verts[67] = 1.390618;

	SloopBermuda_walk_verts[68] = -12.600028;

	SloopBermuda_walk_verts[69] = 2.009113;

	SloopBermuda_walk_verts[70] = 0.897920;

	SloopBermuda_walk_verts[71] = -3.474963;

	SloopBermuda_walk_verts[72] = 2.629377;

	SloopBermuda_walk_verts[73] = 0.903296;

	SloopBermuda_walk_verts[74] = -5.216498;

	SloopBermuda_walk_verts[75] = 2.492786;

	SloopBermuda_walk_verts[76] = 0.909812;

	SloopBermuda_walk_verts[77] = -7.009255;

	SloopBermuda_walk_verts[78] = 0.172310;

	SloopBermuda_walk_verts[79] = 1.057138;

	SloopBermuda_walk_verts[80] = -9.993638;

	SloopBermuda_walk_verts[81] = -2.663525;

	SloopBermuda_walk_verts[82] = 0.903296;

	SloopBermuda_walk_verts[83] = -5.216498;

	SloopBermuda_walk_verts[84] = -2.509860;

	SloopBermuda_walk_verts[85] = 0.909812;

	SloopBermuda_walk_verts[86] = -6.992181;

	SloopBermuda_walk_verts[87] = -0.243674;

	SloopBermuda_walk_verts[88] = 1.021124;

	SloopBermuda_walk_verts[89] = -9.675183;

	SloopBermuda_walk_verts[90] = 1.622373;

	SloopBermuda_walk_verts[91] = 0.895932;

	SloopBermuda_walk_verts[92] = -1.506027;

	SloopBermuda_walk_verts[93] = -1.672715;

	SloopBermuda_walk_verts[94] = 0.895932;

	SloopBermuda_walk_verts[95] = -1.321912;

	SloopBermuda_walk_verts[96] = -1.008438;

	SloopBermuda_walk_verts[97] = 0.958796;

	SloopBermuda_walk_verts[98] = -8.997527;

	SloopBermuda_walk_verts[99] = -1.669044;

	SloopBermuda_walk_verts[100] = 1.128232;

	SloopBermuda_walk_verts[101] = 7.486113;

	SloopBermuda_walk_verts[102] = -1.585325;

	SloopBermuda_walk_verts[103] = 2.126865;

	SloopBermuda_walk_verts[104] = 8.709499;

	SloopBermuda_walk_verts[105] = -2.477144;

	SloopBermuda_walk_verts[106] = 2.241599;

	SloopBermuda_walk_verts[107] = 11.011370;

	SloopBermuda_walk_verts[108] = -0.078462;

	SloopBermuda_walk_verts[109] = 2.175089;

	SloopBermuda_walk_verts[110] = 9.509391;

	SloopBermuda_walk_verts[111] = 1.609580;

	SloopBermuda_walk_verts[112] = 2.126865;

	SloopBermuda_walk_verts[113] = 8.709499;

	SloopBermuda_walk_verts[114] = 1.705871;

	SloopBermuda_walk_verts[115] = 1.128232;

	SloopBermuda_walk_verts[116] = 7.486113;

	SloopBermuda_walk_verts[117] = -0.468180;

	SloopBermuda_walk_verts[118] = 2.376387;

	SloopBermuda_walk_verts[119] = 13.592994;

	SloopBermuda_walk_verts[120] = 1.998575;

	SloopBermuda_walk_verts[121] = 2.309615;

	SloopBermuda_walk_verts[122] = 12.466262;


	
SloopBermuda_walk_types[0 ] = 0;
	SloopBermuda_walk_types[1 ] = 0;
	SloopBermuda_walk_types[2 ] = 0;
	SloopBermuda_walk_types[3 ] = 0;
	SloopBermuda_walk_types[4 ] = 0;
	SloopBermuda_walk_types[5 ] = 0;
	SloopBermuda_walk_types[6 ] = 0;
	SloopBermuda_walk_types[7 ] = 0;
	SloopBermuda_walk_types[8 ] = 0;
	SloopBermuda_walk_types[9 ] = 1;
	SloopBermuda_walk_types[10] = 0;
	SloopBermuda_walk_types[11] = 1;
	SloopBermuda_walk_types[12] = 1;
	SloopBermuda_walk_types[13] = 1;
	SloopBermuda_walk_types[14] = 0;
	SloopBermuda_walk_types[15] = 5;
	SloopBermuda_walk_types[16] = 5;
	SloopBermuda_walk_types[17] = 4;
	SloopBermuda_walk_types[18] = 4;
	SloopBermuda_walk_types[19] = 6;
	SloopBermuda_walk_types[20] = 6;
	SloopBermuda_walk_types[21] = 3;
	SloopBermuda_walk_types[22] = 2;
	SloopBermuda_walk_types[23] = 0;
	SloopBermuda_walk_types[24] = 0;
	SloopBermuda_walk_types[25] = 0;
	SloopBermuda_walk_types[26] = 0;
	SloopBermuda_walk_types[27] = 0;
	SloopBermuda_walk_types[28] = 0;
	SloopBermuda_walk_types[29] = 0;
	SloopBermuda_walk_types[30] = 1;
	SloopBermuda_walk_types[31] = 1;
	SloopBermuda_walk_types[32] = 1;
       SloopBermuda_walk_types[33] = 0;
	SloopBermuda_walk_types[34] = 0;
	SloopBermuda_walk_types[35] = 0;
	SloopBermuda_walk_types[36] = 0;
	SloopBermuda_walk_types[37] = 0;

SloopBermuda_walk_types[38] = 0;
	SloopBermuda_walk_types[39] = 0;

SloopBermuda_walk_types[40] = 0;


	
        SloopBermuda_walk_graph[0 ] = (21)*256 + (22);
	SloopBermuda_walk_graph[1 ] = (22)*256 + (8);
	SloopBermuda_walk_graph[2 ] = (22)*256 + (26);
	SloopBermuda_walk_graph[3 ] = (22)*256 + (29);
	SloopBermuda_walk_graph[4 ] = (29)*256 + (8);
	SloopBermuda_walk_graph[5 ] = (26)*256 + (8);
	SloopBermuda_walk_graph[6 ] = (29)*256 + (28);
	SloopBermuda_walk_graph[7 ] = (26)*256 + (27);
	SloopBermuda_walk_graph[8 ] = (28)*256 + (7);
	SloopBermuda_walk_graph[9 ] = (27)*256 + (25);
	SloopBermuda_walk_graph[10] = (23)*256 + (25);
	SloopBermuda_walk_graph[11] = (24)*256 + (25);
	SloopBermuda_walk_graph[12] = (23)*256 + (24);
	SloopBermuda_walk_graph[13] = (27)*256 + (30);
	SloopBermuda_walk_graph[14] = (8)*256 + (25);
	SloopBermuda_walk_graph[15] = (12)*256 + (13);
	SloopBermuda_walk_graph[16] = (13)*256 + (7);
	SloopBermuda_walk_graph[17] = (26)*256 + (11);
	SloopBermuda_walk_graph[18] = (25)*256 + (11);
	SloopBermuda_walk_graph[19] = (8)*256 + (11);
	SloopBermuda_walk_graph[20] = (23)*256 + (30);
	SloopBermuda_walk_graph[21] = (7)*256 + (3);
	SloopBermuda_walk_graph[22] = (6)*256 + (5);
	SloopBermuda_walk_graph[23] = (3)*256 + (5);
	SloopBermuda_walk_graph[24] = (7)*256 + (5);
	SloopBermuda_walk_graph[25] = (3)*256 + (6);
	SloopBermuda_walk_graph[26] = (7)*256 + (6);
	SloopBermuda_walk_graph[27] = (3)*256 + (14);
	SloopBermuda_walk_graph[28] = (5)*256 + (10);
	SloopBermuda_walk_graph[29] = (14)*256 + (15);
	SloopBermuda_walk_graph[30] = (10)*256 + (16);
	SloopBermuda_walk_graph[31] = (16)*256 + (18);
	SloopBermuda_walk_graph[32] = (18)*256 + (20);
	SloopBermuda_walk_graph[33] = (15)*256 + (17);
	SloopBermuda_walk_graph[34] = (17)*256 + (19);
	SloopBermuda_walk_graph[35] = (14)*256 + (2);
	SloopBermuda_walk_graph[36] = (10)*256 + (4);
	SloopBermuda_walk_graph[37] = (4)*256 + (9);
	SloopBermuda_walk_graph[38] = (2)*256 + (9);
	SloopBermuda_walk_graph[39] = (2)*256 + (4);
	SloopBermuda_walk_graph[40] = (14)*256 + (0);
	SloopBermuda_walk_graph[41] = (4)*256 + (14);
	SloopBermuda_walk_graph[42] = (2)*256 + (12);
	SloopBermuda_walk_graph[43] = (1)*256 + (12);
	SloopBermuda_walk_graph[44] = (0)*256 + (9);
	SloopBermuda_walk_graph[45] = (2)*256 + (9);
	SloopBermuda_walk_graph[46] = (26)*256 + (24);
	SloopBermuda_walk_graph[47] = (24)*256 + (28);
	SloopBermuda_walk_graph[48] = (23)*256 + (6);
	SloopBermuda_walk_graph[49] = (10)*256 + (31);
	SloopBermuda_walk_graph[50] = (31)*256 + (4);
	SloopBermuda_walk_graph[51] = (2)*256 + (30);
	SloopBermuda_walk_graph[52] = (14)*256 + (30);
	SloopBermuda_walk_graph[53] = (31)*256 + (30);
	SloopBermuda_walk_graph[54] = (26)*256 + (32);
	SloopBermuda_walk_graph[55] = (32)*256 + (8);
	SloopBermuda_walk_graph[56] = (32)*256 + (11);
        SloopBermuda_walk_graph[57] = (12)*256 + (33);
        SloopBermuda_walk_graph[58] = (2)*256 + (33);
        SloopBermuda_walk_graph[59] = (9)*256 + (33);
        SloopBermuda_walk_graph[60] = (33)*256 + (34);	                           SloopBermuda_walk_graph[61] = (34)*256 + (35);	                           SloopBermuda_walk_graph[62] = (34)*256 + (36);	                           SloopBermuda_walk_graph[63] = (35)*256 + (36);                             SloopBermuda_walk_graph[64] = (36)*256 + (37);	                           SloopBermuda_walk_graph[65] = (37)*256 + (38);
        SloopBermuda_walk_graph[66] = (38)*256 + (33);	                           SloopBermuda_walk_graph[67] = (38)*256 + (9);	                           SloopBermuda_walk_graph[68] = (38)*256 + (2);	                           SloopBermuda_walk_graph[69] = (35)*256 + (39);	                           SloopBermuda_walk_graph[70] = (39)*256 + (40);
        SloopBermuda_walk_graph[71] = (40)*256 + (37);	        SloopBermuda_walk_graph[72] = (-1)*256 + (-1);
	                        SloopBermuda_walk_graph[73] = (-1)*256 + (-1);
	                        SloopBermuda_walk_graph[74] = (-1)*256 + (-1);
	                        SloopBermuda_walk_graph[75] = (-1)*256 + (-1);
	                        SloopBermuda_walk_graph[76] = (-1)*256 + (-1);
	                        
SloopBermuda_walk_graph[77] = (-1)*256 + (-1);
	                        SloopBermuda_walk_graph[78] = (-1)*256 + (-1);
	                        SloopBermuda_walk_graph[79] = (-1)*256 + (-1);
	                        SloopBermuda_walk_graph[80] = (-1)*256 + (-1);
	                        
SloopBermuda_walk_graph[81] = (-1)*256 + (-1);
}
