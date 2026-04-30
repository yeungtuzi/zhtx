//      dynamicd.c
//	Dynamic map generation.
// 	by yeung

#include <ansi.h>
#include <command.h>

inherit F_DBASE;

#define DOOM_PATH "/d/xanadu"




//下面三个string数组可以放置想要参与动态分配的其他物品，人物和房间。
string *additional_treasure = ({
	"/obj/food/guo.c",
	"/obj/toy/camera.c",
	"/class/taohua/obj/nineflower.c",

	"/d/xueshan/npc/obj/xsword",
	"/d/xueshan/npc/obj/xblade",
        "/d/xueshan/npc/obj/xglove",
        "/d/xueshan/npc/obj/nang",
//	"/d/xueshan/npc/obj/xarmor",

	"/d/tieflag/npc/obj/spear",
	"/d/tieflag/npc/obj/peacock",        
	});                     
string *additional_room = ({
	});
string *additional_npc = ({
	});

//所有可能的方向
string *all_dir =	({ 	"north","northeast","northwest","south",
				"southwest","southeast","east","west",    
				"up","down","enter","out",
				"northup","northdown","eastup","eastdown",
				"westup","westdown","southup","southdown",
			});

int i,j,size,grid_size,flag;
string *dyna_room,*room_names,treasure_name,dir1,dir2,dir3,dir4,rev_dir1,rev_dir2,rev_dir3,rev_dir4,*dirs,*rev_dirs,*cur_exits;
object dyna_npc,dyna_treasure,*room_object,*old_npc,*old_treasure,cur_room;
mixed *room_list,*npc_list,*treasure_list,*temp_list;
int int_dir;

int regenerate_map(int LINK_ONLY);

void create()
{
	seteuid(getuid());
	set("name","动态地图精灵");
	set("id","dynamicd");
      	call_out("regenerate_map",150,0);
}

