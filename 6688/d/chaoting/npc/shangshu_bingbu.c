// /d/chaoting/npc/shangshu_bingbu.c
// chaoting system
// dongsw created for zh2 in 2002.5

#include <ansi.h>

inherit NPC;

string ask_pker();

void create()
{
        set_name("兵部尚书" , ({ "bingbu shangshu", "shangshu" }) );

        set("title",HIY"朝廷大臣"NOR);

        set("long",
        "兵部尚书。\n"
        );

        set("gender", "男性");

        set("age", 35);

        setup();

}

