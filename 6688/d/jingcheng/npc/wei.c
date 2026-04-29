// wei.c

#include <ansi.h>  

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name(HIR"魏不悔"NOR, ({ "wei buhui", "wei" }));
        set("title", "杂货铺老板");
        set("shen_type", 1);

        set("gender", "男性");
        set("age", 50);
        set("long",
        MAG"魏无双是外地人，但他人缘好，再京城很受欢迎。他已做了十几年的小买卖。\n"
"可是有些人说他会武功，整个人充满了神秘。\n"NOR);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_temp("apply/damage", 35);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/dblade.c":20,
                __DIR__"obj/shield.c":20,
//		 __DIR__"obj/sen.c":20,
		__DIR__"obj/vest.c":20,
        ]));

        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
}
