//by tlang
//97.12

#include <ansi.h>
inherit NPC;
inherit "/u/t/tlang/g_quest.c";

void create()
{
	set_name("诸葛先生", ({ "zhuge xiansheng", "zhuge" }));
        set("title","山流老大");
	set("long", "他就是江湖中恶人谈而色变的诸葛先生，也是专门与恶人作对的山流组织的老大。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", 10);
	set("str", 30);
	set("int", 30);
	set("con", 30);
        set("dex", 60);
        set("inquiry", ([
                "护镖" : "你可以找龙五。\n",
		]) );
	
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "kuihua" :),
		(: exert_function, "recover" :),
        }) );

	set("max_kee", 5000);
	set("max_gin", 5000);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
	set("force", 8000);
	set("max_force", 5000);
	set("force_factor", 100);
	set("combat_exp", 2000000);
	set("score", 1000000);

	set_skill("force", 100);
	set_skill("kuihua-shengong", 150);
	set_skill("dodge", 150);
	set_skill("mo-zhang-jue", 150);
	set_skill("strike", 100);
	set_skill("mo-jian-jue", 150);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("literate", 100);
        set_skill("daguanming",150);

	map_skill("force", "kuihua-shengong");
	map_skill("strike", "mo-zhang-jue");
	map_skill("parry", "mo-jian-jue");
	map_skill("sword", "mo-jian-jue");
	map_skill("dodge", "kuihua-shengong");

	prepare_skill("strike", "mo-zhang-jue");

      	set("count", 4);
	
	setup();

	carry_object("obj/cloth/cloth")->wear();
	carry_object("obj/weapon/gangjian")->wield();
}

void init()
{
        ::init();
  //      add_action("give_quest", "quest");
	add_action("do_hireguard", "hireguard");
}

// check if bribe is valid
int valid_bribe(object who,int val) 
{
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) 
{
    message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

//from this line, begin hire guarder to guard player 

int do_hireguard(string arg)
{
	int victimexp,objexp;
	object me,ob,obj,victim;

	me=this_player();

	if(!arg) return notify_fail("你想雇佣保镖保谁?\n");
	if( query("count")<1 ) 
		return notify_fail("今天能出动的人都出动了，等下次吧。\n");
	if( !(victim=find_player(arg)) )
		return notify_fail("对不起，我们现在找不到你要保的人。\n");
	if( (victimexp=victim->query("combat_exp")) > 2000000)	
		return notify_fail("这么厉害的人，我们用不着去保，你还是省点钱吧。\n");
	if( (victimexp=victim->query("shen") )<0 )
		return notify_fail("这种人，保他干嘛？\n");
//	if( victimexp=victim->query("marks/been_guarded") )
//		return notify_fail("不是已经有人去保护他了吗？\n");
	switch (MONEY_D->player_pay(me, victimexp*1/100))
	{
	case 0:
		return notify_fail("道：”没钱的话就对不起了！”\n");
	case 2:
		return notify_fail("道：“您的零钱不够了，银票又没人找得开。”\n");
	default:
		tell_object(me, "道：行了，钱收下了，你就等着听好消息吧。\n");
	}
	obj=find_player(arg);
	ob=new("/class/guard/npc/guarder");
	objexp=obj->query("combat_exp");
	ob->set("combat_exp",objexp*4/3+random(100000));
	ob->move(environment(obj));
	message_vision("$N走了过来，对$n说道：我奉命来保护你。\n" NOR, ob,obj);
	ob->set_leader(obj);
	add("count", -1);
//	obj->set("marks/been_guarded",1);
	obj->add_temp("guarded",({ob}));
		return 1;
}






	