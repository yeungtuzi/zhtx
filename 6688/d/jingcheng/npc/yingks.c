//yingkaishan.c
//created by kiss
//changed by Tang
//1998.6.16

// by yeung 2000-3-26
// 让宝物可能在NPC手里面.
// 添加一个命令来强制宝物更新位置.
// 增强一点稳定性.

// by yeung 2000-3.29
// 从目录文件调房间BUG实在太多了,不再采用这种方式.房间从已经load的房间中随机选择.
// 修改奖励方式,增加连续完成挖宝任务的奖励....(宝物如果移动过就不算连续完成)
// 做成除任务之外的另一种成长方式....尤其是对没事干的老玩家.
// yin 现在可以存盘记下自己的状态
// 宝物按照唯一序列编号.


// 因为宝物太重,move可能不成功,改轻宝物重量.
// by yeung 2000-04-18

// 自动记下无法放置宝物的地方
// by yeung 2000-04-19

#include <ansi.h>
inherit NPC;
inherit F_SAVE;

//经验奖励基数
#define base_exp 20

//存放错误的地方或者NPC
string *bad_location;

string treasure_move();
void treasure_destruct();

string query_save_file()
{
	return DATA_DIR"npc/yinkaishan";
}

void create()
{            
	int res;
	
      	if( catch(res = restore()) || !res )
      	{
	      	set("nickname", RED"当朝总管"NOR);
	      	set("gender","男性");
	      	set("age",40);
	      	set("long",@LONG
他就是当朝总管，现在主持纵横天下的夺宝探险活动。
LONG
		    );
		set("attitude","peaceful");
		set("str",100);
		set("int",100);
		set("con",100);
		set("cps",100);
		set("combat_exp",20000000);
		set("force",10000);
		set("max_force",7000);
		set("force_factor",100);
		set_skill("dodge",500);
		set_skill("parry",500);
		set_skill("claw",500);		
		set_skill("sword",500);
		set_skill("fumo-jian",500);
		set_skill("yingzhua-gong",500);
		set_skill("unarmed",500);
		set_skill("force",300); 
		map_skill("sword","fumo-jian");
		map_skill("claw","yingzhua-gong");
		prepare_skill("claw","yingzhua-gong");
		set("chat_chance",5);
		set("chat_msg",({
                      HIM"殷开山说道：小兄弟到本官这里来有何贵干啊！\n"NOR,
                      HIM"殷开山说道：欢迎参加夺宝探险 ！\n"NOR,
                      HIM"殷开山说道：奖品很丰富的！\n"NOR,
		}));
		set("task_serial",1);
		bad_location = ({
			"/d/jingcheng/tamgch",
		});		
		save();
	}
      	set_name(HIB"殷开山"NOR, ({"yin kaishan","yin"}));
	setup();
	set_temp("apply/damage",500);
	carry_object("/d/jingcheng/npc/obj/cloth2")->wear();
	carry_object("/d/jingcheng/npc/obj/changjian")->wield();
}

void init()
{
	add_action("do_update","redistribute");
	return ::init();
}

// 强制宝物重新分布.
int do_update()
{
	string location;

	object me = this_player(),*treasure,env;

	if( !wiz_level(me) ) return 0;

	location = "未知地点或者不存在";
	treasure = children("/obj/example/stone.c");
	if( sizeof(treasure)>1 )
	{
		env = environment(treasure[0]);
		if( objectp(env) )
			if( env->is_character() )
			{
				location = sprintf("/%O 的身上.",env);
			}
			else
				location = sprintf("/%O - %s.",env,env->query("short"));
	}

	write(YEL"\n宝物原位置: "+location+"\n"NOR);

	location = treasure_move();
	if( !location )
	{
		write("宝物移动错误!重新生成宝物...\n");
		treasure_destruct();
		location = treasure_move();
	}

	location = "未知地点或者不存在";
	treasure = children("/obj/example/stone.c");
	if( sizeof(treasure)>1 )
	{
		env = environment(treasure[0]);
		if( objectp(env) )
			if( env->is_character() )
			{
				location = sprintf("/%O 的身上.",env);
			}
			else
				location = sprintf("/%O - %s.",env,env->query("short"));
	}

	write(YEL"宝物现位置: "+location+"\n"NOR);
	return 1;
}

