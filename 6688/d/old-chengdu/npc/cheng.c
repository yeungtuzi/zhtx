// cheng.c 程老板

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("程老板", ({ "cheng laoban", "cheng" }));
	set("title", "散花楼老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 65);
	set("long", "程老板经营祖传下来的散花酒楼已有多年。\n");

	set("combat_exp", 50000);

	set("qi", 300);
	set("max_qi", 300);
	set("attitude", "friendly");

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);

	set("vendor_goods", ([
		__DIR__"obj/malatang" : 10,
	]) );

	setup();
	add_money("gold", 1);
	carry_object("/obj/cloth/cloth")->wear();
}

void init()
{
	add_action("do_vendor_list", "list");
}

