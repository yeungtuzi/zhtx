// rysj master.c
// write by dfbb@hero
// 1/25/96
// modified by yeung
// 1/14/99

#include <ansi.h>

inherit __DIR__"zhanglao";

void create()
{
	set_name("花想容", ({ "hua xiangrong", "hua"}));
	set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "长老");	
	set("nickname",HIM "追月魔女"NOR);	
	set("long", 
		"她的身份在神教中一直是一个迷，至于她如何能在妙龄之年\n"
		"位列十长老之席一直有许多传言，却从来没有人敢当面提起。\n"
	);
	set("gender", "女性");
	set("age", 21);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("per", 100);
	set("spi", 100);
	
	set("max_kee", 2500);
	set("max_gin", 1500);
	set("max_sen", 1500);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 150);
	set("combat_exp", 5000000);

	set_skill("force", 180);
	set_skill("perception",180);
	set_skill("tianmo-dafa", 200);
	set_skill("dodge", 180);
	set_skill("mo-shan-jue", 180);
        set_skill("strike", 180);
	set_skill("mo-zhang-jue", 180);
	set_skill("parry", 180);
	set_skill("blade", 180);
	set_skill("mo-dao-jue", 180);


	map_skill("force", "tianmo-dafa");
	map_skill("dodge", "mo-shan-jue");
        map_skill("strike", "mo-zhang-jue");
	map_skill("blade","mo-dao-jue");
        map_skill("parry","mo-dao-jue");
        prepare_skill("strike", "mo-zhang-jue");

	create_family("日月神教", 14, "长老");

	setup();
	carry_object("/d/heimuya/obj/coolblade")->wield();
	carry_object("/d/heimuya/obj/coolblade")->wield();
	suit = new("/obj/cloth");
	suit->move(this_object());
	suitname = query("nickname");
	suit->set("name",suitname+suit_name[random(sizeof(suit_name))]);
	suit->wear();	

	
}
