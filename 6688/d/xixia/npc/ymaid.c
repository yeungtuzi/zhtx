#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIG"宫女"NOR, ({ "maid" }));
	set("long", @LONG
银川公主的贴身宫女。
LONG);
	set("gender", "女性");
	set("age", 10+random(12));
	set("shen_type",1);
	set("attitude", "peaceful");

	set("per", 20+random(10));

	set("max_kee", 700);
	set("max_gin", 220);
	set("max_sen", 220);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 2);

	set("combat_exp", 40000);
	set_skill("force", 30);
	set_skill("hand", 30);
	set_skill("zhemei-shou", 30);
	set_skill("dodge", 30);
	set_skill("lingboweibu", 30);
	set_skill("xiaowuxiang-gong", 30);
	set_skill("parry", 30);
	
	map_skill("dodge", "lingboweibu");
	map_skill("force", "xiaowuxiang-gong");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "zhemei-shou");

	prepare_skill("hand", "zhemei-shou");

	setup();
 	carry_object(__DIR__"obj/green_cloth")->wear();
}
