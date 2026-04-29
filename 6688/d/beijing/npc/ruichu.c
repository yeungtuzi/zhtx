//ruichu.c蕊初
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("蕊初", ({ "rui chu","rui","chu"}) );
	set("gender", "女性" );
	set("age", 18);
	set("title",CYN"宫女"NOR);
	set("long", "一个服侍太后的宫女，容貌清秀脱俗，身材娇小玲珑。\n");
	set("shen_type", 1);
	set("combat_exp", 30000);
	set("str", 18);

	set("con", 18);
	set("int", 19);
	set("attitude", "friendly");
	setup();
	carry_object(__DIR__"obj/girlcloth")->wear();
}