// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("采药人", ({ "caiyao ren","ren" }) );
        set("gender", "男性" );
        set("age", 55);
        set("long",
                "这是一位满脸沧桑的采药人，从他的面容来看，已经很大的年龄了。\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/shanshen": 1,
                __DIR__"obj/lingzhi": 1,
                __DIR__"obj/heshouwu": 1,
        ]) );
        setup();

}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	say( "采药人慎重地对你说：这位" + RANK_D->query_respect(ob)+"还是小心点吧，前面的路可不好走。\n");
	return;
}

