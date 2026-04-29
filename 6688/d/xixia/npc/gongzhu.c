inherit NPC;

void create()
{
	set_name("银川公主", ({ "yinchuan gongzhu", "gongzhu"}) );
	set("gender", "女性");
	set("age", 19);

	set("str", 20);
	set("per", 32);

	set("max_force", 2000);
	set("force", 2000);
	set("max_kee", 2000);
        set("max_gin", 600);
        set("max_sen",600);
	set("force_factor", 80);

	set("long", @LONG
这就是西夏的银川公主，这次要招聘驸马的就是她。
LONG);
    	set("combat_exp", 300000);
	set("shen_type", 1);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({ 
		(: exert_function,"recover":),
	 }) );

	set_temp("apply/attack", 20);
	set_temp("apply/armor", 50);
	set_temp("apply/armor_vs_force", 80);

    	set_skill("parry", 120);
	set_skill("dodge", 120);
    	set_skill("force", 120);
	set_skill("hand", 120);
    	set_skill("literate", 150);
    	set_skill("music", 80);
	set_skill("perception",100);

    	set_skill("xiaowuxiang-gong", 120);
    	set_skill("zhemei-shou", 120);
	set_skill("lingboweibu", 120);

	map_skill("force", "xiaowuxiang-gong");
	map_skill("parry", "zhemei-shou");
	map_skill("hand", "zhemei-shou");

	prepare_skill("hand", "zhemei-shou");

	carry_object(__DIR__"obj/dress")->wear();
	setup();
}
