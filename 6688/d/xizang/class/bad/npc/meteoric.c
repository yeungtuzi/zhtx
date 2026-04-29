// /d/xizang/class/bad/npc/meteoric.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("秋离", ({ "meteoric", "qiu li", "qiu", "li" }));
	set("title", RED+"明教光明副使"+NOR);
	set("gender", "男性" );
	set("age", 27);
	set("str", 30);
	set("cor", 30);
	set("cps", 28);
	set("int", 24);
	set("per", 24);
	set("long", "他是明教左右光明使的助手之一,奉命前来恶人谷挑战\n");
	set("combat_exp", 1300000);
	set("attitude", "heroism");
	set("max_force", 2000);
	set("force", 2000);
	set("force_factor", 99);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 99);
	set_skill("sword", 160);
	set_skill("qiankun-danuoyi", 319);
	set_skill("iron-cloth", 219);
	set_skill("jiuyang-shengong", 199);
	set_skill("force", 249);

        map_skill("force", "jiuyang-shengong");
        map_skill("iron-cloth", "jiuyang-shengong");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("dodge", "qiankun-danuoyi");

	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/gangjian")->wield();
}
