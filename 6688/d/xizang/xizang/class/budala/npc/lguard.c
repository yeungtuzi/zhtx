// /d/xizang/class/budala/npc/lguard.c
//

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("明灯守卫", ({"lamp guard", "guard"}));
        set("long", "这是一名守护长明灯的守卫.\n");
        set("gender", "男性");
        set("attitude", "peaceful");
	create_family("布达拉宫", random(3)+15, "弟子");
        set("class", "lama");
        set("age", 25+random(20));
        set("str", 25+random(10));
        set("int", 20);
        set("con", 20);
        set("max_kee", 500);
        set("max_gin", 300);
	set("max_sen", 300);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 20);
        set("combat_exp", 30000);
        set("score", 1);
        set_skill("force", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
        set_skill("parry", 70);
        set_skill("staff", 90);
        setup();
        carry_object(__DIR__"obj/jiasha")->wear();
	carry_object(__DIR__"obj/staff")->wield();
}
