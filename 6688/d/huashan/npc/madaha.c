//比武设擂台 (/d/huashan/leitai) 一个，看台 (/d/huashan/kantai0..9)
//十个，每个看台可容纳 20 人，即最多容纳 200 人观看比武.
//注意的是比武一定要在擂台 (/d/huashan/leitai.c) 举行.

//1.只要玩家 set biwu 1 就能参加比武.
//2.比武以前用召集 (zhaoji) 命令，可以把设 set biwu 1 的玩家抓到
//  看台。注意这条命令同其它命令无关,仅仅是把玩家抓到看台.
//3.用 start from <起始年龄> to <终止年龄> 来分年龄段比武。系统会
//  自动选两一名该年龄段的玩家进行比武，并自动安排下一组玩家，赢者
//  排进下一轮，一直下去，直至决出最后的冠亚军。
//4.每两个玩家比武以前，巫师要用确认 (queren) 命令，使两个玩家正式
//  比武，这样可以控制比武节奏.
//5.巫师可以用 list 本轮 或 次轮 命令，来查看比武名单.
//6.巫师可以用 add <玩家的id> 命令，把一个玩家加到比武中.
//7.巫师可以用 retreat <玩家的id> 命令，把一个玩家从比武名单中去掉.
//8.如果不想按年龄段来比武，可以用如下命令进行.
//  (1)先敲 biwu 命令.
//  (2)再用 add 命令把玩家加入到比赛名单中去.
//  (3)再用 start 命令使比武开始，注意这时的 start 命令没有参数.
//  (4)上述的4.5.6.7条仍然起作用.
//9.为了比武公平，大会统一了比赛的武器。玩家可以用 qu <武器>来取
//  自己需要的武器，具体有什么武器，可以看舍身崖
//  (/d/huashan/sheshen.c)中的字迹.
//10.玩家除了可以由系统自动抓到看台上去外，也可以自己在舍身崖
//   (/d/huashan/sheshen.c) 用 watch 命令自己去，但平常这个命令
//   是不开的，比武时巫师要在舍身崖用 biwu 命令开放 watch 命令，
//   比武结束，用 cancel 命令关闭 watch 命令.
//11.两个组的群殴命令用 group，说明如下：
//   group add1 <id> 把玩家增加到第一组
//   group add2 <id> 把玩家增加到第二组
//   group list 显示两个组的名单
//   group startrace 两个组开始群殴

#define MAXNUMBER 20

inherit NPC;
#include <ansi.h>;

//mixed winer=0,fighter=0,fighter1=0;
//object winerroom,fighterroom,fighter1room;
string *group1=({}),*group2=({});
string *list0=({}),*list1=({});
string first="gong ping zi",second="gong ping zi";

int selectplayer();
int seekplayer(mixed);
int race();
int check_player();
int announce();
int bonus(object);
int full(mixed);

