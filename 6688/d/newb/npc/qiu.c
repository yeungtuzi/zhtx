#include <ansi.h>
inherit NPC;

void create()
{
        // 2026-04-30: unused variable commented out
        // object ob;
        set_name("裘千尺", ({ "qiu qianchi","qianchii"}) );
        set("gender", "男性" );
        set("age", 40);
        set("title",HIR"天下第一"NOR);
        set("long","号称天下第一的人。\n");
        set("combat_exp", 40000);

        carry_object("/obj/cloth")->wear();
        carry_object("obj/weapon/gangjian")->wield();
        setup();
}

