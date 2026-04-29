#include <ansi.h>

inherit NPC;

void create()
{
	set_name(MAG"宫女"NOR, ({ "maid" }));
	set("long", @LONG
银川公主的贴身宫女。
LONG);
	set("gender", "女性");
	set("age", 10+random(12));
	set("shen_type",1);
	set("attitude", "peaceful");

	set("per", 20+random(10));

	set("max_kee", 1000);
	set("max_gin", 220);
	set("max_sen", 220);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 20);

	set("combat_exp", 100000);
	set_skill("force", 70);
	set_skill("hand", 70);
	set_skill("zhemei-shou", 70);
	set_skill("dodge", 70);
	set_skill("lingboweibu", 70);
	set_skill("xiaowuxiang-gong", 70);
	set_skill("parry", 70);
	
	map_skill("dodge", "lingboweibu");
	map_skill("force", "xiaowuxiang-gong");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "zhemei-shou");

	prepare_skill("hand", "zhemei-shou");

	setup();
 	carry_object(__DIR__"obj/mag_cloth")->wear();
}
