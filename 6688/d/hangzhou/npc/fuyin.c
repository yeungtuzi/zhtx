// fuyin.c  府尹
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("杭州府尹", ({ "hangzhou fuyin", "fuyin" }));
        set("gender", "男性");
        set("age", 25);

        set("long", "府尹。\n");
        set("shen_type", 1);
        setup();
//      carry_object("/d/city/npc/obj/yayifu")->wear();
}
        

