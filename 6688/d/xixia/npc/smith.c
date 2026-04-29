// smith.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("铁匠", ({ "smith" }) );
	set("gender", "男性" );
	set("age", 35);
	set("long", "铁匠是党项族人，打造的兵器在整个西夏城都赫赫有名。\n");
	set("combat_exp", 40000);
	set("inquiry", ([
		"兵器": "在下从不为汉人打造兵器。\n",
	]) );

	set("shen_type", -1);

	set("str", 35);
	set_skill("hammer", 80);

	setup();
	carry_object("/obj/weapon/hammer")->wield();
}
