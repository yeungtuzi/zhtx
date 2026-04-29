// by yeung 2000-3-26
// 让每次探宝过程中的水晶球的显示信息不同.(防止机器人)       
// 增加距离的提示.
// 添加从昏迷的NPC/尸体/骸骨上面取宝的功能.


inherit ITEM;
string chstring(string,int);
#include <ansi.h>

int kar_seed;

void create()
{
	set_name("水晶球", ({ "shui jing", "detector", "device" }) );
	set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
	else
	{
		set("unit", "个");
		set("long",@DESC
这是参加夺宝探险必备的物品，有了它，就可以找到(detect)
宝物所藏的地方。而且,它和宝物有一种神秘的联系,只要宝物
没有深埋在土里面,它就能把宝物吸引(attract)到主人的手上。
如果宝物被埋了起来，那就只能挖挖(dig)看了。不过，如果
宝物在别人手里的话，除非他没办法保护他的宝物，否则，
是拿不到的。
DESC
		);

        	set("unpawnable", 1);
	}
	setup();  
	//防止被放到布袋里面
	set("no_get",1);
	remove_call_out("dispear");
	call_out( "dispear", 900 );
	kar_seed = 0;
}

void init()
{
	add_action("do_detect", "detect");
	add_action("do_dig","dig");          
	add_action("do_attract","attract");   
	add_action("do_conjure","conjure");	       
	if( !kar_seed )
		kar_seed = random(this_player()->query("kar"))+this_player()->query("kar")/2;
}

int do_detect()
{
	object me,*treasure,env;
	string msg,location_dir,my_dir,*dir1,*dir2;
	int i, match_ratio;
	
	me =this_player();

	if( me->query("gin") < 90 )
		return notify_fail("你的精力不够集中，无法探测。\n");
	me->receive_damage("gin",100);
	
	treasure = children("/obj/example/stone.c");

	if(sizeof(treasure)<2)
		return notify_fail("宝物还没有出世！！\n");

	env = environment(treasure[0]);
	if( !env )	return notify_fail("宝物还没有出世！\n");

	if( userp(env) )
		tell_object(me,"宝物现在在"+env->name()+"的身上！\n");
	else	
	{
		msg = env->query("long")+"\n";
//		msg = chstring(msg,5);
		msg = "宝物现在在\n"+chstring(msg,kar_seed);
		tell_object(me,msg);

//		printf("%s \n",file_name(env));

	}
// 添加一下大概距离的显示.
// 首先找出路径来.
	if( env->is_character() )
	{
		env = environment(env);
	}			
	location_dir = base_name(env);
	env = environment(me);
	if( env->is_character() )
	{
		env = environment(env);
	}			
	my_dir = base_name(env);	
// 判断距离的依据
// 最近是双方在同一个房间
// 然后按照是双方目录位置重合程度.     
// 都以/d开始,就是非常遥远.
// 如果连开始的/d都不一样是无法感知距离
	if( location_dir == my_dir )
	{
		tell_object(me,"水晶球里面清晰地显示出来这个房间的模样,看来宝物就在你身边的什么地方.\n");
		return 1;
	}		
	dir1 = explode(location_dir,"/");
	dir2 = explode(my_dir,"/");				
// 计算匹配程度
	match_ratio = 0;
	while( dir1[match_ratio] == dir2[match_ratio] )
	{
		match_ratio ++;
		if( match_ratio >= (sizeof(dir1)-1) || match_ratio >= (sizeof(dir2)-1) )	//比较完毕
			break;			
	}	
	switch( match_ratio )
	{
		case 0 :
			tell_object(me,"水晶球清澈透明,看来是无法感知到宝物的位置.\n");
			return 1;                                                   
		case 1 :
			tell_object(me,"水晶球里面隐约看到有十分模糊的景象,不过你仔细一看又消失了.\n");
			return 1;                                                   		
		default:
			tell_object(me,"水晶球里面隐约看到有十分模糊的景象,仔细一看似乎是这附近的山水地貌.\n");
			return 1;                                                   				
	}		
	
	return 1;
}

void dispear()
{
	if( userp(environment(this_object())) )
		tell_object(environment(this_object()),"水晶球化为一股青烟，消失得无影无踪。\n");
	destruct(this_object());
}

