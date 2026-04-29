inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("唐楠", ({ "tang nan", "tang" }));
        set("title", "商号老板");
        set("shen_type", 0);

        set("gender", "男性");
        set("age", 35);
        set("long",
                "这就是专搞买空卖空的唐楠, 据说是四川唐家的后代。\n");
        set("no_get_from", 1);
        set("no_get",1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        setup();
        carry_object("obj/cloth/cloth")->wear();
        add_money("gold", 1);
}

void init()
{
        add_action("do_vendor_list", "list");
        add_action("do_sell", "sell");
        add_action("do_value", "value");
}
