int Corvette47_walk_count;
float Corvette47_walk_verts[144];
int Corvette47_walk_types[48];
int Corvette47_walk_graph[55];

void Corvette47_walk_init()
{
        Corvette47_walk_count = 48;

        Corvette47_walk_verts[0] = -1.230676;
        Corvette47_walk_verts[1] = 1.389999;
        Corvette47_walk_verts[2] = 4.570725;
        Corvette47_walk_verts[3] = -1.252599;
        Corvette47_walk_verts[4] = 1.4225;
        Corvette47_walk_verts[5] = 2.272098;
        Corvette47_walk_verts[6] = -1.228972;
        Corvette47_walk_verts[7] = 1.347503;
        Corvette47_walk_verts[8] = 0.006519;
        Corvette47_walk_verts[9] = -1.445841;
        Corvette47_walk_verts[10] = 1.485003;
        Corvette47_walk_verts[11] = -2.416728;
        Corvette47_walk_verts[12] = 0.003321;
        Corvette47_walk_verts[13] = 1.434995;
        Corvette47_walk_verts[14] = -3.971051;
        Corvette47_walk_verts[15] = 1.244575;
        Corvette47_walk_verts[16] = 1.442503;
        Corvette47_walk_verts[17] = 4.602378;
        Corvette47_walk_verts[18] = 1.336044;
        Corvette47_walk_verts[19] = 1.370001;
        Corvette47_walk_verts[20] = 2.298038;
        Corvette47_walk_verts[21] = 1.269148;
        Corvette47_walk_verts[22] = 1.4225;
        Corvette47_walk_verts[23] = 0.083151;
        Corvette47_walk_verts[24] = 1.321941;
        Corvette47_walk_verts[25] = 1.394999;
        Corvette47_walk_verts[26] = -2.558842;
        Corvette47_walk_verts[27] = -0.054976;
        Corvette47_walk_verts[28] = 1.369996;
        Corvette47_walk_verts[29] = -3.097854;
        Corvette47_walk_verts[30] = 0.098304;
        Corvette47_walk_verts[31] = 1.317501;
        Corvette47_walk_verts[32] = 0.081215;
        Corvette47_walk_verts[33] = -0.007619;
        Corvette47_walk_verts[34] = 1.335001;
        Corvette47_walk_verts[35] = 5.570325;
        Corvette47_walk_verts[36] = -0.010398;
        Corvette47_walk_verts[37] = 2.370008;
        Corvette47_walk_verts[38] = -5.723559;
        Corvette47_walk_verts[39] = 1.601215;
        Corvette47_walk_verts[40] = 2.652514;
        Corvette47_walk_verts[41] = -11.109572;
        Corvette47_walk_verts[42] = -2.104681;
        Corvette47_walk_verts[43] = 2.61501;
        Corvette47_walk_verts[44] = -8.647466;
        Corvette47_walk_verts[45] = -1.591871;
        Corvette47_walk_verts[46] = 2.740021;
        Corvette47_walk_verts[47] = -11.133013;
        Corvette47_walk_verts[48] = 1.788613;
        Corvette47_walk_verts[49] = 2.585009;
        Corvette47_walk_verts[50] = -8.736883;
        Corvette47_walk_verts[51] = -0.016612;
        Corvette47_walk_verts[52] = 2.427505;
        Corvette47_walk_verts[53] = 7.409426;
        Corvette47_walk_verts[54] = 1.936293;
        Corvette47_walk_verts[55] = 2.442502;
        Corvette47_walk_verts[56] = 8.051456;
        Corvette47_walk_verts[57] = 1.501996;
        Corvette47_walk_verts[58] = 2.445005;
        Corvette47_walk_verts[59] = 11.898038;
        Corvette47_walk_verts[60] = -2.017089;
        Corvette47_walk_verts[61] = 2.390004;
        Corvette47_walk_verts[62] = 7.957716;
        Corvette47_walk_verts[63] = -1.172816;
        Corvette47_walk_verts[64] = 2.525004;
        Corvette47_walk_verts[65] = 11.967222;
        Corvette47_walk_verts[66] = -1.544605;
        Corvette47_walk_verts[67] = 2.845003;
        Corvette47_walk_verts[68] = -13.028966;
        Corvette47_walk_verts[69] = 1.474155;
        Corvette47_walk_verts[70] = 2.857505;
        Corvette47_walk_verts[71] = -13.032763;
        Corvette47_walk_verts[72] = -1.021937;
        Corvette47_walk_verts[73] = 3.020038;
        Corvette47_walk_verts[74] = -15.176387;
        Corvette47_walk_verts[75] = 1.023555;
        Corvette47_walk_verts[76] = 3.005017;
        Corvette47_walk_verts[77] = -15.152007;
        Corvette47_walk_verts[78] = 2.027299;
        Corvette47_walk_verts[79] = 1.48748;
        Corvette47_walk_verts[80] = 4.549139;
        Corvette47_walk_verts[81] = 2.103619;
        Corvette47_walk_verts[82] = 1.37998;
        Corvette47_walk_verts[83] = 2.242751;
        Corvette47_walk_verts[84] = 2.160463;
        Corvette47_walk_verts[85] = 1.452481;
        Corvette47_walk_verts[86] = 0.0537;
        Corvette47_walk_verts[87] = -1.976747;
        Corvette47_walk_verts[88] = 1.494988;
        Corvette47_walk_verts[89] = 4.522105;
        Corvette47_walk_verts[90] = -1.986886;
        Corvette47_walk_verts[91] = 1.439988;
        Corvette47_walk_verts[92] = 2.285453;
        Corvette47_walk_verts[93] = -1.962229;
        Corvette47_walk_verts[94] = 1.394988;
        Corvette47_walk_verts[95] = 0.103728;
        Corvette47_walk_verts[96] = 3.577161;
        Corvette47_walk_verts[97] = 2.712494;
        Corvette47_walk_verts[98] = -5.663361;
        Corvette47_walk_verts[99] = 4.000099;
        Corvette47_walk_verts[100] = 2.54499;
        Corvette47_walk_verts[101] = -3.634307;
        Corvette47_walk_verts[102] = 1.186304;
        Corvette47_walk_verts[103] = 13.88751;
        Corvette47_walk_verts[104] = -3.021737;
        Corvette47_walk_verts[105] = 2.119065;
        Corvette47_walk_verts[106] = 2.552499;
        Corvette47_walk_verts[107] = -6.395842;
        Corvette47_walk_verts[108] = -2.233124;
        Corvette47_walk_verts[109] = 2.517496;
        Corvette47_walk_verts[110] = -6.404235;
        Corvette47_walk_verts[111] = -4.00369;
        Corvette47_walk_verts[112] = 2.539994;
        Corvette47_walk_verts[113] = -3.417929;
        Corvette47_walk_verts[114] = -3.588941;
        Corvette47_walk_verts[115] = 2.607492;
        Corvette47_walk_verts[116] = -5.813155;
        Corvette47_walk_verts[117] = -1.214458;
        Corvette47_walk_verts[118] = 13.902637;
        Corvette47_walk_verts[119] = -3.034029;
        Corvette47_walk_verts[120] = -3.736411;
        Corvette47_walk_verts[121] = 2.61498;
        Corvette47_walk_verts[122] = 9.150934;
        Corvette47_walk_verts[123] = 3.719986;
        Corvette47_walk_verts[124] = 2.544991;
        Corvette47_walk_verts[125] = 9.241133;
        Corvette47_walk_verts[126] = 3.630718;
        Corvette47_walk_verts[127] = 2.647491;
        Corvette47_walk_verts[128] = 8.035869;
        Corvette47_walk_verts[129] = -3.657967;
        Corvette47_walk_verts[130] = 2.617486;
        Corvette47_walk_verts[131] = 7.941484;
        Corvette47_walk_verts[132] = -1.223419;
        Corvette47_walk_verts[133] = 12.870011;
        Corvette47_walk_verts[134] = 9.281985;
        Corvette47_walk_verts[135] = 1.212779;
        Corvette47_walk_verts[136] = 12.862483;
        Corvette47_walk_verts[137] = 9.255598;
        Corvette47_walk_verts[138] = 2.621115;
        Corvette47_walk_verts[139] = 2.394994;
        Corvette47_walk_verts[140] = -3.750393;
        Corvette47_walk_verts[141] = -2.604309;
        Corvette47_walk_verts[142] = 2.559995;
        Corvette47_walk_verts[143] = -3.831311;

        Corvette47_walk_types[0] = 0;
        Corvette47_walk_types[1] = 0;
        Corvette47_walk_types[2] = 0;
        Corvette47_walk_types[3] = 0;
        Corvette47_walk_types[4] = 0;
        Corvette47_walk_types[5] = 0;
        Corvette47_walk_types[6] = 0;
        Corvette47_walk_types[7] = 0;
        Corvette47_walk_types[8] = 0;
        Corvette47_walk_types[9] = 0;
        Corvette47_walk_types[10] = 0;
        Corvette47_walk_types[11] = 0;
        Corvette47_walk_types[12] = 0;
        Corvette47_walk_types[13] = 0;
        Corvette47_walk_types[14] = 0;
        Corvette47_walk_types[15] = 0;
        Corvette47_walk_types[16] = 0;
        Corvette47_walk_types[17] = 0;
        Corvette47_walk_types[18] = 0;
        Corvette47_walk_types[19] = 0;
        Corvette47_walk_types[20] = 0;
        Corvette47_walk_types[21] = 0;
        Corvette47_walk_types[22] = 0;
        Corvette47_walk_types[23] = 0;
        Corvette47_walk_types[24] = 0;
        Corvette47_walk_types[25] = 0;
        Corvette47_walk_types[26] = 2;
        Corvette47_walk_types[27] = 2;
        Corvette47_walk_types[28] = 2;
        Corvette47_walk_types[29] = 1;
        Corvette47_walk_types[30] = 1;
        Corvette47_walk_types[31] = 1;
        Corvette47_walk_types[32] = 5;
        Corvette47_walk_types[33] = 5;
        Corvette47_walk_types[34] = 4;
        Corvette47_walk_types[35] = 0;
        Corvette47_walk_types[36] = 0;
        Corvette47_walk_types[37] = 5;
        Corvette47_walk_types[38] = 5;
        Corvette47_walk_types[39] = 4;
        Corvette47_walk_types[40] = 5;
        Corvette47_walk_types[41] = 5;
        Corvette47_walk_types[42] = 5;
        Corvette47_walk_types[43] = 5;
        Corvette47_walk_types[44] = 6;
        Corvette47_walk_types[45] = 6;
        Corvette47_walk_types[46] = 0;
        Corvette47_walk_types[47] = 0;

        Corvette47_walk_graph[0] = (1)*256 + (0);
        Corvette47_walk_graph[1] = (1)*256 + (2);
        Corvette47_walk_graph[2] = (2)*256 + (3);
        Corvette47_walk_graph[3] = (3)*256 + (4);
        Corvette47_walk_graph[4] = (4)*256 + (8);
        Corvette47_walk_graph[5] = (8)*256 + (7);
        Corvette47_walk_graph[6] = (7)*256 + (6);
        Corvette47_walk_graph[7] = (6)*256 + (5);
        Corvette47_walk_graph[8] = (11)*256 + (0);
        Corvette47_walk_graph[9] = (5)*256 + (11);
        Corvette47_walk_graph[10] = (13)*256 + (16);
        Corvette47_walk_graph[11] = (15)*256 + (14);
        Corvette47_walk_graph[12] = (10)*256 + (11);
        Corvette47_walk_graph[13] = (22)*256 + (24);
        Corvette47_walk_graph[14] = (23)*256 + (13);
        Corvette47_walk_graph[15] = (23)*256 + (25);
        Corvette47_walk_graph[16] = (29)*256 + (0);
        Corvette47_walk_graph[17] = (30)*256 + (1);
        Corvette47_walk_graph[18] = (31)*256 + (2);
        Corvette47_walk_graph[19] = (26)*256 + (5);
        Corvette47_walk_graph[20] = (27)*256 + (6);
        Corvette47_walk_graph[21] = (28)*256 + (7);
        Corvette47_walk_graph[22] = (7)*256 + (10);
        Corvette47_walk_graph[23] = (8)*256 + (9);
        Corvette47_walk_graph[24] = (3)*256 + (9);
        Corvette47_walk_graph[25] = (2)*256 + (10);
        Corvette47_walk_graph[26] = (33)*256 + (34);
        Corvette47_walk_graph[27] = (35)*256 + (12);
        Corvette47_walk_graph[28] = (35)*256 + (32);
        Corvette47_walk_graph[29] = (37)*256 + (39);
        Corvette47_walk_graph[30] = (37)*256 + (38);
        Corvette47_walk_graph[31] = (41)*256 + (42);
        Corvette47_walk_graph[32] = (45)*256 + (41);
        Corvette47_walk_graph[33] = (44)*256 + (40);
        Corvette47_walk_graph[34] = (40)*256 + (43);
        Corvette47_walk_graph[35] = (42)*256 + (18);
        Corvette47_walk_graph[36] = (20)*256 + (43);
        Corvette47_walk_graph[37] = (18)*256 + (19);
        Corvette47_walk_graph[38] = (21)*256 + (20);
        Corvette47_walk_graph[39] = (11)*256 + (17);
        Corvette47_walk_graph[40] = (19)*256 + (21);
        Corvette47_walk_graph[41] = (36)*256 + (38);
        Corvette47_walk_graph[42] = (36)*256 + (47);
        Corvette47_walk_graph[43] = (12)*256 + (14);
        Corvette47_walk_graph[44] = (12)*256 + (16);
        Corvette47_walk_graph[45] = (35)*256 + (16);
        Corvette47_walk_graph[46] = (15)*256 + (22);
        Corvette47_walk_graph[47] = (25)*256 + (24);
        Corvette47_walk_graph[48] = (33)*256 + (32);
        Corvette47_walk_graph[49] = (14)*256 + (36);
        Corvette47_walk_graph[50] = (35)*256 + (46);
        Corvette47_walk_graph[51] = (4)*256 + (12);
        Corvette47_walk_graph[52] = (36)*256 + (12);
        Corvette47_walk_graph[53] = (18)*256 + (17);
        Corvette47_walk_graph[54] = (20)*256 + (17);
}
