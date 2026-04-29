// rysj master.c
// write by dfbb@hero
// 1/25/96
// modified by yeung
// 1/14/99

#include <ansi.h>

inherit __DIR__"zhanglao";

void create()
{
	set_name("曲洋", ({ "qu yang", "qu" }));
	set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "长老");	
	set("nickname",HIB "天音神魔"NOR);	
	set("long", 
		"曲洋不但武功盖世，更妙悟音律，吹箫之技天下无双。\n");
	set("gender", "男性");
	set("age", 51);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("int", 300);
	
	set("max_kee", 2500);
	set("max_gin", 1500);
	set("max_sen", 1500);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 150);
	set("combat_exp", 5000000);

	set_skill("force", 180);
	set_skill("music",200);
	set_skill("tianmo-dafa", 200);
	set_skill("dodge", 180);
	set_skill("mo-shan-jue", 200);
        set_skill("strike", 180);
	set_skill("mo-zhang-jue", 180);
	set_skill("parry", 180);
	set_skill("hook", 180);
	set_skill("mo-gou-jue", 180);


	map_skill("force", "tianmo-dafa");
	map_skill("dodge", "mo-shan-jue");
        map_skill("strike", "mo-zhang-jue");
	map_skill("hook","mo-gou-jue");
        map_skill("parry","mo-gou-jue");
        prepare_skill("strike", "mo-zhang-jue");

	create_family("日月神教", 14, "长老");

	setup();
	carry_object("/d/heimuya/obj/coolhook")->wield();
	carry_object("/d/heimuya/obj/coolhook")->wield();
	suit = new("/obj/cloth");
	suit->move(this_object());
	suitname = query("nickname");
	suit->set("name",suitname+suit_name[random(sizeof(suit_name))]);
	suit->wear();	

	
}
