//      dynamapd.c
//	Dynamic map generation.
// 	by meteoric

#include <ansi.h>
#include <command.h>

#define MAX_MAP_SIZE 10

inherit F_CLEAN_UP;
inherit F_DBASE;

//下面三个string数组可以放置想要参与动态分配的其他物品，人物和房间。

string *all_dir =       ({      "north","northeast","northwest","south",
                                "southwest","southeast","east","west",    
                        });

int i,j,k,size,dup_num,position,*available_position,*available_edge;
int *available_east_edge,*available_west_edge,*available_south_edge,*available_north_edge;
string *room_map,*dyna_room,*edge_room,treasure_name;
mixed *room_list,*npc_list,*treasure_list;
mapping edge_map,npc_map,rooms=([]);


int generate_map(string doom_path);
void generate_npc();
void generate_multi_npc(string npc,int dup_num);
int get_all_file(string doom_path);
int link_room(int,int,string,string,string);
void show_map();
void find_edge();
void block_all(string,object);

void create()
{
	seteuid(getuid());
	set("name","动态地图精灵");
	set("id","dynamapd");
	set("no_clean_up",1);
}


int generate_map(string doom_path)
{
	int kk,row,col;
	
	get_all_file(doom_path);

	//动态创建路径，创建一张二维表格来存放地图，每个房间有唯一的坐标，坐标相邻的有路径连通。
	//CHANNEL_D->do_channel(this_object(),"sys","room_list size="+sprintf("%d",sizeof(room_list)));
	
        room_map=({});
        for(i=0;i<=MAX_MAP_SIZE*MAX_MAP_SIZE;i++) room_map+=({"free"});
        
	//开始放随机房间
	CHANNEL_D->do_channel(this_object(),"sys","开始生成动态地图。\n");	
	
	size = sizeof(dyna_room);
	available_position=({55});
	for(i=0;i<size;i++)
	{
	       	//房间里随机放置宝物
	       	if(!sizeof(available_position)) return 0;
	       	rooms[dyna_room[i]]=([]);
	       	rooms[dyna_room[i]]["objects"]=([]);
	       	rooms[dyna_room[i]]["exits"]=([]);
	       	rooms[dyna_room[i]]["blocks"]=([]);
		if( random(10) > 5 && sizeof(treasure_list)) 
	        {
	        	j = random(sizeof(treasure_list));
			treasure_name = treasure_list[j];
			rooms[dyna_room[i]]["objects"][treasure_name]+=1;
			CHANNEL_D->do_channel(this_object(),"sys",NOR"新生成宝物[ "+treasure_name+" ]放置到"+dyna_room[i]+"。\n");
		}
	
		j=random(sizeof(available_position));
		j=available_position[j];
		
		row=j/MAX_MAP_SIZE;
		col=j-(j/MAX_MAP_SIZE)*MAX_MAP_SIZE; 
		//计算出行列
		room_map[j]=dyna_room[i];
		available_position-=({j});
		//此房间已被占用
		
		if(row-1>=0 && col-1>=0) link_room(row-1,col-1,dyna_room[i],"northwest","southeast");
		if(row-1>=0 && col>=0) link_room(row-1,col,dyna_room[i],"north","south");
		if(row-1>=0 && col+1>=0) link_room(row-1,col+1,dyna_room[i],"northeast","southwest");
		if(row>=0 && col-1>=0) link_room(row,col-1,dyna_room[i],"west","east");
		if(row>=0 && col+1>=0) link_room(row,col+1,dyna_room[i],"east","west");
		if(row+1>=0 && col-1>=0) link_room(row+1,col-1,dyna_room[i],"southwest","northeast");
		if(row+1>=0 && col>=0) link_room(row+1,col,dyna_room[i],"south","north");
		if(row+1>=0 && col+1>=0) link_room(row+1,col+1,dyna_room[i],"southeast","northwest");
	}		                                    
	
	//开始放边缘房间
	
	//CHANNEL_D->do_channel(this_object(),"sys","开始放置边缘地图。\n");
	
	size = sizeof(edge_room);
	
	find_edge();//寻找可用的边缘区域
	
	for(i=0;i<size;i++)
	{
		if(!sizeof(available_edge)) 
		{
			CHANNEL_D->do_channel(this_object(),"sys","边缘位置不够");
			break;
		}
		
		rooms[edge_room[i]]=([]);
	       	rooms[edge_room[i]]["objects"]=([]);
	       	rooms[edge_room[i]]["exits"]=([]);
	       	rooms[edge_room[i]]["blocks"]=([]);
		if(edge_map[edge_room[i]]=="east")
		{
			j=random(sizeof(available_east_edge));
			j=available_east_edge[j];
			CHANNEL_D->do_channel(this_object(),"sys","east_edge:"+edge_room[i]);
		}
		else if(edge_map[edge_room[i]]=="south")
		{
			j=random(sizeof(available_south_edge));
			j=available_south_edge[j];
			CHANNEL_D->do_channel(this_object(),"sys","south_edge:"+edge_room[i]);
		}
		else if(edge_map[edge_room[i]]=="west")
		{
			j=random(sizeof(available_west_edge));
			j=available_west_edge[j];
			CHANNEL_D->do_channel(this_object(),"sys","west_edge:"+edge_room[i]);
		}
		else if(edge_map[edge_room[i]]=="north")
		{
			j=random(sizeof(available_north_edge));
			j=available_north_edge[j];
			CHANNEL_D->do_channel(this_object(),"sys","north_edge:"+edge_room[i]);
		}
		else
		{
			j=random(sizeof(available_edge));
			j=available_edge[j];
			CHANNEL_D->do_channel(this_object(),"sys","random_edge:"+edge_room[i]);
		}
		
		row=j/MAX_MAP_SIZE;
		col=j-(j/MAX_MAP_SIZE)*MAX_MAP_SIZE; 
		//计算出行列
		room_map[j]=edge_room[i];
		available_east_edge-=({j});
		available_west_edge-=({j});
		available_south_edge-=({j});
		available_north_edge-=({j});
		available_edge-=({j});
		//此房间已被占用
		
		if(row-1>=0 && col-1>=0) link_room(row-1,col-1,edge_room[i],"northwest","southeast");
		if(row-1>=0 && col>=0) link_room(row-1,col,edge_room[i],"north","south");
		if(row-1>=0 && col+1>=0) link_room(row-1,col+1,edge_room[i],"northeast","southwest");
		if(row>=0 && col-1>=0) link_room(row,col-1,edge_room[i],"west","east");
		if(row>=0 && col+1>=0) link_room(row,col+1,edge_room[i],"east","west");
		if(row+1>=0 && col-1>=0) link_room(row+1,col-1,edge_room[i],"southwest","northeast");
		if(row+1>=0 && col>=0) link_room(row+1,col,edge_room[i],"south","north");
		if(row+1>=0 && col+1>=0) link_room(row+1,col+1,edge_room[i],"southeast","northwest");
	}
	//CHANNEL_D->do_channel(this_object(),"sys","边缘地图放置完毕。\n");
	
	generate_npc();
	
	CHANNEL_D->do_channel(this_object(),"sys","动态地图产生完毕。\n");
	
	//CHANNEL_D->do_channel(this_object(),"sys","NPC创建完毕。\n");
	//for(i=0;i<sizeof(dyna_room);i++) room_object[i]->save();
	//for(i=0;i<sizeof(edge_room);i++) edge_room[i]->save();
	//show_map();
	return 1;
}

