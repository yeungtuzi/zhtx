#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
	object sword;

	set_name("宇文秀", ({ "yuwen xiu","yuwen","xiu"}) );
	set("long",
		"宇文秀原本是河南名士，步玄派嫡传弟子。三年前进入幽明山庄探奇。\n"
		"此后就没有人再见过他。没想到会在这里。\n"
		"此刻他披头散发，衣衫破碎，满身鲜血，目光赤红，显然是受了莫大的刺激。\n"
	 );

	set("nickname",GRN"笑语追魂"NOR);
	set("title",RED"幽冥山庄药人"NOR);
create_family("步玄派", 8, "八代弟子");
	set("max_gin", 2000);
	set("max_kee", 4000);                    
	set("max_sen", 2000);
	set("max_force",4000); 
	set("force",10000);
	set("force_factor",200);     
	set("combat_exp",9000000);
	set("bellicosity",5000000);
	set("cor",100);

	set_skill("mystsword", 220);
	set_skill("dodge", 200);
	set_skill("mysterrier",200);
	set_skill("parry", 200);
	set_skill("sword",220);
	set_skill("force",800); //防止别人来弹指
	set_skill("mystforce",200);

	map_skill("sword","mystsword");
	map_skill("parry","mystsword");
	map_skill("dodge","mysterrier");
	map_skill("move","mysterrier");

	set_temp("apply/attack",100);
	set_temp("apply/damage",250);
	set_temp("apply/dodge",100);

	set("chat_chance",20);
        set("chat_msg_combat", ({
                "鬼..活不了了...救命...龙吟密籍...啊...我的功力...\n",
		(: random_move :),
        }) );

	set("chat_chance_combat",90);
        set("chat_msg_combat", ({
		(: perform_action,"move.hasten" :),
        }) );

	set("shen",1);
	set("score",1);

	setup();

	sword = new("/class/scholar/windspring");
	sword->move(this_object());
	sword->wield();
        if(random(10)>2) carry_rnd_equip(2,4);
}
