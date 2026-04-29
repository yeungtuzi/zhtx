// /d/xizang/class/budala/npc/bguard.c
// by secret
// /d/xueshan/npc/seng-bing1.c
//

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("布达拉宫守卫", ({"guard"}));
        set("long", "这是一名布达拉宫的守卫,他们都是世代担任此职,尽职尽责.\n");
        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "lama");
        set("age", 25+random(20));
        set("str", 25+random(10));
        set("int", 20);
        set("con", 20);
        set("max_kee", 500);
        set("max_gin", 300);
	set("max_sen", 300);
	create_family("布达拉宫", random(3)+15, "弟子");
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 10);
        set("combat_exp", 10000);
        set("score", 1);
        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("staff", 50);
        setup();
        carry_object(__DIR__"obj/jiasha")->wear();
	carry_object(__DIR__"obj/staff")->wield();
}
