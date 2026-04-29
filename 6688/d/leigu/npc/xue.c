inherit NPC;

void create()
{
    	set_name("薛慕华", ({ "xue muhua", "xue" }) );
	set("gender", "男性" );
	set("nickname", "薛神医");
	set("long", @LONG
薛慕华在江湖中有薛神医的美誉，不过此人脾气古怪，他不想给人治的
时候，就算黄金万两，或是利刃加身，也会冷眼旁观。他黑须及胸，脸
如冠玉，神态甚是闲雅。
LONG);
    	set("age", 43);
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
	set_skill("medicine", 150);
        set_skill("force", 60);
        set_skill("dodge", 80);
        set_skill("sword", 80);
        set_skill("parry", 80);
	
	setup();
	carry_object(__DIR__"obj/cyn_cloth")->wear();
	add_money("gold", 1);

}