int accept_fight(object ob)
{
	command("say 大家以和为贵，何必拚个你死我活呢？");
	command("sigh");
	command("kick "+ob->query("id"));
	return 0;
}

int accept_object(object me, object ob)
{
	object *treasure,env,paper;
	int i,k,bonus_amount;
	string msg="Ok!\n";

	// 当有特殊奖励时各种奖励的基数.(*连续完成挖宝任务数为实际奖励,连续数<=50)


string *bonus_desc =
({
	"内力瓶颈上升",
	"获得武林声望",
	"内力增加",
	"师门信任度增加",
	"综合评价增加",
	"先天福缘成长",
	"先天灵性成长",
	"杀气增加",
	"分得钱庄花红",
	"内力增强",
	"正气增加",
	"法力瓶颈上升",
	"灵力瓶颈上升",
	"法术运用效果增强",
});

float *bonus_base =
({
	0.4,
	0.1,
	100.0,
	10.0,
	10.0,
	0.02,
	0.02,
	10.0,   	
	100000.0,
	2.0,
	20000.0,           
	2.0,
	2.0,
	2.0,
});

// 各种特殊奖励的上限
string *bonus_key =
({
	"max_force" ,
	"wlsh" ,
	"force" ,
	"faith" ,
	"score" ,
	"kar"	,
	"spi" 	,
	"bellicosity" ,
	"deposit" ,
	"force_factor" ,
	"shen" ,
	"max_mana" ,
	"max_atman" ,		
	"mana_factor" ,	
});

int *bonus_limit =
({
	4000,
	30,
	10000,
	10000,
	10000,
	50,
	50,
	10000,
	50000000,
	300,
	80000000,       
	3000,
	3000,
	100,
});

string *bonus = ({
		"/d/xingxiu/npc/obj/xuelian",
		"/d/snow/npc/obj/agaric",
		"/d/taishan/obj/tongtiancao",
		"/d/huashan/obj/zitanhua",
		"/d/emei/houshan/npc/obj/renshen",
		"/d/quanzhen/npc/obj/fengwmi",                  
		"/d/xueshan/npc/obj/yangjing-wan",
		"/d/xueshan/npc/obj/huanshen-dan",		
		});


       if( wiz_level(me) )
	{
		command("say 啊,这怎么敢当,神仙大驾光临,请入内上座,何必和众生一般操劳.");
		return 0;
	}
	if( ob->query("money_id") && ob->value() >= 20000 )
	{
		command("smile");

		treasure = children("/obj/example/stone.c");
		command("say 欢迎这位" + RANK_D->query_respect(me) + "参加夺宝探险 ！");
		if( !(paper=present("shui jing",me)) )
		{
			paper=new("/obj/toy/crystall");
			paper->move(me);
			message_vision("殷总管给$N一个水晶球。\n", me);
			command("say 此物限时半日，逾时失效，切记切记！");
		}
		if( sizeof(treasure) < 2 )
		{
			msg=treasure_move();
			if( !msg )	return 0;
			apply_condition("treasure_move",219);
		}

		if( !query_condition("treasure_move") )
			apply_condition("treasure_move",219);

		return 1;
	}

	if( base_name(ob) == "/obj/example/stone" )
	{

		i = random(100);

		//是否连续完成?
		if( ob->query("task_serial") == query("task_serial") && me->query("task/last_task_serial") == query("task_serial")-1 )
                {
				//最长连续完成50个,奖励*50.
				if( me->query("task/task_count") < 50 )
					 me->add("task/task_count",1);
		}
		else
		{
				 me->set("task/task_count",1);
		}
		me->set("task/last_task_serial", query("task_serial") );
		destruct(ob);

// 发放奖励
		//me->set("task/task_count",50);
		if( i < 10 ) //特别奖励
		{
        		command("say 恭喜你!获得了我们的特别奖励!");
			k = random(sizeof(bonus_key));
			bonus_amount = to_int( bonus_base[k] * to_float(me->query("task/task_count")) );
			message_vision(sprintf("$n大声宣布：$N获得此次夺宝探险的特别奖励 - %s %d 点!\n",bonus_desc[k],bonus_amount),me,this_object());
			bonus_amount += me->query(bonus_key[k]);
			if( bonus_amount > bonus_limit[k] )
				bonus_amount = bonus_limit[k];
			//write( sprintf("me->set(%s,%d)\n",bonus_key[k],bonus_amount));
			me->set(bonus_key[k],bonus_amount);
			me->save(); 
			if( bonus_amount > 0 )
				log_file("WABAO_BONUS",sprintf("%s gain %d points of %s at %s\n",me->query("id"),bonus_amount,bonus_key[k],ctime(time())));
			return 1;
		}

		if( i < 50 && i >= 10 ) //经验
		{
			command("say 恭喜!你被奖励了!");
			k = base_exp * me->query("task/task_count");
			k = random(k) + k/2;
			command("say "+sprintf(" %d 点经验, %d 点潜能, 1 点综合评价。",k*5,k));
			me->add("combat_exp",k*5);
			me->add("potential",k);
			if( (me->query("potential") - me->query("learned_points")) > 500 )
				me->set("potential",me->query("learned_points")+500);
			me->add("score",1);
			me->save();
			return 1;
		}

		switch( i )
		{
			case 98:
				paper = new("/d/shaolin/obj/puti-zi");
				message_vision("$n将一等奖奖品："+paper->query("name")+"交给$N！\n",me,this_object());
				paper->move(me);
				break;
			case 97:
			case 96:
				paper = new("class/scholar/windspring");
				message_vision("$n将二等奖奖品："+paper->query("name")+"交给$N！\n",me,this_object());
				paper->move(me);
				break;
			case 95:
			case 94:
				paper = new("/class/fighter/dragon_armor");
				message_vision("$n将二等奖奖品："+paper->query("name")+"交给$N！\n",me,this_object());
				paper->move(me);
				break;
			case 93:
			case 92:
			case 91:
			case 90:
				paper = new("/class/taohua/obj/nineflower");
				message_vision("$n将三等奖奖品："+paper->query("name")+"交给$N！\n",me,this_object());
				paper->move(me);
				break;
			case 89:
			case 88:
				paper = new("/d/xueshan/npc/obj/fcloth");
				message_vision("$n将二等奖奖品："+paper->query("name")+"交给$N！\n",me,this_object());
				paper->move(me);
				break;
			case 87:
			case 86:
			case 85:
			case 84:						
				paper = new("/obj/food/guo");
				message_vision("$n将三等奖奖品："+paper->query("name")+"交给$N！\n",me,this_object());
				paper->move(me);
				break;
				
			default:
				paper = new(bonus[random(sizeof(bonus))]);
				message_vision("$n将四等奖奖品："+paper->query("name")+"交给$N！\n",me,this_object());
				paper->move(me);
				break;
		}
		return 1;
	}

	return 0;
}

