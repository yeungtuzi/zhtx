// /d/xizang/class/bad/npc/poi.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("爱学习", ({ "poi", "ai xuexi", "xi" }));
	set("title", BLU"纯情少年"+NOR);
	set("gender", "男性" );
	set("age", 21);
	set("str", 30);
	set("cor", 23);
	set("cps", 30);
	set("int", 25);
	set("per", 24);
	set("long", @TEXT
据说侠客就是为了躲避此人才逃到恶人谷....他的武功也不算高,被侠客打晕
过无数次,不知为什么舍不得杀他.他最厉害的功夫是武当"缠"字诀,华山金面
功也颇为不凡,外加偷学自茅山的"阴魂不散",招惹他的人多半会很难受
TEXT
);
	set("combat_exp", 900000);
	set("force", 1999);
	set("max_force", 1000);
	set("attitude", "heroism");
	set_skill("unarmed", 140);
	set_skill("parry", 130);
	set_skill("dodge", 100);
	set_skill("sword", 120);
	set_skill("force", 100);

	set_skill("yaksword", 120);
	set_skill("literate", 100);

	map_skill("sword", "yaksword");
	map_skill("parry", "yaksword");
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/gangjian")->wield();
	carry_object(__DIR__"obj/jianpu");
}
