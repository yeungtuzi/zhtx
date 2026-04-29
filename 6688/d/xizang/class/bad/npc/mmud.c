// /d/xizang/class/bad/npc/mmud.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("阿土", ({ "mmud", "a tu", "tu" }));
	set("title", HIB+"四海为家"+NOR);
	set("gender", "男性" );
	set("age", 38);
	set("str", 22);
	set("cor", 29);
	set("cps", 29);
	set("int", 23);
	set("long", "他就是助人为乐的流浪刀客阿土\n");
	set("combat_exp", 1800000);
	set("attitude", "heroism");
	set("force", 2999);
	set("max_force",1500);
	set("force_factor", 50);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("dodge", 199);
	set_skill("blade", 210);
	set_skill("move", 199);
	set_skill("force", 240);
	set_skill("spring-blade", 240);
	set_skill("pyrobat-steps", 240);
	set_skill("celestial", 180);
	set_skill("celestrike", 199);

	map_skill("blade", "spring-blade");
	map_skill("parry", "spring-blade");
	map_skill("dodge", "pyrobat-steps");
	map_skill("move", "pyrobat-steps");
	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/gangdao")->wield();
}
