#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
	object sword;

	set_name("谈应手", ({ "tan yingshou","tan","yingshou"}) );
	set("long",@LONG
	这人勾鼻深目，皮包骨的脸像鬼而不似人，配合着似若从地狱里爬出来
的魔鹰，教人感到不寒而栗。
LONG
	 );

	set("title",CYN"十恶庄主"NOR);
	set("max_gin", 1000);
	set("max_kee", 3000);                    
	set("max_sen", 1000);
	set("max_force",5000); 
	set("force",10000);
	set("force_factor",150);     
	set("combat_exp",69999999);
	set("cor",100);
	set("cps",100);
	set("age",35);

	set_skill("jingang-quan", 220);
	set_skill("dodge", 220);
	set_skill("shaolin-shenfa",220);
	set_skill("parry", 220); 
	set_skill("cuff",220);
	set_skill("force",220);
	set_skill("hunyuan-yiqi",220);
        set_skill("banruo-zhang",220);
        set_skill("strike",220);

	map_skill("force","hunyuan-yiqi");
        map_skill("strike","banruo-zhang");
	map_skill("cuff","jingang-quan");
	map_skill("parry","jingang-quan");
	map_skill("dodge","shaolin-shenfa");
	map_skill("move","shaolin-shenfa");
       set_temp("pfm/shaolin_jzz", 1);

	prepare_skill("cuff","jingang-quan");
        prepare_skill("strike","banruo-zhang");
	set_temp("apply/damage",150);
/*
	set("chat_chance",3);
        set("chat_msg_combat", ({
		"浪翻云凝视着窗外的明月，姿态悠闲之极。\n",
		"浪翻云举起盛满了清溪流泉的酒壶喝了一大口，笑道：痛快，痛快！\n"
        }) );

	set("chat_chance_combat",10);
        set("chat_msg_combat", ({
		(: exert_function,"powerup" :),
        }) );
*/
	setup();

        add_money("tenthousand-cash",1);
        if(random(10)>2) carry_rnd_equip(3,5);  
}                          

int init()
{
        set("shen",-500000);
	return 1;
}
                             
int killed_enemy(object ob)
{
	command("sigh");
}
