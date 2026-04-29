inherit NPC;

void create()
{
    	set_name("吴领军", ({ "wu lingjun", "wu" }) );
	set("gender", "男性" );
	set("nickname", "函谷八友");
	set("long", @LONG
函谷八友老四吴领军雅擅丹青，山水人物，翎毛花卉，并皆精巧。
他以前曾在朝廷做过领军将军之值，因此大家度称之吴领军，真实
名字反倒忘了。
LONG);
    	set("age", 42);
    	set("str", 30);
    	set("cor", 27);
    	set("cps", 28);
    	set("int", 26);
    	set("per", 29);
    	set("spi", 26);
    	set("kar", 27);
    	set("con", 28);
	set("inquiry", ([ "here": "这里就是擂谷山，请问有何贵干?", ]) );

        set("force", 900);
        set("max_force", 900);
        set("force_factor", 20);

        set("score", -100);
        set("combat_exp", 314500);

        set_skill("unarmed", 100);
	set_skill("drawing", 150);//草书
        set_skill("force", 60);
        set_skill("dodge", 80);
        set_skill("sword", 80);
        set_skill("parry", 80);

	setup();
	carry_object(__DIR__"obj/pen")->wield();
	carry_object(__DIR__"obj/cyn_cloth")->wear();

}
