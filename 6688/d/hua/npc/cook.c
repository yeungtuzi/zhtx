inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("老板娘", ({ "cook" }) );
	set("gender", "女性" );
	set("age", 22);
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("inquiry", ([
		"work" : "这里也就是些洗盘子刷碗之类的活，你要是不愿意干的话去后院问我男人吧!",
		"工作" : "这里也就是些洗盘子刷碗之类的活，你要是不愿意干的话去后院问我男人吧!",
		]));
        set("vendor_goods", ([
                "/d/hua/obj/dust1":30,
                "/d/hua/obj/dust2":30
        ]) );
	
	setup();
}

void init()
{
        // 2026-04-30: unused variable commented out
        // object ob;

        ::init();
        add_action("do_vendor_list", "list");


}

