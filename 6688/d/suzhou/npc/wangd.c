//NPC:/d/suzhou/npc/wangd.c
//by tlang
//98.2
       
#include <ansi.h>
inherit NPC;
string ask_for_hubiao();

void create()
{
        set_name(HIM"王动"NOR, ({"wang dong", "wang" }));
	set("title", HIW"镖局长老"NOR);
	set("long", @LONG
他是镖局的镖局四大长老之一的王动，年纪虽然不大，武功却是不同凡响。连
老长老龙五都未必是他的对手，人道：王动不动，一动惊魂。他的轻功端地非
同小可。而且据说他幼时在茅山学有异术，可说是长老中的翘楚。
LONG
	);

	set("gender", "男性");
	set("attitude", "friendly");
	
	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 35);
	set("con", 30);
	set("dex", 25);
	set("per", 35);
	
	set("max_gin", 500);
        set("eff_gin", 500);
        set("gin", 500);
        set("max_kee", 2000);
        set("eff_kee", 2000);
        set("kee", 2000);
        set("max_sen", 500);
        set("eff_sen", 500);
        set("sen", 500);

        set("force", 800);
        set("max_force", 800);
        set("force_factor", 50);

        set("atman", 1500);
        set("max_atman", 1500);

        set("mana", 3000);
        set("max_mana", 3000);
        set("mana_factor", 50);
	
	set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "invocation" :),
                (: command("cast animate on corpse") :),
                (: command("cast animate on corpse") :),
        }) );

	set("combat_exp", 1000000);

	set_skill("force", 100);
	set_skill("spells",100);
	set_skill("scratching", 100);
	set_skill("dodge", 150);
	set_skill("strike",100);
	set_skill("parry", 100);
	set_skill("chaos-steps",150);
	set_skill("gouyee", 100);
	set_skill("banruo-zhang",100);
	set_skill("taoism", 120);
        set_skill("necromancy", 100);
       
        map_skill("spells", "necromancy");
	map_skill("force", "gouyee");
	map_skill("dodge", "chaos-steps");
 	map_skill("strike","banruo-zhang");
	map_skill("parry","banruo-zhang");
 
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

//this is for players to learn blade by giving money.

int recognize_apprentice(object ob)
{
	if (ob->query("class")=="guard")
		return 1;
	if (!(int)ob->query_temp("mark/wangd"))  return 0; 
	return 1;
}

int accept_learn(object me, string skill)
{
	if (skill=="dodge")
	{
		if (me->query("class")=="guard")
			return 1;
		if (!(int)me->query_temp("mark/wangd"))
			return 0; 
		me->add_temp("mark/wangd", -1);
		return 1;
	}

	return 0;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/wangd"))
                who->set_temp("mark/wangd", 0);
        if (ob->query("money_id") && ob->value() >= 1000) {
                message_vision("王动同意指点$N一些基本轻功的问题。\n", who);
                who->add_temp("mark/wangd", ob->value() / 50);
                return 1;
        }
        return 0;
}


	
		

