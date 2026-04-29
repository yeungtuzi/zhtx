// /d/xizang/class/budala/npc/spy.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("蒙面人", ({"spy"}));
        set("long", "这是一个蒙面的家伙,看上去不怀好意.\n");
        set("gender", "男性");
        set("attitude", "heroism");
        set("age", 25+random(20));
        set("str", 25+random(10));
        set("int", 20);
        set("con", 20);
        set("max_kee", 1000);
        set("max_gin", 1000);
        set("force", 1000);
        set("max_force", 1900);
        set("force_factor", 20);
        set("combat_exp", 100000+100000*random(11));
        set("score", 1);
        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("blade", 50);
        setup();
        carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/gangdao")->wield();
}