// 参数如果为非0,则只重新连接地图，并不生成宝物
int regenerate_map(int LINK_ONLY)
{
	int kk;

	remove_call_out("regenerate_map");
	if( !LINK_ONLY )
		call_out("regenerate_map",900,0); // regenerate map every 15 mins.

	room_list = get_dir(DOOM_PATH+"/dynamic/*.c");	
	for(kk=0;kk<sizeof(room_list);kk++)
		room_list[kk] = DOOM_PATH+"/dynamic/"+room_list[kk];
	room_list += additional_room;	                            

	npc_list = get_dir(DOOM_PATH+"/dynamic/npc/*.c");	
	for(kk=0;kk<sizeof(npc_list);kk++)
		npc_list[kk] = DOOM_PATH+"/dynamic/npc/"+npc_list[kk];
	npc_list += additional_npc;

	treasure_list = get_dir(DOOM_PATH+"/treasure/*.c");	
	for(kk=0;kk<sizeof(treasure_list);kk++)
		treasure_list[kk] = DOOM_PATH+"/treasure/"+treasure_list[kk];
	treasure_list += additional_treasure;

	//动态创建路径，创建一张二维表格来存放地图，每个房间有唯一的坐标，坐标相邻的有路径连通。
	//位于表格最右下方(grid_size,grid_size)的是入口，和山庄甬道连接，最左上方(0,0)的是出
	//口，和庄主的密室相连接。
	dyna_room = ({});
	while(sizeof(room_list))
	{
        	j = random(sizeof(room_list));
		dyna_room += ({room_list[j]});
		room_list -= ({room_list[j]});
	}//随机分配位置完毕						

	size = sizeof(dyna_room);

	CHANNEL_D->do_channel(this_object(),"sys","开始重新生成幽明山庄地图。"+(LINK_ONLY?"(不生成宝物)\n":"\n"));	
	//先往接天楼放置宝物
	if( !LINK_ONLY )
	for(i=1;i<10;i++)
	{
		j = random(sizeof(treasure_list));
		treasure_name = treasure_list[j];
	        old_treasure = children(treasure_name);
		//不重复生成宝物
		if( sizeof(old_treasure)<=1 ) //接天楼宝贝最多，不过那里的人可不是好惹的。
		{
			dyna_treasure = new(treasure_name);
			dyna_treasure->move(DOOM_PATH+"/lou"+i);
			(DOOM_PATH+"/lou"+i)->set("no_clean_up",1);
			CHANNEL_D->do_channel(this_object(),"sys",NOR"新生成宝物[ "+dyna_treasure->query("name")+" ]放置到"+(DOOM_PATH+"/lou"+i)->query("short")+"。\n");
		}
        }

	//全部刷新一遍                     
	room_object = ({});
	for(i=0;i<size;i++)
	{
	        if( !(cur_room = find_object(dyna_room[i])) )
			cur_room = load_object(dyna_room[i]);
		tell_room(cur_room,"从山庄中心传来机关发动的隆隆声...\n顿时一阵天旋地转...\n");
		cur_room->delete("exits");
		cur_room->delete("blocks");
		cur_room->set("no_clean_up",1);

		//房间里随机放置宝物
		j = random(sizeof(treasure_list));
		treasure_name = treasure_list[j];
	        old_treasure = children(treasure_name);
		//不重复生成宝物
		if( !LINK_ONLY && sizeof(old_treasure)<=1 && random(10) > 8 ) //白拣的宝贝当然生成的概率比较小 :) 
		{
			dyna_treasure = new(treasure_name);
			dyna_treasure->move(cur_room);
			CHANNEL_D->do_channel(this_object(),"sys",NOR"新生成宝物[ "+dyna_treasure->query("name")+" ]放置到"+cur_room->query("short")+"。\n");
		}
		room_object += ({cur_room});
	}

	//开始生成路径
	for(i=0;i<size;i++)
	{
		//生成四个不同的方向对
		dirs = 	({ 	"north","northeast","northwest","south",
				"southwest","southeast","east","west",    
				"up","down","enter","out",
				"northup","northdown","eastup","eastdown",
				"westup","westdown","southup","southdown",
			});

		rev_dirs = ({ 	"south","southwest","southeast","north",
				"northeast","northwest","west","east",
				"down","up","out","enter",
				"southdown","southup","westdown","westup",
				"eastdown","eastup","northdown","northup",
			   });	             	

                int_dir = random(sizeof(dirs));
		dir1 = dirs[int_dir];
		rev_dir1 = rev_dirs[int_dir];		
		dirs -= ({dir1});
		rev_dirs -= ({rev_dir1});
        	
		int_dir = random(sizeof(dirs));
		dir2 = dirs[int_dir];
		rev_dir2 = rev_dirs[int_dir];		
		dirs -= ({dir2});
		rev_dirs -= ({rev_dir2});

		int_dir = random(sizeof(dirs));
		dir3 = dirs[int_dir];
		rev_dir3 = rev_dirs[int_dir];		
		dirs -= ({dir3});
		rev_dirs -= ({rev_dir3});

//决定少连一条，不然可能太多路径很乱。
/*
		int_dir = random(sizeof(dirs));
		dir4 = dirs[int_dir];
		rev_dir4 = rev_dirs[int_dir];		

*/	
		//先生成一条通路，保证迷宫有解
		if(i>0)
		{
//			write(YEL"create path ["+dir1+"] for "+dyna_room[i]+"->"+dyna_room[i-1]+"\n"NOR);
			(room_object[i])->set("exits/"+dir1,dyna_room[i-1]);
//			write(YEL"create reverse path ["+rev_dir1+"] for "+dyna_room[i-1]+"->"+dyna_room[i]+"\n"NOR);
			(room_object[i-1])->set("exits/"+rev_dir1,dyna_room[i]);			
		}

		//随机生成通道                                       
		int_dir = random(size);                                  
		//不能覆盖已经存在的路径，也不能允许连到自己。
		if( (int_dir != i) && !((room_object[int_dir])->query("exits/"+rev_dir2)) )
		{
//			write("create additional path ["+dir2+"] for "+dyna_room[i]+"->"+dyna_room[int_dir]+"\n");
			(room_object[i])->set("exits/"+dir2,dyna_room[int_dir]);                                               
//			write("create additional reverse path ["+rev_dir2+"] for "+dyna_room[int_dir]+"->"+dyna_room[i]+"\n");
			(room_object[int_dir])->set("exits/"+rev_dir2,dyna_room[i]);
		}
                                                                                             
		int_dir = random(size);                                                    
		if( (int_dir != i) && !((room_object[int_dir])->query("exits/"+rev_dir3)) )
		{	
//			write("create additional path ["+dir3+"] for "+dyna_room[i]+"->"+dyna_room[int_dir]+"\n");
			(room_object[i])->set("exits/"+dir3,dyna_room[int_dir]);                                           
//			write("create additional reverse path ["+rev_dir3+"] for "+dyna_room[int_dir]+"->"+dyna_room[i]+"\n");
			(room_object[int_dir])->set("exits/"+rev_dir3,dyna_room[i]);
		}
/*
		int_dir = random(size);
		write("create additional path ["+dir4+"] for "+dyna_room[i]+"->"+dyna_room[int_dir]+"\n");
		(room_object[i])->set("exits/"+dir4,dyna_room[int_dir]);                                           
		write("create additional reverse path ["+rev_dir4+"] for "+dyna_room[int_dir]+"->"+dyna_room[i]+"\n");
		(room_object[int_dir])->set("exits/"+rev_dir4,dyna_room[i]);

*/
		tell_room(room_object[i],"待声音停歇下来，你发现一切都已经变了...\n");
	}		                                    

	//整个路径的出入口
	(room_object[size-1])->set("exits/south",DOOM_PATH+"/yongdao3");
	(room_object[0])->set("exits/north",DOOM_PATH+"/hall");                        
                                               
	//创建所有npc
	if( !LINK_ONLY )
	for(i=0;i<sizeof(npc_list);i++)	
	{
	        old_npc = children(npc_list[i]);
		if( sizeof(old_npc)<1 )
		{
		        dyna_npc = new(npc_list[i]);
//	                write("Creating new "+dyna_npc->query("name")+"\n");
		}
		else
			dyna_npc = old_npc[0];

		//往npc身上随机分配宝物                                            
		j = random(sizeof(treasure_list));
		treasure_name = treasure_list[j];
	        old_treasure = children(treasure_name);
		//不重复生成宝物
		if( sizeof(old_treasure)<=1 ) 
		{
			dyna_treasure = new(treasure_name);
			dyna_treasure->move(dyna_npc);
			CHANNEL_D->do_channel(this_object(),"sys",NOR"新生成宝物[ "+dyna_treasure->query("name")+" ]放置到"+dyna_npc->query("name")+"身上。\n");
		}
		j = random(sizeof(dyna_room));
//		message("sys","NPC "+npc_list[i]+" move to "+dyna_room[j]+"\n",users());
		dyna_npc->move(dyna_room[j]);
		for(int_dir=0;int_dir<sizeof(all_dir);int_dir++)
			if( (dyna_room[j])->query("exits/"+all_dir[int_dir]) )
				(dyna_room[j])->set("blocks/"+all_dir[int_dir],dyna_npc->query("id"));
	}

	return 1;
}

