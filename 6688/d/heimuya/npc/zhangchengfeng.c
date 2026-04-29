// rysj master.c
// write by dfbb@hero
// 1/25/96
// modified by yeung
// 1/14/99

#include <ansi.h>

inherit __DIR__"zhanglao";

void create()
{
	set_name("张乘风", ({ "zhang chengfeng", "zhang" }));
	set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "长老");	
	set("nickname",HIY "金猴神魔"NOR);	
	set("long", 
		"他身材不高，但是十分灵活。嘴角总是一副略带不屑的笑容，\n反而使他有一种特别的魅力。\n");
	set("gender", "男性");
	set("age", 51);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 300);
	
	set("max_kee", 2500);
	set("max_gin", 1500);
	set("max_sen", 1500);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 150);
	set("combat_exp", 5000000);

	set_skill("force", 180);
	set_skill("tianmo-dafa", 200);
	set_skill("dodge", 180);
	set_skill("mo-shan-jue", 200);
        set_skill("strike", 180);
	set_skill("mo-zhang-jue", 180);
	set_skill("parry", 180);
	set_skill("halberd", 180);
	set_skill("mo-ji-jue", 180);


	map_skill("force", "tianmo-dafa");
	map_skill("dodge", "mo-shan-jue");
        map_skill("strike", "mo-zhang-jue");
	map_skill("fork","mo-ji-jue");
        map_skill("halberd","mo-ji-jue");
        prepare_skill("strike", "mo-zhang-jue");

	create_family("日月神教", 14, "长老");

	setup();
	carry_object("/d/heimuya/obj/coolhalberd")->wield();
	carry_object("/d/heimuya/obj/coolhalberd")->wield();
	suit = new("/obj/cloth");
	suit->move(this_object());
	suitname = query("nickname");
	suit->set("name",suitname+suit_name[random(sizeof(suit_name))]);
	suit->wear();	

}
