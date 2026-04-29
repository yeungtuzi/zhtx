// /d/xizang/class/bad/npc/hic.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("茜茜", ({ "hic", "qian qian", "qian" }));
	set("title", HIC+"才女"+NOR);
	set("gender", "女性" );
	set("age", 17);
	set("str", 15);
	set("cor", 23);
	set("cps", 19);
	set("int", 25);
	set("per", 26);
	set("long", @TEXT
她是步玄派的小女徒,她不是来挑战十大恶人的,她是来赚钱的,她只卖一样
东西,那就是....棺材!
TEXT
);
	set("chat_chance", 15);
        set("chat_msg", ({
                (: this_object(), "random_move" :)
        }));	set("combat_exp", 600000);
	set("attitude", "friendly");
	set("force", 999);
	set("max_force", 999);
		
	set_skill("unarmed", 10);
	set_skill("parry", 80);
	set_skill("dodge", 99);
	set_skill("force", 100);
	set_skill("mystforce", 200);
	set_skill("sword", 100);
	set_skill("mystsword", 200);
	set_skill("dodge", 100);
	set_skill("mysterrier", 200);
	set_skill("literate", 220);
	set_skill("move", 100);
	
	map_skill("force", "mystforce");
	map_skill("parry", "mystsword");
	map_skill("sword", "mystsword");
	map_skill("dodge", "mysterrier");
	map_skill("move", "mysterrier");
	set("vendor_goods", ([
		"棺材" : OBJ_DIR"toy/guancai",
	]));
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/gangjian")->wield();
}
