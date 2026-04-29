// /d/xizang/npc/sheepgirl3.c

inherit NPC;

void create()
{
        set_name("牧羊女", ({ "sheep girl", "girl" }) );
        set("gender", "女性" );
        set("age", 14);
        set("long", "一个天真活泼，美丽大方的少女。 \n");
        set("combat_exp", 5000);
	set("per", 30);
        set("inquiry", ([
               "宝藏" : "真的有宝藏就好了,听说鹰记商号在招募寻宝者.\n",
           "昆仑之墟" : "昆仑之墟是诸神居住的地方.\n",
               "寻宝" : "最好别去,去的人没有一个活着回来.\n",
        ]) );
        set("attitude", "friendly");
        set_skill("whip", 10);
        set_skill("parry", 25);
	set_skill("dodge", 60);
//	set_skill("snowwhip", 10);
//	map_skill("whip", "snowwhip");
//	map_skill("parry", "snowwhip");

	setup();
	add_money("coin", 5);
        carry_object(__DIR__"obj/skirt")->wear();
	carry_object(__DIR__"obj/whip")->wield();
}
