int BarqueHeavy_walk_count;
float BarqueHeavy_walk_verts[129];
int BarqueHeavy_walk_types[43];
int BarqueHeavy_walk_graph[49];

void BarqueHeavy_walk_init()
{
        BarqueHeavy_walk_count = 43;

        BarqueHeavy_walk_verts[0] = 1.810673;
        BarqueHeavy_walk_verts[1] = 4.022446;
        BarqueHeavy_walk_verts[2] = 9.465455;
        BarqueHeavy_walk_verts[3] = 1.14375;
        BarqueHeavy_walk_verts[4] = 3.609934;
        BarqueHeavy_walk_verts[5] = 4.566856;
        BarqueHeavy_walk_verts[6] = 1.05533;
        BarqueHeavy_walk_verts[7] = 3.63242;
        BarqueHeavy_walk_verts[8] = 2.404654;
        BarqueHeavy_walk_verts[9] = 2.899421;
        BarqueHeavy_walk_verts[10] = 3.65992;
        BarqueHeavy_walk_verts[11] = 0.372689;
        BarqueHeavy_walk_verts[12] = 2.842077;
        BarqueHeavy_walk_verts[13] = 4.347415;
        BarqueHeavy_walk_verts[14] = -0.796817;
        BarqueHeavy_walk_verts[15] = 2.20316;
        BarqueHeavy_walk_verts[16] = 4.589908;
        BarqueHeavy_walk_verts[17] = -4.254487;
        BarqueHeavy_walk_verts[18] = -1.910075;
        BarqueHeavy_walk_verts[19] = 4.169879;
        BarqueHeavy_walk_verts[20] = 9.525445;
        BarqueHeavy_walk_verts[21] = -1.239533;
        BarqueHeavy_walk_verts[22] = 3.684904;
        BarqueHeavy_walk_verts[23] = 4.593071;
        BarqueHeavy_walk_verts[24] = -1.045352;
        BarqueHeavy_walk_verts[25] = 3.577404;
        BarqueHeavy_walk_verts[26] = 2.49225;
        BarqueHeavy_walk_verts[27] = -2.953371;
        BarqueHeavy_walk_verts[28] = 3.604903;
        BarqueHeavy_walk_verts[29] = 0.490803;
        BarqueHeavy_walk_verts[30] = -2.979897;
        BarqueHeavy_walk_verts[31] = 4.399915;
        BarqueHeavy_walk_verts[32] = -0.846006;
        BarqueHeavy_walk_verts[33] = -2.087878;
        BarqueHeavy_walk_verts[34] = 4.560052;
        BarqueHeavy_walk_verts[35] = -4.451491;
        BarqueHeavy_walk_verts[36] = 0.091952;
        BarqueHeavy_walk_verts[37] = 4.675062;
        BarqueHeavy_walk_verts[38] = -6.059911;
        BarqueHeavy_walk_verts[39] = -1.93668;
        BarqueHeavy_walk_verts[40] = 4.937553;
        BarqueHeavy_walk_verts[41] = -11.084093;
        BarqueHeavy_walk_verts[42] = 2.111658;
        BarqueHeavy_walk_verts[43] = 4.985056;
        BarqueHeavy_walk_verts[44] = -11.00563;
        BarqueHeavy_walk_verts[45] = 4.047867;
        BarqueHeavy_walk_verts[46] = 4.512532;
        BarqueHeavy_walk_verts[47] = -4.310947;
        BarqueHeavy_walk_verts[48] = 4.194117;
        BarqueHeavy_walk_verts[49] = 4.42002;
        BarqueHeavy_walk_verts[50] = -2.233965;
        BarqueHeavy_walk_verts[51] = -4.060184;
        BarqueHeavy_walk_verts[52] = 4.519985;
        BarqueHeavy_walk_verts[53] = -4.416701;
        BarqueHeavy_walk_verts[54] = -4.192767;
        BarqueHeavy_walk_verts[55] = 4.437483;
        BarqueHeavy_walk_verts[56] = -2.18982;
        BarqueHeavy_walk_verts[57] = 2.226839;
        BarqueHeavy_walk_verts[58] = 3.66751;
        BarqueHeavy_walk_verts[59] = 2.3819;
        BarqueHeavy_walk_verts[60] = 2.245017;
        BarqueHeavy_walk_verts[61] = 3.635017;
        BarqueHeavy_walk_verts[62] = 4.564888;
        BarqueHeavy_walk_verts[63] = 1.937432;
        BarqueHeavy_walk_verts[64] = 4.739986;
        BarqueHeavy_walk_verts[65] = 10.204626;
        BarqueHeavy_walk_verts[66] = -2.223924;
        BarqueHeavy_walk_verts[67] = 3.610018;
        BarqueHeavy_walk_verts[68] = 2.415148;
        BarqueHeavy_walk_verts[69] = -2.363176;
        BarqueHeavy_walk_verts[70] = 3.652524;
        BarqueHeavy_walk_verts[71] = 4.58783;
        BarqueHeavy_walk_verts[72] = -1.871098;
        BarqueHeavy_walk_verts[73] = 4.682503;
        BarqueHeavy_walk_verts[74] = 10.20035;
        BarqueHeavy_walk_verts[75] = 1.810741;
        BarqueHeavy_walk_verts[76] = 4.78999;
        BarqueHeavy_walk_verts[77] = -7.928573;
        BarqueHeavy_walk_verts[78] = -1.903875;
        BarqueHeavy_walk_verts[79] = 4.785028;
        BarqueHeavy_walk_verts[80] = -8.038487;
        BarqueHeavy_walk_verts[81] = 1.0341;
        BarqueHeavy_walk_verts[82] = 5.075017;
        BarqueHeavy_walk_verts[83] = -13.942662;
        BarqueHeavy_walk_verts[84] = -1.239711;
        BarqueHeavy_walk_verts[85] = 5.125019;
        BarqueHeavy_walk_verts[86] = -14.089706;
        BarqueHeavy_walk_verts[87] = 0.011601;
        BarqueHeavy_walk_verts[88] = 3.612521;
        BarqueHeavy_walk_verts[89] = 0.588713;
        BarqueHeavy_walk_verts[90] = 2.139341;
        BarqueHeavy_walk_verts[91] = 3.685023;
        BarqueHeavy_walk_verts[92] = 6.347926;
        BarqueHeavy_walk_verts[93] = -2.512121;
        BarqueHeavy_walk_verts[94] = 3.66752;
        BarqueHeavy_walk_verts[95] = 6.425726;
        BarqueHeavy_walk_verts[96] = 2.279032;
        BarqueHeavy_walk_verts[97] = 3.627519;
        BarqueHeavy_walk_verts[98] = 1.227873;
        BarqueHeavy_walk_verts[99] = -2.23291;
        BarqueHeavy_walk_verts[100] = 3.577515;
        BarqueHeavy_walk_verts[101] = 1.47171;
        BarqueHeavy_walk_verts[102] = -0.157702;
        BarqueHeavy_walk_verts[103] = 3.585011;
        BarqueHeavy_walk_verts[104] = 6.088806;
        BarqueHeavy_walk_verts[105] = 0.903451;
        BarqueHeavy_walk_verts[106] = 13.060098;
        BarqueHeavy_walk_verts[107] = -2.335189;
        BarqueHeavy_walk_verts[108] = -0.708007;
        BarqueHeavy_walk_verts[109] = 13.105115;
        BarqueHeavy_walk_verts[110] = -2.393259;
        BarqueHeavy_walk_verts[111] = -3.965897;
        BarqueHeavy_walk_verts[112] = 4.177509;
        BarqueHeavy_walk_verts[113] = 7.888167;
        BarqueHeavy_walk_verts[114] = 4.089813;
        BarqueHeavy_walk_verts[115] = 4.039974;
        BarqueHeavy_walk_verts[116] = 6.837087;
        BarqueHeavy_walk_verts[117] = -4.061991;
        BarqueHeavy_walk_verts[118] = 4.097502;
        BarqueHeavy_walk_verts[119] = 7.122987;
        BarqueHeavy_walk_verts[120] = 4.063299;
        BarqueHeavy_walk_verts[121] = 4.162478;
        BarqueHeavy_walk_verts[122] = 7.73592;
        BarqueHeavy_walk_verts[123] = 0.792968;
        BarqueHeavy_walk_verts[124] = 12.389985;
        BarqueHeavy_walk_verts[125] = 7.950143;
        BarqueHeavy_walk_verts[126] = -0.857768;
        BarqueHeavy_walk_verts[127] = 12.347624;
        BarqueHeavy_walk_verts[128] = 7.925544;

        BarqueHeavy_walk_types[0] = 0;
        BarqueHeavy_walk_types[1] = 0;
        BarqueHeavy_walk_types[2] = 0;
        BarqueHeavy_walk_types[3] = 0;
        BarqueHeavy_walk_types[4] = 0;
        BarqueHeavy_walk_types[5] = 0;
        BarqueHeavy_walk_types[6] = 0;
        BarqueHeavy_walk_types[7] = 0;
        BarqueHeavy_walk_types[8] = 0;
        BarqueHeavy_walk_types[9] = 0;
        BarqueHeavy_walk_types[10] = 0;
        BarqueHeavy_walk_types[11] = 0;
        BarqueHeavy_walk_types[12] = 0;
        BarqueHeavy_walk_types[13] = 0;
        BarqueHeavy_walk_types[14] = 0;
        BarqueHeavy_walk_types[15] = 5;
        BarqueHeavy_walk_types[16] = 5;
        BarqueHeavy_walk_types[17] = 5;
        BarqueHeavy_walk_types[18] = 5;
        BarqueHeavy_walk_types[19] = 2;
        BarqueHeavy_walk_types[20] = 2;
        BarqueHeavy_walk_types[21] = 3;
        BarqueHeavy_walk_types[22] = 1;
        BarqueHeavy_walk_types[23] = 1;
        BarqueHeavy_walk_types[24] = 3;
        BarqueHeavy_walk_types[25] = 0;
        BarqueHeavy_walk_types[26] = 0;
        BarqueHeavy_walk_types[27] = 0;
        BarqueHeavy_walk_types[28] = 0;
        BarqueHeavy_walk_types[29] = 0;
        BarqueHeavy_walk_types[30] = 0;
        BarqueHeavy_walk_types[31] = 0;
        BarqueHeavy_walk_types[32] = 0;
        BarqueHeavy_walk_types[33] = 0;
        BarqueHeavy_walk_types[34] = 0;
        BarqueHeavy_walk_types[35] = 4;
        BarqueHeavy_walk_types[36] = 4;
        BarqueHeavy_walk_types[37] = 5;
        BarqueHeavy_walk_types[38] = 5;
        BarqueHeavy_walk_types[39] = 5;
        BarqueHeavy_walk_types[40] = 5;
        BarqueHeavy_walk_types[41] = 6;
        BarqueHeavy_walk_types[42] = 6;

        BarqueHeavy_walk_graph[0] = (30)*256 + (1);
        BarqueHeavy_walk_graph[1] = (1)*256 + (2);
        BarqueHeavy_walk_graph[2] = (32)*256 + (3);
        BarqueHeavy_walk_graph[3] = (3)*256 + (4);
        BarqueHeavy_walk_graph[4] = (4)*256 + (5);
        BarqueHeavy_walk_graph[5] = (31)*256 + (6);
        BarqueHeavy_walk_graph[6] = (8)*256 + (7);
        BarqueHeavy_walk_graph[7] = (9)*256 + (33);
        BarqueHeavy_walk_graph[8] = (10)*256 + (9);
        BarqueHeavy_walk_graph[9] = (11)*256 + (10);
        BarqueHeavy_walk_graph[10] = (0)*256 + (6);
        BarqueHeavy_walk_graph[11] = (12)*256 + (11);
        BarqueHeavy_walk_graph[12] = (33)*256 + (8);
        BarqueHeavy_walk_graph[13] = (25)*256 + (26);
        BarqueHeavy_walk_graph[14] = (27)*256 + (14);
        BarqueHeavy_walk_graph[15] = (26)*256 + (13);
        BarqueHeavy_walk_graph[16] = (5)*256 + (15);
        BarqueHeavy_walk_graph[17] = (16)*256 + (15);
        BarqueHeavy_walk_graph[18] = (17)*256 + (11);
        BarqueHeavy_walk_graph[19] = (17)*256 + (18);
        BarqueHeavy_walk_graph[20] = (2)*256 + (19);
        BarqueHeavy_walk_graph[21] = (1)*256 + (20);
        BarqueHeavy_walk_graph[22] = (0)*256 + (21);
        BarqueHeavy_walk_graph[23] = (8)*256 + (22);
        BarqueHeavy_walk_graph[24] = (7)*256 + (23);
        BarqueHeavy_walk_graph[25] = (6)*256 + (24);
        BarqueHeavy_walk_graph[26] = (25)*256 + (5);
        BarqueHeavy_walk_graph[27] = (26)*256 + (11);
        BarqueHeavy_walk_graph[28] = (32)*256 + (29);
        BarqueHeavy_walk_graph[29] = (33)*256 + (29);
        BarqueHeavy_walk_graph[30] = (30)*256 + (0);
        BarqueHeavy_walk_graph[31] = (31)*256 + (7);
        BarqueHeavy_walk_graph[32] = (27)*256 + (28);
        BarqueHeavy_walk_graph[33] = (13)*256 + (28);
        BarqueHeavy_walk_graph[34] = (25)*256 + (14);
        BarqueHeavy_walk_graph[35] = (12)*256 + (5);
        BarqueHeavy_walk_graph[36] = (13)*256 + (14);
        BarqueHeavy_walk_graph[37] = (32)*256 + (2);
        BarqueHeavy_walk_graph[38] = (30)*256 + (34);
        BarqueHeavy_walk_graph[39] = (31)*256 + (34);
        BarqueHeavy_walk_graph[40] = (29)*256 + (34);
        BarqueHeavy_walk_graph[41] = (16)*256 + (35);
        BarqueHeavy_walk_graph[42] = (36)*256 + (18);
        BarqueHeavy_walk_graph[43] = (30)*256 + (38);
        BarqueHeavy_walk_graph[44] = (40)*256 + (38);
        BarqueHeavy_walk_graph[45] = (40)*256 + (41);
        BarqueHeavy_walk_graph[46] = (31)*256 + (39);
        BarqueHeavy_walk_graph[47] = (37)*256 + (39);
        BarqueHeavy_walk_graph[48] = (37)*256 + (42);
}
