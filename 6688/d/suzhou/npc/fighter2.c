//NPC:/d/suzhou/npc/fighter2.c 
//by dwolf
//97.11.4
         
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW"镖局弟子"NOR, ({ "biaoju dizi", "dizi", "fighter" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "他是镖局的弟子，正在勤奋练武。\n");
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
||  this_object()->is_fighting() || random(100)<=60 ) return;
	switch(random(3)) {
	case 0:
	tell_object(ob,YEL"一个镖局弟子一招黑虎偷心，另外一个弟子身子一转，
不知道怎么就避开了。\n"NOR);
	break;
	case 1: 
	tell_object(ob,YEL"左边一个弟子反了一招青蛇吐信，右边一个弟子躲闪不及，
正中肩头，不由得变了脸色：佩服！\n"NOR);
	break;
	case 2: 
	tell_object(ob,YEL"年纪大些的弟子以刀做剑，一招白龙出水，年纪小的弟子
一式雁落平沙，堪堪避开。\n"NOR);
	break;
	}
}

	