void create()
{
	set_name("公平子", ({ "gong ping zi", "zi", "gong" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是一位仙风道骨的中年道人，早年云游四方，性好任侠，公正无私。\n");
	set("combat_exp",60000);
        set("shen_type", 1);
	set("attitude", "friendly");

	set("first","gong ping zi");
	set("second","gong ping zi");
	set("guanjun","gong ping zi");
	set("yajun","gong ping zi");

	set("apply/attack", 50);
	set("apply/defense", 50);

	set("max_kee", 800);
	set("max_gin", 800);
	set("max_force", 800);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("sword",80);
	set_skill("parry",80);
	set_skill("dodge", 80);

	set("no_get",1);

	setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/changjian")->wield();
}


void init()
{
	add_action("do_zhaoji","zhaoji");
	add_action("do_start","start");
	add_action("do_queren","queren");
	add_action("do_biwu","biwu");
	add_action("do_add","add");
	add_action("do_list","list");
	add_action("do_retreat","retreat");
	add_action("do_qu","qu");
        add_action("do_halt", "halt");

	add_action("do_study","study");
	add_action("do_practice","practice");
	add_action("do_update","update");
	add_action("do_get","get");
	add_action("do_play","play");
	add_action("do_group","group");
}

int do_update(string arg)
{
	if( query("biwu/in_race") || query("biwu/group_race"))
	{
	write("比武期间不能在这update，如果真需要的话，可以先smash公平子，再update。\n");
	return 1;
	}
	return 0;
}

int do_play(string arg)
{
	write("不准在这弹琴.\n");
	return 1;
}

int do_get(string arg)
{
	if (!wizardp(this_player()) )
	{
		write("不许在这拿东西。\n");
		return 1;
	}
	return 0;
}

int do_practice(string arg)
{
	if ( query("biwu/in_race") )
	{
		write("不能在这练武。\n");
		return 1;
	}
	return 0;
}

int do_study(string arg)
{
	if ( query("biwu/in_race") )
	{
		write("这不是读书的地方。\n");
		return 1;
	}
	return 0;
}

int do_group(string arg)
{
	if(!arg) return notify_fail("group startrace\ngroup list\ngroup add1 <id>\ngroup add2 <id>\n");

	if(arg=="startrace")
	{
		int i,j;
		object ob1,ob2;

		if(!wizardp(this_player())) return notify_fail("只有巫师才能开始。\n");
		command("chat 团体比赛开始。");
		for(i=0;i<sizeof(group1);i++)
		{
			if( !ob1=find_player(group1[i]) ) continue;
			if( !living(ob1) ) ob1->revive();
			if(ob1->is_ghost()) ob1->reincarnate();
			if(ob1->is_busy())  ob1->interrupt_me(ob1, "halt");
			full(ob1);
			if(!present(ob1,environment())) ob1->move(environment());

			for(j=0;j<sizeof(group2);j++)
			{
				if( !ob2=find_player(group2[j]) ) continue;
				if( !living(ob2) ) ob2->revive();
				if(ob2->is_ghost()) ob2->reincarnate();
				if(ob2->is_busy())  ob2->interrupt_me(ob2, "halt");
				full(ob2);
				if(!present(ob2,environment())) ob2->move(environment());

				ob1->bihua_ob(ob2);
				ob2->bihua_ob(ob1);
			}
		}
		set("biwu/group_race",1);
		remove_call_out("group_check");
		call_out("group_check",1);
		return 1;
	}
	if(arg=="list")
	{
		int i;

		write("第一组的名单:\n");
		for(i=0;i<sizeof(group1);i++) write(group1[i]+"\n");
		write("\n第二组的名单:\n");
		for(i=0;i<sizeof(group2);i++) write(group2[i]+"\n");
		return 1;
	}
	if( sscanf(arg, "add1 %s", arg)==1 )
	{
		object ob;

		if(!wizardp(this_player())) return notify_fail("只有巫师才能加名额。\n");
		if(member_array(arg, group1)!=-1
			|| member_array(arg, group2)!=-1)
			return notify_fail("这个人已经参加比赛了。\n");
		if( !(ob=find_player(arg)) ) return notify_fail("没这个人。\n");
		group1 += ({arg});
		command("chat "+ob->short()+"加入第一比赛组。");
		return 1;
	}
	if( sscanf(arg, "add2 %s", arg)==1 )
	{
		object ob;

		if(!wizardp(this_player())) return notify_fail("只有巫师才能加名额。\n");
		if(member_array(arg, group1)!=-1
			|| member_array(arg, group2)!=-1)
			return notify_fail("这个人已经参加比赛了。\n");
		if( !(ob=find_player(arg)) ) return notify_fail("没这个人。\n");
		group2 += ({arg});
		command("chat "+ob->short()+"加入第二比赛组。");
		return 1;
	}

	return notify_fail("group startrace\ngroup list\ngroup add1 <id>\ngroup add2 <id>\n");
}

void group_check()
{
	object *ob;
	int i,amount=0;

	ob=all_inventory(environment());
	ob=filter_array( ob, (: userp($1) :) );
	for(i=0;i<sizeof(ob);i++)
	{
		if( !living(ob[i]) )
		{
			full(ob[i]);
			ob[i]->revive();
			ob[i]->remove_all_killer();
			ob[i]->move("/d/huashan/kantai"+random(10));
			command("chat "+ob[i]->short()+"被踢出擂台！\n");
		}
		if( !ob[i]->is_fighting() ) amount += 1;
	}
	if( amount==sizeof(ob) )
	{
		command("chat 团体比赛结束！\n");
		for(i=0;i<sizeof(ob);i++)
		{
			if( !wizardp(ob[i]) )
			{
				full(ob[i]);
				ob[i]->remove_all_killer();
			}
		}
		group1=({});
		group2=({});
		delete("biwu/group_race");
		return;
	}
	call_out("group_check",1);
	return;
}

int do_biwu(string arg)
{
	if ( query("biwu/in_race") )	
		return notify_fail("现在正在召开比武大会！\n");

	if(wizardp(this_player()))
	{
		set("biwu/biwu",1);
		set("biwu/in_race",1);
		list0=({});
		list1=({});
		write("请先加入(add)比武名单，然后正式开始(start)。\n");
		return 1;
	}
	return notify_fail("你无权举行比武！\n");
}

int do_zhaoji(string arg)
{
	object *ob,env,*watcher;
	int i,j;
	string *watchroom,str;

	if ( !wizardp(this_player()) ) return notify_fail("你无权召集参加比武的人员！\n");
	if ( query("biwu/in_race") )	return notify_fail("现在正在召开比武大会！\n");

	command("chat 现在比武大会即将开始,马上集合！\n");

	if( !arrayp(watchroom=environment()->query("watch_room"))
		|| !sizeof(watchroom) )
		return notify_fail("没有看台,没法比武。\n");

	ob = users();
	i=sizeof(ob);
	env=environment();
	j=0;
	while(i-- )
	{
		if((int)ob[i]->query("env/biwu") && !wizardp(ob[i]) )
		{
			if(ob[i]->is_ghost())
			{
				ob[i]->reincarnate();
				tell_object(ob[i],"由于举行武林大会，你重现人间。\n");
			}
			while(1)
			{
				if(!find_object(watchroom[j])) load_object(watchroom[j]);
				watcher=all_inventory(find_object(watchroom[j]));
				watcher=filter_array( watcher, (: userp($1) :) );
				if(sizeof(watcher)<MAXNUMBER) break;
				j++;
				if(j>(sizeof(watchroom)-1))
					return notify_fail("看台不够。\n");
			}
			str=sprintf("你被分到%d号看台。\n",j);
			tell_object(ob[i],str);
			ob[i]->move(find_object(watchroom[j]),1);

		}
	}
	command("chat 集合完毕！\n");
	return 1;
}

int do_start(string arg)
{
	object obj,*ob;
	int age1,age2,age,i;
	string str;

	if ( !wizardp(this_player()) ) return notify_fail("你无权举行比武！\n");

	if( query("in_race") )	return notify_fail("正在比武。\n");

	environment()->set("no_fight",1);

	delete("in_race");
	delete("limit");
	delete("no_limit");
	delete("over");
	delete("biwu/over");
	delete("change");
	delete("team");

	if(!query("biwu/biwu"))
	{
		if(!arg || sscanf(arg, "from %d to %d",age1,age2)!=2 )
			return notify_fail("start from <起始年龄> to <终止年龄>\n");
		
		ob=users();
		i=sizeof(ob);
		list0=({});
		list1=({});
		while(i--)
		{
//			if((int)ob[i]->query("env/biwu") && !wizardp(ob[i])
			if((int)ob[i]->query("env/biwu")
				&& (age=ob[i]->query("age")+ob[i]->query("吃驻颜丹"))>=age1 && age<=age2 )
				list0+=({ob[i]->query("id")});
		}
		if(sizeof(list0)<2)
		{
			command("chat 这个年龄组人数不够,取消这个组的比赛。\n");
			command("chat 这个年龄组的比武大会到此结束。\n");
			delete("biwu");
			return 1;
		}
		set("limit",age2);
	}
	else
	{
		if(sizeof(list0)<2)
		{
			command("chat 比赛人数不够,取消比赛。\n");
			command("chat 比武大会到此结束。\n");	
			delete("biwu");
			return 1;
		}
	}

	set("biwu/in_race",1);

	if(!query("biwu/biwu"))
		str=sprintf("现在%d到%d年龄组的比赛正式开始。\n",age1,age2);
	else
		str="现在比武正式开始。\n";
	command("chat "+str);
	
	if( arg == "无差别级" )	set("no_limit",1);
	set("in_race",1);

	selectplayer();
	
	race();
	return 1;
}

int selectplayer()
{
	string player;

	first = query("first");
	second = query("second");

	if( !sizeof(list0) && !sizeof(list1) )	
	{
		set("biwu/over",1);
		set("first","gong ping zi");
		set("second","gong ping zi");
		return 1;
	}

	if( query("change") == 2 )	set("change",0);

	if( query("change") == 1 )
	{
		set("change",2);
		set("first","gong ping zi");
		set("second","gong ping zi");
		return 1;
	}

	if( query("team") )
	{
		if(!sizeof(list1))	
		{
			set("team",0);
			set("change",2);
			set("first","gong ping zi");
			set("second","gong ping zi");
//			selectplayer();
			return 1;
		}
		
		player=list1[random(sizeof(list1))];
		list1-=({player});
		set("first",player);

		if(!sizeof(list1))	
		{
			set("team",0);
			set("change",1);
			set("second","gong ping zi");
		}
		else
		{
			player=list1[random(sizeof(list1))];
			list1-=({player});
			set("second",player);
			set("change",0);
		}
		return 1;
	}
	else
	{
		if(!sizeof(list0))	
		{
			set("team",1);
			set("change",2);
			set("first","gong ping zi");
			set("second","gong ping zi");
//			selectplayer();
			return 1;
		}
		
		player=list0[random(sizeof(list0))];
		list0-=({player});
		set("first",player);

		if(!sizeof(list0))	
		{
			set("team",1);
			set("change",1);
			set("second","gong ping zi");
		}
		else
		{
			set("change",0);
			player=list0[random(sizeof(list0))];
			list0-=({player});
			set("second",player);
		}
		return 1;
	}
}

int race()
{
	object ob1,ob2;

	if( !query("biwu/over") )	selectplayer();

	if( query("over") )	return 1;

	if( first == "gong ping zi")	
	{
		command("chat 下面进行新一轮比武。\n");
		race();
		return 1;
	}

	if( query("biwu/over") )
		command("chat 下面进行冠亚军决战。\n");
	else
	{
		if( query("change") == 2 )
			command("chat 下面进行本轮最后一组比赛。\n");
		else
		{
			if( query("change") == 1 )
				command("chat 下面进行本轮倒数第二组比赛。\n");
			else 	command("chat 下面进行的比赛是...\n");
		}
	}

	command("chat "+first+" VS "+second+"\n");

	if( query("first") != "gong ping zi" && query("change") != 3 )
		command("chat 下一组："+query("first")+" VS "+query("second")+"\n");

	command("rumor 对手为 gong ping zi 作 轮空处理。\n");

	ob1 = find_player(first);

	ob2 = find_player(second);

	if( query("biwu/over") )
	{
		command("chat 激动人心的一刻终于来到了，下面进行冠亚军决战！\n");
		if( objectp(ob1) )
			command("chat 由"+ob1->short()+"对");
		else	command("chat "+first+"对");
		if (objectp(ob2) )
			command("chat "+ob2->short()+"\n");
		else	command("chat "+second+"\n");

		command("chat 首先出场的是...\n");
		if( objectp(ob1) )
		{
			if(!present(first,environment())) 	ob1->move(environment());
			command("chat "+ob1->short()+"\n");
			if( ob1->query("long") )
				command("chat "+ob1->short()+ob1->query("long")+"\n");
		}
		else
		{
			command("chat "+first+"\n");
			command("chat 但是 "+first+" 由于某种原因没有来。\n");
			command("chat 当弃权处理。\n");
		}

		if( objectp(ob2) )
		{
			command("chat 接着"+ob2->short()+"缓步走上擂台。\n");
			if(!present(second,environment())) 	ob1->move(environment());
			command("chat "+ob2->short()+"\n");
			if( ob1->query("long") )
				command("chat "+ob2->short()+ob1->query("long")+"\n");
		}
		else
		{
			command("chat 接着出场的是 "+second+" 。\n");
			command("chat 但是 "+second+" 由于某种原因没有来。\n");
			command("chat 当弃权处理。\n");
		}
	}
	else	command("chat ("+first+")　VS ("+second+")\n");

	if( !check_player() )	
	{
		race();
		return 1;
	}

	if( !living(ob1) ) 	ob1->revive();
	if( !living(ob2) ) 	ob2->revive();
	if(ob1->is_ghost()) 	ob1->reincarnate();
	if(ob2->is_ghost()) 	ob2->reincarnate();

	full(ob1);
	full(ob2);

	if(!present(first,environment()))
	 	ob1->move(environment());
	if(!present(second,environment())) 
		ob2->move(environment());

	command("chat "+ob1->short()+"　VS "+ob2->short()+"\n");
	
        ob1->delete_temp("halted");
       	ob2->delete_temp("halted");
	ob1->delete_temp("be_defeated");
	ob2->delete_temp("be_defeated");

	set("queren",1);
	return 1;
}

int check_player()
{
	object ob1,ob2;

	if( query("over") )	return 0;

	ob1 = find_player(first);

	ob2 = find_player(second);

	if( query("biwu/over") )
	{
		if( !objectp(ob1) )
		{
			if( !objectp(ob2) )
			{
				remove_call_out("check");
				if( first != "gong ping zi" && second != "gong ping zi" )
					command("chat "+first+"和"+second+"不知哪去了，作弃权处理。\n");
				if( first != "gong ping zi" && second == "gong ping zi" )
					command("chat "+first+"不知哪去了，作弃权处理。\n");

				set("guanjun","gong ping zi");
				set("yajun","gong ping zi");
				announce();
				return 0;
			}
			else 
			{
				remove_call_out("check");
				if( first == "gong ping zi" )
					command("chat "+second+" 轮空，不战而胜。\n");
				else	command("chat "+first+" 弃权，"+second+" 不战而胜。\n");
				set("guanjun",second);
				set("yajun",first);

	        		ob2->delete_temp("pending/fight");
				ob2->remove_all_killer();

				announce();
				return 0;
			}
		}
		else 
		{
			if( !objectp(ob2) )
			{
				remove_call_out("check");
				if( second == "gong ping zi" )
					command("chat 本组"+first+" 轮空，不战而胜。\n");
				else	command("chat "+second+" 弃权，"+first+" 不战而胜。\n");
				set("guanjun",first);
				set("yajun",second);
	
			        ob1->delete_temp("pending/fight");
				ob1->remove_all_killer();

				announce();
				return 0;
			}
			return 1;
		}
		return 1;
	}

	else
	{
		if( !objectp(ob1) )
		{
			if( !objectp(ob2) )
			{
				remove_call_out("check");
				if( first != "gong ping zi" && second != "gong ping zi" )
					command("chat "+first+"和"+second+"不知哪去了，作弃权处理。\n");
				if( first != "gong ping zi" && second == "gong ping zi" )
					command("chat "+first+"不知哪去了，作弃权处理。\n");

//				selectplayer();
//				race();
				return 0;
			}
			else 
			{
				remove_call_out("check");
				if( first == "gong ping zi" )
					command("chat "+second+" 轮空，不战而胜。\n");
				else	command("chat "+first+" 弃权，"+second+" 不战而胜。\n");

				if( query("change") == 3 )
					command("chat "+ob2->name(1)+"("+second+")进入决赛。\n");
				else 	command("chat "+ob2->name(1)+"("+second+")进入下一轮。\n");

				if( query("team") )
				{
					if( !query("change") )	list0 += ({second});
					else	list1 += ({second});
				}
				else	
				{
					if( !query("change") )	list1 += ({second});
					else	list0 += ({second});
				}

        			ob2->delete_temp("pending/fight");
				ob2->remove_all_killer();

				full(ob2);
				ob2->move("/d/huashan/kantai"+random(10));
//				selectplayer();
//				race();
				return 0;
			}
		}
		else
		{
			if( !objectp(ob2) )
			{
				remove_call_out("check");
				if( second == "gong ping zi" )
					command("chat "+first+" 轮空，不战而胜。\n");
				else	command("chat "+second+" 弃权，"+first+" 不战而胜。\n");

				if( query("change") == 3 )
					command("chat "+ob1->name(1)+"("+first+")进入决赛。\n");
				else 	command("chat "+ob1->name(1)+"("+first+")进入下一轮。\n");

				if( query("team") )
				{
					if( !query("change") )	list0 += ({first});
					else	list1 += ({first});
				}
				else	
				{
					if( !query("change") )	list1 += ({first});
					else	list0 += ({first});
				}

			        ob1->delete_temp("pending/fight");
				ob1->remove_all_killer();

				full(ob1);
				ob1->move("/d/huashan/kantai"+random(10));
//				selectplayer();
//				race();
				return 0;
			}
			return 1;
		}
		return 1;
	}
	return 1;
}

int do_queren()
{
	object ob1,ob2;

	if ( !wizardp(this_player()) ) return notify_fail("你无权确认比武！\n");
	if(!query("queren"))
		return notify_fail("现在还没人上场，怎么比武？\n");
	delete("queren");
	command("chat 比武开始");

	if( !check_player() )	
	{
		race();
		return 1;
	}

	ob1 = find_player(first);

	ob2 = find_player(second);

	if( !living(ob1) ) 	ob1->revive();
	if( !living(ob2) ) 	ob2->revive();
	if(ob1->is_ghost()) 	ob1->reincarnate();
	if(ob2->is_ghost()) 	ob2->reincarnate();

	full(ob1);
	full(ob2);

        ob1->delete_temp("halted");
       	ob2->delete_temp("halted");
	ob1->delete_temp("be_defeated");
	ob2->delete_temp("be_defeated");

	if(ob1->is_busy())  ob1->interrupt_me(ob1, "halt");
	if(ob2->is_busy())  ob2->interrupt_me(ob2, "halt");

	tell_object(ob1,"该上场了。\n");
	tell_object(ob2,"该上场了。\n");

	if(!present(first,environment()))
	 	ob1->move(environment());

	if(!present(second,environment())) 
		ob2->move(environment());

	remove_call_out("check");
	call_out("check",1,ob1,ob2);

	ob1->bihua_ob(ob2);
	ob2->bihua_ob(ob1);

	return 1;
}

int check(object ob1,object ob2)
{

	if( query("over") )	return 0;

	if( query("biwu/over") )
	{
		if( !objectp(ob1) )
		{
			if( !objectp(ob2) )
			{
				remove_call_out("check");
				if( first != "gong ping zi" && second != "gong ping zi" )
					command("chat "+first+"和"+second+"不知哪去了，作弃权处理。\n");
				if( first != "gong ping zi" && second == "gong ping zi" )
					command("chat "+first+"不知哪去了，作弃权处理。\n");
				set("guanjun","gong ping zi");
				set("yajun","gong ping zi");
				announce();
				return 0;
			}
			else 
			{
				remove_call_out("check");
				if( first == "gong ping zi" )
					command("chat "+second+" 轮空，不战而胜。\n");
				else	command("chat ("+first+")退线了，("+second+")获得冠军。\n");
				set("guanjun",second);
				set("yajun",first);

	        		ob2->delete_temp("pending/fight");
				ob2->remove_all_killer();

				announce();
				return 0;
			}
		}
		else 
		{
			if( !objectp(ob2) )
			{
				remove_call_out("check");
				if( second == "gong ping zi" )
					command("chat 本组"+first+" 轮空，不战而胜。\n");
				else	command("chat ("+second+")退线了，("+first+")获得冠军。\n");
				set("guanjun",first);
				set("yajun",second);
	
			        ob1->delete_temp("pending/fight");
				ob1->remove_all_killer();

				announce();
				return 0;
			}
		}
	}

	else
	{
		if( !objectp(ob1) )
		{
			if( !objectp(ob2) )
			{
				remove_call_out("check");
				if( first != "gong ping zi" && second != "gong ping zi" )
					command("chat "+first+"和"+second+"不知哪去了，作弃权处理。\n");
				if( first != "gong ping zi" && second == "gong ping zi" )
					command("chat "+first+"不知哪去了，作弃权处理。\n");

//				selectplayer();
				race();
				return 0;
			}
			else 
			{
				remove_call_out("check");
				if( first == "gong ping zi" )
					command("chat "+second+" 轮空，不战而胜。\n");
				else	command("chat ("+first+")退线了。\n");

				if( query("change") == 3 )
					command("chat "+ob2->name(1)+"("+second+")进入决赛。\n");
				else 	command("chat "+ob2->name(1)+"("+second+")进入下一轮。\n");

				if( query("team") )
				{
					if( !query("change") )	list0 += ({second});
					else	list1 += ({second});
				}
				else	
				{
					if( !query("change") )	list1 += ({second});
					else	list0 += ({second});
				}

	       			ob2->delete_temp("pending/fight");
				ob2->remove_all_killer();

				full(ob2);
				ob2->move("/d/huashan/kantai"+random(10));
//				selectplayer();
				race();
				return 0;
			}
		}
		else
		{
			if( !objectp(ob2) )
			{
				remove_call_out("check");
				if( second == "gong ping zi" )
					command("chat "+first+" 轮空，不战而胜。\n");
				else	command("chat ("+second+")退线了。\n");

				if( query("change") == 3 )
					command("chat "+ob1->name(1)+"("+first+")进入决赛。\n");
				else 	command("chat "+ob1->name(1)+"("+first+")进入下一轮。\n");

				if( query("team") )
				{
					if( !query("change") )	list0 += ({first});
					else	list1 += ({first});
				}
				else	
				{
					if( !query("change") )	list1 += ({first});
					else	list0 += ({first});
				}

			        ob1->delete_temp("pending/fight");
				ob1->remove_all_killer();

				full(ob1);
				ob1->move("/d/huashan/kantai"+random(10));
//				selectplayer();
				race();
				return 0;
			}
		}
	}

	if( (ob1->is_killing() || ob1->is_fighting())
	&&  (ob2->is_killing() || ob2->is_fighting())
	&& present(ob1,environment()) && present(ob2,environment()) )
	{
		call_out("check",1,ob1,ob2);
		return 1;
	}

	if ( !present(ob1, environment()) || ob1->query_temp("halted")
		|| ob1->query_temp("be_defeated") ) 
	{
		if( !living(ob1) ) 	ob1->revive();
		if( !living(ob2) ) 	ob2->revive();

	        ob1->delete_temp("pending/fight");
        	ob2->delete_temp("pending/fight");
		ob1->remove_all_killer();
		ob2->remove_all_killer();
		full(ob1);
		ob1->move("/d/huashan/kantai"+random(10));			

		if( ob1->query_temp("halted") )
	               	command("chat " + first + "中途放弃比武！\n");
		else
		{
			if( ob1->query_temp("be_defeated") )
				command("chat (" + second + ") 比武 战胜 (" + first + ")！\n");
			else
				if( !present(first, environment()) )
					command("chat " + first + "落荒而逃了！\n");
		}

		if( !query("biwu/over") )
		{
			if( second != "gong ping zi" )
			{
				if( query("change") == 3 )
					command("chat "+ob2->name(1)+"("+second+")进入决赛。\n");
				else 	command("chat "+ob2->name(1)+"("+second+")进入下一轮。\n");

				if( query("team") )
				{
					if( !query("change") )	list0 += ({second});
					else	list1 += ({second});
				}
				else	
				{
					if( !query("change") )	list1 += ({second});
					else	list0 += ({second});
				}

				full(ob2);
				ob2->move("/d/huashan/kantai"+random(10));
			}

//			selectplayer();
			race();
			return 1;
		}
		else
		{
			if( second != "gong ping zi" )	full(ob2);
			if( first != "gong ping zi" )	full(ob1);
			
			set("guanjun",second);
			set("yajun",first);
			announce();
			return 1;
		}
	}

	if ( !present(ob2, environment()) || ob2->query_temp("halted")
		|| ob2->query_temp("be_defeated") ) 
	{
		if( !living(ob1) ) 	ob1->revive();
		if( !living(ob2) ) 	ob2->revive();

	        ob1->delete_temp("pending/fight");
        	ob2->delete_temp("pending/fight");
		ob1->remove_all_killer();
		ob2->remove_all_killer();
		full(ob2);
		ob2->move("/d/huashan/kantai"+random(10));

		if( ob2->query_temp("halted") )
	               	command("chat " + second + "中途放弃比武！\n");
		else
		{
			if( ob2->query_temp("be_defeated") )
				command("chat (" + first + ") 比武 战胜 (" + second + ")！\n");
			else
				if( !present(second, environment()) )
					command("chat " + second + "落荒而逃了！\n");
		}

		if( !query("biwu/over") )
		{
			if( first != "gong ping zi" )
			{
				if( query("change") == 3 )
					command("chat "+ob1->name(1)+"("+first+")进入决赛。\n");
				else 	command("chat "+ob1->name(1)+"("+first+")进入下一轮。\n");

				if( query("team") )
				{
					if( !query("change") )	list0 += ({first});
					else	list1 += ({first});
				}
				else	
				{
					if( !query("change") )	list1 += ({first});
					else	list0 += ({first});
				}

				full(ob1);
				ob1->move("/d/huashan/kantai"+random(10));
			}

//			selectplayer();
			race();
			return 1;
		}
		else
		{
			if( second != "gong ping zi" )	full(ob2);
			if( first != "gong ping zi" )	full(ob1);
			
			set("guanjun",first);
			set("yajun",second);
			announce();
			return 1;
		}
	}
           
	return 1;
}

int announce()
{
	object ob;

	if( query("guanjun") != "gong ping zi" )
	{
		ob =find_player(query("guanjun"));
		command("chat 我宣布冠军是...\n");
		if( objectp(ob) )
		{
			command("chat "+ob->short()+"\n");
			if( query("no_limit") )
			{
				ob->set("marks/帮派","武");
				ob->set("marks/武","状元 ");
				command("es "+ob->short()+"晋升为 武状元。\n");
			}
		}
		else	command("chat "+query("guanjun")+"\n");
//		command("chat* nomatch "+query("guanjun"));
	}
	if( query("yajun") != "gong ping zi" )
	{
		ob =find_player(query("yajun"));
		command("chat 亚军是...\n");
		if( objectp(ob) )	command("chat "+ob->short()+"\n");
		else	command("chat "+query("yajun")+"\n");
//		command("chat* addoil "+query("yajun"));
	}

	if( query("biwu/biwu") )
		command("chat 本次比武大会到此结束。\n");
	else	command("chat 这个年龄组的比武大会到此结束。\n");

	delete("biwu/in_race");
	delete("in_race");
	set("over",1);
	list0 = ({});
	list1 = ({});
	set("team",0);
	set("change",0);
	set("first","gong ping zi");
	set("second","gong ping zi");
	set("guanjun","gong ping zi");
	set("yajun","gong ping zi");
	first = "gong ping zi";
	second = "gong ping zi";
	return 1;
}

int do_add(string arg)
{
	object ob;

	if(!query("biwu/in_race")) 	return notify_fail("现在还没进行比武大会。\n");
	if(!wizardp(this_player())) 	return notify_fail("只有巫师才能加名额。\n");
	if(!arg ) return notify_fail("格式：add <某人>\n");

	if( !(ob=find_player(arg)) ) return notify_fail("没这个人。\n");

	if( query("limit") && ob->age()+ob->query("吃驻颜丹") > query("limit") )
		return notify_fail("这个人不适合这一年龄段。\n");

	if( query("team") )
	{
		if(member_array(arg, list1)!=-1) return notify_fail("这个人已经参加比赛了。\n");
		list1+=({arg});
	}
	else
	{
		if(member_array(arg, list0)!=-1) return notify_fail("这个人已经参加比赛了。\n");
		list0+=({arg});
	}
	command("chat "+ob->query("name")+"加入比赛。\n");
	return 1;
}

int do_list(string arg)
{
	string str;
	int i;
	if(!query("biwu/in_race")) return notify_fail("现在还没进行比武大会。\n");

	if( !arg && arg != "本轮" && arg != "次轮" )
		return notify_fail("list 本轮 或 次轮\n");
	if( arg == "本轮" )
		str="这一轮剩下的比武名单如下:\n";
	else	str="下一轮剩下的比武名单如下:\n";

	str+="---------------------------------------------------------------\n";

	if( arg == "本轮" )
	{
		if( query("team") )
		{
			for(i=0;i<sizeof(list1);i++)
			{	
				str+=sprintf("%-15s",list1[i]);
				if( !((i+1)%4) ) str+="\n";
			}
		}
		else
		{
			for(i=0;i<sizeof(list0);i++)
			{	
				str+=sprintf("%-15s",list0[i]);
				if( !((i+1)%4) ) str+="\n";
			}
		}
	}
	else
	{
		if( !query("team") )
		{
			for(i=0;i<sizeof(list1);i++)
			{	
				str+=sprintf("%-15s",list1[i]);
				if( !((i+1)%4) ) str+="\n";
			}
		}
		else
		{
			for(i=0;i<sizeof(list0);i++)
			{	
				str+=sprintf("%-15s",list0[i]);
				if( !((i+1)%4) ) str+="\n";
			}
		}
	}

	str+="\n---------------------------------------------------------------\n";
	write(str);
	return 1;
}

int do_retreat(string arg)
{
	string id;
	if(!query("biwu/in_race")) return notify_fail("现在还没进行比武大会。\n");
	if( wizardp(this_player()) )
	{
		if(arg) id=arg;
		else  id=this_player()->query("id");
	}
	else
		id=this_player()->query("id");

	if( query("team") )
	{
		if(member_array(id, list1)==-1) 
			return notify_fail(id+"本来就没参加比赛。\n");
		list1-=({id});
	}
	else
	{
		if(member_array(id, list0)==-1) 
			return notify_fail(id+"本来就没参加比赛。\n");
		list0-=({id});
	}

	command("chat "+id+"退出比赛。\n");
	return 1;
}

int do_qu(string arg)
{
	object ob,me=this_player();
	if(!query("biwu/in_race")) return notify_fail("现在还没进行比武大会。\n");
	if(me->query_temp("get_weapon") ) return notify_fail("你已经拿了一样了。\n");
	if(arg=="sword")
	{
		if(ob=new("/obj/weapon/c_sword"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="blade")
	{
		if(ob=new("/obj/weapon/c_blade"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="whip")
	{
		if(ob=new("/obj/weapon/c_whip"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="hammer")
	{
		if(ob=new("/obj/weapon/c_hammer"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}

	if(arg=="spear")
	{
		if(ob=new("/obj/weapon/c_spear"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="staff")
	{
		if(ob=new("/obj/weapon/c_staff"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="gun")
	{
		if(ob=new("/obj/weapon/c_club"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="ji")
	{
		if(ob=new("/obj/weapon/c_halberd.c"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}

	if(arg=="dagger")
	{
		if(ob=new("/obj/weapon/c_dagger.c"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="qin")
	{
		if(ob=new("/obj/weapon/c_qin.c"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一样武器。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}
	if(arg=="dart")
	{
		if(ob=new("/obj/weapon/c_dart.c"))
		{
			ob->move(me);
			if ( !wizardp(me) ) me->set_temp("get_weapon",1);
			tell_object(me,"你从兵器架上取下一些飞镖。\n");
		}
		else
			tell_object(me,"这种武器没了。\n");
		return 1;
	}

	return notify_fail("找不到你要的。\n");
}

int do_halt()
{
	object me = this_player();

	if( query("group_race") && !wizardp(me))
	{
		write(HIW"团体比赛期间，不能halt。\n"NOR);
		return 1;
	}

	if (me->is_fighting() || me->is_killing())
	{
		me->set_temp("halted",1);
		me->remove_all_killer();
		message_vision(HIW"$N向後一跃，离开战圈罢手不斗了。\n"NOR, me);
		return 1;
	}

	if( me->is_busy() )
	{
		me->interrupt_me(me, "halt");
		write("ok。\n");
		return 1;
	}

	return 1;
}

int seekplayer(mixed name)
{
	object ob;
	if( stringp(name) && (ob=find_player(name)) && !ob->is_ghost())
	{
		return 1;
	}
	return 0;
}

int bonus(object ob)
{
	object obj;
/*
	if((obj=new("/d/shaolin/obj/puti-zi")))
	{
		obj->move(ob);
		tell_object(ob,"你得到了奖励。\n");
	}
*/
	return 1;
}

int full(mixed ob)
{
	int i;
	string *gifts=({ "gin","kee","sen" });
	string *gifts1=({"atman","force","mana"});

	if(!objectp(ob)) return 0;
    
	for( i = 0; i < sizeof(gifts); i++ )
	{
	ob->set(gifts[i],ob->query("max_"+gifts[i]));
	ob->set("eff_"+gifts[i],ob->query("max_"+gifts[i]));
	}
	for( i = 0; i < sizeof(gifts1); i++ )
	{
	ob->set(gifts1[i],2*ob->query("max_"+gifts1[i])-1);
	}
	ob->set("food",ob->max_food_capacity());
	ob->set("water",ob->max_water_capacity());
	ob->clear_condition();
	return 1;
}
