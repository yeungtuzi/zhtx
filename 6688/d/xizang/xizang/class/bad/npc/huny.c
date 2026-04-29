// /d/xizang/class/bad/npc/huny.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("风玄", ({ "huny", "fengxuan", "feng", "xuan" }));
	set("title", HIC+"书生"+NOR);
	set("gender", "男性" );
	set("age", 30);
	set("str", 25);
	set("cor", 30);
	set("int", 25);
	set("per", 26);
	set("long", @TEXT
他是步玄派的高足,这个门派很少参与江湖仇杀,他到这里来大概是为了
追回顽皮淘气的小师妹茜茜吧,如果看到茜茜记得通知他一声
TEXT
);
	set("force", 3500);
	set("max_force", 3500);
	set("combat_exp", 2600000);
	set("attitude", "friendly");
	set_skill("unarmed", 100);
	set_skill("parry", 220);
	set_skill("dodge", 199);
	set_skill("force", 200);
	set_skill("mystforce", 240);
	set_skill("sword", 220);
	set_skill("mystsword", 240);
	set_skill("dodge", 240);
	set_skill("mysterrier", 240);
	set_skill("literate", 240);
	set_skill("move", 230);
	
	map_skill("force", "mystforce");
	map_skill("parry", "mystsword");
	map_skill("sword", "mystsword");
	map_skill("dodge", "mysterrier");
	map_skill("move", "mysterrier");
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/gangjian")->wield();
}
