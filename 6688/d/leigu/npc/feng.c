inherit NPC;

void create()
{
    	set_name("冯阿三", ({ "feng asan", "feng" }) );
	set("gender", "男性" );
	set("nickname", "寒谷八友");
	set("long", @LONG
冯阿三原本是一位木匠，但已经在方圆数百里很有名气了，
后来得遇高人指点，更是巧上加巧，他也是函谷八友之一。
LONG);
    	set("age", 38);
    	set("str", 30);
    	set("cor", 27);
    	set("cps", 28);
    	set("int", 26);
    	set("per", 29);
    	set("spi", 26);
    	set("kar", 27);
    	set("con", 28);
	set("inquiry", ([ "here": "这里就是擂谷山，请问有何贵干?", ]) );

        set("force", 1200);
        set("max_force", 1200);
        set("force_factor", 20);

        set("score", -100);
        set("combat_exp", 314500);

        set_skill("unarmed", 100);
	set_skill("making", 150);
        set_skill("force", 60);
        set_skill("dodge", 80);
        set_skill("sword", 80);
        set_skill("parry", 80);

	setup();
	carry_object(__DIR__"obj/hand_axe")->wield();
	carry_object("obj/cloth")->wear();

}
