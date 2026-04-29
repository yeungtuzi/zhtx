// /d/xizang/class/budala/npc/mujiang.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("木匠", ({"mu jiang", "jiang" }));
        set("long", "这是一个普通的木匠,手指灵巧,能作各种木器,但不会武功.\n");
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 45);
        set("str", 28);
        set("max_kee", 500);
        set("max_gin", 300);
        set("combat_exp", 10);
        set("score", 1);
        setup();
        carry_object(OBJ_DIR"cloth")->wear();
}
