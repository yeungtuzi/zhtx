#include <ansi.h>

inherit NPC;

void create()
{
	set_name("段延庆", ({"duan yanqing", "duan"}));
        set("nickname", HIR "恶贯满盈" NOR);
	set("title", "四大恶人");
	set("gender", "男性");
	set("age", 47);
	set("long", @LONG
段延庆本是大理皇太子，一场宫廷事变不但使他失去太子之位，且几
成废人，一场奇遇又使他得以重新振作，几年以后以四大恶人之首的
身份重出江湖。他面色煞白，毫无表情，双腿显然已废，因而只能靠
撑着拐杖走路。
LONG);

	set("attitude", "killer");
	set("shen_type", -1);
	
	set("int", 40);
	set("con", 35);
	set("cor", 40);
	set("wil", 40);
	set("dex", 30);
	set("per", 15);

	set("max_kee", 3000);
	set("max_gin", 1000);
	set("max_sen", 1000);
	set("force", 6000);
	set("max_force", 3000);
	set("force_factor", 200);
	
	set("combat_exp", 2500000);

	set("bellicosity", 500);

	set_temp("apply/armor", 80);
	set_temp("apply/armor_vs_force", 80);
	
	set_skill("force", 200); 
	set_skill("tianmo-dafa", 200); 
        set_skill("strike", 200);
	set_skill("mo-zhang-jue", 180); 
	set_skill("dodge", 180); 
	set_skill("mo-shan-jue", 180); 
	set_skill("literate", 150);
	set_skill("qi", 180);
	set_skill("parry", 200); 
	set_skill("move", 180);
	set_skill("staff", 200); 
	set_skill("wuchang-zhang", 200); 
	
	map_skill("force", "tianmo-dafa");
	map_skill("strike", "mo-zhang-jue");
	map_skill("staff", "wuchang-zhang");
	map_skill("parry", "wuchang-zhang");
	map_skill("dodge", "mo-shan-jue");
	map_skill("move", "mo-shan-jue");

	prepare_skill("strike", "mo-zhang-jue");
	
	setup();

	carry_object(__DIR__"obj/staff")->wield();
	carry_object(__DIR__"obj/yanqing_cloth")->wear();
}