int suitable_npc(object npc)
{
		return (
				clonep(npc)&&objectp(npc)&&!userp(npc) && !npc->is_fighting() && npc != this_object() &&
				objectp(environment(npc)) &&
				!environment(npc)->query("sleep_room") &&
				!environment(npc)->query("no_fight") &&
				strsrch(base_name(environment(npc)),"/wizard/") == -1 &&
				strsrch(base_name(environment(npc)),"/death/") == -1 &&
				(!sizeof(bad_location) || member_array(base_name(npc),bad_location) == -1)     	
		       );
}

int suitable_room(object room)
{
		return (		
 				function_exists("create_door", room) &&
				!room->query("sleep_room") &&
				!room->query("no_fight") &&
				strsrch(base_name(room),"/wizard/") == -1 &&
				(strsrch(base_name(room),"/d/") != -1 || strsrch(base_name(room),"/class/") != -1) &&
				strsrch(base_name(room),"/death/") == -1 &&
				(!sizeof(bad_location) || member_array(base_name(room),bad_location) == -1)     	
			);
}

// 改进函数,确保宝物能正确生成和移动.
// by yeung 2000-4-18
string treasure_move()
{
	object *treasure,tr,room,env,*allnpc, *allroom, bak_room;
	// 2026-04-30: unused variable commented out
	// mixed *list;
	int i,j,k,npc_flag,no_suitable;

	// by yeung
	// 宝物也可能在某个NPC身上
	
	// 该死的filter_array把整个数组当参数放到stack里面。 :(
	// kick mudos 
	
	// 我们要确保找到了合适的目标   	
		
	no_suitable = 0;
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
			 log_file("WABAO",ctime(time())+"Cannot find a suitable NPC to place treasure.\n");
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
			 log_file("WABAO",ctime(time())+"Cannot find a suitable ROOM to place treasure,abort.\n");
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

	//设定宝物序列号(玩家,自身,宝物)
	add("task_serial",1);

	treasure = children("/obj/example/stone.c");
	if( sizeof(treasure)>1 )
	{
		treasure[0]->set("task_serial",query("task_serial"));
		//宝物太重,所以有些时候无法move到NPC身上,降低重量
		treasure[0]->set_weight(1);
		env = environment(treasure[0]);
		if( !objectp(env) )	
		{
			if(!(treasure[0]->move(room)))
			{
				bad_location += ({base_name(room)});
				log_file("WABAO",ctime(time())+sprintf("Cannot move treasure to /%O.\n",room));			
				if(!(treasure[0]->move(bak_room)))
				{
					bad_location += ({base_name(bak_room)});
					log_file("WABAO",ctime(time())+sprintf("Cannot move treasure to /%O.\n",bak_room));			
	        			load_object("/d/snow/inn");
	        			room = find_object("/d/snow/inn");
					treasure[0]->move(room);
				}
			}
		}
		else
		{
	        	if( !env->is_character() )
				env->delete("no_fly");
			else if( objectp(env = environment(env)) && !env->is_character() )
				env->delete("no_fly");

			if(!(treasure[0]->move(room)))
			{
				bad_location += ({base_name(room)});
				log_file("WABAO",ctime(time())+sprintf("Cannot move treasure to /%O.\n",room));
				if(!(treasure[0]->move(bak_room)))
				{
                                        bad_location += ({base_name(bak_room)});
					log_file("WABAO",ctime(time())+sprintf("Cannot move treasure to /%O.\n",bak_room));			
	        			load_object("/d/snow/inn");
	        			room = find_object("/d/snow/inn");
					treasure[0]->move(room);
				}
			}
		}
	}

	else
	{
		tr = new("/obj/example/stone");
		tr->set("task_serial",query("task_serial"));
		if(!(tr->move(room)))
		{
				bad_location += ({base_name(room)});
				log_file("WABAO",ctime(time())+sprintf("Cannot move treasure to /%O.\n",room));
				if(!(tr->move(bak_room)))
				{
					bad_location += ({base_name(bak_room)});
					log_file("WABAO",ctime(time())+sprintf("Cannot move treasure to /%O.\n",bak_room));			
	        			load_object("/d/snow/inn");
	        			room = find_object("/d/snow/inn");
					tr->move(room);
				}
		}

	}

	command("sys 宝物移动了。\n");

        // 不许直接飞过来挖宝
	if( npc_flag )
		environment(room)->set("no_fly",1);
	else
		room->set("no_fly",1);

	save();
	return "\n宝物现在在\n"+room->query("long")+"\n";

}

void treasure_destruct()
{
	object *treasure,env;

	treasure = children("/obj/example/stone.c");

	if( sizeof(treasure) < 2 )	return;

	env = environment(treasure[0]);

	if( !env ) destruct(treasure[0]);

	return;
}

void die()
{      
        unconcious();
        "/cmds/imm/full"->main(this_object(),"");
        revive();
        command("heng");
        command("say 我乃当朝总管，岂是你这等鼠辈能加害得了的！");
        command("praise yin kaishan"); 
        return;
}

