//by tlang with /include/globals.h and /adm/daemons/gtimed.c

#include <ansi.h>
#include <localtime.h>

#define CLASSDIR "/class/"
#define TIME_TICK (time()*60)    
//#define GTIME_D "/u/t/tlang/gtime.c"

inherit NPC;
//inherit "/adm/daemons/gtime.c";

void check();
int midnight();
int make_yardmap(object);
int accept_fight();
int do_halt();
int accept_object(object,object); 
string ask_fairy();
string ask_lucy();

void create()
{
	set_name(GRN"小霖"NOR, ({ "xiao lin", "xiao"}) );
	set("gender", "男性" );
	set("age", 18);
        set("long",
		"他是逍遥大仙小霖的化身，正愉快地喝着酒。\n");
	set("combat_exp", 2999999);
	set("attitude", "friendly");
	set("per", 30);
	set("int", 100);
	set("con", 30);
	set("str", 30);
	set("cps", 30);
	set("inquiry", ([
	"警幻仙子" : (: ask_fairy :),
	"fairy" : (: ask_fairy : ),
	"露露" : (: ask_lucy : ),
	"lucy" : (: ask_lucy : ),
	]));
     
	set("max_kee", 3000);
	set("kee", 3000);   
	set("max_atman",3000);
	set("atman",3000);
	set("max_force", 3000);
	set("force", 5000);
	set("force_factor", 200);
	set("max_mana",3000);
	set("mana",5000);
	set("mana_factor", 50);
	
	set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "invocation" :),
                (: command("cast animate on corpse") :),
                (: command("cast animate on corpse") :),
        }) );
		
	set_skill("iron-cloth", 200);
	set_skill("dodge", 220);
	set_skill("unarmed", 200);
	set_skill("spells",200);
	set_skill("force", 200);
	set_skill("fonxanforce", 200);
	set_skill("taoism", 220);
        set_skill("necromancy", 200);
	map_skill("force","fonxanforce");
	map_skill("spells","necromancy");

	set("count",1);
	set("trigger",1);
	set("pills",1);

	setup();
	carry_object("/d/suzhou/npc/obj/baishan.c")->wear();
//	call_out("check",1);
}  

string ask_fairy()
{
	object ob=this_player();

	if(!ob->query("marks/wuji"))
		return "谁让你来问我的？\n";
	ob->delete("marks/wuji");
	ob->set("marks/小霖", 1);
	return "你到雪山上找胡斐打听消息即可。\n";
}

string ask_lucy()
{
	object ob=this_player();
	
	if(ob->query_temp("save_lucy/zhangji")!=3 )
		return "谁叫你来问我的？我不知道。。。。pp\n";
	if(ob->query("save_lucy/time")>=2)
		return "你已经帮助过她两次了，还是算了吧。\n";

	if(ob->query("combat_exp")<=1000)
		return "你刚出道，我不敢信任你。。。。。pp\n";

	if(!ob->query_temp("save_lucy/wine") || !ob->query_temp("looking/wine") )
	{
		if(query("count")>1)
			return "我已经叫人去给我拿酒了。。。。。。pp\n";
		add("count",1);	
		tell_object(ob,"。。。。。我想喝梨花酒，你能帮我弄一些来吗？\n");
		ob->set_temp("looking/wine",1);
			return "然后我来想想是否可以告诉你。\n";
	}

	if(!ob->query_temp("save_lucy/oldguy") )
	{
		if(query("trigger")>1)
			return "你还是先去找我大哥吧。。。。。。pp\n";
		add("trigger",1);
		ob->set_temp("save_lucy/xiaolin",1);
		tell_object(ob,"这事情还得征求我大哥的同意，他在黄龙洞，你自己去找他吧。\n");
		return "我在这儿等你，要快喔。。。。pp\n";
	}
/*	if(!( room = find_object(__DIR__"huaxint2")) )
        room = load_object(__DIR__"huaxint2");
    	if(objectp(room))
    	{*/
	ob->set_temp("save_lucy/braver",1);
	ob->delete_temp("save_lucy/wine");
	ob->delete_temp("looking/wine");
	ob->delete_temp("save_lucy/oldguy");
	ob->delete_temp("save_lucy/xiaolin");
	ob->delete_temp("save_lucy/lucy");
	ob->delete_temp("save_lucy/zhangji");
	environment(ob)->set("exits/up","/d/hangzhou/huaxint2");
	command("tell "+ob->query("id")+" 你上去吧!\n");
	tell_object(environment(ob),"小霖凌空一指，天上出现了一个亭子，一个出口连通到这儿。\n");
		return "好自为之吧。。。。。\n";
	
//}	return "..pp\n";	
}