string chstring(string arg,int n)
{
	int i,j,k;
	string msg="";
	
	i = sizeof(arg);
	
	for( j=0;j<i;j++ )
	{
		if( arg[j] <= 160 )
			msg += arg[j..j]+" ";
		else	msg += arg[j..j];
	}
	
	i = sizeof(msg);
	j = i + n ;
	
	if( i > 20 )
	{
		for( k=3;k<5;k++ )
		{
			if( !is_chinese(msg[k*2..k*2+1])) 	
				continue;
			else	msg[k*2..k*2+1] = "□";
		}
		for( k=6;k<10;k++ )
		{
			if( !is_chinese(msg[k*2..k*2+1])) 	
				continue;
			else	msg[k*2..k*2+1] = "□";
		}
	}

	for( k=0;k<i/2;k++ )
	{
		switch( (k+j)%7 )
		{
			case 0:
				if( (j+k)%5 < 3 )
				{
					if( !is_chinese(msg[k*2..k*2+1])) 	
						continue;
					else	msg[k*2..k*2+1] = "□";
				}
				break;
			case 1:
				if( (j+k)%6 < 3 )
				{
					if( !is_chinese(msg[k*2..k*2+1])) 	
						continue;
					else	msg[k*2..k*2+1] = "□";
				}
				break;
			case 2:
				if( (j+k)%4 < 3 )
				{
					if( !is_chinese(msg[k*2..k*2+1])) 	
						continue;
					else	msg[k*2..k*2+1] = "□";
				}
				break;
			case 3:
				if( (j+k)%6 < 3 )
				{
					if( !is_chinese(msg[k*2..k*2+1])) 	
						continue;
					else	msg[k*2..k*2+1] = "□";
				}
				break;
			default:
				if( (j+k)%8 < 2 )
				{
					if( !is_chinese(msg[k*2..k*2+1])) 	
						continue;
					else	msg[k*2..k*2+1] = "□";
				}
				break;
		}
	}
	return msg;
}

int do_dig()
{
	object *list,me=this_player();
	int i;

	message_vision(HIY"$N挥舞着锄头，发了疯似的乱挖....\n"NOR,me);

	if( me->query("kee") < 100 )
		return notify_fail("你太累啦，歇一歇吧！\n");
	me->receive_damage("kee",70);

	list = all_inventory(environment(me));
	i = sizeof(list);
	while( i-- )
	{
		if( base_name(list[i]) == "/obj/example/stone" )
		{
			list[i]->delete("no_shown");
			list[i]->move(me);
			tell_object(me,HIG"你挖到了宝物！\n"NOR);
			environment(me)->delete("no_fly");
			return 1;
		}
	}

	return 1;
}

int do_attract()
{
	object me = this_player();
	
	if( me->query("force") < 100 )
		return notify_fail("你内力不够啦，歇一歇吧！\n");
	me->add("force",-100);
	message_vision(HIG"$N双手轻轻摩擦水晶球的表面，水晶球微微发出绿色的光芒 ... 越来越亮。\n"NOR,me);
	me->start_busy(3);
	call_out("get_stone",2,me);				
	return 1;
}	

int get_stone(object me)
{
	object *list,env;

	env = environment(me);
	list = filter_array( deep_inventory(env), 
				(:  
					base_name($1)=="/obj/example/stone" 
					&& objectp(environment($1))
					&& !living(environment($1))
				:)
		);                                                
	if( !sizeof(list) )
	{
		message_vision(HIG"水晶球又渐渐黯淡下去，什么都没有发生。\n"NOR,me);	
	}
	else
	{
			list[0]->delete("no_shown");
			list[0]->move(me);
			message_vision(HIG"突然"+list[0]->name()+HIG"飞入了$N的手中。\n"NOR,me);				
			env->delete("no_fly");
	}
	
}	

int do_conjure(string arg)
{
	if( !stringp(arg) ) return 0;	

	if( strsrch(arg,"drift_sense")!=-1 || strsrch(arg,"drift sense")!=-1 )
	{
		write("水晶发出一种奇异的力量，阻止了你继续施用神通。\n");
		return 1;
	}	         
	return 0;
}	

