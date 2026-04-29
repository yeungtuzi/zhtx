#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
	object sword;

	set_name("封寒", ({ "feng han","feng","han"}) );
	set("long",@LONG
	他背上斜插著把长刀，高瘦修长，却丝毫不给人半点体弱的感觉。整个人
像以钢筋架成，深藏著惊人的力量。使人觉得他不动则已，一动起来必是万分迅捷
灵巧。他面貌长而削，颧骨高起，双睛神采异常，光华隐现。
LONG
	 );

	set("title",CYN"左手刀"NOR);
	set("max_gin", 1000);
	set("max_kee", 3000);                    
	set("max_sen", 1000);
	set("max_force",2000); 
	set("force",4000);
	set("force_factor",150);     
        set("combat_exp",69999999);
	set("cor",100);
        set("wil",100);
	set("cps",100);
        set("fav",1);
	set("age",35);
	set("bellicosity",20000);
		
	set("skill_mark/spring-blade",1);
	set_skill("spring-blade", 220);
	set_skill("dodge", 220);
	set_skill("mysterrier",220);
	set_skill("parry", 220);
	set_skill("blade",220);
	set_skill("force",220);
	set_skill("celestial",220);

	map_skill("force","celestial");
	map_skill("blade","spring-blade");
	map_skill("parry","spring-blade");
	map_skill("dodge","mysterrier");
	map_skill("move","mysterrier");

	set_temp("apply/damage",50);
/*
	set("chat_chance",3);
        set("chat_msg_combat", ({
		"浪翻云凝视着窗外的明月，姿态悠闲之极。\n",
		"浪翻云举起盛满了清溪流泉的酒壶喝了一大口，笑道：痛快，痛快！\n"
        }) );
*/
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
		(: exert_function,"powerup" :),
                (: perform_action,"blade.yingfeng" :),
        }) );
	set_temp("apply/armor_vs_magic",500);
	setup();

        carry_object(__DIR__"obj/tbblade")->wield();
        carry_object("/class/fighter/houndbane");
        add_money("tenthousand-cash",1);
        if(random(10)>2) carry_rnd_equip(3,5);	
}                          

void init()
{
        set("shen",-500000);
	return;
}
                             
int killed_enemy(object ob)
{
	command("sigh");
}
