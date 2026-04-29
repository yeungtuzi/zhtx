// /d/xizang/class/bad/npc/lsj.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("后悔", ({ "hou hui", "hui", "lsj" }));
	set("title", "多嘴和尚 "+HIW+"唐三藏"+NOR);
	set("gender", "男性" );
	set("age", 22);
	set("str", 19);
	set("cor", 20);
	set("cps", 30);
	set("int", 25);
	set("per", 20);
	set("long", @TEXT
他的外号虽然是"多嘴和尚",却非佛门中人. 他满嘴悲天悯人的大道理,连雪亭
书院的先生魏无极都说不过他,只是在你被他说得头昏眼花的时候,他手底下可
就没那么客气了,那时你就该知道 后悔 是让谁后悔....
TEXT
);
	set("combat_exp", 600000);
	set("attitude", "heroism");
	set("force", 1500);
        set("max_force", 1500);
	set("force_factor", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 80);
	set_skill("literate", 120);
	set_skill("floodspeak", 500);
//add floodspeak effect
	map_skill("unarmed", "floodspeak");

	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(: perform_action, "unarmed.flood" :),
	}));
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
}
