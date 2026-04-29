
inherit NPC;
void create()
{
        set_name("老妇人", ({ "old woman" }) );
        set("gender", "女性" );
        set("age", 48);
        set("str", 58);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);
        set("max_atman", 300);
        set("atman", 300);
        set("max_mana", 300);
        set("mana", 300);

        set("max_force", 1000);
        set("force", 2000);
        set("force_factor", 50);
        set("attitude", "peaceful");

        set("long","这人云鬓不整，未洗铅华，四十多岁的年纪，五尺多高的身材，
容貌虽憔悴，但依稀仍可见少年时的风华。
\n");
        set("combat_exp", 200000);
        set_skill("strike", 100);
        set_skill("dodge", 100);
	set_skill("force",100);
        set_skill("taxue-wuhen",100);
        set_skill("moni-strike", 100);
	set_skill("moni-xinfa",100);
        map_skill("strike", "moni-strike");
        map_skill("dodge", "taxue-wuhen");
	map_skill("force", "moni-xinfa");

	prepare_skill("strike","moni-strike");

        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
	setup();
	carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/oilbag");
        add_money( "silver" , 50);
}
