#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
	// 2026-04-30: unused variable commented out
	// object sword;

	set_name("乾罗", ({ "gan luo","gan","luo"}) );
       create_family("步玄派", 8, "八代弟子");
	set("long",@LONG
	他一副慢条斯理的悠闲神态。瘦削的脸庞，高挺微勾的鼻，轮廓清楚分明，
两眼似开似闭，时有精光电闪，一看便知道是难惹的人物。他看来只有三十许，还
算得上相当英俊，但他成名江湖最少有四十年以上，如此估计，他的年岁应该不少於
六十。只不过先天气功到了他们这类境界，往往能克服衰老这个障碍。竟然是威震黄
河流域，乾罗山城的主人，毒手乾罗。
LONG
	 );

	set("title",RED"毒手"NOR);
	set("max_gin", 1000);
	set("max_kee", 3000);                    
	set("max_sen", 1000);
	set("max_force",5000); 
	set("force",10000);
	set("force_factor",150);     
	set("combat_exp",6999999);
	set("cor",100);
	set("cps",100);
	set("age",35);

	set_skill("spicyclaw", 250);
	set_skill("dodge", 220);
	set_skill("mysterrier",220);
	set_skill("parry", 220);
	set_skill("claw",220);
	set_skill("force",220);
	set_skill("celestial",220);
        set_skill("strike",250);
        set_skill("cuixin-zhang",250);

	map_skill("force","celestial");
        map_skill("strike","cuixin-zhang");
	map_skill("claw","spicyclaw");
	map_skill("parry","spicyclaw");
	map_skill("dodge","mysterrier");
	map_skill("move","mysterrier");

	prepare_skill("claw","spicyclaw");
        prepare_skill("strike","cuixin-zhang");
	set_temp("apply/damage",50);
/*
	set("chat_chance",3);
        set("chat_msg_combat", ({
		"浪翻云凝视着窗外的明月，姿态悠闲之极。\n",
		"浪翻云举起盛满了清溪流泉的酒壶喝了一大口，笑道：痛快，痛快！\n"
        }) );
*/
        set("chat_chance_combat",100);
        set("chat_msg_combat", ({
//                (: exert_function,"powerup" :),
          (: perform_action,"move.hasten" :),
        }) );

	setup();

//	carry_object(__DIR__"obj/tbblade")->wield();
	add_money("tenthousand-cash",1);
        if(random(10)>2) carry_rnd_equip(3,5);	
}                          

void init()
{
        set("shen",-1*this_player()->query("shen")/10);
	return;
}
                             
int killed_enemy(object ob)
{
	command("sigh");
}
