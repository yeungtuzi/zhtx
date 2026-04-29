//NPC:/d/suzhou/npc/guodl.c
//by tlang
//98.2
       
#include <ansi.h>
inherit NPC;
string ask_for_hubiao();

void heal();
void create()
{
        set_name(HIM"郭大路"NOR, ({"guo dalu", "guo", "dalu" }));
	set("title", HIW"镖局长老"NOR);
	set("long", @LONG
他是镖局的镖局四大长老之一的郭大路，年纪虽然不大，武功却是不同凡响。连
老长老龙五都未必是他的对手。郭大少的拳头可是天下闻名的。
LONG
	);

	set("gender", "男性");
	set("attitude", "friendly");
	
	set("age", 25);
	set("shen_type", 1);
	set("str", 35);
	set("int", 35);
	set("con", 30);
	set("dex", 25);
	set("per", 25);
	set("max_kee", 2000);
	set("max_gin", 500);
	set("max_sen",500);
	set("force", 3000);
	set("max_force", 3000);
	set("force_factor", 60);
	set("combat_exp", 1000000);

	set_skill("unarmed",120);
	set_skill("force", 100);
	set_skill("strike", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("iron-cloth",150);
	set_skill("xianglong-zhang", 100);
	set_skill("jin-gang", 120);
	set_skill("xiaoyaoyou",100);
	set_skill("huntian-qigong", 100);
       
        map_skill("strike", "xianglong-zhang");
	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("iron-cloth","jin-gang");
	map_skill("parry", "xianglong-zhang");

        prepare_skill("strike", "xianglong-zhang");

	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: perform_action, "leiting" :)
        }) );

	set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

	set("inquiry", ([
		"护镖" : (: ask_for_hubiao :),
		"hubiao" : (: ask_for_hubiao :),
	]));

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("gold", 1);
}  

string ask_for_hubiao()
{
	object me=this_player();
	
	if( !me->query("class") || me->query("class")!="guard" )
		return "你不是镖局弟子，不能护镖。\n";
	command("say 这你得去找江总镖头要任务。\n");	
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert lifeheal");
                command("enforce 60");
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}

//this is for players to learn blade by giving money.

int recognize_apprentice(object ob)
{
	if (ob->query("class")=="guard")
		return 1;
	if (!(int)ob->query_temp("mark/guodl"))  return 0; 
	return 1;
}

int accept_learn(object me, string skill)
{
	if (skill=="unarmed")
	{
		if (me->query("class")=="guard")
			return 1;
		if (!(int)me->query_temp("mark/guodl"))
			return 0; 
		me->add_temp("mark/guodl", -1);
		return 1;
	}

	return 0;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/guodl"))
                who->set_temp("mark/guodl", 0);
        if (ob->query("money_id") && ob->value() >= 1000) {
                message_vision("郭大路同意指点$N一些扑击格斗之技的问题。\n", who);
                who->add_temp("mark/guodl", ob->value() / 50);
                return 1;
        }
        return 0;
}

