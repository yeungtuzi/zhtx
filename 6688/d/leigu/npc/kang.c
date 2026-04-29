inherit NPC;

void create()
{
    	set_name("康广陵", ({ "kang guangling", "kang" }) );
	set("gender", "男性" );
	set("nickname", "函谷八友");
	set("long", @LONG
康广陵是函谷八友中的老五，醉心于声乐。函谷八友等八人臭味相投，
物以类聚。个个疯疯颠颠，也不必细说了。
LONG);
    	set("age", 52);
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
	set_skill("music", 150);
        set_skill("force", 60);
        set_skill("dodge", 80);
        set_skill("sword", 80);
        set_skill("parry", 80);

	setup();
	carry_object(__DIR__"obj/qing");
	carry_object("obj/cloth")->wear();

}
