inherit NPC;

void create()
{
	set_name("虚竹", ({ "xu zhu", "xu"}) );
	set("gender", "男性");
	set("age", 23);
	set("str", 50);
	set("cor", 20);
	set("cps", 30);
	set("int", 20);
	set("per", 12);
	set("con", 30);
	set("kar", 40);
	set("max_force", 4000);
	set("force", 8000);
	set("max_kee", 7000);
        set("max_gin", 1000);
        set("max_sen",1000);
	set("force_factor", 200);
	set("long", @LONG
一个小和尚，居然也跑到这里来了。
LONG);
	create_family("灵鹫宫", 2, "尊主");
	set("family/create_time",4);
    	set("combat_exp", 2000000);
	set("shen_type", 1);
    	set("score", 20000);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({ 
		(: exert_function,"recover":),
		(: exert_function,"exert powerup" :),
	 }) );

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 150);
	set_temp("apply/armor_vs_force", 180);

    	set_skill("parry", 200);
	set_skill("dodge", 200);
    	set_skill("force", 200);
	set_skill("hand", 200);
	set_skill("strike", 200);
    	set_skill("literate", 100);
	set_skill("perception",100);

    	set_skill("bahuang-gong", 200);
    	set_skill("zhemei-shou", 200);
	set_skill("liuyang-zhang", 200);

	map_skill("force", "bahuang-gong");
	map_skill("parry", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("strike", "liuyang-zhang");

	prepare_skill("hand", "zhemei-shou");
	prepare_skill("strike", "liuyang-zhang");

	carry_object("/obj/cloth")->wear();
	setup();
}
