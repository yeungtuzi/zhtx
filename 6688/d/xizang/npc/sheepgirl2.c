// /d/xizang/npc/sheepgirl2.c

inherit NPC;

void create()
{
        set_name("牧羊女", ({ "sheep girl", "girl" }) );
        set("gender", "女性" );
        set("age", 16+random(4));
        set("long", "一个天真活泼，美丽大方的少女。 \n");
        set("combat_exp", 5000+100*random(40));
	set("per", 30);
        set("inquiry", ([
               "宝藏": "真的有宝藏就好了.\n",
           "昆仑之墟": "昆仑之墟是诸神居住的地方.\n",
        ]) );
        set("attitude", "friendly");
        set_skill("whip", 50);
        set_skill("parry", 25);
	set_skill("dodge", 80);
//	set_skill("fall-steps", 50);
//	set_skill("snowwhip", 50);
//	map_skill("whip", "snowwhip");
//	map_skill("parry", "snowwhip");
//	map_skill("dodge", "fall-steps");
	setup();
	add_money("coin", 15);
        carry_object(__DIR__"obj/skirt")->wear();
	carry_object(__DIR__"obj/whip")->wield();
}
