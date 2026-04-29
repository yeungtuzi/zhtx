//NPC:/d/suzhou/npc/longwu.c
//by dwolf
//9711.4
//changed by tlang
//97.12.3
       
#include <ansi.h>
inherit NPC;
string ask_for_hubiao();

void create()
{
        set_name(YEL"龙五"NOR, ({"long wu", "longwu", "long" }));
	set("title", HIW"镖局长老"NOR);
	set("long", @LONG
他是镖局的镖局四大长老之首的龙五，由于年纪太大，现在已经不管事了。据说他是少林俗家弟子中
的高手。
LONG
	);

	set("gender", "男性");
	set("attitude", "friendly");
	
	set("age", 65);
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 30);
	set("dex", 25);
	set("per", 25);
	set("max_kee", 2000);
	set("max_gin", 500);
	set("max_sen", 500);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 40);
	set("combat_exp", 1000000);
	set("score", 100000);
	
	set_skill("force", 120);
	set_skill("blade", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("shaolin-shenfa", 100);
	set_skill("cibei-dao", 120);
	set_skill("hunyuan-yiqi", 100);
        set_skill("strike", 120);
	set_skill("sanhua-zhang", 100);

        map_skill("strike", "sanhua-zhang");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

        prepare_skill("strike", "sanhua-zhang");
	prepare_skill("blade", "cibei-dao");
 
	set("inquiry", ([
		"护镖" : (: ask_for_hubiao :),
		"hubiao" : (: ask_for_hubiao :),
	]));

	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("gold", 5);
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
	if (!(int)ob->query_temp("mark/longwu"))  return 0; 
	return 1;
}

int accept_learn(object me, string skill)
{
	if (skill=="blade")
	{
		if (me->query("class")=="guard")
			return 1;
		if (!(int)me->query_temp("mark/longwu"))
			return 0; 
		me->add_temp("mark/longwu", -1);
		return 1;
	}

	return 0;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/longwu"))
                who->set_temp("mark/longwu", 0);
        if (ob->query("money_id") && ob->value() >= 1000) {
                message_vision("龙五同意指点$N一些基本刀法的问题。\n", who);
                who->add_temp("mark/longwu", ob->value() / 50);
                return 1;
        }
        return 0;
}
