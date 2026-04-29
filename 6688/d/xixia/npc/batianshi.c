#include <ansi.h>

inherit NPC;

void create()
{
	set_name("巴天石", ({"ba tian shi", "ba"}));
	set("title", "大理国司空");
	set("gender", "男性");
	set("age", 39);
	set("rank_info/respect", "巴司空");
	set("long", @LONG
大理国巴司空，轻功绝顶。
LONG);
	set("attitude", "peaceful");
	
	set("int", 30);
	set("dex", 35);
	set("per", 20);

	set("max_kee", 1800);
	set("max_gin", 400);
	set("max_sen", 400);
	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 101);
	
	set("combat_exp", 800000);

	set_temp("apply/armor", 30);
	
	set_skill("force", 130); 
	set_skill("taiji-shengong", 130); 
        set_skill("unarmed", 220);
	set_skill("dodge", 170); 
	set_skill("move", 170); 
	set_skill("tiyunzong", 170); 
	set_skill("parry", 120); 
	set_skill("cuff", 90); 
	set_skill("taiji-quan", 90); 
	
	map_skill("force", "taiji-shengong");
	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("dodge", "tiyunzong");
	map_skill("move", "tiyunzong");

	prepare_skill("cuff", "taiji-quan");

	setup();
	
	carry_object("/obj/cloth")->wear();
	add_money("gold", 3);
}
