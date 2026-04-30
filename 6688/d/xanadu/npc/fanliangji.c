#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
	// 2026-04-30: unused variable commented out
	// object sword;

	set_name("范良极", ({ "fan liangji","fan","liangji"}) );
	set("long",@LONG
　　	那人看来非常老，脸皮都皱了起来，身材矮小，原本应是个毫不起眼的糟老头，
可是他一对眼睛神芒闪烁，锐利至像能透视别人肺腑般，一脚踏在凳上，手肘枕在膝头
处托着旱烟，有种稳如泰山的感觉，在在都使人感到他绝非平凡之辈。
LONG
	 );

	set("title",BLU"偷王之王"NOR);
	set("nickname","独行盗");
	set("max_gin", 1000);
	set("max_kee", 3000);                    
	set("max_sen", 1000);
	set("max_force",5000); 
	set("force",10000);
	set("force_factor",150);     
	set("combat_exp",69999999);
	set("cor",100);
	set("cps",100);           
	set("kar",100);
	set("age",65);

	set_skill("touwang-bada", 220);
	set_skill("dodge", 220);
	set_skill("qingcheng-steps",220);
	set_skill("parry", 220); 
	set_skill("dagger",220);
	set_skill("force",220);
	set_skill("qingcheng-force",220);
	set_skill("stealing",250);

	map_skill("force","qingcheng-force");
	map_skill("dagger","touwang-bada");
	map_skill("parry","touwang-bada");
	map_skill("dodge","qingcheng-steps");
	map_skill("move","qingcheng-steps");

	set_temp("apply/attack",50);

	set("chat_chance_combat",20);
        set("chat_msg_combat", ({
		(: perform_action,"dagger.smoke" :),
        }) );

	setup();

	carry_object(__DIR__"obj/yandai")->wield();
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

