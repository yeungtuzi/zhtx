#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
	set_name(MAG"艳无忧"NOR, ({ "yan wuyou","yan","wuyou"}) );
	set("long",
		"血霜妃擅长奇门八卦，化血大法与摄魂魔音，嗜吸人血。\n"
		"这女子二十出头，似是霜花一般皎洁，双眸如春水一般荡漾。\n"
		"不转目也有风情无数，发如垂瀑。\n"
	 );

	set("title",GRN"血霜妃"NOR);
	set("gender","女性");
	set("age",22);
	set("int",100);
	set("cor",100);
	set("per",200);		

	set("max_gin", 2000);
	set("max_kee", 4000);                    
	set("max_sen", 2000);
	set("max_force",4000); 
	set("force",10000);
	set("force_factor",200);     
	set("combat_exp",5000000);
	set("bellicosity",500000);

	set_skill("snowwhip", 220);
	set_skill("dodge", 250);
	set_skill("stormdance",250);
	set_skill("parry", 200);
	set_skill("whip",220);
	set_skill("force",800); //防止别人来弹指
	set_skill("iceforce",200);

	map_skill("whip","snowwhip");
	map_skill("parry","snowwhip");
	map_skill("dodge","stormdance");
	map_skill("move","stormdance");
	map_skill("force","iceforce");

	set_temp("apply/attack",100);
	set_temp("apply/dodge",100);

	set("chat_chance",10);
        set("chat_msg", ({
                "艳无忧轻轻抚着自己的如云长发，对你说道：来呀...来呀...\n",
		(: random_move :),
        }) );

	set("chat_chance_combat",80);
        set("chat_msg_combat", ({
		(: perform_action,"dodge.ensnare" :),
		(: exert_function,"chillgaze" :),
        }) );

	setup();

	carry_object(__DIR__"obj/sidai")->wield();
        if(random(10)>2) carry_rnd_equip(2,3);
}
