// /d/xizang/class/bad/npc/emote.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("唐话", ({ "emote", "tang hua", "hua" }));
	set("title", HIG+"毒魔女"+NOR);
	set("gender", "女性" );
	set("age", 22);
	set("str", 26);
	set("cor", 29);
	set("cps", 27);
	set("int", 30);
	set("per", 27);
	set("long", @TEXT
她就是唐门原来的大师姐唐话,因为用毒杀人太多而被逐出门墙,逃到恶人谷
安身.她的医术其实也是不错的,不过是杀人还是救人全看她一时心情的好坏
了.至于她卖出去的药,也是有真有假,买到真的算你运气,买到假的算你倒霉
TEXT
);
	set("combat_exp", 1400000);
	set("attitude", "heroism");
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("dodge", 180);
//add some other skill
//add inquiry for heal
	set("vendor_goods", ([
		"九花玉露丸"  	: __DIR__"obj/wan",
		"菩提子" 	: __DIR__"obj/ptz",
		"天香断续膏"	: __DIR__"obj/gao",
		"起死回生散"	: __DIR__"obj/san",
		"保命还魂丹"	: __DIR__"obj/dan",
		"天山雪莲"	: __DIR__"obj/lotus",
		"人参"		: __DIR__"obj/ginseng",
		"灵芝"		: __DIR__"obj/agaric",
	]));
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
}
