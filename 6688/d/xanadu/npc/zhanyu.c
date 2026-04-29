#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
	object sword;

	set_name("展羽", ({ "zhan yu","zhan","yu"}) );
	set("long",@LONG
	他年约六十馀，身形高瘦，手脚均较普通人长上一些，动作灵巧，双目
转动间使人感到他是个机灵多智的人物。
LONG
	 );

	set("title",MAG"矛铲双飞"NOR);
	set("max_gin", 1000);
	set("max_kee", 3000);                    
	set("max_sen", 1000);
	set("max_force",5000); 
	set("force",10000);
	set("force_factor",250);     
	set("combat_exp",69999999);
	set("bellicosity",50000);
	set("cor",100);
	set("cps",100);
	set("age",65);
         set("shen",-500000);

	set_skill("kuihua-shengong", 220);
	set_skill("dodge", 220);
	set_skill("parry", 220); 
	set_skill("halberd",220);
	set_skill("mo-ji-jue",220);
	set_skill("force",220);


	map_skill("force","kuihua-shengong");
	map_skill("halberd","mo-ji-jue");
	map_skill("parry","mo-ji-jue");
	map_skill("dodge","kuihua-shengong");

	set_temp("apply/damage",200);
/*
	set("chat_chance",3);
        set("chat_msg_combat", ({
		"浪翻云凝视着窗外的明月，姿态悠闲之极。\n",
		"浪翻云举起盛满了清溪流泉的酒壶喝了一大口，笑道：痛快，痛快！\n"
        }) );
*/
	set("chat_chance_combat",30);
        set("chat_msg_combat", ({
		(: exert_function,"kuihua" :),
        }) );

	setup();

	carry_object(__DIR__"obj/changji.c")->wield();
        if(random(10)>8) add_money("tenthousand-cash",1);
        if(random(10)>2) carry_rnd_equip(3,5);	
}                          
                           
int killed_enemy(object ob)
{
	command("sigh");
}
