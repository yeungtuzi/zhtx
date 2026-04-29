// /d/xizang/class/bad/npc/gadzooks.c

#include <ansi.h>
#define OBJ_DIR "/obj/"

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("小巫仙", ({ "gadzooks", "midnight", "xiao wu xian" }));
	set("title", HIM+"桃花岛小仙女"+NOR);
	set("gender", "女性" );
	set("age", 22);
	set("str", 22);
	set("cor", 27);
	set("cps", 27);
	set("int", 27);
	set("per", 29);
	set("long", "她就是让人一见倾心的桃花岛小仙女\n");
	set("combat_exp", 1200000);
	set("attitude", "heroism");
	set("force", 3500);
	set("max_force", 3500);
	set("force_factor", 150);
	set("revive",8);

	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("sword", 230);
	set_skill("dodge", 180);
	set_skill("move", 180);
	set_skill("luoying-zhang", 665);
	set_skill("force", 900);
	set_skill("taohua-force", 220);
	set_skill("yuxiao-jian", 530);

	map_skill("strike", "luoying-zhang");
	map_skill("force", "taohuan-force");
	map_skill("sword", "yuxiao-jian");
	map_skill("parry", "yuxiao-jian");

	set("vendor_goods", ([
		 __DIR__"obj/wine3": -1,
		OBJ_DIR"food/meat": -1,
		OBJ_DIR"food/waterpot":-1,
		OBJ_DIR"example/bag":-1,
		OBJ_DIR"example/dagger":-1,
		OBJ_DIR"example/orange":-1,
		OBJ_DIR"medicine/jinchuang":-1,
	]));
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/gangjian")->wield();
//	carry_object(OBJ_DIR"toy/book");
}

void init()
{
 	add_action("do_vendor_list", "list");
}

//add fight function and ask for helping things

void die()
{
	if( query("revive") <= 0 ) return ::die();
	add("revive",-1);
	unconcious();
	"/cmds/imm/full"->main(this_object(),"");
	revive();
	command("xixi");
	command("say 我没死");
	command("sigh");
	command("qifu");
	return;
}

