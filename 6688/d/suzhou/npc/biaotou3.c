//NPC:/d/suzhou/npc/biaotou3.c 
//by dwolf
//97.11.4
//modified by tlang
         
#include <ansi.h>
inherit NPC;
#include "/d/suzhou/npc/biaoju.h"

void create()
{
	set_name(YEL"宁馨"NOR, ({ "nin xin", "jade" }));
	set("title","九天仙子");
	set("age", 18);
	set("gender", "女性");
	set("long", "她正是二九，风姿迷人，是镖局的镖头，负责守卫精进楼的书籍。\n");
	set("attitude", "friendly");

	set("str", 24);
	set("dex", 22);      
	set("per", 30);
	set("max_kee",2000);
	set("combat_exp", 200000);
	set("shen_type", 2);

	set_skill("unarmed", 85);
	set_skill("dodge", 85);
	set_skill("parry", 85);
	set_skill("sword", 85);
	set_skill("force", 85);
	set_skill("blade",85);
	set_skill("fonxansword",70);
	
	map_skill("sword","fonxansword");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 30);
              
	setup();
	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object(__DIR__"obj/bjcloth")->wear();
}