int suitable_npc(object npc)
{
                return (
                                clonep(npc)&&objectp(npc)&&!userp(npc) && !npc->is_fighting() && npc != this_object() &&
                                objectp(environment(npc)) &&
                                !environment(npc)->query("sleep_room") &&
                                !environment(npc)->query("no_fight") &&
                                strsrch(base_name(environment(npc)),"/wizard/") == -1 &&
                                strsrch(base_name(environment(npc)),"/xanadu/") == -1 &&
                                strsrch(base_name(environment(npc)),"/death/") == -1 
                       );
}


int suitable_room(object room)
{
                return (
                                function_exists("create_door", room) &&
                                !room->query("sleep_room") &&
                                //!room->query("no_fight") &&
                                strsrch(base_name(room),"/wizard/") == -1 &&
                                strsrch(base_name(room),"/xanadu/") == -1 &&
                                (strsrch(base_name(room),"/d/") != -1 || 
					strsrch(base_name(room),"/class/") != -1) 
//                              strsrch(base_name(room),"/death/") == -1 
                        );
}


object get_random_room_npc()
{
	object *treasure,tr,room,env, bak_room, *allnpc, *allroom;
        // 2026-04-30: unused variable commented out
        // mixed *list;
        int i,j,k,npc_flag,no_suitable;

        allnpc = livings();
        i = random(sizeof(allnpc));
        k = i;
        while( !suitable_npc(allnpc[i]) )
        {
                i++;
                if( i >= sizeof(allnpc) ) i = 0;

                //转了一圈也没找到？
                if( i == k )
                {
                         no_suitable = 1;
                         break;
                }
        }

        room = allnpc[i];
        allnpc = ({});
        npc_flag = 1;

        // by YEUNG
        //宝物可能在所有的房间,除了休息室,比武擂台看台,巫师房间,阴间

        allroom = objects();
        i = random(sizeof(allroom));
        k = i;
        while( !suitable_room(allroom[i]) )
        {
                i++;
                if( i >= sizeof(allroom) ) i = 0;
                if( i == k )
                {
                         no_suitable = 2;
                         break;
                }
        }
        bak_room = allroom[i];
        allroom = ({});

        if( no_suitable == 1 || !random(3) )
        {
                room = bak_room;
                no_suitable = 0;
                npc_flag = 0;
        }

        // 现在可以确定,如果no_suitable == 0我们找到了一个地方来移动宝物,否则,没有合适的地方
        if( no_suitable == 2 )
        {
                load_object("/d/snow/inn");
                room = find_object("/d/snow/inn");
        }

	return room;	
}


