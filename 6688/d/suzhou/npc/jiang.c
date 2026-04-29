//NPC:/d/suzhou/npc/jiang.c
//changed by tlang
//97.12.4

#include <ansi.h>
inherit NPC;
#include "/d/suzhou/npc/biaoju.h"

string ask_for_ning();

void create()
{
        set_name(YEL"江小川"NOR, ({"jiang xiaochuan", "jiang" }));
	set("title", HIW"总镖头"NOR);
	set("long",
	"他是镖局的总镖头，由于前任总镖头年纪太大，所以他年纪轻轻就掌管了镖局。\n");

	set("gender", "男性");
	set("attitude", "heroism");
	
	set("age", 25);
	set("shen_type", 2);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 25);
	set("per", 27);
	set("max_kee", 1500);
	set("max_gin", 300);
	set("max_sen",300);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 60);
	set("combat_exp", 500000+random(500000));
	set("score", 10000);

	set_skill("force", 150);
	set_skill("blade", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike", 150);
	set_skill("shaolin-shenfa", 120);
	set_skill("cibei-dao", 120);
	set_skill("hunyuan-yiqi", 120);
        set_skill("sanhua-zhang", 120);

        map_skill("strike", "sanhua-zhang");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

        prepare_skill("strike", "sanhua-zhang");

	set("inquiry", ([
		"宁王府" : (: ask_for_ning :),
		"wangfu" : (: ask_for_ning :),
	]));


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
	if( !me || environment(me) != environment() || !me->query("biao_ju")
 || random(100)<=20 ) return;
       	command("say 要多多练功，为镖局办事。\n");
}

string ask_for_ning()
{
	return "宁王府在苏州城东，宁王爷和我们镖局交情甚厚，只要你是镖局中人\n
		相信王府中人不会为难你的。\n"; 
}                                      
