#include <ansi.h>

inherit "/ldg/std/doomnpc";
//inherit "/ldg/std/rnd_equipd";

int remove_effect(object ob);
int consider();

void create()
{
	// 2026-04-30: unused variable commented out
	// object sword;

	set_name(RED"幽明血奴"NOR, ({ "xue nu","xue","nu"}) );
	set("long",
		RED"一个血肉模糊、稀烂一团的“人形”。\n"
		"这“人形”还有两张薄薄的、轻纱一般的、但又叫人呕心至极的羽翼。\n"
		"这是什么“东西”……\n"NOR
	 );

	set("gender","男性");
	set("age",38);

	set("max_gin", 2000);
	set("max_kee", 4000);                    
	set("max_sen", 2000);
	set("max_force",4000); 
	set("force",8000);
	set("force_factor",200);     
	set("combat_exp",5000000);
	set("bellicosity",500000);
	set("cor",100);      
	set("int",100);

	set_skill("force", 220);
        set_skill("huaxue-shengong", 200);
        set_skill("move", 200);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 200);
        set_skill("cuff", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 200);
        set_temp("apply/armor",200);

       
        map_skill("force","huaxue-shengong");
	map_skill("dodge", "tiyunzong");
        map_skill("move", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");


	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: consider :),
        }) );

	setup();

	carry_object("/obj/weapon/changjian")->wield();
	if(random(10)>4) carry_rnd_equip(2,3);
	if(random(10)>4) carry_object("/d/moyu/obj/nineflower");
}

int consider()
{
	if( query("env/invisibility") || !is_fighting() ) 
	{
		command("exert suck");
		return 0;
	}
	message_vision(RED"你眼前红光一闪，已经不见了$N"+RED"的踪影。\n"NOR,this_object());
	set("env/invisibility",1);
	call_out("remove_effect",60,this_object());			
	return 1;
}                              

int remove_effect(object me)
{
	remove_call_out("remove_effect");
	message_vision(BLU"$N"+BLU"的身形突然又显露了出来，让所有的人大吃一惊。\n"NOR,me);
	me->delete("env/invisibility");
	me->start_busy(3);
	return 1;
}
