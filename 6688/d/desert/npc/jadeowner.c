
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("珠宝商", ({ "jade seller", "seller" }) );
        set("gender", "男性" );
        set("age", 49);
        set("long", "这是一位饱经风霜的店掌柜\n");
        set("combat_exp", 700000);
	set("str", 300);
        set("attitude", "friendly");
	set("force",1500);
	set("max_force",1000);
	set("force_factor",50);
	set("max_kee",600);
	set("max_sen",300);
	set("max_gin",300);
	set("kee",600);
	set("sen",300);
	set("gin",300);

        set_skill("blade", 150);
        set_skill("shortsong-blade", 150);
        set_skill("fall-steps", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
	set_skill("strike",150);
	set_skill("meihua-shou",150);
        map_skill("blade", "shortsong-blade");
        map_skill("parry", "shortsong-blade");
        map_skill("strike", "meihua-shou");
        map_skill("dodge", "fall-steps");
	prepare_skill("strike","meihua-shou");
        set("vendor_goods", ([
                __DIR__"obj/jade1":5,
                __DIR__"obj/jade2":5,
                __DIR__"obj/jade3":5,
                 __DIR__"obj/jade4":5,
		 __DIR__"obj/snake_drug":10,
        ]) );

        setup();
        add_money("gold",5);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/jadeblade")->wield();
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
        switch( random(2) ) {
                case 0:
                        say( " 店掌柜笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买玉挡灾吗？ \n");
                        break;
                case 1:
                        say( " 店掌柜笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，玉是吉祥之物，大漠无情，还是买一块挡灾吧。 \n");
                        break;

        }
}



