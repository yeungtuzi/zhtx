inherit NPC;

void create()
{
	set_name("江洋大盗", ({ "jiangyang dadao", "dadao" }));
	set("long", @LONG
此人纵横江湖十余载，从未失手，没想到碰上了一品堂的高手，
中了悲酥清风之毒，只好束手就擒。
LONG);
	set("gender", "男性");
	set("age", 43);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("per", 10);

	set("max_kee", 1400);
	set("max_force", 2000);
	set("force", 500);
	set("force_factor", 101);

	set("combat_exp", 450000);

	set_skill("strike", 130);
	set_skill("force", 130);
	set_skill("dodge", 130);
	set_skill("parry", 130);
	set_skill("cuixin-zhang", 130);
	set_skill("qingcheng-force", 130);
	set_skill("qingcheng-steps", 130);

	map_skill("strike", "cuixin-zhang");
	map_skill("parry", "cuixin-zhang");
	map_skill("dodge", "qingcheng-steps");
	map_skill("force", "qingcheng-force");

	prepare_skill("strike", "cuixin-zhang");

	setup();
 	carry_object("obj/cloth")->wear();
}
