#include <ansi.h>

inherit NPC;

void create()
{
	set_name("叶二娘", ({"ye erniang", "ye"}));
        set("nickname", HIR "无恶不做" NOR);
	set("title", "四大恶人");
	set("gender", "女性");
	set("age", 34);
	set("long", @LONG
她本来颇有几分姿色，只是右边脸上多了几道抓痕，显得可怖。
LONG);

	set("attitude", "peaceful");
	
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	set("per", 15);

	set("max_kee", 2000);
	set("max_gin", 700);
	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 90);
	
	set("combat_exp", 1000000);

	set("bellicosity", 500);

	set_temp("apply/armor", 40);
	
	set_skill("force", 120); 
	set_skill("tianmo-dafa", 120); 
        set_skill("strike", 120);
	set_skill("mo-zhang-jue", 150); 
	set_skill("dodge", 120); 
	set_skill("mo-shan-jue", 120); 
	set_skill("parry", 150); 
	set_skill("move", 120);
	set_skill("blade", 150); 
	set_skill("mo-dao-jue", 150); 
	
	map_skill("force", "tianmo-dafa");
	map_skill("strike", "mo-zhang-jue");
	map_skill("blade", "mo-dao-jue");
	map_skill("parry", "mo-dao-jue");
	map_skill("dodge", "mo-shan-jue");
	map_skill("move", "mo-shan-jue");

	prepare_skill("strike", "mo-zhang-jue");
	
	setup();

	carry_object(__DIR__"obj/liu_blade")->wield();
	carry_object(__DIR__"obj/pink_cloth")->wear();
	add_money("gold", 5);
}
