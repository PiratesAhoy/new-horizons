int Tartane50_walk_count;
float Tartane50_walk_verts[15];
int Tartane50_walk_types[5];
int Tartane50_walk_graph[10];

void Tartane50_walk_init()
{
	Tartane50_walk_count = 5;

	Tartane50_walk_verts[0 ] = 0.333500;
	Tartane50_walk_verts[1 ] = 0.387010;
	Tartane50_walk_verts[2 ] = 1.800935;

	Tartane50_walk_verts[3 ] = -0.343441;
	Tartane50_walk_verts[4 ] = 0.387010;
	Tartane50_walk_verts[5 ] = 1.800935;

	Tartane50_walk_verts[6 ] = -0.213196;
	Tartane50_walk_verts[7 ] = 0.338588;
	Tartane50_walk_verts[8 ] = -1.889769;

	Tartane50_walk_verts[9 ] = 0.343614;
	Tartane50_walk_verts[10] = 0.255819;
	Tartane50_walk_verts[11] = -0.938992;

	Tartane50_walk_verts[12] = 0.332624;
	Tartane50_walk_verts[13] = 0.387010;
	Tartane50_walk_verts[14] = 1.800935;


	Tartane50_walk_types[0 ] = 0;
	Tartane50_walk_types[1 ] = 0;
	Tartane50_walk_types[2 ] = 0;
	Tartane50_walk_types[3 ] = 0;
	Tartane50_walk_types[4 ] = 0;

	Tartane50_walk_graph[0 ] = (0)*256 + (4);
	Tartane50_walk_graph[1 ] = (1)*256 + (2);
	Tartane50_walk_graph[2 ] = (2)*256 + (3);
	Tartane50_walk_graph[3 ] = (3)*256 + (0);
	Tartane50_walk_graph[4 ] = (1)*256 + (4);
	Tartane50_walk_graph[5 ] = (-1)*256 + (-1);
	Tartane50_walk_graph[6 ] = (-1)*256 + (-1);
	Tartane50_walk_graph[7 ] = (-1)*256 + (-1);
	Tartane50_walk_graph[8 ] = (-1)*256 + (-1);
	Tartane50_walk_graph[9 ] = (-1)*256 + (-1);
}
