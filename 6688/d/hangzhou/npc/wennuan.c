//《倚天屠龙记》
//by tlang

#include <ansi.h>
inherit NPC;

string ask_xiaolin();
void kill_ob(object ob);

void create()
{
	set_name(HIM"温暖"NOR, ({ "wen nuan","lover"}) );
	set("gender", "女性" );
	set("age", 17);
        set("long","一位漂亮的小美眉，本来是天上的一个仙子，吵着要下凡，\n神仙们不答应，她就偷偷下来了。\n");
	set("per",30);
	set("int",30);

	set("combat_exp", 1000000); 
	set("attitude", "friendly");
		
	set("max_force",1000);
	set("force",1000);
	set("max_mana",800);
	set("mana",800);
	set("max_atman",800);
	set("atman",800);
	
	set_skill("literate",200);
	set_skill("music",150);

	set_skill("dodge",150);
	set_skill("finger",150);
	set_skill("parry",150);
	set_skill("force",150);
	set_skill("shaolin-shenfa",120);
	set_skill("nianhua-zhi",120);
	set_skill("hunyuan-yiqi",120);	
	map_skill("dodge","shaolin-shenfa");
	map_skill("finger","nianhua-zhi");
	map_skill("parry","nianhua-zhi");
	map_skill("force","hunyuan-yiqi");

	set("inquiry",([
	"小霖" : (: ask_xiaolin :),
	"xiaolin" : (: ask_xiaolin :),
	"道可道" : ({
		(: command,"fear" :),
		(: command,"shake" :),
		(: random_move :),
		}),
	"dao" : ({
		(: command,"fear" :),
		(: command,"shake" :),
		(: random_move :),
		}),
	"游戏人生" : ({
		(: command,"fear" :),
		(: command,"shake" :),
		(: random_move :),
		}),
	"disc" : ({
		(: command,"fear" :),
		(: command,"shake" :),
		(: random_move :),
		}),
	]));

	set("count",1);
	set("trigger",1);

	setup();
	carry_object("/d/suzhou/npc/obj/bjcloth.c")->wear(); 
}

string ask_xiaolin()
{
	// 2026-04-30: unused variable commented out
	// object me=this_object();
	object ob=this_player();

	if(query("count")<1)
	{
		command("? "+ob->query("id"));
		return "你老问这干嘛？。。。。。pp\n";
	}
	add("count",-1);
	command("smile "+ob->query("id"));
		return "就是他让我偷偷下凡的，结果。。。。。\n";
}

void init()
{
	add_action("give_talk","talk");
}

int give_talk(string arg)
{
	object obj;
	object ob=this_player();

	if(arg=="温暖" || arg=="wennuan" || arg=="wwwl" )
	{
		if(query("trigger")<1)
		{
		tell_object(ob,"你和温暖高兴地聊了一会儿天，时间就这样打发了。\n");
			return 1;
		}
		obj=new("/d/hangzhou/npc/obj/book12");
		obj->move(ob);
		add("trigger",-1);
		tell_object(ob,"温暖和你聊得高兴，就拿出一本书送给你。\n");
		return 1;
	}
	tell_object(ob,"你要和谁说话？\n");
	return 1;
}

void kill_ob(object ob)
{
	command("say 我才不和你打呢。。。。。\n");
	command("angry "+ob->query("id"));
	ob->start_busy(3);
	random_move();
	remove_killer(ob);
}



