// rysj master.c
// write by dfbb@hero
// 1/25/96
// modified by yeung
// 1/14/99

#include <ansi.h>

inherit __DIR__"zhanglao";

void create()
{
	set_name("杨延庆", ({ "yang yanqing", "yang"}));
	set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "长老");	
	set("nickname",HIR "刺日神魔"NOR);	
	set("long", 
		"他是杨家枪法的杰出传人，后来杀了本门长辈叛入魔教。\n"
		"将家传枪法和日月教武功相结合，又自行创出一种枪法。\n"
		"他面上满是刚毅之色，显然并非寻常人物。\n"
	);
	set("gender", "男性");
	set("age", 51);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("cor", 100);
	set("cps", 200);
	
	set("max_kee", 2500);
	set("max_gin", 1500);
	set("max_sen", 1500);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 150);
	set("combat_exp", 5000000);

	set_skill("force", 180);
	set_skill("perception",150);
	set_skill("tianmo-dafa", 200);
	set_skill("dodge", 180);
	set_skill("mo-shan-jue", 200);
        set_skill("strike", 180);
	set_skill("mo-zhang-jue", 180);
	set_skill("parry", 180);
	set_skill("spear", 180);
	set_skill("mo-qiang-jue", 180);


	map_skill("force", "tianmo-dafa");
	map_skill("dodge", "mo-shan-jue");
        map_skill("strike", "mo-zhang-jue");
	map_skill("spear","mo-qiang-jue");
        map_skill("parry","mo-qiang-jue");
        prepare_skill("strike", "mo-zhang-jue");

	create_family("日月神教", 14, "长老");

	setup();
	carry_object("/d/heimuya/obj/coolspear")->wield();
	suit = new("/obj/cloth");
	suit->move(this_object());
	suitname = query("nickname");
	suit->set("name",suitname+suit_name[random(sizeof(suit_name))]);
	suit->wear();	

	
}
