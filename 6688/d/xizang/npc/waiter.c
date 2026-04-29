// /d/xizang/npc/waiter.c

inherit NPC;
inherit F_VENDOR;

string ask_me();
void create()
{
	set_name("班察那", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 32);
	set("long",
	"店小二班察那正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
//	set_skill("iron-cloth", 2000);
	set_skill("unarmed", 100);
	set_skill("bloodystrike", 50);
	map_skill("unarmed", "bloodystrike");
	set("rank_info/respect", "小二哥");
        set("inquiry", ([
                "宝藏": "那只是一个传说,没有人能找得到.\n",
                "传说": "就是昆仑之墟的传说啦.\n",
                "寻宝": "鹰记商号在招募寻宝者,不过去的人没有一个回来.\n",
            "鹰记商号": "鹰记商号在城东北角,老板卜鹰十分有钱.\n",
                "卜鹰": "他好象是中原人,十分有钱,但是....\n",
            "昆仑之墟": (: ask_me :),
        ]) );

	set("vendor_goods", ([
		__DIR__"obj/junksword" : 5,
		__DIR__"obj/junkblade": 5,
		__DIR__"obj/junkstaff": 5,
		__DIR__"obj/jade3": 5,
		OBJ_DIR"example/bag": 5,
		__DIR__"obj/wineskin": 5,
		__DIR__"obj/sheep_leg": 5,
		OBJ_DIR"medicine/snake_drug": 5,
                __DIR__"obj/bean": 10,
                OBJ_DIR"clothes/leather": -1,
	]) );
	setup();
	if( !present("zang pao",this_object()) )
	carry_object(__DIR__"obj/zcloth")->wear();
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
	switch( random(3) ) {
		case 0:
			say( "店小二班察那笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二班察那用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
		case 2:
			say( "店小二班察那说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝几盅小店的酒吧，这几天才从窖子里开封的哟。\n");
			break;
	}
}

string ask_me()
{
        object who;
        who = this_player();
        if (who->query("marks/昆仑之墟")) 
                return "什么?!您真的到过那里?真是失敬,对不起.\n";
        return "昆仑之墟是神仙居住的地方,非要去瞧瞧的话最好带件皮衣御寒.\n";
}
