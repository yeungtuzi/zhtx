// /d/xizang/class/budala/npc/shijiang.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("石匠", ({"shi jiang", "jiang" }));
        set("long", "这是一个布达拉宫的石匠.\n");
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 42);
        set("str", 31);
        set("max_kee", 300);
        set("max_gin", 300);
        set("combat_exp", 10);
	set_skill("hammer", 30);
        set("score", 1);
        setup();
        carry_object(OBJ_DIR"cloth")->wear();
}
