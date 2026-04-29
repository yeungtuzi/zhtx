// /d/xizang/class/budala/npc/chashi.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("茶师", ({"teaman", "chashi", "shi" }));
        set("long", "这是一个布达拉宫的茶师,善于配制好茶.\n");
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 49);
        set("str", 20);
        set("max_kee", 300);
        set("max_gin", 300);
        set("combat_exp", 10);
        set("score", 1);
        setup();
        carry_object(OBJ_DIR"cloth")->wear();
}