int link_room(int row,int col, string room,string dir, string rev_dir)
{
	string temp_room;
	position=row*MAX_MAP_SIZE+col;
	if(position>MAX_MAP_SIZE*MAX_MAP_SIZE-1) return 0;
	temp_room=room_map[position];
	if(temp_room=="free") 
	{
		available_position-=({position});
		available_position+=({position});
	}
	else {
		rooms[temp_room]["exits"][rev_dir]=room;
		rooms[room]["exits"][dir]=temp_room;
		return 1;
	}
	return 0;
}

void show_map()
{
	int i,j;
	string temp;
	for(i=0;i<MAX_MAP_SIZE;i++)
	{
		temp="";
		for(j=0;j<MAX_MAP_SIZE;j++)
		{
		if(room_map[i*MAX_MAP_SIZE+j]=="free")	temp+=" 0";
		else temp+=" 1";
		}
		CHANNEL_D->do_channel(this_object(),"sys",temp);
	}
}

int get_all_file(string doom_path)
{
	string *files,*file,enter,edgerooms,*npcs,*npc,multinpcs;
	int i;
	int kk;

	room_list = get_dir(doom_path+"/*.c");	
	for(kk=0;kk<sizeof(room_list);kk++)
		room_list[kk] = doom_path+"/"+room_list[kk];
	
	npc_list = get_dir(doom_path+"/npc/*.c");	
	for(kk=0;kk<sizeof(npc_list);kk++)
		npc_list[kk] = doom_path+"/npc/"+npc_list[kk];
	
	treasure_list = get_dir(doom_path+"/treasure/*.c");	
	for(kk=0;kk<sizeof(treasure_list);kk++)
		treasure_list[kk] = doom_path+"/treasure/"+treasure_list[kk];
	
	npc_map=([]);
	if(multinpcs=read_file(doom_path+"/npc/multinpc.out")) 
	{
		npcs=explode(multinpcs,"\n");
		for(i=0;i<sizeof(npcs);i++)
		{
		npc=explode(npcs[i],":");
		if(sizeof(npc)>1) npc_map+=([doom_path+"/npc/"+npc[0]:npc[1]]);
		npc_list-=({doom_path+"/npc/"+npc[0]});
		CHANNEL_D->do_channel(this_object(),"sys",doom_path+"/npc/"+npc[0]);
		}
	}
	
	edge_map=([]);
	edge_room=({});
	if(edgerooms=read_file(doom_path+"/edgeroom.out")) 
	{
		files=explode(edgerooms,"\n");
		for(i=0;i<sizeof(files);i++)
		{
		file=explode(files[i],":");
		if(sizeof(file)>1) edge_map+=([doom_path+"/"+file[0]:file[1]]);
		edge_room+=({doom_path+"/"+file[0]});
		room_list-=({doom_path+"/"+file[0]});
		//CHANNEL_D->do_channel(this_object(),"sys",edge_room[i]);
		}
		//CHANNEL_D->do_channel(this_object(),"sys","room_list size="+sprintf("%d",sizeof(room_list)));			
	}
	
	dyna_room = ({});
	while(sizeof(room_list))
	{
        	j = random(sizeof(room_list));
		dyna_room += ({room_list[j]});
		room_list -= ({room_list[j]});
	}//随机分配位置完毕	
	return 1;
}

