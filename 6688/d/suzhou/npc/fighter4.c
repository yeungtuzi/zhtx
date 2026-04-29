//NPC:/d/suzhou/npc/fighter4.c 
//by dwolf
//97.11.4
         
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(BLK"镖局弟子"NOR, ({ "biaoju dizi", "dizi", "fighter" }));
	set("age", 25);
	set("gender", "男性");
	set("long", "他是镖局的弟子，正在勤奋读书，以求进步。\n");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 22);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("blade", 20);
	set_skill("force", 20);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 20);
              
	setup();
	carry_object(__DIR__"obj/zhudao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
	remove_call_out("greeting");
	call_out("greeting",1,this_player());
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() 
||  this_object()->is_fighting() ) return;
	switch(random(3)) {
	case 0:
	command("wa");
	command("say 写得好！天上白玉京，九楼十二城。哈哈！！！\n");
	break;
	case 1:
	command("xixi"); 
	command("say 诗意与剑意融为一体，果然是利害！\n");
	break;
	case 2:
	command("sigh"); 
	command("say 这招霸王擎天，我老是不能领会，兄弟你呢？\n");
	break;
	}
}

	