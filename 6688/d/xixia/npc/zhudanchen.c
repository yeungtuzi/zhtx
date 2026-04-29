#include <ansi.h>

inherit NPC;

void create()
{
	set_name("朱丹臣", ({"zhu dan chen", "zhu"}));
        set("title", "大理国宰相");
	set("gender", "男性");
	set("age", 37);
	set("long", @LONG
大理国的宰相，堪称文武全才。
LONG);
	set("attitude", "peaceful");
	
	set("int", 30);
	set("dex", 35);
	set("per", 30);

	set("max_kee", 2000);
	set("max_gin", 400);
	set("max_sen", 400);
	set("force", 1700);
	set("max_force", 1500);
	set("force_factor", 70);
	
	set("combat_exp", 700000);

	set_temp("apply/armor", 30);
	set_temp("apply/armor_vs_armor", 30);
	
	set_skill("force", 130); 
	set_skill("jiayiforce", 130); 
        set_skill("finger", 150);
	set_skill("yizhi-chan", 150);
	set_skill("dodge", 110); 
	set_skill("move", 110); 
	set_skill("tie-steps", 110); 
	set_skill("parry", 150); 
	set_skill("sword", 150); 
	set_skill("fy-sword", 150); 
	
	map_skill("force", "jiayiforce");
	map_skill("sword", "fy-sword");
	map_skill("parry", "fy-sword");
	map_skill("dodge", "tie-steps");
	map_skill("finger", "yizhi-chan");

	prepare_skill("finger", "yizhi-chan");

	setup();
	
	carry_object(__DIR__"obj/ironfan")->wield();
	carry_object("/obj/cloth")->wear();
	add_money("gold", 3);
}
