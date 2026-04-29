#include <ansi.h>

inherit NPC;

void create()
{
	set_name("史火龙", ({"shi huo long", "shi"}));
	set("gender", "男性");
	set("age", 16);
	set("long", @LONG
一个衣衫褴褛的小叫花。
LONG);

	set("attitude", "peaceful");
	
	set("str", 38);
	set("con", 35);
	set("per", 23);

	set("max_kee", 1000);
	set("force", 2000);
	set("max_force", 1200);
	set("shen", 10000);
	set("force_factor", 60);
	
	set("combat_exp", 200000);

	set("inquiry", ([
		"name": "小人名字不值一提。",
	]));

	set_temp("apply/armor", 40);
	set_temp("apply/damage", 40);
	
	set_skill("force", 150); 
	set_skill("huntian-qigong", 150); 
        set_skill("strike", 80);
	set_skill("xianglong-zhang", 80); 
	set_skill("dodge", 120); 
	set_skill("xiaoyaoyou", 120); 
	set_skill("parry", 100); 
	set_skill("staff", 130);
	set_skill("dagou-bang", 130);
	set_skill("checking", 150);
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");

	prepare_skill("strike", "xianglong-zhang");
	
	setup();

	carry_object("obj/cloth")->wear();
	carry_object(__DIR__"obj/dagoubang")->wield();

}
