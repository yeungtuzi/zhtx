//NPC:/d/suzhou/npc/biaotou2.c 
//by dwolf
//97.11.4
         
#include <ansi.h>
inherit NPC;
#include "/d/suzhou/npc/biaoju.h"

void create()
{
	set_name(HIW"金成武"NOR, ({ "jin chengwu", "jin" }));
	set("title","大力镖头");
	set("age", 32);
	set("gender", "男性");
	set("long", "他虎背熊腰，威风凛凛，本来在和弟子聊天，见人来了，就转过头来。\n");
	set("attitude", "heroism");

	set("str", 34);
	set("dex", 22);      
	set("per", 23);
	set("combat_exp", 150000+random(50000));
	set("shen_type", 2);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("force", 80);
	set_skill("blade",80);
	set_skill("strike",80);
	set_skill("fonxansword",70);
	set_skill("chaos-steps",70);

	map_skill("sword","fonxansword");
	map_skill("dodge","chaos-stpes");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 30);
              
	setup();
	add_money("silver",2);
	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object(__DIR__"obj/qbcloth")->wear();
}

