// /d/xizang/npc/zseller.c

// #define OBJ_DIR "/obj/"

inherit NPC;
inherit F_VENDOR;

string ask_me();
void create()
{
        set_name("次仁多吉", ({ "seller" }) );
        set("gender", "男性" );
        set("age", 55);
        set("long",
        "这是宫前街杂货店的老板次仁多吉,他早年行走中原,颇认得很多宝物.\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("bloodystrike", 50);
        map_skill("unarmed", "bloodystrike");
        set("rank_info/respect", "大叔");
        set("inquiry", ([
                "宝藏": "那只是一个传说,没有人能找得到.\n",
                "传说": "就是昆仑之墟的传说啦.\n",
                "寻宝": "鹰记商号在招募寻宝者,不过去的人没有一个回来.\n",
            "鹰记商号": "鹰记商号在城东北角,老板卜鹰十分有钱.\n",
                "卜鹰": "他好象是中原人,十分有钱,但是....\n",
            "昆仑之墟": (: ask_me :),
        ]) );

        set("vendor_goods", ([
                __DIR__"obj/junkstaff" : 1,
                __DIR__"obj/jade3" : 1,
                "/obj/example/bag": -1,
                "/obj/medicine/snake_drug": 20,
                "/obj/clothes/leather": 20,
		__DIR__"obj/statue": 1,
        ]) );
        setup();
	if( !present("zang pao",this_object()) )
		carry_object(__DIR__"obj/zcloth")->wear();
}

void init()
{
        add_action("do_vendor_list", "list");
}

string ask_me()
{
        object who;
        who = this_player();
        if (who->query("marks/昆仑之墟"))
                return "什么?!您真的到过那里?真是失敬,对不起.\n";
        return "昆仑之墟是神仙居住的地方,非要去瞧瞧的话,最好带件皮衣御寒.\n";
}
