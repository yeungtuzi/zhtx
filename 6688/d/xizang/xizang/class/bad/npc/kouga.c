// /d/xizang/class/bad/npc/kouga.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("小雨点", ({ "kouga", "xiao yu dian", "dian" }));
	set("title", HIW+"黑店老板"+NOR);
	set("gender", "男性" );
	set("age", 20);
	set("str", 20);
	set("cor", 20);
	set("cps", 30);
	set("int", 25);
	set("per", 30);
	set("long", @TEXT
他就是黑店的老板小雨点,从这家伙手里卖出去的东西....还是不要碰为好
TEXT
);
	set("combat_exp", 1100000);
	set("attitude", "heroism");
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("dodge", 180);
//add some other skill
	set("vendor_goods", ([
		"布衣"  	: __DIR__"obj/cloth",
		"软猬甲" 	: __DIR__"obj/armor1",
		"怒龙锦胄"	: __DIR__"obj/armor2",
		"风泉之剑"	: __DIR__"obj/sword1",
		"邪剑穿灵"	: __DIR__"obj/sword2",
		"离别钩"	: __DIR__"obj/hook",
		"妖刀狗屠"	: __DIR__"obj/blade1",
		"碧玉胡刀"	: __DIR__"obj/blade2",
		"昏睡卡"	: __DIR__"obj/card1",
		"抢夺卡"	: __DIR__"obj/card2",
		"诬告卡"	: __DIR__"obj/card3",
		"复仇卡"	: __DIR__"obj/card4",
		"均富卡"	: __DIR__"obj/card5",
	]));
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
}
