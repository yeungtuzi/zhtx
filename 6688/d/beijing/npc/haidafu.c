#include <ansi.h>
inherit NPC;

void create()
{
	set_name("海大富", ({ "hai dafu", "hai"}));
	set("gender", "无性");
	set("age", 55);
	set("title",CYN"尚膳监总管"NOR);
	set("long",@TEXT
海大富虽然年老多病，但因曾经服侍过先帝，谁也不敢对他尚膳监总管
的职务有丝毫的意见。
TEXT
	);
	set("combat_exp", 500000);
	set("max_force",1000);
	set("max_kee",1000);
	set("kee",1000);
	set("force",1500);
	set("force_factor",50);
	set("shen_type", 0);

	set_skill("strike", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("celestrike",100);

	map_skill("strike","celestrike");
	prepare_skill("strike","celestrike");
	map_skill("parry","celestrike");
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	add_money("gold", random(2));
	carry_object(__DIR__"obj/tj-cloth")->wear();
}
