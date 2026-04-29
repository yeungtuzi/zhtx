// /d/leigu/npc/laozhe2在无崖子那里

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(YEL"无名老者"NOR, ({ "nonename oldman", "oldman"}));
	set("long", "一个老者，正笑眯眯的看着你。\n");

	set("gender", "男性");
    	set("age", 92);
	set("shen_type",1);
    	set("attitude", "friendly");

    	set("str", 50);
    	set("int", 50);
    	set("con", 50);
    	set("dex", 50);  
    	set("cor", 30);
	set("per", 30);

    	set("max_kee", 2000);
    	set("max_gin", 500);
    	set("max_sen",500);
    	set("force", 7000);
    	set("max_force", 3500);
    	set("force_factor", 150);

    	set("combat_exp", 3600000);
    
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 100);
	set_temp("apply/armor_vs_force", 150);

    	set_skill("force", 200);
    	set_skill("parry", 220);
    	set_skill("dodge", 150);
	set_skill("hand",200);
	set_skill("cuff",150);
	set_skill("iron-cloth",200);
	set_skill("sword",200);

	set_skill("jiuyang-shengong", 200);
	set_skill("qiankun-danuoyi", 220);
  	set_skill("shenghuo-shengong",200);
	set_skill("qishang-quan",150);

	map_skill("force", "jiuyang-shengong");
	map_skill("iron-cloth", "jiuyang-shengong");
	map_skill("sword", "shenghuo-shengong");
	map_skill("cuff", "qishang-quan");	
	map_skill("parry", "qiankun-danuoyi");
	map_skill("hand", "shenghuo-shengong");	

	prepare_skill("hand", "shenghuo-shengong");

	setup();
	carry_object("obj/cloth")->wear();
	carry_object("/obj/weapon/bamboo_sword")->wield();	
}
