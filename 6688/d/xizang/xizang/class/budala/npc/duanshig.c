// /d/xizang/class/budala/npc/duanshig.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("禄东赞", ({"lu dongzan", "lu", "judge", "guan" }));
	set("title", "断事官");
        set("long", "他就是达赖喇嘛的代表禄东赞,负责藏边府的一般政务.\n");
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 46);
        set("str", 26);
        set("max_kee", 800);
        set("max_gin", 300);
	set("max_sen", 600);
	set_skill("zang-buddhi", 100);
	set_skill("literate", 170);
	set_skill("unarmed", 240);
	
        set("combat_exp", 1111000);
        set("score", 1000000);

	set("env/wimpy", 70);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: random_move :)
	}));
        setup();
        carry_object(__DIR__"obj/zcloth1")->wear();
}

//he can give quest
