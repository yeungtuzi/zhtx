
inherit NPC;

#include <ansi.h>

void create()
{
	set_name(HIG"妙玉"NOR, ({ "miao yu" }));
	set("gender", "女性");
	set("age", 20);
	set("str", 25);
	set("dex", 30);
	set("long", HIG"她风姿绰约，浑不似凡间人物。\n"NOR);
	set("combat_exp", 1000);
	set("shen_type", 100000000);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);

	setup();
}
