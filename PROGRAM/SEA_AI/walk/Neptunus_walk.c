int Neptunus_walk_count;
float Neptunus_walk_verts[201];
int Neptunus_walk_types[67];
int Neptunus_walk_graph[85];

void Neptunus_walk_init()
{
        Neptunus_walk_count = 67;

        Neptunus_walk_verts[0] = -0.236675;
        Neptunus_walk_verts[1] = 3.497422;
        Neptunus_walk_verts[2] = -11.162162;
        Neptunus_walk_verts[3] = -1.298383;
        Neptunus_walk_verts[4] = 3.337421;
        Neptunus_walk_verts[5] = -9.71714;
        Neptunus_walk_verts[6] = 1.267309;
        Neptunus_walk_verts[7] = 3.327419;
        Neptunus_walk_verts[8] = -9.306473;
        Neptunus_walk_verts[9] = 0.794284;
        Neptunus_walk_verts[10] = 3.699919;
        Neptunus_walk_verts[11] = -13.649371;
        Neptunus_walk_verts[12] = -1.008343;
        Neptunus_walk_verts[13] = 3.637414;
        Neptunus_walk_verts[14] = -13.341435;
        Neptunus_walk_verts[15] = -0.068835;
        Neptunus_walk_verts[16] = 3.374928;
        Neptunus_walk_verts[17] = -8.867801;
        Neptunus_walk_verts[18] = -0.016238;
        Neptunus_walk_verts[19] = 1.24742;
        Neptunus_walk_verts[20] = -7.468146;
        Neptunus_walk_verts[21] = 0.115271;
        Neptunus_walk_verts[22] = 1.414911;
        Neptunus_walk_verts[23] = -10.003189;
        Neptunus_walk_verts[24] = -0.046583;
        Neptunus_walk_verts[25] = 1.219907;
        Neptunus_walk_verts[26] = -6.944532;
        Neptunus_walk_verts[27] = -0.707773;
        Neptunus_walk_verts[28] = 1.344911;
        Neptunus_walk_verts[29] = -10.276;
        Neptunus_walk_verts[30] = 0.831885;
        Neptunus_walk_verts[31] = 1.397414;
        Neptunus_walk_verts[32] = -10.132929;
        Neptunus_walk_verts[33] = 1.271682;
        Neptunus_walk_verts[34] = 1.067407;
        Neptunus_walk_verts[35] = -5.590375;
        Neptunus_walk_verts[36] = -0.99539;
        Neptunus_walk_verts[37] = 1.069904;
        Neptunus_walk_verts[38] = -5.626036;
        Neptunus_walk_verts[39] = 0.063041;
        Neptunus_walk_verts[40] = 1.089905;
        Neptunus_walk_verts[41] = -4.185028;
        Neptunus_walk_verts[42] = -1.37592;
        Neptunus_walk_verts[43] = 0.974906;
        Neptunus_walk_verts[44] = -2.59653;
        Neptunus_walk_verts[45] = 1.651404;
        Neptunus_walk_verts[46] = 0.929905;
        Neptunus_walk_verts[47] = -2.602111;
        Neptunus_walk_verts[48] = 0.892887;
        Neptunus_walk_verts[49] = 0.944912;
        Neptunus_walk_verts[50] = -1.168462;
        Neptunus_walk_verts[51] = -0.475967;
        Neptunus_walk_verts[52] = 0.939922;
        Neptunus_walk_verts[53] = -1.100445;
        Neptunus_walk_verts[54] = -0.489127;
        Neptunus_walk_verts[55] = 0.922418;
        Neptunus_walk_verts[56] = 1.266925;
        Neptunus_walk_verts[57] = 0.687131;
        Neptunus_walk_verts[58] = 0.872422;
        Neptunus_walk_verts[59] = 1.274154;
        Neptunus_walk_verts[60] = 0.682501;
        Neptunus_walk_verts[61] = 0.859927;
        Neptunus_walk_verts[62] = 3.504979;
        Neptunus_walk_verts[63] = -0.588738;
        Neptunus_walk_verts[64] = 0.837434;
        Neptunus_walk_verts[65] = 3.488842;
        Neptunus_walk_verts[66] = 0.907937;
        Neptunus_walk_verts[67] = 0.922429;
        Neptunus_walk_verts[68] = 5.746037;
        Neptunus_walk_verts[69] = -0.927396;
        Neptunus_walk_verts[70] = 0.81743;
        Neptunus_walk_verts[71] = 5.84705;
        Neptunus_walk_verts[72] = 0.781953;
        Neptunus_walk_verts[73] = 0.897432;
        Neptunus_walk_verts[74] = 7.8345;
        Neptunus_walk_verts[75] = -0.698123;
        Neptunus_walk_verts[76] = 0.869928;
        Neptunus_walk_verts[77] = 7.915238;
        Neptunus_walk_verts[78] = 1.048317;
        Neptunus_walk_verts[79] = 0.897421;
        Neptunus_walk_verts[80] = 8.809232;
        Neptunus_walk_verts[81] = -0.93209;
        Neptunus_walk_verts[82] = 0.874896;
        Neptunus_walk_verts[83] = 8.818238;
        Neptunus_walk_verts[84] = -0.982494;
        Neptunus_walk_verts[85] = 2.327425;
        Neptunus_walk_verts[86] = 9.619295;
        Neptunus_walk_verts[87] = 0.975456;
        Neptunus_walk_verts[88] = 2.277412;
        Neptunus_walk_verts[89] = 9.596999;
        Neptunus_walk_verts[90] = -0.021234;
        Neptunus_walk_verts[91] = 2.362415;
        Neptunus_walk_verts[92] = 9.941056;
        Neptunus_walk_verts[93] = 2.127763;
        Neptunus_walk_verts[94] = 0.904919;
        Neptunus_walk_verts[95] = 6.951036;
        Neptunus_walk_verts[96] = -2.136926;
        Neptunus_walk_verts[97] = 0.902424;
        Neptunus_walk_verts[98] = 7.000956;
        Neptunus_walk_verts[99] = 2.273;
        Neptunus_walk_verts[100] = 1.012405;
        Neptunus_walk_verts[101] = -2.625005;
        Neptunus_walk_verts[102] = -2.275109;
        Neptunus_walk_verts[103] = 1.017408;
        Neptunus_walk_verts[104] = -2.568115;
        Neptunus_walk_verts[105] = -2.185074;
        Neptunus_walk_verts[106] = 1.147407;
        Neptunus_walk_verts[107] = -5.821996;
        Neptunus_walk_verts[108] = 2.252363;
        Neptunus_walk_verts[109] = 1.209911;
        Neptunus_walk_verts[110] = -5.76008;
        Neptunus_walk_verts[111] = 2.471499;
        Neptunus_walk_verts[112] = 3.412426;
        Neptunus_walk_verts[113] = -10.480949;
        Neptunus_walk_verts[114] = -2.63111;
        Neptunus_walk_verts[115] = 3.297426;
        Neptunus_walk_verts[116] = -10.307661;
        Neptunus_walk_verts[117] = 3.213257;
        Neptunus_walk_verts[118] = 2.539927;
        Neptunus_walk_verts[119] = -5.120599;
        Neptunus_walk_verts[120] = 3.355228;
        Neptunus_walk_verts[121] = 2.374954;
        Neptunus_walk_verts[122] = -3.18758;
        Neptunus_walk_verts[123] = -3.265143;
        Neptunus_walk_verts[124] = 2.449935;
        Neptunus_walk_verts[125] = -3.32632;
        Neptunus_walk_verts[126] = -3.168349;
        Neptunus_walk_verts[127] = 2.54995;
        Neptunus_walk_verts[128] = -4.803807;
        Neptunus_walk_verts[129] = -1.013158;
        Neptunus_walk_verts[130] = 1.342416;
        Neptunus_walk_verts[131] = -7.031328;
        Neptunus_walk_verts[132] = -1.138824;
        Neptunus_walk_verts[133] = 1.012412;
        Neptunus_walk_verts[134] = -4.130946;
        Neptunus_walk_verts[135] = -1.287228;
        Neptunus_walk_verts[136] = 0.877409;
        Neptunus_walk_verts[137] = -1.104002;
        Neptunus_walk_verts[138] = -1.361227;
        Neptunus_walk_verts[139] = 0.857413;
        Neptunus_walk_verts[140] = 1.290981;
        Neptunus_walk_verts[141] = -1.395731;
        Neptunus_walk_verts[142] = 0.884916;
        Neptunus_walk_verts[143] = 3.558124;
        Neptunus_walk_verts[144] = -1.265802;
        Neptunus_walk_verts[145] = 0.85991;
        Neptunus_walk_verts[146] = 5.879619;
        Neptunus_walk_verts[147] = -1.174827;
        Neptunus_walk_verts[148] = 0.902396;
        Neptunus_walk_verts[149] = 7.753054;
        Neptunus_walk_verts[150] = 1.08512;
        Neptunus_walk_verts[151] = 1.154935;
        Neptunus_walk_verts[152] = -7.051312;
        Neptunus_walk_verts[153] = 1.147772;
        Neptunus_walk_verts[154] = 1.002401;
        Neptunus_walk_verts[155] = -4.166679;
        Neptunus_walk_verts[156] = 1.417779;
        Neptunus_walk_verts[157] = 0.972417;
        Neptunus_walk_verts[158] = -1.150788;
        Neptunus_walk_verts[159] = 1.435049;
        Neptunus_walk_verts[160] = 0.912419;
        Neptunus_walk_verts[161] = 1.202819;
        Neptunus_walk_verts[162] = 1.309531;
        Neptunus_walk_verts[163] = 0.879913;
        Neptunus_walk_verts[164] = 3.538536;
        Neptunus_walk_verts[165] = 1.240509;
        Neptunus_walk_verts[166] = 0.874905;
        Neptunus_walk_verts[167] = 5.765935;
        Neptunus_walk_verts[168] = 1.145017;
        Neptunus_walk_verts[169] = 1.027414;
        Neptunus_walk_verts[170] = 7.824968;
        Neptunus_walk_verts[171] = 3.248195;
        Neptunus_walk_verts[172] = 2.252415;
        Neptunus_walk_verts[173] = 6.632903;
        Neptunus_walk_verts[174] = -3.209565;
        Neptunus_walk_verts[175] = 2.274944;
        Neptunus_walk_verts[176] = 6.665377;
        Neptunus_walk_verts[177] = -1.058353;
        Neptunus_walk_verts[178] = 9.959909;
        Neptunus_walk_verts[179] = -2.94389;
        Neptunus_walk_verts[180] = 0.954631;
        Neptunus_walk_verts[181] = 9.977417;
        Neptunus_walk_verts[182] = -2.913834;
        Neptunus_walk_verts[183] = -0.882332;
        Neptunus_walk_verts[184] = 8.847463;
        Neptunus_walk_verts[185] = -9.977915;
        Neptunus_walk_verts[186] = 0.84529;
        Neptunus_walk_verts[187] = 8.767464;
        Neptunus_walk_verts[188] = -9.882292;
        Neptunus_walk_verts[189] = 0.946397;
        Neptunus_walk_verts[190] = 9.604924;
        Neptunus_walk_verts[191] = 7.558041;
        Neptunus_walk_verts[192] = -0.87625;
        Neptunus_walk_verts[193] = 9.642425;
        Neptunus_walk_verts[194] = 7.737899;
        Neptunus_walk_verts[195] = -1.838021;
        Neptunus_walk_verts[196] = 1.282421;
        Neptunus_walk_verts[197] = -8.325314;
        Neptunus_walk_verts[198] = 1.523594;
        Neptunus_walk_verts[199] = 1.277423;
        Neptunus_walk_verts[200] = -8.486305;

        Neptunus_walk_types[0] = 0;
        Neptunus_walk_types[1] = 0;
        Neptunus_walk_types[2] = 0;
        Neptunus_walk_types[3] = 0;
        Neptunus_walk_types[4] = 0;
        Neptunus_walk_types[5] = 0;
        Neptunus_walk_types[6] = 0;
        Neptunus_walk_types[7] = 0;
        Neptunus_walk_types[8] = 0;
        Neptunus_walk_types[9] = 1;
        Neptunus_walk_types[10] = 2;
        Neptunus_walk_types[11] = 0;
        Neptunus_walk_types[12] = 0;
        Neptunus_walk_types[13] = 0;
        Neptunus_walk_types[14] = 0;
        Neptunus_walk_types[15] = 0;
        Neptunus_walk_types[16] = 0;
        Neptunus_walk_types[17] = 0;
        Neptunus_walk_types[18] = 0;
        Neptunus_walk_types[19] = 0;
        Neptunus_walk_types[20] = 0;
        Neptunus_walk_types[21] = 0;
        Neptunus_walk_types[22] = 0;
        Neptunus_walk_types[23] = 0;
        Neptunus_walk_types[24] = 0;
        Neptunus_walk_types[25] = 0;
        Neptunus_walk_types[26] = 0;
        Neptunus_walk_types[27] = 0;
        Neptunus_walk_types[28] = 0;
        Neptunus_walk_types[29] = 0;
        Neptunus_walk_types[30] = 0;
        Neptunus_walk_types[31] = 0;
        Neptunus_walk_types[32] = 0;
        Neptunus_walk_types[33] = 0;
        Neptunus_walk_types[34] = 0;
        Neptunus_walk_types[35] = 0;
        Neptunus_walk_types[36] = 0;
        Neptunus_walk_types[37] = 5;
        Neptunus_walk_types[38] = 5;
        Neptunus_walk_types[39] = 5;
        Neptunus_walk_types[40] = 5;
        Neptunus_walk_types[41] = 5;
        Neptunus_walk_types[42] = 5;
        Neptunus_walk_types[43] = 1;
        Neptunus_walk_types[44] = 1;
        Neptunus_walk_types[45] = 1;
        Neptunus_walk_types[46] = 1;
        Neptunus_walk_types[47] = 1;
        Neptunus_walk_types[48] = 1;
        Neptunus_walk_types[49] = 1;
        Neptunus_walk_types[50] = 2;
        Neptunus_walk_types[51] = 2;
        Neptunus_walk_types[52] = 2;
        Neptunus_walk_types[53] = 2;
        Neptunus_walk_types[54] = 2;
        Neptunus_walk_types[55] = 2;
        Neptunus_walk_types[56] = 2;
        Neptunus_walk_types[57] = 5;
        Neptunus_walk_types[58] = 5;
        Neptunus_walk_types[59] = 6;
        Neptunus_walk_types[60] = 6;
        Neptunus_walk_types[61] = 4;
        Neptunus_walk_types[62] = 4;
        Neptunus_walk_types[63] = 5;
        Neptunus_walk_types[64] = 5;
        Neptunus_walk_types[65] = 0;
        Neptunus_walk_types[66] = 0;

        Neptunus_walk_graph[0] = (1)*256 + (0);
        Neptunus_walk_graph[1] = (2)*256 + (0);
        Neptunus_walk_graph[2] = (3)*256 + (0);
        Neptunus_walk_graph[3] = (4)*256 + (0);
        Neptunus_walk_graph[4] = (4)*256 + (1);
        Neptunus_walk_graph[5] = (4)*256 + (3);
        Neptunus_walk_graph[6] = (9)*256 + (7);
        Neptunus_walk_graph[7] = (10)*256 + (7);
        Neptunus_walk_graph[8] = (10)*256 + (7);
        Neptunus_walk_graph[9] = (2)*256 + (37);
        Neptunus_walk_graph[10] = (3)*256 + (2);
        Neptunus_walk_graph[11] = (6)*256 + (5);
        Neptunus_walk_graph[12] = (35)*256 + (12);
        Neptunus_walk_graph[13] = (1)*256 + (5);
        Neptunus_walk_graph[14] = (8)*256 + (6);
        Neptunus_walk_graph[15] = (8)*256 + (6);
        Neptunus_walk_graph[16] = (36)*256 + (11);
        Neptunus_walk_graph[17] = (8)*256 + (11);
        Neptunus_walk_graph[18] = (5)*256 + (2);
        Neptunus_walk_graph[19] = (1)*256 + (38);
        Neptunus_walk_graph[20] = (38)*256 + (61);
        Neptunus_walk_graph[21] = (38)*256 + (61);
        Neptunus_walk_graph[22] = (62)*256 + (37);
        Neptunus_walk_graph[23] = (8)*256 + (43);
        Neptunus_walk_graph[24] = (8)*256 + (50);
        Neptunus_walk_graph[25] = (35)*256 + (42);
        Neptunus_walk_graph[26] = (12)*256 + (8);
        Neptunus_walk_graph[27] = (12)*256 + (13);
        Neptunus_walk_graph[28] = (14)*256 + (13);
        Neptunus_walk_graph[29] = (15)*256 + (13);
        Neptunus_walk_graph[30] = (44)*256 + (13);
        Neptunus_walk_graph[31] = (51)*256 + (13);
        Neptunus_walk_graph[32] = (11)*256 + (13);
        Neptunus_walk_graph[33] = (11)*256 + (13);
        Neptunus_walk_graph[34] = (14)*256 + (17);
        Neptunus_walk_graph[35] = (14)*256 + (34);
        Neptunus_walk_graph[36] = (41)*256 + (34);
        Neptunus_walk_graph[37] = (42)*256 + (59);
        Neptunus_walk_graph[38] = (41)*256 + (59);
        Neptunus_walk_graph[39] = (45)*256 + (17);
        Neptunus_walk_graph[40] = (46)*256 + (18);
        Neptunus_walk_graph[41] = (17)*256 + (18);
        Neptunus_walk_graph[42] = (19)*256 + (18);
        Neptunus_walk_graph[43] = (21)*256 + (18);
        Neptunus_walk_graph[44] = (21)*256 + (20);
        Neptunus_walk_graph[45] = (21)*256 + (23);
        Neptunus_walk_graph[46] = (21)*256 + (47);
        Neptunus_walk_graph[47] = (23)*256 + (48);
        Neptunus_walk_graph[48] = (33)*256 + (15);
        Neptunus_walk_graph[49] = (16)*256 + (15);
        Neptunus_walk_graph[50] = (19)*256 + (16);
        Neptunus_walk_graph[51] = (16)*256 + (52);
        Neptunus_walk_graph[52] = (19)*256 + (53);
        Neptunus_walk_graph[53] = (19)*256 + (20);
        Neptunus_walk_graph[54] = (22)*256 + (20);
        Neptunus_walk_graph[55] = (54)*256 + (20);
        Neptunus_walk_graph[56] = (55)*256 + (22);
        Neptunus_walk_graph[57] = (24)*256 + (26);
        Neptunus_walk_graph[58] = (24)*256 + (22);
        Neptunus_walk_graph[59] = (25)*256 + (23);
        Neptunus_walk_graph[60] = (27)*256 + (25);
        Neptunus_walk_graph[61] = (49)*256 + (25);
        Neptunus_walk_graph[62] = (56)*256 + (24);
        Neptunus_walk_graph[63] = (26)*256 + (27);
        Neptunus_walk_graph[64] = (26)*256 + (29);
        Neptunus_walk_graph[65] = (30)*256 + (29);
        Neptunus_walk_graph[66] = (30)*256 + (28);
        Neptunus_walk_graph[67] = (32)*256 + (23);
        Neptunus_walk_graph[68] = (32)*256 + (58);
        Neptunus_walk_graph[69] = (58)*256 + (64);
        Neptunus_walk_graph[70] = (28)*256 + (27);
        Neptunus_walk_graph[71] = (31)*256 + (57);
        Neptunus_walk_graph[72] = (63)*256 + (57);
        Neptunus_walk_graph[73] = (31)*256 + (24);
        Neptunus_walk_graph[74] = (33)*256 + (40);
        Neptunus_walk_graph[75] = (60)*256 + (40);
        Neptunus_walk_graph[76] = (39)*256 + (60);
        Neptunus_walk_graph[77] = (39)*256 + (36);
        Neptunus_walk_graph[78] = (39)*256 + (36);
        Neptunus_walk_graph[79] = (8)*256 + (66);
        Neptunus_walk_graph[80] = (7)*256 + (65);
        Neptunus_walk_graph[81] = (8)*256 + (65);
        Neptunus_walk_graph[82] = (8)*256 + (65);
        Neptunus_walk_graph[83] = (7)*256 + (66);
        Neptunus_walk_graph[84] = (7)*256 + (66);
}
