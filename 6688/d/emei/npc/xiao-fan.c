// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("小贩", ({ "xiao fan", "seller", "fan" }) );
	set("gender", "女性" );
	set("age", 32);
	set("long",
		"这是个小贩，是一个为了生计而出来劳动的老实巴交的乡下妇人。\n");
	set("shen_type", 1);
	set("combat_exp", 250); 
        set("max_kee",300);
        set("kee",300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "peaceful");
	set("vendor_goods", ([
		__DIR__"obj/hulu":10,
		__DIR__"obj/doufu":10,
		__DIR__"obj/mantou":10,
		__DIR__"obj/tiejia":10,
                __DIR__"obj/changjian":10,
                __DIR__"obj/gangdao":10,
                __DIR__"obj/baozi":10,
                __DIR__"obj/beixin":10,
                __DIR__"obj/goldring":10,
                __DIR__"obj/flower_shoe":10,
	]) );
	setup();
        carry_object(__DIR__"obj/cloth")->wear();
	add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_vendor_list", "list");
}