int accept_object(object who, object what)
{
	object obj;

	if(userp(what) )
		return notify_fail("小霖说道：“你竟然感拿玩家来送人？！再叫我遇上，小心我宰了你。”
	说罢小霖又奸笑几声。\n");
	if((string)what->query("id")=="lihua jiu" )
		return notify_fail("梨花酒没有翡翠杯盛，也无味得紧。。。。pp\n");
	if((string)what->query("id")=="feicui bei" )
	{
		if(query("pills")>1)
			return notify_fail("我今天已经得到过酒了，等明天吧。\n");
		if(!who->query_temp("looking/wine") )
		{
			command("say 我不随便要别人的东西的。。。。pp\n");
				return notify_fail("说罢小霖对你摇摇手。\n");
		}
		if(who->query_temp("save_lucy/wine") )
		{
			command("papaya "+who->query("id"));
				return notify_fail("你不是已经给过我了吗？\n");
		}

		if(!(string)what->query("drinkable") 
|| what->query("drinkable")<5 )
		{                             
        	command("hehe "+who->query("id"));
		command("say 你竟然敢拿没有装满梨花酒的翡翠杯来骗我？！\n");
			return notify_fail("拿开。。。。\n");
		}
	
	add("pills",1);
  	command("smile " + who->query("id") );
	command("say 现在你有什么就问我吧。。。。\n");
	who->set_temp("save_lucy/wine",1);       	
		return 1;
	}
	command("thank "+who->query("id"));
	destruct(what);
       	return 1;
}

//blocked by tlang for not finished.
/*
//added for celebrating 元宵节 by tlang
//include void check();int midnight();int make_yardmap();
void check()
{
	if( NATURE_D->game_time()!=GTIME_D->chinese_date(TIME_TICK))
		{
			command("say 时间还没有到啊。\n");
			call_out("check",120);
			command("say "+NATURE_D->game_time()+"距"
				+GTIME_D->chinese_date(TIME_TICK)+
				"，有一段时间差呢。\n");
					return;
		}
	command("chat 生活在地狱中的人们，接受我的召唤，重会到人间吧。\n"); 
	call_out("midnight",5);	
}

mapping yard_daemons=([]);  
int midnight()
{
	object *ob,theob;
        int i;

	ob = users();
	command("chat 元宵到了，大家回去过节吧。我来助大家回去。\n");
	for(i=0; i<sizeof(ob); i++) {
	        if( !environment(ob[i]) ) continue;
        //        if( !ob[i]->qurey("class")) continue;
		if( ob[i]->is_ghost() ) {
		theob=ob[i];
		theob->reincarnate();
		call_out("make_yardmap",5, theob);
		}
	call_out("make_yardmap",5, ob[i]);	
	}
}

int make_yardmap(object theob)
{
	int i,j,len;
	string *classname,*yardname,name;

	classname = get_dir(CLASSDIR);
	i = sizeof(classname);
	while(i--)
	{
		classname[i]=theob->query("class");
		yardname=get_dir(CLASSDIR+classname[i]+"/yard/");
		j=sizeof(yardname);
		while(j--)
		{
			len=sizeof(yardname[j]);
			if ( yardname[j][(len-2)..(len-1)]==".c" )
			{
				name=yardname[j][0..(len-3)];
				yard_daemons[name]=CLASSDIR+classname[i]+"/yard/"+name;
			}
		}
	}
	theob->move(yard_daemons[name]);
	call_out("check",600);
		return 1;
}                 
*/
int accept_fight()
{       
	command("shake");
	call_out("do_halt",2);
		return 1;            
}

int do_halt()
{
	command("halt");
	command("sigh");
}      