void find_edge()
{
	int find;
	available_edge=({});
	available_east_edge=({});
	available_west_edge=({});
	available_south_edge=({});
	available_north_edge=({});
	
	for(i=0;i<MAX_MAP_SIZE;i++) 
	{
		find=0;
		for(j=0;j<MAX_MAP_SIZE;j++) 
			if(room_map[i*MAX_MAP_SIZE+j]!="free"&&j!=0) {find=1;break;}
		if(find) 
		{
			available_edge+=({i*MAX_MAP_SIZE+j-1});
			available_west_edge+=({i*MAX_MAP_SIZE+j-1});
		}
	}
	
	for(j=0;j<MAX_MAP_SIZE;j++) 
	{
		find=0;
		for(i=MAX_MAP_SIZE-1;i>=0;i--) 
			if(room_map[i*MAX_MAP_SIZE+j]!="free"&&i!=MAX_MAP_SIZE-1) {find=1;break;}
		if(find) 
		{
			available_edge+=({(i+1)*MAX_MAP_SIZE+j});
			available_south_edge+=({(i+1)*MAX_MAP_SIZE+j});
		}
	}
	for(i=MAX_MAP_SIZE-1;i>=0;i--) 
	{
		find=0;
		for(j=MAX_MAP_SIZE-1;j>=0;j--) 
			if(room_map[i*MAX_MAP_SIZE+j]!="free"&&j!=MAX_MAP_SIZE-1) {find=1;break;}
		if(find) 
		{
			available_edge+=({i*MAX_MAP_SIZE+j+1});
			available_east_edge+=({i*MAX_MAP_SIZE+j+1});
		}
	}
	for(j=MAX_MAP_SIZE-1;j>=0;j--) 
	{
		find=0;
		for(i=0;i<MAX_MAP_SIZE;i++) 
			if(room_map[i*MAX_MAP_SIZE+j]!="free"&&i!=0) {find=1;break;}
		if(find) 
		{
			available_edge+=({(i-1)*MAX_MAP_SIZE+j});
			available_north_edge+=({(i-1)*MAX_MAP_SIZE+j});
		}
	}
}

void generate_multi_npc(string npc,int dup_num)
{
	int move_num,new_num,exist_num,dest_num;
	
	//CHANNEL_D->do_channel(this_object(),"sys",NOR"已经有的数:"+sprintf("%d",sizeof(old_npc)));	
	for(i=0;i<dup_num;i++)
	{
		j = random(sizeof(dyna_room));
		rooms[dyna_room[j]]["objects"][npc_list[i]]+=1;
	}
	return;
}

void generate_npc()	//创建所有npc
{
	int dup_num;
	string *multi_npc;
	for(i=0;i<sizeof(npc_list);i++)	
	{
		j = random(sizeof(dyna_room));
		rooms[dyna_room[j]]["objects"][npc_list[i]]=1;
	}
	multi_npc=keys(npc_map);
	for(i=0;i<sizeof(multi_npc);i++)
	{
		dup_num=to_int(npc_map[multi_npc[i]]);
		CHANNEL_D->do_channel(this_object(),"sys",NOR"产生"+sprintf("%d",dup_num)+"个"+multi_npc[i]);
		for(j=0;j<dup_num;j++)
		{
			k = random(sizeof(dyna_room));
			rooms[dyna_room[k]]["objects"][multi_npc[i]]+=1;
		}
	}
}

int load_room(string domain,string room_name)
{
	mapping exits,objects,blocks;
	if(!mapp(rooms)||!sizeof(rooms)) generate_map(domain);
	if(!sizeof(rooms[room_name])) generate_map(domain);
	exits=rooms[room_name]["exits"];
	objects=rooms[room_name]["objects"];
	blocks=rooms[room_name]["blocks"];
	if(room_name->query("exits")) exits+=room_name->query("exits");
	if(room_name->query("objects")) objects+=room_name->query("objects");
	if(room_name->query("blocks")) blocks+=room_name->query("blocks");
	
	room_name->set("exits",exits);
	room_name->set("objects",objects);
	room_name->set("blocks",blocks);
	return 1;
}

void remove_room()
{
	object cur_room;
	for(i=0;i<sizeof(dyna_room);i++)
		if(cur_room=find_object(dyna_room[i]))	destruct(cur_room);
	for(i=0;i<sizeof(edge_room);i++)
		if(cur_room=find_object(edge_room[i]))	destruct(cur_room);
}
