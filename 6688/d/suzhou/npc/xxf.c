//NPC:/d/suzhou/npc/xxf.c
//by tlang
//98.2

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"小旋风"NOR, ({"xiao xuanfeng", "xiao" }));
	set("title", HIW"镖头"NOR);
	set("long",
	"他是镖局的镖头，在江湖上名气不小，很的总镖头重用。\n"
	);

	set("gender", "男性");
	set("attitude", "heroism");
	
	set("age", 25);
	set("shen_type", 10);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 25);
	set("per", 27);
	set("max_kee", 500);
	set("max_gin", 300);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 30);
	set("combat_exp", 150000);
	set("score", 1000);
	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("force", 60);
	set_skill("blade", 70);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("shaolin-shenfa", 60);
	set_skill("cibei-dao", 60);
	set_skill("hunyuan-yiqi", 60);
        set_skill("strike", 60);
	set_skill("sanhua-zhang", 60);

        map_skill("strike", "sanhua-zhang");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

        prepare_skill("strike", "sanhua-zhang");

	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("gold", 1);
}

void init()
{
	object ob, me;
	me=this_player();

	 ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, me); 
}

void greeting(object me)
{
	object ob;
	ob=this_object();

	if( !me || environment(me) != environment() || !me->query("saver") ) 
		return notify_fail("来的可是白道上的朋友，这厮厉害，请到镖\n
局为我搬来救兵！\n");
       	command("say 援兵终于来了，快来与我合力杀了这厮！\n");
	tell_object(me,"刚说到这里，大狗熊得空劈出一刀，重伤了小旋风，小旋风\n
大吼一声，“镖银被这厮抢了，你一定要强回来！”说罢含痕而死。\n");
	ob->die();
}

         