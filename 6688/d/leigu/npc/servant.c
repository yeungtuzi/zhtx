inherit NPC;

void create()
{
    	set_name("聋哑仆人", ({ "servant" }) );
	set("gender", "男性" );
	set("long", @LONG
他是聪辩先生苏星河所创立聋哑门的人，聋哑门全都又聋又哑，
连掌门人苏星河也不例外。
LONG);
    	set("age", 20+random(20));
    	set("str", 30);
    	set("cor", 27);
    	set("cps", 28);
    	set("int", 26);
    	set("per", 29);
    	set("spi", 26);
    	set("kar", 27);
    	set("con", 28);
	set("inquiry", ([ "here": "这里就是擂谷山，请问有何贵干?", ]) );

        set("force", 200);
        set("max_force", 200);
        set("force_factor", 20);

        set("score", -100);
        set("combat_exp", 314500);

        set_skill("unarmed", 100);
        set_skill("force", 60);
        set_skill("dodge", 80);
        set_skill("sword", 80);
        set_skill("parry", 80);

	setup();
	carry_object("obj/cloth")->wear();

}
