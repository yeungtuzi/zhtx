#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
	object sword;

	set_name("莫意闲", ({ "mo yixian","mo","yixian"}) );
	set("long",@LONG
	莫意闲名列黑榜，赫赫有名，原来竟是个水桶般又矮又大的胖子，
LONG
	 );

	set("title",CYN"逍遥门主"NOR);
	set("max_gin", 1000);
	set("max_kee", 3000);                    
	set("max_sen", 1000);
	set("max_force",5000); 
	set("force",10000);
	set("force_factor",250);     
	set("combat_exp",69999999);
	set("cor",100);
	set("cps",100);
	set("age",35);

	set_skill("celestrike", 220);
	set_skill("dodge", 220);
	set_skill("pyrobat-steps",220);
	set_skill("parry", 220); 
	set_skill("strike",220);
	set_skill("force",220);
	set_skill("celestial",220);
        set_skill("xingxiu-duzhang",220);
        set_skill("dugong",220);
        set_skill("fushi-dugong",220);

	map_skill("force","celestial");
        map_skill("dugong","fushi-dugong");
        map_skill("strike","xingxiu-duzhang");
	map_skill("parry","celestrike");
	map_skill("dodge","pyrobat-steps");
	map_skill("move","pyrobat-steps");

        prepare_skill("strike","xingxiu-duzhang");
	set_temp("apply/damage",150);
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
        }) );

	setup();

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
