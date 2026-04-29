// /d/xizang/class/bad/npc/apul.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("干将", ({ "apul", "gan jiang", "jiang", "gan" }));
	set("title", GRN+"华山剑侠"+NOR);
	set("gender", "男性" );
	set("age", 23);
	set("str", 25);
	set("cor", 24);
	set("cps", 27);
	set("int", 26);
	set("per", 26);
	set("long", @TEXT
他是花云的师弟,奉师父之命前来协助师姐的,不过他的武功并不太好,不帮倒
忙已经不错了.
TEXT
);
	set("combat_exp", 400000);
	set("attitude", "heroism");
	set("force", 1500);
	set("max_force", 1500);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 99);
	set_skill("sword", 99);
	set_skill("move", 99);
	set_skill("force", 99);
	set_skill("zixia-shengong", 100);
	set_skill("sword9", 80);
	set_skill("huashan-zhangfa", 99);

	map_skill("sword", "sword9");
	map_skill("parry", "sword9");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "huashan-shenfa");
	map_skill("move","huashan-shenfa");
	map_skill("unarmed", "huashan-zhangfa");
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/gangjian")->wield();
}
