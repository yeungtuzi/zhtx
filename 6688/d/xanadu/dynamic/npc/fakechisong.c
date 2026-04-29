inherit NPC;

void create()
{
	set_name("赤松", ({ "chi song", "chi","song" }) );
	set("gender", "男性" );
	set("age", 49);
	set("str", 50);
	set("long",
		"这就是葛伦的大弟子赤松吗？听说他被师傅打断了腿，这个可不太象耶。。\n一定是个冒牌货。\n"
		);
        set("combat_exp", 29999999);
	set("force_factor",200);

	set("atman",3000);
	set("max_atman",3000);
	set("kee",1000);
	set("max_kee",1000);
	set("sen",1000);
	set("max_sen",1000);
	set("force",8000);
	set("max_force",4000);

        set_skill("strike", 200);
        set_skill("staff", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("literate", 150);
	set_skill("iron-cloth", 300);
	set_skill("magic", 200);

	set_skill("bloodystrike", 180);
	set_skill("cloudstaff", 200);
	set_skill("bolomiduo", 200);
	set_skill("buddhism", 200);
	set_skill("essencemagic", 200);
	set_skill("notracesnow",180);
        set_skill("jin-gang", 300);


	map_skill("strike", "bloodystrike");
        map_skill("staff", "cloudstaff");
        map_skill("force", "bolomiduo");
        map_skill("parry", "cloudstaff");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("magic", "essencemagic");
        map_skill("dodge", "notracesnow");
	prepare_skill("strike","bloodystrike");
	setup();
}
