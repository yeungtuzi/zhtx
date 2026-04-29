//NPC:/d/suzhou/npc/biaotou.c 
//by dwolf
//97.11.4
         
#include <ansi.h>
inherit NPC;
#include "/d/suzhou/npc/biaoju.h"

void create()
{
	set_name(HIW"纪嫣然"NOR, ({ "ji yanran", "ji" }));
	set("age", 37);
	set("gender", "女性");
	set("long", "她正是半老徐娘，风姿迷人，是镖局中有数的镖头，正在指导弟子练武。\n");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 22);      
	set("per", 30);
	set("combat_exp", 150000+random(50000));
	set("shen_type", 2);

	set_skill("unarmed", 75);
	set_skill("dodge", 75);
	set_skill("parry", 75);
	set_skill("sword", 75);
	set_skill("force", 75);
	set_skill("blade",75);
	set_skill("strike",75);
	set_skill("chaos-steps",80);
	set_skill("fonxansword",80);
	
	map_skill("sword","fonxansword");
	map_skill("dodge","chaos-steps");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 30);
              
	setup();
	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object(__DIR__"obj/bjcloth")->wear();
}

