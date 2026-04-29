//by tlang
//97.12
//hylai2.c

#include <ansi.h>
inherit NPC;
int dest();

void create()
{
	set_name(YEL"花夜来"NOR, ({"hua yelai", "hua"}) );
	set("long", "她无疑是个风姿绰约的绝代丽人。只见她手腕圆润，手指纤美, \n"
"眉宇间仿佛带着种淡淡的哀愁，仿佛正在感怀着春的易老，情人的离别。\n");
	set("per", 40);
	set("int", 30);
	set("str", 20);
	set("gender", "女性");
	set("age", 30);
	set("combat_exp", 500000+random(100000));
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 50);
	
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("chaos-steps", 60);
	set_skill("fonxanforce", 100);
	set_skill("fonxansword", 60);
	map_skill("sword", "fonxansword");
	map_skill("dodge", "chaos-steps");
	map_skill("force", "fonxanforce");	
	
	setup();
	add_money("silver",5);
	carry_object("/d/suzhou/npc/obj/gangjian")->wield();
	carry_object("/d/suzhou/npc/obj/cloth2")->wear();
}

void die()
{
        object ob;
	ob=new("/d/hangzhou/npc/obj/diamond");
	ob->move(environment(this_object()));
        message_vision("$N凄惨地叫了一声，死了！尸体忽然消失，只留下一颗珍珠。\n", this_object());
	call_out("dest",0);
}        

int dest()
{
	destruct(this_object());
		return 1;
}
