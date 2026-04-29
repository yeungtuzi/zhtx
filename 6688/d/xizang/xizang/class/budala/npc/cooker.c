// /d/xizang/class/budala/npc/cooker.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("厨子", ({"cooker", "chuzi" }));
        set("long", "这是一个普通的厨子,作不出什么好菜的.\n");
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 35);
        set("str", 20);
        set("max_kee", 300);
        set("max_gin", 300);
        set("combat_exp", 10);
        set("score", 1);
        setup();
        carry_object(OBJ_DIR"cloth")->wear();
}
