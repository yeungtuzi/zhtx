//s_czj.c

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name(HIW"曹子建"NOR, ({ "cao zijian","cao" }) );
        set("gender", "男性" );
        set("age", 25);
        set("long", "一个落泊书生，虽然读着书，但显然有些心事。\n");
       
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("shen_type",0);

	set_skill("literate",200);
	set_skill("parry",50);

	set("vendor_goods",([
        __DIR__"obj/shuji1":-1,
        __DIR__"obj/shuji2":-1,
        __DIR__"obj/shuji3":-1,
        __DIR__"obj/shuji4":-1,
    	]));

        setup();
        add_money("gold", 1);
        carry_object("/d/suzhou/npc/obj/baishan")->wear();
}

void init(){
    add_action("do_vendor_list","list");
}