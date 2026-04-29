inherit NPC;

void create()
{
    	set_name("石清露", ({ "shi qinglou", "shi" }) );
	set("gender", "女性" );
	set("nickname", "函谷八友");
	set("long", @LONG
函谷八友中的七师妹，擅长莳花，天下的奇花异草，
经她培植，无不欣欣向荣。
LONG);
    	set("age", 31);
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
        set_skill("force", 60);
        set_skill("dodge", 80);
        set_skill("sword", 80);
        set_skill("parry", 80);

	setup();
	carry_object(__DIR__"obj/pink_cloth")->wear();

}
