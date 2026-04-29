inherit NPC;

void create()
{
    	set_name("苟读", ({ "gou du", "gou" }) );
	set("long", @LONG
他就是函谷八友之一苟读，此人最是热衷于读书，已经到了如痴如醉的
地步。这时他正摇头晃脑地念得起劲，全没注意到你的到来。你看到他
书呆子的傻样，差点要笑出声来。
LONG);
	set("gender", "男性" );
    	set("age", 35);
    	set("str", 30);
    	set("cor", 27);
    	set("cps", 28);
    	set("int", 46);
    	set("per", 29);
    	set("spi", 26);
    	set("kar", 27);
    	set("con", 28);
	set("inquiry", ([ "here": "这里就是擂谷山，请问有何贵干?", ]) );

        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 20);

        set("score", -100);
        set("combat_exp", 314500);

        set_skill("unarmed", 100);
	set_skill("literate", 150);
        set_skill("force", 60);
        set_skill("dodge", 80);
        set_skill("sword", 80);
        set_skill("parry", 80);

	setup();
	carry_object(__DIR__"obj/book");
	carry_object("obj/cloth")->wear();
}
