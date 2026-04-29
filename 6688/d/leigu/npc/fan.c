inherit NPC;

void create()
{
    	set_name("范百龄", ({ "fan bailing", "fan" }) );
	set("gender", "男性" );
	set("nickname", "函谷八友");
	set("long", @LONG
范百龄是函谷八友之一，此人热衷于围棋，已经到了如痴如醉的
地步。若是找到棋逢对手的对手或者什么棋谱，便是天塌下来也
置诸脑后。
LONG);
    	set("age", 45);
    	set("str", 30);
    	set("cor", 27);
    	set("cps", 28);
    	set("int", 26);
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
	set_skill("qi", 150);
        set_skill("force", 60);
        set_skill("dodge", 80);
        set_skill("sword", 80);
        set_skill("parry", 80);

	setup();
	carry_object(__DIR__"obj/qipan")->wield();
	carry_object(__DIR__"obj/cyn_cloth")->wear();

}
